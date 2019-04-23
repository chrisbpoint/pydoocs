#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_ARRAY_UNIQUE_SYMBOL pydoocs_ARRAY_API
#include <numpy/arrayobject.h>

#include "pydoocs.h"
#include "pydoocs_names.h"
#include "pydoocs_read.h"
#include "pydoocs_write.h"


const char* PYDOOCS_NAME = "pydoocs";
const char* PYDOOCS_DOC = "Python bindings to the standard DOOCS client API written in C/C++.";
const char* PYDOOCS_VERSION_ATTRIBUTE = "__version__";
const char* PYDOOCS_VERSION_NUMBER = "2.0.4";

/*
 * Add functions (names, read, and write) to the pydoocs module in accordance with the Python/C API.
 */
static PyMethodDef pydoocs_functions[] = {
        {PYDOOCS_NAMES_NAME, pydoocs_names_function, METH_VARARGS, PYDOOCS_NAMES_DOC},
        {PYDOOCS_READ_NAME, (PyCFunction) pydoocs_read_function, METH_VARARGS | METH_KEYWORDS, PYDOOCS_READ_DOC},
        {PYDOOCS_WRITE_NAME, (PyCFunction) pydoocs_write_function, METH_VARARGS | METH_KEYWORDS, PYDOOCS_WRITE_DOC},
        {nullptr, nullptr, 0, nullptr}  // a sentinel required by the Python/C API
};

/*
 * Initialize the pydoocs module in accordance with the Python/C API.
 */
PyMODINIT_FUNC
initpydoocs(void)
{
    import_array();  // needed in order to be able to return numpy arrays

    PyObject* pydoocs_module = Py_InitModule3(PYDOOCS_NAME, pydoocs_functions, PYDOOCS_DOC);

    // add custom PyDoocsException
    PyDoocsException().initialize_with(PYDOOCS_NAME);
    PyModule_AddObject(pydoocs_module, PyDoocsException::NAME, PyDoocsException::OBJECT);

    // add custom DoocsException
    DoocsException().initialize_with(PYDOOCS_NAME);
    PyModule_AddObject(pydoocs_module, DoocsException::NAME, DoocsException::OBJECT);

    // add version number
    PyModule_AddStringConstant(pydoocs_module, PYDOOCS_VERSION_ATTRIBUTE, PYDOOCS_VERSION_NUMBER);
}
