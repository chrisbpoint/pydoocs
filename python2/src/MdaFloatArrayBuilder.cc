#include "MdaFloatArrayBuilder.h"


const int MdaFloatArrayBuilder::SUPPORTED_DIMENSIONALITY = 2;

PyObject* MdaFloatArrayBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return mda_float_array_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* MdaFloatArrayBuilder::mda_float_array_from(EqData* data_from_doocs) const {
    MDA_FLOAT* mda_float = data_from_doocs->get_mda();

    if (mda_float->dimn != SUPPORTED_DIMENSIONALITY) {
        throw PyDoocsException::dimensionality_not_supported_yet();
    }

    std::vector<std::vector<float>> array_data;
    for (int row = 0; row < mda_float->dims[0]; ++row) {
        std::vector<float> row_data;
        for (int column = 0; column < mda_float->dims[1]; ++column) {
            int index[SUPPORTED_DIMENSIONALITY] {row, column};
            float data;
            data_from_doocs->get(index, mda_float->dimn, &data);
            row_data.push_back(data);
        }
        array_data.push_back(row_data);
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_FLOAT);
    PyObject* miscellaneous = Py_BuildValue("{ss}", "comment", mda_float->comment.comment_val);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array, miscellaneous);
    Py_DECREF(numpy_array);
    Py_DECREF(miscellaneous);

    return built_for_return;
}

PyObject* MdaFloatArrayBuilder::write(EqAdr* , EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
