#ifndef PYTHON3_INCLUDE_NAMESBUILDER_H_
#define PYTHON3_INCLUDE_NAMESBUILDER_H_

#include <Python.h>

#include <eq_client.h>


/**
 * Class for building PyObject objects for the DOOCS names call.
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class NamesBuilder {
public:
    /**
     * DOOCS implementation level function to build the PyObject for the DOOCS names call.
     *
     * @param data_from_doocs The DOOCS EqData object to query the DOOCS data from.
     *
     * @return The pointer to an PyObject object containing the data to be queried.
     */
    PyObject* names(EqData* data_from_doocs) const;
};

#endif  // PYTHON3_INCLUDE_NAMESBUILDER_H_
