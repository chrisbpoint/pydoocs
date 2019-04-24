#ifndef PYTHON2_INCLUDE_ABSTRACTBASEEXCEPTION_H_
#define PYTHON2_INCLUDE_ABSTRACTBASEEXCEPTION_H_

#include <Python.h>

#include <stdexcept>
#include <string>


/**
 * Abstract base class for the custom exceptions used in pydoocs.
 *
 * @see PyDoocsException
 * @see DoocsException
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class AbstractBaseException : public std::exception {
public:
    /**
     * Method to initialize the custom exception with the actual name of the module.
     *
     * @param module_name The actual name of the pydoocs module to attach the custom exception.
     */
    void initialize_with(const std::string& module_name);

protected:
    /**
     * Method to return the name of the custom exception used in pydoocs.
     *
     * @return The name of the custom exception used in pydoocs.
     */
    virtual const char* get_name() const = 0;

    /**
     * Method to set the custom exceptions object to attach to the pydoocs module.
     *
     * @param object The custom exceptions object to attach to the pydoocs module.
     */
    virtual void set_exception_object(PyObject* object) = 0;

    /**
     * Method to return the doc string of the custom exception used in pydoocs.
     *
     * @return The doc string of the custom exception used in pydoocs.
     */
    virtual const char* get_doc() const = 0;
};

#endif  // PYTHON2_INCLUDE_ABSTRACTBASEEXCEPTION_H_
