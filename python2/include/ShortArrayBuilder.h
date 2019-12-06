#ifndef INCLUDE_SHORTARRAYBUILDER_H_
#define INCLUDE_SHORTARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS integer array data (DATA_A_SHORT).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date December, 2019
 */
class ShortArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the short array.
     */
    PyObject* short_array_from(EqData* data_from_doocs) const;
};

#endif  // INCLUDE_SHORTARRAYBUILDER_H_
