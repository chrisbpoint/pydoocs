#ifndef PYTHON3_INCLUDE_ABSTRACTBASEBUILDER_H_
#define PYTHON3_INCLUDE_ABSTRACTBASEBUILDER_H_

#include <Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_ARRAY_UNIQUE_SYMBOL pydoocs_ARRAY_API
#define NO_IMPORT_ARRAY
#include <numpy/arrayobject.h>

#include <eq_client.h>

#include <vector>

#include "PyDoocsException.h"
#include "DoocsException.h"


/**
 * Abstract base class for actual DOOCS data type builders.
 *
 * @author Christopher Behrens
 * @date March, 2018
 */
class AbstractBaseBuilder {
public:
    /**
     * The constant macropulse key for the output python dictionary.
     */
    static const char* MACROPULSE_KEY;

protected:
    /**
     * DOOCS implementation level function to build the PyObject for the DOOCS read call.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write additional DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to read the DOOCS data from.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    virtual PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                           PyObject* doocs_parameters) const = 0;
    /**
     * DOOCS implementation level to build the PyObject for the DOOCS write call.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write the DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to retrieve additional DOOCS data from.
     * @param data_from_python Data from python to be send to DOOCS.
     * @param doocs_parameters Optional parameters for the DOOCS call.
     *
     * @return The pointer to an PyObject object while writing data from within python to DOOCS.
     */
    virtual PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                            PyObject* data_from_python, PyObject* doocs_parameters) const = 0;

    /**
     * Template helper method to abstract the final building PyObject objects without, i.e. empty, miscellaneous data.
     *
     * @tparam T Template type of the actual data read from DOOCS and returned to python.
     *
     * @param type Type format of the data to be returned to python according to the Python/C API.
     * @param data_from_doocs The DOOCS EqData object to read the DOOCS data from.
     * @param data The actual data read from DOOCS and returned to python.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    template<typename T>
    PyObject* build_read(char type, EqData* data_from_doocs, T data) const;

    /**
     * Template helper method to abstract final building PyObject objects with, i.e. non-empty, miscellaneous data for
     * the DOOCS read call.
     *
     * @tparam T Template type of the actual data read from DOOCS and returned to python.
     *
     * @param type Type format of the data to be returned to python according to the Python/C API.
     * @param data_from_doocs The DOOCS EqData object to read the DOOCS data from.
     * @param data The actual data read from DOOCS and returned to python.
     * @param miscellaneous Python dict for miscellaneous to be returned to python.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    template<typename T>
    PyObject* build_read(char type, EqData* data_from_doocs, T data, const PyObject* miscellaneous) const;

    /**
     * Template helper method to abstract building of 1d numpy arrays.
     *
     * @tparam T1 Template type of the 1d array data read from DOOCS and returned to python.
     * @tparam T2 Template type of the data to be returned to python according to the NumPy C API.
     *
     * @param array_data The actual 1d array data read from DOOCS and returned to python.
     * @param type Type of the data to be returned to python according to the NumPy C API.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    template<typename T1, typename T2>
    PyObject* build_numpy_array(const std::vector<T1>& array_data, T2 type) const;

    /**
     * Template helper method to abstract building of 2d numpy arrays.
     *
     * @tparam T1 Template type of the 2d array data read from DOOCS and returned to python.
     * @tparam T2 Template type of the data to be returned to python according to the NumPy C API.
     *
     * @param array_data The actual 2d array data read from DOOCS and returned to python.
     * @param type Type of the data to be returned to python according to the NumPy C API.
     *
     * @return The pointer to an PyObject object containing the data to be read.
     */
    template<typename T1, typename T2>
    PyObject* build_numpy_array(const std::vector<std::vector<T1>>& array_data, T2 type) const;

    /**
     * Template helper method to abstract final building PyObject objects for the DOOCS write call of singular data.
     *
     * @tparam T Template type of the actual data provided in python and sent to DOOCS.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write the DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to retrieve additional DOOCS data from.
     * @param data The actual data provided in python and sent to DOOCS.
     *
     * @return The pointer to an PyObject object while writing data from within python to DOOCS.
     */
    template<typename T>
    PyObject* build_write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, T data) const;

    /**
     * Template helper method to abstract final building PyObject objects for the DOOCS write call of array data.
     *
     * @tparam T Template type of the actual data provided in python and sent to DOOCS.
     *
     * @param address The DOOCS EqAdr object encapsulating the DOOCS address for I/O.
     * @param data_to_doocs The DOOCS EqData object to write the DOOCS data to.
     * @param data_from_doocs The DOOCS EqData object to retrieve additional DOOCS data from.
     * @param array_data The actual 1d array data provided in python and sent to DOOCS.
     *
     * @return The pointer to an PyObject object while writing data from within python to DOOCS.
     */
    template<typename T>
    PyObject* build_write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs,
                          const std::vector<T>& array_data) const;

    /**
     * Method to check if the passed numpy object is of any float type (currently float16, float32, or float64)
     *
     * @param numpy_object The numpy object to check for any float type.
     * @return If the passed numpy object is of any float type.
     */
    bool is_any_numpy_float(PyObject* numpy_object) const;

private:
    /*
     * The constant data key for the output python dictionary.
     */
    static const char* DATA_KEY;

    /*
     * The constant type key for the output python dictionary.
     */
    static const char* TYPE_KEY;

    /*
     * The constant timestamp key for the output python dictionary.
     */
    static const char* TIMESTAMP_KEY;

    /*
     * The constant miscellaneous key for the output python dictionary.
     */
    static const char* MISCELLANEOUS_KEY;
};

#include "../src/AbstractBaseBuilder.tcc"  // to allow simple builds with templates

#endif  // PYTHON3_INCLUDE_ABSTRACTBASEBUILDER_H_
