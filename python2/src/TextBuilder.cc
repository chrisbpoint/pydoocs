#include "TextBuilder.h"


PyObject* TextBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        auto text_length = static_cast<std::size_t>(data_from_doocs->array_length());

        auto text_data = static_cast<char*>(malloc((text_length+1) * sizeof(char)));

        data_from_doocs->get_string(text_data, text_length);
        PyObject* built_for_return = build_read('s', data_from_doocs, text_data);

        if (text_data) {
            free(text_data);
        }

        return built_for_return;
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* TextBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                             PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyString_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        return build_write(address, data_to_doocs, data_from_doocs,
                           PyString_AsString(data_from_python));
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
