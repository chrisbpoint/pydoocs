/**
 * Python3 bindings to the standard DOOCS set call written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 *
 * @file pydoocs_write.h
 */
#ifndef PYTHON2_INCLUDE_PYDOOCS_WRITE_H_
#define PYTHON2_INCLUDE_PYDOOCS_WRITE_H_

#include <Python.h>


/**
 * The actual name of the pydoocs write function to be called.
 */
extern const char* PYDOOCS_WRITE_NAME;

/**
 * The doc string for the pydoocs write function displayed with help(pydoocs.write) or pydoocs.write.__doc__.
 */
extern const char* PYDOOCS_WRITE_DOC;

/**
 * Function to return the pointer to an PyObject object in accordance with the Python/C API while writing data
 * from within python to DOOCS.
 *
 * @param _unused_ignored Ignored but needed for the Python/C API.
 * @param args The standard arguments to be used with the write function.
 * @param kwargs Optional keyword arguments to be used with the write function.
 *
 * @return The pointer to an PyObject object while writing data from within python to DOOCS.
 */
PyObject* pydoocs_write_function(PyObject*, PyObject* args, PyObject* kwargs);

#endif  // PYTHON2_INCLUDE_PYDOOCS_WRITE_H_
