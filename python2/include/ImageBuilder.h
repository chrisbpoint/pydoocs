#ifndef PYTHON2_INCLUDE_IMAGEBUILDER_H_
#define PYTHON2_INCLUDE_IMAGEBUILDER_H_

#include "AbstractBaseBuilder.h"

#include <vector>


/**
 * Concrete class for building PyObject objects for DOOCS image data (DATA_IMAGE).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class ImageBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the image.
     */
    PyObject* image_from(EqData* data_from_doocs) const;

    /*
     * Helper predicate to check for valid image data.
     */
    bool image_data_is_valid(const IMH& image_header) const;

    /*
     * Helper method to build the image as a 2d numpy array.
     */
    PyObject* build_image_array(const IMH& image_header, const u_char* image_values) const;

    /*
     * Helper method to build the 2d numpy array.
     */
    template<typename T>
    std::vector<std::vector<T>> build_array_data(const IMH& image_header, const u_char* image_values) const;
};

#endif  // PYTHON2_INCLUDE_IMAGEBUILDER_H_
