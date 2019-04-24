#ifndef PYTHON3_INCLUDE_IIIIBUILDER_H_
#define PYTHON3_INCLUDE_IIIIBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS iiii data (DATA_IIII).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class IiiiBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Input list size constant.
     */
    static const int IIII_INPUT_SIZE;
};

#endif  // PYTHON3_INCLUDE_IIIIBUILDER_H_
