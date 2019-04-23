#include "XyArrayBuilder.h"


PyObject* XyArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return xy_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* XyArrayBuilder::xy_array_from(EqData* data_from_doocs) const {
    float x, y;

    std::vector<std::vector<float>> array_data;
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_xy(&x, &y, i);
        array_data.push_back(std::vector<float>{x, y});
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_FLOAT);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array);
    Py_DECREF(numpy_array);

    return built_for_return;
}

PyObject* XyArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
