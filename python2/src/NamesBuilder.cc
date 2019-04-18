#include "NamesBuilder.h"

#include <array>


PyObject* NamesBuilder::names(EqData* data_from_doocs) const {
    PyObject* data_to_python = PyList_New(data_from_doocs->length());

    std::array<char, STRING_LENGTH> buffer{};
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_string_arg(i, buffer.data(), buffer.size());
        PyList_SetItem(data_to_python, i, Py_BuildValue("s", buffer.data()));
    }

    return data_to_python;
}
