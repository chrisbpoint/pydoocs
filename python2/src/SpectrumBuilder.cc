#include "SpectrumBuilder.h"


PyObject* SpectrumBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    return spectrum_from(data_from_doocs);
}

PyObject* SpectrumBuilder::spectrum_from(EqData* data_from_doocs) const {
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

PyObject* SpectrumBuilder::write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                                 PyObject* data_from_python, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        if (!PyList_CheckExact(data_from_python)) {
            throw PyDoocsException::wrong_input_data_format();
        }

        SPECTRUM* spectrum = data_from_doocs->get_spectrum();

        if (PyList_Size(data_from_python) > static_cast<Py_ssize_t>(spectrum->d_spect_array.d_spect_array_len)) {
            throw PyDoocsException::input_list_too_large();
        }

        for (std::int64_t i = 0; i < PyList_Size(data_from_python); ++i) {
            spectrum->d_spect_array.d_spect_array_val[i] = PyFloat_AsDouble(PyList_GetItem(data_from_python, i));
        }

        return build_write(address, data_to_doocs, data_from_doocs, spectrum);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}
