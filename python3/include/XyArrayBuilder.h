#ifndef PYTHON3_INCLUDE_XYARRAYBUILDER_H_
#define PYTHON3_INCLUDE_XYARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS xy array data (DATA_A_XY).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class XyArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the xy array.
     */
    PyObject* xy_array_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON3_INCLUDE_XYARRAYBUILDER_H_
