#ifndef INCLUDE_DOUBLEARRAYBUILDER_H_
#define INCLUDE_DOUBLEARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS double array data (DATA_A_DOUBLE).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class DoubleArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the double array.
     */
    PyObject* double_array_from(EqData* data_from_doocs) const;
};

#endif  // INCLUDE_DOUBLEARRAYBUILDER_H_
