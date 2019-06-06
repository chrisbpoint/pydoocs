#include "build_util.h"
#include "sync_util.h"
#include "DoocsException.h"
#include "py_object_builder.h"


namespace build_util {
    PyObject* names(const char* doocs_address) {
        EqAdr address{doocs_address};  // the DOOCS EqAdr object encapsulating the DOOCS address for I/O
        EqData data_from_doocs;  // the DOOCS EqData object to query the DOOCS data from

        if (EqCall().names(&address, &data_from_doocs)) {
            throw DoocsException::from(data_from_doocs);  // to trigger proper exception handling in the caller (names)
        }

        return py_object_builder::names(&data_from_doocs);
    }

    PyObject* read(const char* doocs_address, PyObject* doocs_parameters, PyObject* macropulse_number) {
        EqAdr address{doocs_address};  // the DOOCS EqAdr object encapsulating the DOOCS address for I/O
        EqData data_to_doocs;  // The DOOCS EqData object to write additional DOOCS data to
        EqData data_from_doocs;  // The DOOCS EqData object to read the DOOCS data from

        sync_util::synchronize_readout_for(&address, &data_to_doocs, &data_from_doocs, doocs_parameters, macropulse_number);

        Py_BEGIN_ALLOW_THREADS
        if (EqCall().get(&address, &data_to_doocs, &data_from_doocs)) {
            throw DoocsException::from(data_from_doocs);  // to trigger proper exception handling in the caller (read)
        }
        Py_END_ALLOW_THREADS

        return py_object_builder::read(&address, &data_to_doocs, &data_from_doocs, doocs_parameters, macropulse_number);
    }

    PyObject* write(const char* doocs_address, PyObject* data_from_python, PyObject* doocs_parameters) {
        EqAdr address{doocs_address};  // the DOOCS EqAdr object encapsulating the DOOCS address for I/O
        EqData data_to_doocs;  // the DOOCS EqData object to write the DOOCS data to
        EqData data_from_doocs;  // the DOOCS EqData object to retrieve additional DOOCS data from

        if (EqCall().get(&address, &data_to_doocs, &data_from_doocs)) {
            throw DoocsException::from(data_from_doocs);  // to trigger proper exception handling in the caller (write)
        }

        return py_object_builder::write(&address, &data_to_doocs, &data_from_doocs, data_from_python, doocs_parameters);
    }
}  // namespace build_util
