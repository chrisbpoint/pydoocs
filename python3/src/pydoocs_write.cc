#include "pydoocs_write.h"
#include "parse_util.h"
#include "build_util.h"


const char* PYDOOCS_WRITE_NAME = "write";
const char* PYDOOCS_WRITE_DOC = "Function to write data to a given DOOCS address.";

PyObject* pydoocs_write_function(PyObject* Py_UNUSED(ignored), PyObject* args, PyObject* kwargs) {
    const char* doocs_address = nullptr;  // address to write to
    PyObject* data_from_python = nullptr;  // data to be written
    PyObject* doocs_parameters = nullptr;  // optional parameters for the DOOCS calls

    try {
        parse_util::parse_write_arguments(args, kwargs, &doocs_address, &data_from_python, &doocs_parameters);
        return build_util::write(doocs_address, data_from_python, doocs_parameters);
    } catch (...) {
        // Catching simply any exception is fine as the internal python exception is set already. The catch block is
        // simply needed as guard in order to return a null pointer in case of an exception.
        return nullptr;
    }
}
