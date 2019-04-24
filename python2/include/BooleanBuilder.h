#ifndef PYTHON2_INCLUDE_BOOLEANBUILDER_H_
#define PYTHON2_INCLUDE_BOOLEANBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS boolean data (DATA_BOOL).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class BooleanBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;
};

#endif  // PYTHON2_INCLUDE_BOOLEANBUILDER_H_
