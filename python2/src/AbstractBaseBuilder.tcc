#include <iterator>

using doocs::Timestamp;


template<typename T>
PyObject* AbstractBaseBuilder::build_read(const char type, EqData* data_from_doocs, const T data) const {
    PyObject* miscellaneous = Py_BuildValue("{}");  // miscellaneous data as empty dict

    PyObject* built_for_return = build_read(type, data_from_doocs, data, miscellaneous);
    Py_DECREF(miscellaneous);

    return built_for_return;
}

template<typename T>
PyObject* AbstractBaseBuilder::build_read(const char type, EqData* data_from_doocs, const T data,
                                          const PyObject* miscellaneous) const {
    Timestamp timestamp = data_from_doocs->get_timestamp();
    Timestamp::SecondsAndMicroseconds seconds_and_microseconds = timestamp.get_seconds_and_microseconds_since_epoch();

    int timestamp_sec = seconds_and_microseconds.seconds;
    int timestamp_micro_sec = seconds_and_microseconds.microseconds;

    const std::string output_format{std::string("{s") + type + "sssdslsO}"};  // according to the Python/C API

    // the actual data dict returned from pydoocs to python
    return Py_BuildValue(output_format.c_str(),
                         DATA_KEY, data,
                         TYPE_KEY, data_from_doocs->type_string(),
                         TIMESTAMP_KEY, timestamp_sec + (timestamp_micro_sec / 1e6),
                         MACROPULSE_KEY, data_from_doocs->mpnum(),
                         MISCELLANEOUS_KEY, miscellaneous);
}

template<typename T1, typename T2>
PyObject* AbstractBaseBuilder::build_numpy_array(const std::vector<T1>& array_data, const T2 type) const {
    npy_intp array_size{static_cast<npy_intp>(array_data.size())};

    PyObject* py_array_1d = PyArray_SimpleNew(1, &array_size, type);

    std::copy(array_data.begin(), array_data.end(),
              static_cast<T1*>(PyArray_DATA(reinterpret_cast<PyArrayObject*>(py_array_1d))));

    return py_array_1d;
}

template<typename T1, typename T2>
PyObject* AbstractBaseBuilder::build_numpy_array(const std::vector<std::vector<T1>>& array_data, const T2 type) const {
    if (array_data.size() < 1) {
        throw PyDoocsException::array_size_invalid();
    }

    npy_intp array_size[] = {static_cast<npy_intp>(array_data.size()), static_cast<npy_intp>(array_data[0].size())};

    PyObject* py_array_2d = PyArray_SimpleNew(2, array_size, type);

    for (std::size_t i = 0; i < array_data.size(); ++i) {
        std::copy(array_data[i].begin(), array_data[i].end(),
                  static_cast<T1 *>(PyArray_DATA(reinterpret_cast<PyArrayObject *>(py_array_2d))) +
                          i * array_data[0].size());
    }

    return py_array_2d;
}

template<typename T>
PyObject* AbstractBaseBuilder::build_write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                           const T data) const {
    data_to_doocs->set(data);

    if (EqCall().set(address, data_to_doocs, data_from_doocs)) {
        throw DoocsException::from(*data_from_doocs);
    }

    Py_RETURN_NONE;
}

template<typename T>
PyObject* AbstractBaseBuilder::build_write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                           const std::vector<T>& array_data) const {
    for (unsigned int i = 0; i < array_data.size(); ++i) {
        data_to_doocs->set(array_data[i], static_cast<int>(i));
    }

    if (EqCall().set(address, data_to_doocs, data_from_doocs)) {
        throw DoocsException::from(*data_from_doocs);
    }

    Py_RETURN_NONE;
}
