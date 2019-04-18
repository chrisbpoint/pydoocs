#include "StringBuilder.h"

#include <array>


PyObject* StringBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        std::array<char, STRING_LENGTH> string_data{};
        data_from_doocs->get_string(string_data.data(), string_data.size());

        return build_read('s', data_from_doocs, string_data.data());
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* StringBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                               PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyString_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        PyObject* built_for_return = build_write(address, data_to_doocs, data_from_doocs,
                                                 PyString_AsString(data_from_python));

        if (data_from_doocs->type() != DATA_NULL) {
            return nullptr;  // as sentinel for write calls that return data (RPC call)
        }

        return built_for_return;
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
