#include "TsFloatArrayBuilder.h"


PyObject* TsFloatArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return ts_float_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* TsFloatArrayBuilder::ts_float_array_from(EqData* data_from_doocs) const {
    u_int seconds;
    u_short milliseconds;
    double time;
    u_short status;
    float history;

    PyObject* history_list = PyList_New(data_from_doocs->length());
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_ts_float(&seconds, &milliseconds, &status, &history, i);
        time = seconds + milliseconds/1e3;

        PyList_SetItem(history_list, i, Py_BuildValue("[ffi]", time, history, status));
    }

    PyObject* built_for_return = build_read('O', data_from_doocs, history_list);
    Py_DECREF(history_list);

    return built_for_return;
}

PyObject* TsFloatArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
