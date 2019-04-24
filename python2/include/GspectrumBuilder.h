#ifndef PYTHON2_INCLUDE_GSPECTRUMBUILDER_H_
#define PYTHON2_INCLUDE_GSPECTRUMBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS gspectrum data (DATA_GSPECTRUM).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class GspectrumBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the gspectrum.
     */
    PyObject* gspectrum_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON2_INCLUDE_GSPECTRUMBUILDER_H_
