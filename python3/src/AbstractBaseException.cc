#include "AbstractBaseException.h"


void AbstractBaseException::initialize_with(const std::string& module_name) {
    const auto exception_class_name = module_name + "." + get_name();
    // Set a python internal custom exception in accordance with the Python/C API.
    set_exception_object(PyErr_NewExceptionWithDoc(exception_class_name.c_str(), get_doc(), nullptr, nullptr));
}
