#ifndef PYTHON2_INCLUDE_DOOCSEXCEPTION_H_
#define PYTHON2_INCLUDE_DOOCSEXCEPTION_H_

#include "AbstractBaseException.h"

#include <eq_client.h>


/**
 * Concrete class for the custom exception 'DoocsException'.
 *
 * @see AbstractBaseException
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class DoocsException : public AbstractBaseException {
public:
    /**
     * Constant name for the 'DoocsException' exception used in pydoocs.
     */
    static const char* NAME;

    /**
     * Constant exception object for 'DoocsException' attached to the pydoocs module.
     */
    static PyObject* OBJECT;

protected:
    const char* get_name() const override {return NAME;}

    void set_exception_object(PyObject* object) override {OBJECT = object;}

    const char* get_doc() const override {return DOC;}

private:
    /*
     * The constant doc string for the 'DoocsException' exception used in pydoocs.
     */
    static const char* DOC;


/* DoocsException specific members below */
public:
    /**
     * Method to return the custom exception of type 'DoocsException'.
     *
     * @param data_from_doocs The EqData object that encapsulates the DOOCS error code and message.
     *
     * @return The custom exception 'DoocsException'.
     */
    static DoocsException from(const EqData& data_from_doocs);

private:
    /*
     * The constant code key for the exception python dictionary.
     */
    static const char* EXCEPTION_CODE_KEY;

    /*
     * The constant message key for the exception python dictionary.
     */
    static const char* EXCEPTION_MESSAGE_KEY;
};

#endif  // PYTHON2_INCLUDE_DOOCSEXCEPTION_H_
