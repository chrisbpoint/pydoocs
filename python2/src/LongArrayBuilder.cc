#include "LongArrayBuilder.h"


PyObject* LongArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return long_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* LongArrayBuilder::long_array_from(EqData* data_from_doocs) const {
    std::vector<std::int64_t> array_data;
    // TODO(cbehrens): array_data.reserve(data_from_doocs->array_length());
    for (int i = 0; i < data_from_doocs->array_length(); ++i) {
        array_data.push_back(data_from_doocs->get_long(i));
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_LONG);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array);
    Py_DECREF(numpy_array);

    return built_for_return;
}

PyObject* LongArrayBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                  PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        if (PyList_Size(data_from_python) > data_from_doocs->array_length()) {
            throw PyDoocsException::input_list_too_large();
        }

        std::vector<long long> array_data;  //NOLINT: int64 vs long long
        for (std::int64_t i = 0; i < PyList_Size(data_from_python); ++i) {
            array_data.push_back(static_cast<std::int64_t>(PyLong_AsLong(PyList_GetItem(data_from_python, i))));
        }

        return build_write(address, data_to_doocs, data_from_doocs, array_data);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
