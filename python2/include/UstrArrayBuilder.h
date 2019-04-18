#ifndef INCLUDE_USTRARRAYBUILDER_H_
#define INCLUDE_USTRARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS ustr array data (DATA_A_USTR).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class UstrArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the ustr array.
     */
    PyObject* ustr_array_from(EqData* data_from_doocs) const;
};

#endif  // INCLUDE_USTRARRAYBUILDER_H_
