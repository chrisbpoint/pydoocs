#ifndef PYTHON3_INCLUDE_SYNC_UTIL_H_
#define PYTHON3_INCLUDE_SYNC_UTIL_H_

#include <Python.h>

#include <eq_client.h>


/**
 * Synchronization utility for the Python3 bindings to the standard DOOCS client API written in C/C++.
 *
 * @author Christopher Behrens
 * @date May, 2018
 */
namespace sync_util {
    /**
     * Function to synchronize a read call for a given macropulse object.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to be synchronized with the given macropulse.
     * @param data_from_doocs The DOOCS EqData object to read the DOOCS data from.
     * @param macropulse_number The macropulse object for synchronized readout.
     */
    void synchronize_readout_for(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                 PyObject* doocs_parameters, PyObject* macropulse_number);
    /**
     * Function to check the synchronization of a read call with a given macropulse object.
     *
     * @param built_for_return The PyObject object pointer containing the data to be read including the macropulse.
     * @param macropulse_number The macropulse object to check for synchronized readout.
     */
    void check_synchronization_for(PyObject* built_for_return, PyObject* macropulse_number);
}  // namespace sync_util

#endif  // PYTHON3_INCLUDE_SYNC_UTIL_H_
