#ifndef INCLUDE_XYZSARRAYBUILDER_H_
#define INCLUDE_XYZSARRAYBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS xyzs array data (DATA_A_XYZS).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class XyzsArrayBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the xyzs array.
     */
    PyObject* xyzs_array_from(EqData* data_from_doocs) const;
};

#endif  // INCLUDE_XYZSARRAYBUILDER_H_
