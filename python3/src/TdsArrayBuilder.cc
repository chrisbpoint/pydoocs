#include "TdsArrayBuilder.h"


PyObject* TdsArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return tds_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* TdsArrayBuilder::tds_array_from(EqData* data_from_doocs) const {
    TDS* history;

    PyObject* history_list = PyList_New(data_from_doocs->length());
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        history = data_from_doocs->get_tds(i);

        PyList_SetItem(history_list, i, Py_BuildValue("[ifB]", history->tm, history->data, history->status));
    }

    PyObject* built_for_return = build_read('O', data_from_doocs, history_list);
    Py_DECREF(history_list);

    return built_for_return;
}

PyObject* TdsArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
