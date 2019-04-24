#ifndef PYTHON2_INCLUDE_TSFLOATARRAYBUILDER_H_
#define PYTHON2_INCLUDE_TSFLOATARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS ts float array data (DATA_A_TS_FLOAT).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class TsFloatArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the ts float array.
     */
    PyObject* ts_float_array_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON2_INCLUDE_TSFLOATARRAYBUILDER_H_
