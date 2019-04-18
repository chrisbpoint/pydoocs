#include "parse_util.h"

#include <stdexcept>


namespace parse_util {
    const char* ADDRESS_KEYWORD = "address";
    const char* PARAMETERS_KEYWORD = "parameters";
    const char* MACROPULSE_KEYWORD = "macropulse";
    const char* DATA_KEYWORD = "data";

    void parse_names_arguments(PyObject* args, const char** doocs_address) {
        if (!PyArg_ParseTuple(args, "s", doocs_address)) {
            throw std::exception();  // to trigger proper exception handling in the caller (names)
        }
    }

    void parse_read_arguments(PyObject* args, PyObject* kwargs, const char** doocs_address,
                              PyObject** doocs_parameters, PyObject** macropulse_number) {
        static const char* kwargs_list[] = {ADDRESS_KEYWORD, PARAMETERS_KEYWORD, MACROPULSE_KEYWORD, nullptr};

        if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|OO", const_cast<char **>(kwargs_list),
                                         doocs_address, doocs_parameters, macropulse_number)) {
            throw std::exception();  // to trigger proper exception handling in the caller (read)
        }
    }

    void parse_write_arguments(PyObject* args, PyObject* kwargs, const char** doocs_address,
                               PyObject** data_from_python, PyObject** doocs_parameters) {
        static const char* kwargs_list[] = {ADDRESS_KEYWORD, DATA_KEYWORD, PARAMETERS_KEYWORD, nullptr};

        if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sO|O", const_cast<char**>(kwargs_list),
                                         doocs_address, data_from_python, doocs_parameters)) {
            throw std::exception();  // to trigger proper exception handling in the caller (write)
        }
    }
}  // namespace parse_util
