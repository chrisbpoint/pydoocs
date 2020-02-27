#include "ImageBuilder.h"


PyObject* ImageBuilder::read(EqAdr*, EqData*, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return image_from(data_from_doocs);
    } else {
        throw PyDoocsException::functionality_not_supported_yet();
    }
}

PyObject* ImageBuilder::image_from(EqData* data_from_doocs) const {
    IMH image_header{};
    u_char* image_values;
    int int_dummy;
    time_t time_t_dummy;
    int status;

    if (!data_from_doocs->get_image(&image_values, &int_dummy, &image_header)) {
        throw PyDoocsException::image_header_invalid();
    }

    if (!image_data_is_valid(image_header)) {
        throw PyDoocsException::image_data_invalid();
    }

    data_from_doocs->get_image_timestamp_and_status(&time_t_dummy, &time_t_dummy, &status);

    PyObject* image_array = build_image_array(image_header, image_values);

    PyObject* miscellaneous = Py_BuildValue("{sisisisisisisisisisisIsfsfsfsisisisisi}",
            "width", image_header.width, "height", image_header.height,
            "aoi_width",image_header.aoi_width, "aoi_height", image_header.aoi_height,
            "x_start", image_header.x_start , "y_start", image_header.y_start,
            "hbin", image_header.hbin , "vbin", image_header.vbin,
            "bpp", image_header.bpp, "ebitpp", image_header.ebitpp,
            "event", image_header.event,
            "fspare2", image_header.fspare2, "fspare3", image_header.fspare3, "fspare4", image_header.fspare4,
            "ispare2", image_header.ispare2, "ispare3", image_header.ispare3, "ispare4", image_header.ispare4,
            "length", image_header.length,
            "status", status);

    PyObject* built_for_return = build_read('O', data_from_doocs, image_array, miscellaneous);
    Py_DECREF(image_array);
    Py_DECREF(miscellaneous);

    return built_for_return;
}

bool ImageBuilder::image_data_is_valid(const IMH& image_header) const {
    if (image_header.image_format == -1) return false;
    if (image_header.aoi_width == 0 || image_header.aoi_height == 0) return false;
    if (image_header.length == 0) return false;
    if (!(image_header.bpp == 1 || image_header.bpp == 2)) return false;

    return true;
}

PyObject* ImageBuilder::build_image_array(const IMH& image_header, const u_char* image_values) const {
    switch(image_header.image_format) {
        case TTF2_IMAGE_FORMAT_GRAY:
            if (image_header.bpp == 1) {
                return build_numpy_array(build_array_data<std::uint8_t>(image_header, image_values), NPY_UINT8);
            }

            if (image_header.bpp == 2) {
                return build_numpy_array(build_array_data<std::uint16_t>(image_header, image_values), NPY_UINT16);
            }

            throw PyDoocsException::type_not_supported_yet();
        default:
            throw PyDoocsException::type_not_supported_yet();
    }
}

template<typename T>
std::vector<std::vector<T>> ImageBuilder::build_array_data(const IMH& image_header, const u_char* image_values) const {
    std::vector<std::vector<T>> array_data;
    for (int y = 0; y < image_header.aoi_height; ++y) {
        std::vector<T> row;
        for (int x = 0; x < image_header.aoi_width; ++x) {
            int pixel_index = y * image_header.aoi_width + x;
            row.push_back(*(reinterpret_cast<T*>(const_cast<u_char*>(image_values)) + pixel_index));
        }
        array_data.push_back(row);
    }
    return array_data;
}

PyObject* ImageBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
