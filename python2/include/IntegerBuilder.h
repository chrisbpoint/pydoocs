#ifndef INCLUDE_INTEGERBUILDER_H_
#define INCLUDE_INTEGERBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS integer data (DATA_INT).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class IntegerBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;
};

#endif  // INCLUDE_INTEGERBUILDER_H_
