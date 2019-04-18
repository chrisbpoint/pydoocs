#ifndef INCLUDE_PYDOOCSEXCEPTION_H_
#define INCLUDE_PYDOOCSEXCEPTION_H_

#include "AbstractBaseException.h"


/**
 * Concrete class for the custom exception 'PyDoocsException'.
 *
 * @see AbstractBaseException
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class PyDoocsException : public AbstractBaseException {
public:
    /**
     * Constant name for the 'PyDoocsException' exception used in pydoocs.
     */
    static const char* NAME;

    /**
     * Constant exception object for 'PyDoocsException' attached to the pydoocs module.
     */
    static PyObject* OBJECT;

protected:
    const char* get_name() const override {return NAME;}

    void set_exception_object(PyObject* object) override {OBJECT = object;}

    const char* get_doc() const override {return DOC;}

private:
    /*
     * The constant doc string for the 'PyDoocsException' exception used in pydoocs.
     */
    static const char* DOC;


/* PyDoocsException specific members below */
public:
    /**
     * Method to return the custom exception 'PyDoocsException' for type not supported yet.
     *
     * @return The custom exception 'PyDoocsException' for type not supported yet.
     */
    static PyDoocsException type_not_supported_yet();

    /**
     * Method to return the custom exception 'PyDoocsException' for wrong input data format.
     *
     * @return The custom exception 'PyDoocsException' for wrong input data format.
     */
    static PyDoocsException wrong_input_data_format();

    /**
     * Method to return the custom exception 'PyDoocsException' for functionality not supported yet.
     *
     * @return The custom exception 'PyDoocsException' for functionality not supported yet.
     */
    static PyDoocsException functionality_not_supported_yet();

    /**
     * Method to return the custom exception 'PyDoocsException' for input list too large.
     *
     * @return The custom exception 'PyDoocsException' for input list too large.
     */
    static PyDoocsException input_list_too_large();

    /**
     * Method to return the custom exception 'PyDoocsException' for input list size mismatch.
     *
     * @return The custom exception 'PyDoocsException' for input list size mismatch.
     */
    static PyDoocsException input_list_size_mismatch();

    /**
     * Method to return the custom exception 'PyDoocsException' for spectrum type not supported yet.
     *
     * @return The custom exception 'PyDoocsException' for spectrum type not supported yet.
     */
    static PyDoocsException spectrum_type_not_supported_yet();

    /**
     * Method to return the custom exception 'PyDoocsException' for unexpected behaviour.
     *
     * @return The custom exception 'PyDoocsException' for unexpected behaviour.
     */
    static PyDoocsException unexpected_behaviour();

    /**
     * Method to return the custom exception 'PyDoocsException' for image header invalid.
     *
     * @return The custom exception 'PyDoocsException' for image header invalid.
     */
    static PyDoocsException image_header_invalid();

    /**
     * Method to return the custom exception 'PyDoocsException' for image data invalid.
     *
     * @return The custom exception 'PyDoocsException' for image data invalid.
     */
    static PyDoocsException image_data_invalid();

    /**
     * Method to return the custom exception 'PyDoocsException' for array size invalid.
     *
     * @return The custom exception 'PyDoocsException' for array size invalid.
     */
    static PyDoocsException array_size_invalid();

    /**
     * Method to return the custom exception 'PyDoocsException' for macropulse mismatch.
     *
     * @param macropulse_difference The difference between the requested and actual macropulse.
     *
     * @return The custom exception 'PyDoocsException' for macropulse mismatch.
     */
    static PyDoocsException macropulse_mismatch(std::int64_t macropulse_difference);

    /**
     * Method to return the custom exception 'PyDoocsException' for synchronization not supported yet.
     *
     * @return The custom exception 'PyDoocsException' for synchronization not supported yet.
     */
    static PyDoocsException synchronization_not_supported_yet();

    /**
     * Method to return the custom exception 'PyDoocsException' for invalid macropulse.
     *
     * @return The custom exception 'PyDoocsException' for invalid macropulse.
     */
    static PyDoocsException invalid_macropulse();

    /**
     * Method to return the custom exception 'PyDoocsException' for wrong macropulse format.
     *
     * @return The custom exception 'PyDoocsException' for wrong macropulse format.
     */
    static PyDoocsException wrong_macropulse_format();
  
   /**
     * Method to return the custom exception 'PyDoocsException' for wrong parameter format.
     *
     * @return The custom exception 'PyDoocsException' for wrong parameter format.
     */
    static PyDoocsException wrong_parameter_format();

private:
    /*
     * Helper method to return the custom exception of type 'PyDoocsException'.
     */
    static PyDoocsException exception_of_type(const char* error_message);

    /*
     * The string constants for the specific 'PyDoocsException' exception messages.
     */
    static const char* TYPE_NOT_SUPPORTED_YET;
    static const char* WRONG_INPUT_DATA_FORMAT;
    static const char* FUNCTIONALITY_NOT_SUPPORTED_YET;
    static const char* INPUT_LIST_TOO_LARGE;
    static const char* INPUT_LIST_SIZE_MISMATCH;
    static const char* SPECTRUM_TYPE_NOT_SUPPORTED_YET;
    static const char* UNEXPECTED_BEHAVIOUR;
    static const char* IMAGE_HEADER_INVALID;
    static const char* IMAGE_DATA_INVALID;
    static const char* ARRAY_SIZE_INVALID;
    static const char* MACROPULSE_MISMATCH;
    static const char* SYNCHRONIZATION_NOT_SUPPORTED_YET;
    static const char* INVALID_MACROPULSE;
    static const char* WRONG_MACROPULSE_FORMAT;
    static const char* WRONG_PARAMETER_FORMAT;
};

#endif  // INCLUDE_PYDOOCSEXCEPTION_H_
