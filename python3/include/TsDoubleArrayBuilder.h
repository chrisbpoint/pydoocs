#ifndef PYTHON3_INCLUDE_TSDOUBLEARRAYBUILDER_H_
#define PYTHON3_INCLUDE_TSDOUBLEARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS ts double array data (DATA_A_TS_DOUBLE).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class TsDoubleArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the ts double array.
     */
    PyObject* ts_double_array_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON3_INCLUDE_TSDOUBLEARRAYBUILDER_H_
