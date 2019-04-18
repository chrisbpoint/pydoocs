#include "FloatArrayBuilder.h"


PyObject* FloatArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return float_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* FloatArrayBuilder::float_array_from(EqData* data_from_doocs) const {
    std::vector<float> array_data;
    for (int i = 0; i < data_from_doocs->array_length(); ++i) {
        array_data.push_back(data_from_doocs->get_float(i));
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_FLOAT);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array);
    Py_DECREF(numpy_array);

    return built_for_return;
}

PyObject* FloatArrayBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                   PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        if (PyList_Size(data_from_python) > data_from_doocs->array_length()) {
            throw PyDoocsException::input_list_too_large();
        }

        std::vector<float> array_data;
        for (std::int64_t i = 0; i < PyList_Size(data_from_python); ++i) {
            array_data.push_back(static_cast<float>(PyFloat_AsDouble(PyList_GetItem(data_from_python, i))));
        }

        return build_write(address, data_to_doocs, data_from_doocs, array_data);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
