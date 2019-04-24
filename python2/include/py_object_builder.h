#ifndef PYTHON2_INCLUDE_PY_OBJECT_BUILDER_H_
#define PYTHON2_INCLUDE_PY_OBJECT_BUILDER_H_

#include "Python.h"

#include <eq_client.h>


/**
 * Utility for building PyObjects for the Python3 bindings to the standard DOOCS client API written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
namespace py_object_builder {
    /**
     * Low level function to build the PyObject for the DOOCS names call.
     *
     * @param data_from_doocs The DOOCS EqData object to query the DOOCS data from.
     * @return The pointer to an PyObject object containing the data to be queried.
     */
    PyObject* names(EqData* data_from_doocs);

    /**
     * Low level function to build the PyObject for the DOOCS read call.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write additional DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to read the DOOCS data from.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     * @param macropulse_number Optional macropulse number for synchronized readout.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, PyObject* doocs_parameters,
                   PyObject* macropulse_number);

    /**
     * Low level function to build the PyObject for the DOOCS write call.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write the DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to retrieve additional DOOCS data from.
     * @param data_from_python Data from python to be send to DOOCS.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     *
     * @return The pointer to an PyObject object while writing data from within python to DOOCS.
     */
    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, PyObject* data_from_python,
                    PyObject* doocs_parameters);
}  // namespace py_object_builder

#endif  // PYTHON2_INCLUDE_PY_OBJECT_BUILDER_H_
