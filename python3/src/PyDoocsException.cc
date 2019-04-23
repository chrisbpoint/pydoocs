#include "PyDoocsException.h"


const char* PyDoocsException::NAME = "PyDoocsException";

const char* PyDoocsException::DOC = "Custom pydoocs exception with specific message.";

const char* PyDoocsException::TYPE_NOT_SUPPORTED_YET = "data type not supported yet";
const char* PyDoocsException::WRONG_INPUT_DATA_FORMAT = "wrong input data format";
const char* PyDoocsException::FUNCTIONALITY_NOT_SUPPORTED_YET = "functionality not supported yet";
const char* PyDoocsException::INPUT_LIST_TOO_LARGE = "input list too large";
const char* PyDoocsException::INPUT_LIST_SIZE_MISMATCH = "input list size mismatch";
const char* PyDoocsException::SPECTRUM_TYPE_NOT_SUPPORTED_YET = "spectrum type not supported yet";
const char* PyDoocsException::UNEXPECTED_BEHAVIOUR = "unexpected behaviour occurred";
const char* PyDoocsException::IMAGE_HEADER_INVALID = "image header invalid";
const char* PyDoocsException::IMAGE_DATA_INVALID = "image data invalid";
const char* PyDoocsException::ARRAY_SIZE_INVALID = "array size invalid";
const char* PyDoocsException::MACROPULSE_MISMATCH = "macropulse mismatch";
const char* PyDoocsException::SYNCHRONIZATION_NOT_SUPPORTED_YET = "synchronization not supported yet";
const char* PyDoocsException::INVALID_MACROPULSE = "invalid macropulse";
const char* PyDoocsException::WRONG_MACROPULSE_FORMAT = "wrong macropulse format";
const char* PyDoocsException::WRONG_PARAMETER_FORMAT = "wrong doocs parameter format";
const char* PyDoocsException::NO_HISTORY_AVAILABLE = "no history available";


PyDoocsException PyDoocsException::type_not_supported_yet() {
    return exception_of_type(TYPE_NOT_SUPPORTED_YET);
}

PyDoocsException PyDoocsException::wrong_input_data_format() {
    return exception_of_type(WRONG_INPUT_DATA_FORMAT);
}

PyDoocsException PyDoocsException::functionality_not_supported_yet() {
    return exception_of_type(FUNCTIONALITY_NOT_SUPPORTED_YET);
}

PyDoocsException PyDoocsException::input_list_too_large() {
    return exception_of_type(INPUT_LIST_TOO_LARGE);
}

PyDoocsException PyDoocsException::input_list_size_mismatch() {
    return exception_of_type(INPUT_LIST_SIZE_MISMATCH);
}

PyDoocsException PyDoocsException::spectrum_type_not_supported_yet() {
    return exception_of_type(SPECTRUM_TYPE_NOT_SUPPORTED_YET);
}

PyDoocsException PyDoocsException::unexpected_behaviour() {
    return exception_of_type(UNEXPECTED_BEHAVIOUR);
}

PyDoocsException PyDoocsException::image_header_invalid() {
    return exception_of_type(IMAGE_HEADER_INVALID);
}

PyDoocsException PyDoocsException::image_data_invalid() {
    return exception_of_type(IMAGE_DATA_INVALID);
}

PyDoocsException PyDoocsException::array_size_invalid() {
    return exception_of_type(ARRAY_SIZE_INVALID);
}

PyDoocsException PyDoocsException::macropulse_mismatch(std::int64_t macropulse_difference) {
    std::string macropulse_mismatch = MACROPULSE_MISMATCH;

    macropulse_mismatch += ": (requested - actual) is ";
    macropulse_mismatch += std::to_string(macropulse_difference);

    return exception_of_type(macropulse_mismatch.c_str());
}

PyDoocsException PyDoocsException::synchronization_not_supported_yet() {
    return exception_of_type(SYNCHRONIZATION_NOT_SUPPORTED_YET);
}

PyDoocsException PyDoocsException::invalid_macropulse() {
    return exception_of_type(INVALID_MACROPULSE);
}

PyDoocsException PyDoocsException::wrong_macropulse_format() {
    return exception_of_type(WRONG_MACROPULSE_FORMAT);
}

PyDoocsException PyDoocsException::wrong_parameter_format() {
    return exception_of_type(WRONG_PARAMETER_FORMAT);
}

PyDoocsException PyDoocsException::no_history_available() {
    return exception_of_type(NO_HISTORY_AVAILABLE);
}

PyDoocsException PyDoocsException::exception_of_type(const char* error_message) {
    // Set the python internal error state needed for raising exceptions in accordance with the Python/C API.
    PyErr_SetObject(OBJECT, Py_BuildValue("s", error_message));
    return PyDoocsException();
}
