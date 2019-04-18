#include "IiiiBuilder.h"


const int IiiiBuilder::IIII_INPUT_SIZE = 4;

PyObject* IiiiBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        int i1, i2, i3, i4;

        data_from_doocs->get_iiii(&i1, &i2, &i3, &i4);

        return build_read('O', data_from_doocs, Py_BuildValue("[iiii]", i1, i2, i3, i4));
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* IiiiBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                             PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        if (PyList_Size(data_from_python) != IIII_INPUT_SIZE) {
            throw PyDoocsException::input_list_size_mismatch();
        }

        IIII* iiii_data = data_from_doocs->get_iiii();

        iiii_data->i1_data = PyLong_AsLong(PyList_GetItem(data_from_python, 0));
        iiii_data->i2_data = PyLong_AsLong(PyList_GetItem(data_from_python, 1));
        iiii_data->i3_data = PyLong_AsLong(PyList_GetItem(data_from_python, 2));
        iiii_data->i4_data = PyLong_AsLong(PyList_GetItem(data_from_python, 3));

        return build_write(address, data_to_doocs, data_from_doocs, iiii_data);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
