#include "ByteArrayBuilder.h"


PyObject* ByteArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return byte_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* ByteArrayBuilder::byte_array_from(EqData* data_from_doocs) const {
    int byte_array_length;
    u_char* byte_array_data;

    data_from_doocs->get_byte(&byte_array_length, &byte_array_data);

    std::vector<u_char> array_data;
    for (int i = 0; i < byte_array_length; ++i) {
        array_data.push_back(byte_array_data[i]);
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_UINT8);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array);
    Py_DECREF(numpy_array);

    return built_for_return;
}

PyObject* ByteArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
