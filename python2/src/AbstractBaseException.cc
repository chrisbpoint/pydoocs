#include "AbstractBaseException.h"


void AbstractBaseException::initialize_with(const std::string& module_name) {
    const auto exception_class_name = module_name + "." + get_name();
    // Set a python internal custom exception in accordance with the Python/C API.
    set_exception_object(PyErr_NewExceptionWithDoc(const_cast<char*>(exception_class_name.c_str()), const_cast<char*>(get_doc()), nullptr, nullptr));
}
