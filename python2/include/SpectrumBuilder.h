#ifndef PYTHON2_INCLUDE_SPECTRUMBUILDER_H_
#define PYTHON2_INCLUDE_SPECTRUMBUILDER_H_

#include "AbstractBaseBuilder.h"


/**
 * Concrete class for building PyObject objects for DOOCS spectrum data (DATA_SPECTRUM).
 *
 * @see AbstractBaseBuilder
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class SpectrumBuilder : public AbstractBaseBuilder {
public:
    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                   PyObject* doocs_parameters) const override;

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                    PyObject* data_from_python, PyObject* doocs_parameters) const override;

private:
    /*
     * Helper method to retrieve the spectrum.
     */
    PyObject* spectrum_from(EqData* data_from_doocs) const;
};

#endif  // PYTHON2_INCLUDE_SPECTRUMBUILDER_H_
