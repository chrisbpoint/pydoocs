#include "LongBuilder.h"


PyObject* LongBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return build_read('l', data_from_doocs, data_from_doocs->get_long());
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* LongBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                             PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyLong_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        return build_write(address, data_to_doocs, data_from_doocs,
                static_cast<long long>(PyLong_AsLong(data_from_python)));  //NOLINT: int64 vs long long
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
