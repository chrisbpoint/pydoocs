#include "pydoocs_read.h"
#include "parse_util.h"
#include "build_util.h"


const char* PYDOOCS_READ_NAME = "read";
const char* PYDOOCS_READ_DOC = "Function to read data from a given DOOCS address.";

PyObject* pydoocs_read_function(PyObject* Py_UNUSED(ignored), PyObject* args, PyObject* kwargs) {
    const char* doocs_address = nullptr;  // address to be read from
    PyObject* doocs_parameters = nullptr;  // optional parameters for the DOOCS calls
    PyObject* macropulse_number = nullptr;  // optional macropulse for synchronized readout

    try {
        parse_util::parse_read_arguments(args, kwargs, &doocs_address, &doocs_parameters, &macropulse_number);
        return build_util::read(doocs_address, doocs_parameters, macropulse_number);
    } catch (...) {
        // Catching simply any exception is fine as the internal python exception is set already. The catch block is
        // simply needed as guard in order to return a null pointer in case of an exception.
        return nullptr;
    }
}
