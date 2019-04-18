#include "GspectrumBuilder.h"


PyObject* GspectrumBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return gspectrum_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* GspectrumBuilder::gspectrum_from(EqData* data_from_doocs) const {
    // for the data key of the output map
    float* spectrum_data;
    float spectrum_start, spectrum_increment;

    // for the miscellaneous key of the output map
    char* comment;
    int comment_length;
    time_t time_stamp;
    u_int status;
    int spectrum_length;

    int spectrum_type = data_from_doocs->get_spectrum(&comment, &comment_length, &time_stamp, &spectrum_start,
                                                      &spectrum_increment, &status, &spectrum_data, &spectrum_length);

    if (!(spectrum_type == 1 || spectrum_type == 2)) {
        throw PyDoocsException::spectrum_type_not_supported_yet();
    }

    std::vector<std::vector<float>> array_data;
    for (int i = 0; i < spectrum_length; ++i) {
        array_data.push_back(std::vector<float>{spectrum_start + i * spectrum_increment, spectrum_data[i]});
    }

    PyObject* numpy_array = build_numpy_array(array_data, NPY_FLOAT);
    PyObject* miscellaneous = Py_BuildValue("{sssisi}", "comment", comment, "timestamp", time_stamp, "status", status);

    PyObject* built_for_return = build_read('O', data_from_doocs, numpy_array, miscellaneous);
    Py_DECREF(numpy_array);
    Py_DECREF(miscellaneous);

    return built_for_return;
}

PyObject* GspectrumBuilder::write(EqAdr* , EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
