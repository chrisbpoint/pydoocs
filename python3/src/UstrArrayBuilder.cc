#include "UstrArrayBuilder.h"
#include <iostream>

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

PyObject* UstrArrayBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                  PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python) ||
            PyList_Size(data_from_python) != 1 ||
            !PyList_CheckExact(PyList_GetItem(data_from_python, 0)) ||
            PyList_Size(PyList_GetItem(data_from_python, 0)) != 5) {
            throw PyDoocsException::wrong_input_data_format();
        }

        USTR* ustr_data = data_from_doocs->get_ustr(0);

        PyObject* ustr = PyList_GetItem(data_from_python, 0);

        ustr_data->i1_data = PyLong_AsLong(PyList_GetItem(ustr, 0));
        ustr_data->f1_data = PyFloat_AsDouble(PyList_GetItem(ustr, 1));
        ustr_data->f2_data = PyFloat_AsDouble(PyList_GetItem(ustr, 2));
        ustr_data->tm = PyLong_AsLong(PyList_GetItem(ustr, 3));
        ustr_data->str_data.str_data_val = static_cast<char*>(PyUnicode_DATA(PyList_GetItem(ustr, 4)));

        return build_write(address, data_to_doocs, data_from_doocs, ustr_data, 0);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
