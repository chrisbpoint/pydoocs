#include "sync_util.h"
#include "AbstractBaseBuilder.h"


namespace sync_util {
    /*
     * The int constant for the default (current) macropulse.
     */
    const int DEFAULT_MACROPULSE = -1;

    /*
     * The int constant for various default parameters.
     */
    const int DEFAULT = -1;
    const int IIII_SIZE = 4;

    void synchronize_readout_for(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                 PyObject* doocs_parameters, PyObject* macropulse_number) {
        if (macropulse_number) {
            if (!(PyLong_CheckExact(macropulse_number) || PyInt_CheckExact(macropulse_number))) {
                throw PyDoocsException::wrong_macropulse_format();
            }

            auto macropulse = static_cast<int>(PyLong_AsLong(macropulse_number));

            if (macropulse > DEFAULT_MACROPULSE) {  // non-current macropulse (buffer) is supposed to be > -1
                // TODO(cbehrens): this entire block should be replaced once the macropulse set interface is unified
                if (EqCall().get(address, data_to_doocs, data_from_doocs)) {
                    throw DoocsException::from(*data_from_doocs);  // to trigger proper exception handling in the caller
                }

                switch (data_from_doocs->type()) {
                    case DATA_INT:
                        data_to_doocs->set(macropulse);
                        break;
                    case DATA_LONG:
                         data_to_doocs->set(macropulse);
                        break;                      
                    case DATA_FLOAT:
                        data_to_doocs->set(macropulse);
                        break;
                    case DATA_DOUBLE:
                        data_to_doocs->set(macropulse);
                        break;
                    case DATA_SPECTRUM:
                        data_to_doocs->set(macropulse, DEFAULT, DEFAULT, DEFAULT);
                        break;
                    case DATA_GSPECTRUM:
                        data_to_doocs->set(macropulse, DEFAULT, DEFAULT, DEFAULT);
                        break;
                    case DATA_IMAGE:
                        data_to_doocs->set(macropulse);
                        break;
                    default:
                        throw PyDoocsException::synchronization_not_supported_yet();
                }
            } else {
                throw PyDoocsException::invalid_macropulse();
            }
        } else if (doocs_parameters) {
            if (!PyList_CheckExact(doocs_parameters)) {
                throw PyDoocsException::wrong_parameter_format();
            }
            if (PyList_Size(doocs_parameters) != IIII_SIZE) {
                throw PyDoocsException::input_list_size_mismatch();
            }
            // TODO(cbehrens):
            // Normally one would have to check now on the plausibility of the input data, but we'll implement it later

            IIII iiii_data;
            data_to_doocs->init();
            data_to_doocs->set_type(DATA_IIII);

            iiii_data.i1_data = static_cast<int>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 0)));
            iiii_data.i2_data = static_cast<int>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 1)));
            iiii_data.i3_data = static_cast<int>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 2)));
            iiii_data.i4_data = static_cast<int>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 3)));

           // TODO(cbehrens): error handling
            data_to_doocs->set(iiii_data.i1_data, iiii_data.i2_data, iiii_data.i3_data, iiii_data.i4_data);

        }
    }

    void check_synchronization_for(PyObject* built_for_return, PyObject* macropulse_number) {
        if (macropulse_number) {
            if (!(PyLong_CheckExact(macropulse_number) || PyInt_CheckExact(macropulse_number))) {
                throw PyDoocsException::wrong_macropulse_format();
            }
            auto macropulse = static_cast<int>(PyLong_AsLong(macropulse_number));

            PyObject* macropulse_pyobject = PyDict_GetItemString(built_for_return, AbstractBaseBuilder::MACROPULSE_KEY);

            if (!(PyLong_CheckExact(macropulse_pyobject) || PyInt_CheckExact(macropulse_pyobject))) {  // the macropulse is supposed to be declared as a long ("l")
                throw PyDoocsException::unexpected_behaviour();
            }

            auto macropulse_difference = macropulse - PyLong_AsLong(macropulse_pyobject);
            if (macropulse_difference != 0) {
                throw PyDoocsException::macropulse_mismatch(macropulse_difference);
            }
        }
    }
}  // namespace sync_util
