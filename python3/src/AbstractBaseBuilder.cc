#include "AbstractBaseBuilder.h"


const char* AbstractBaseBuilder::MACROPULSE_KEY = "macropulse";
const char* AbstractBaseBuilder::DATA_KEY = "data";
const char* AbstractBaseBuilder::TYPE_KEY = "type";
const char* AbstractBaseBuilder::TIMESTAMP_KEY = "timestamp";
const char* AbstractBaseBuilder::MISCELLANEOUS_KEY = "miscellaneous";

bool AbstractBaseBuilder::is_any_numpy_float(PyObject* numpy_object) const {
    PyArray_Descr* data_type;
    if (!PyArray_DescrConverter(numpy_object, &data_type)) return false;

    int type_number = data_type->type_num;
    Py_DECREF(data_type);

    return (type_number == NPY_FLOAT16) || (type_number == NPY_FLOAT32) || (type_number == NPY_FLOAT64);
}
