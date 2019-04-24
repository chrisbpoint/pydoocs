/**
 * Python3 bindings to the standard DOOCS names call written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 *
 * @file pydoocs_names.h
 */
#ifndef PYTHON2_INCLUDE_PYDOOCS_NAMES_H_
#define PYTHON2_INCLUDE_PYDOOCS_NAMES_H_

#include <Python.h>


/**
 * The actual name of the pydoocs names function to be called.
 */
extern const char* PYDOOCS_NAMES_NAME;

/**
 * The doc string for the pydoocs names function displayed with help(pydoocs.names) or pydoocs.names.__doc__.
 */
extern const char* PYDOOCS_NAMES_DOC;

/**
 * Function to return the pointer to an PyObject object containing the data to be queried in
 * accordance with the Python/C API.
 *
 * @param _unused_ignored Ignored but needed for the Python/C API.
 * @param args The standard arguments to be used with the names function.
 *
 * @return The pointer to an PyObject object containing the data to be queried.
 */
PyObject* pydoocs_names_function(PyObject*, PyObject* args);

#endif  // PYTHON2_INCLUDE_PYDOOCS_NAMES_H_
