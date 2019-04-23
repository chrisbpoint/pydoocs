#ifndef INCLUDE_BUILD_UTIL_H_
#define INCLUDE_BUILD_UTIL_H_

#include <Python.h>

#include <eq_client.h>


/**
 * Building utility for the Python3 bindings to the standard DOOCS client API written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
namespace build_util {
    /**
     * High level function to build the PyObject for the DOOCS names call.
     *
     * @param doocs_address The DOOCS address to perform I/O for.
     *
     * @return The pointer to an PyObject object containing the data to be queried.
     */
    PyObject* names(const char* doocs_address);

    /**
     * High level function to build the PyObject for the DOOCS read call.
     *
     * @param doocs_address The DOOCS address to perform I/O for.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     * @param macropulse_number Optional macropulse number for synchronized readout.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    PyObject* read(const char* doocs_address, PyObject* doocs_parameters, PyObject* macropulse_number);

    /**
     * High level function to build the PyObject for the DOOCS write call.
     *
     * @param doocs_address The DOOCS address to perform I/O for.1
     * @param data_from_python Data from python to be send to DOOCS.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     *
     * @return The pointer to an PyObject object while writing data from within python to DOOCS.
     */
    PyObject* write(const char* doocs_address, PyObject* data_from_python, PyObject* doocs_parameters);
}  // namespace build_util

#endif  // INCLUDE_BUILD_UTIL_H_
