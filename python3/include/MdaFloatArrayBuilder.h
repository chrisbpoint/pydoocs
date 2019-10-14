#ifndef PYTHON3_INCLUDE_MDAFLOATARRAYBUILDER_H_
#define PYTHON3_INCLUDE_MDAFLOATARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS mda float array data (DATA_MDA_FLOAT).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class MdaFloatArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Supported dimensionality constant.
     */
    static const int SUPPORTED_DIMENSIONALITY;

    /*
     * Helper method to retrieve the mda float array.
     */
    PyObject* mda_float_array_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON3_INCLUDE_MDAFLOATARRAYBUILDER_H_
