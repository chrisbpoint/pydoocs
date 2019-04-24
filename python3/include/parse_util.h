#ifndef PYTHON3_INCLUDE_PARSE_UTIL_H_
#define PYTHON3_INCLUDE_PARSE_UTIL_H_

#include <Python.h>


/**
 * Parsing utility for the Python3 bindings to the standard DOOCS client API written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
namespace parse_util {
    /**
     * Parsing function to provide a DOOCS address, e.g., for the DOOCS names call.
     *
     * @param args Pydoocs functions parameter to bind to doocs_address.
     * @param doocs_address The DOOCS address to perform I/O for.
     */
    void parse_names_arguments(PyObject* args, const char** doocs_address);

    /**
     * Parsing function to provide a DOOCS address and optional parameters, e.g., for the DOOCS read call.
     *
     * @param args Pydoocs functions parameter to bind to doocs_address.
     * @param kwargs Optional keyword parameter to bind to  doocs_parameters
     * @param doocs_address The DOOCS address to perform I/O for.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     * @param macropulse_number Optional macropulse number for synchronized readout.
     */
    void parse_read_arguments(PyObject* args, PyObject* kwargs, const char** doocs_address,
                              PyObject** doocs_parameters, PyObject** macropulse_number);

    /**
     * Parsing function to provide a DOOCS address, optional parameters, and data, e.g., for the DOOCS write call.
     *
     * @param args Pydoocs functions parameter to bind to doocs_address.
     * @param kwargs Optional keyword parameters to provide parameters for DOOCS.
     * @param doocs_address The DOOCS address to perform I/O for.
     * @param data_from_python Data from python to be send to DOOCS.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     */
    void parse_write_arguments(PyObject* args, PyObject* kwargs, const char** doocs_address,
                               PyObject** data_from_python, PyObject** doocs_parameters);

    /**
     * The string constant for the address keyword parameter.
     */
    extern const char* ADDRESS_KEYWORD;

    /**
     * The string constant for the optional parameters keyword parameter.
     */
    extern const char* PARAMETERS_KEYWORD;

    /**
     * The string constant for the optional macropulse keyword parameter.
     */
    extern const char* MACROPULSE_KEYWORD;

    /**
     * The string constant for the data keyword parameter.
     */
    extern const char* DATA_KEYWORD;
}  // namespace parse_util

#endif  // PYTHON3_INCLUDE_PARSE_UTIL_H_
