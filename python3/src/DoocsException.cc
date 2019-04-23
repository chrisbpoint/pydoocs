#include "DoocsException.h"

#include <array>


const char* DoocsException::NAME = "DoocsException";

const char* DoocsException::DOC = "Custom DOOCS exception with dict_keys(['code', 'message']) in its first argument.";

const char* DoocsException::EXCEPTION_CODE_KEY = "code";
const char* DoocsException::EXCEPTION_MESSAGE_KEY = "message";

DoocsException DoocsException::from(const EqData& data_from_doocs) {
    std::array<char, STRING_LENGTH> doocs_error_message{};
    data_from_doocs.get_string(doocs_error_message.data(), doocs_error_message.size());

    // Set the python internal error state needed for raising exceptions in accordance with the Python/C API.
    PyErr_SetObject(OBJECT, Py_BuildValue("{siss}",
                                          EXCEPTION_CODE_KEY, data_from_doocs.error(),
                                          EXCEPTION_MESSAGE_KEY, doocs_error_message.data()));

    return DoocsException();
}
