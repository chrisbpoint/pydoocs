#include "pydoocs_names.h"
#include "parse_util.h"
#include "build_util.h"


const char* PYDOOCS_NAMES_NAME = "names";
const char* PYDOOCS_NAMES_DOC = "Function to query names from a given DOOCS name domain.";

PyObject* pydoocs_names_function(PyObject*, PyObject* args) {
    const char* doocs_address = nullptr;  // address to query from

    try {
        parse_util::parse_names_arguments(args, &doocs_address);
        return build_util::names(doocs_address);
    } catch (...) {
        // Catching simply any exception is fine as the internal python exception is set already. The catch block is
        // simply needed as guard in order to return a null pointer in case of an exception.
        return nullptr;
    }
}
