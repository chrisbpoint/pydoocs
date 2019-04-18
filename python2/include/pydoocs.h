/**
 * Python3 bindings to the standard DOOCS client API written in C/C++.
 *
 * @author Christopher Behrens
 * @date March, 2018
 *
 * @file pydoocs.h
 */
#ifndef INCLUDE_PYDOOCS_H_
#define INCLUDE_PYDOOCS_H_

#include "PyDoocsException.h"
#include "DoocsException.h"


/**
 * The actual name of the pydoocs module used for the import.
 */
extern const char* PYDOOCS_NAME;

/**
 * The doc string for the pydoocs module displayed with help(pydoocs) or pydoocs.__doc__.
 */
extern const char* PYDOOCS_DOC;

/**
 * The version attribute name of the pydoocs module.
 */
extern const char* PYDOOCS_VERSION_ATTRIBUTE;

/**
 * The actual version number of the pydoocs module.
 */
extern const char* PYDOOCS_VERSION_NUMBER;

/**
 * The custom PyDoocsException object.
 */
PyObject* PyDoocsException::OBJECT;

/**
 * The custom DoocsException object.
 */
PyObject* DoocsException::OBJECT;

#endif  // INCLUDE_PYDOOCS_H_
