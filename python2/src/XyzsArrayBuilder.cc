#include "XyzsArrayBuilder.h"


PyObject* XyzsArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return xyzs_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* XyzsArrayBuilder::xyzs_array_from(EqData* data_from_doocs) const {
    int status;
    float x, y, z;
    char* comment;

    PyObject* array_list = PyList_New(data_from_doocs->length());
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_xyzs(&status, &x, &y, &z , &comment, i);
        PyList_SetItem(array_list, i, Py_BuildValue("[ifffs]", status, x, y, z, comment));
    }

    PyObject* built_for_return = build_read('O', data_from_doocs, array_list);
    Py_DECREF(array_list);

    return built_for_return;
}

PyObject* XyzsArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
