#include "IfffBuilder.h"


const int IfffBuilder::IFFF_INPUT_SIZE = 4;

PyObject* IfffBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        int i1;
        float f1, f2, f3;

        data_from_doocs->get_ifff(&i1, &f1, &f2, &f3);

        return build_read('O', data_from_doocs, Py_BuildValue("[ifff]", i1, f1, f2, f3));
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* IfffBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                             PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        if (PyList_Size(data_from_python) != IFFF_INPUT_SIZE) {
            throw PyDoocsException::input_list_size_mismatch();
        }

        IFFF* ifff_data = data_from_doocs->get_ifff();

        ifff_data->i1_data = PyLong_AsLong(PyList_GetItem(data_from_python, 0));
        ifff_data->f1_data = PyFloat_AsDouble(PyList_GetItem(data_from_python, 1));
        ifff_data->f2_data = PyFloat_AsDouble(PyList_GetItem(data_from_python, 2));
        ifff_data->f3_data = PyFloat_AsDouble(PyList_GetItem(data_from_python, 3));

        return build_write(address, data_to_doocs, data_from_doocs, ifff_data);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
