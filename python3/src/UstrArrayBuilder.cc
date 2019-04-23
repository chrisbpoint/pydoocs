#include "UstrArrayBuilder.h"


PyObject* UstrArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return ustr_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* UstrArrayBuilder::ustr_array_from(EqData* data_from_doocs) const {
    int i1;
    float f1, f2;
    time_t tm;
    char comment[STRING_LENGTH];
    char* comment_data;

    PyObject* array_list = PyList_New(data_from_doocs->length());
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_ustr(&i1, &f1, &f2, &tm, &comment_data, i);
        strncpy(comment, comment_data, sizeof(comment));

        PyList_SetItem(array_list, i, Py_BuildValue("[iffls]", i1, f1, f2, tm, comment));
    }

    PyObject* built_for_return = build_read('O', data_from_doocs, array_list);
    Py_DECREF(array_list);

    return built_for_return;
}

PyObject* UstrArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
