#include "DoubleBuilder.h"


PyObject* DoubleBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return build_read('d', data_from_doocs, data_from_doocs->get_double());
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* DoubleBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                               PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!(PyFloat_CheckExact(data_from_python) || PyLong_CheckExact(data_from_python) ||
                is_any_numpy_float(data_from_python))) {
            throw PyDoocsException::wrong_input_data_format();
        }

        return build_write(address, data_to_doocs, data_from_doocs, PyFloat_AsDouble(data_from_python));
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
