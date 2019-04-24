/**
 * Python3 bindings to the standard DOOCS get call written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 *
 * @file pydoocs_read.h
 */
#ifndef PYTHON3_INCLUDE_PYDOOCS_READ_H_
#define PYTHON3_INCLUDE_PYDOOCS_READ_H_

#include <Python.h>


/**
 * The actual name of the pydoocs read function to be called.
 */
extern const char* PYDOOCS_READ_NAME;

/**
 * The doc string for the pydoocs read function displayed with help(pydoocs.read) or pydoocs.read.__doc__.
 */
extern const char* PYDOOCS_READ_DOC;

/**
 * Function to return the pointer to an PyObject object containing the data to be read in
 * accordance with the Python/C API.
 *
 * @param _unused_ignored Ignored but needed for the Python/C API.
 * @param args The standard arguments to be used with the read function.
 * @param kwargs Optional keyword arguments to be used with the read function.
 *
 * @return The pointer to an PyObject object containing the data to be read.
 */
PyObject* pydoocs_read_function(PyObject* Py_UNUSED(ignored), PyObject* args, PyObject* kwargs);

#endif  // PYTHON3_INCLUDE_PYDOOCS_READ_H_
