#include <vector>
#include <list>
#include <cmath>
#include <set>

#include "TsFloatArrayBuilder.h"


PyObject* TsFloatArrayBuilder::read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, PyObject* doocs_parameters) const {
    if (!doocs_parameters) {
        return ts_float_array_from(data_from_doocs);
    } else {

        u_int seconds;
        u_short milliseconds;
        double time;
        u_short status;
        float history;

        std::vector<double> time_vector;
        std::vector<u_short> status_vector;
        std::vector<float> history_vector;

        std::list<double> time_list;
        std::list<u_short> status_list;
        std::list<float> history_list;

        auto time_list_it = time_list.begin();
        auto status_list_it = status_list.begin();
        auto history_list_it = history_list.begin();


        auto start = static_cast<time_t>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 0)));
        auto end = static_cast<time_t>(PyLong_AsLong(PyList_GetItem(doocs_parameters, 1)));

        TTII par;
        data_to_doocs->init();
        data_to_doocs->set_type(DATA_TTII);

        par.i1_data = 1<<8;
        par.i2_data = 0;


        while (true) {
            par.tm1 = start;
            par.tm2 = end;

            data_to_doocs->set(par.tm1, par.tm2, par.i1_data, par.i2_data);

            if (EqCall().get(address, data_to_doocs, data_from_doocs)) {
                throw DoocsException::from(*data_from_doocs);  // to trigger proper exception handling in the caller
            }

            if (data_from_doocs->length() == 0) {
                throw PyDoocsException::no_history_available();
            }

            time_vector.clear();
            status_vector.clear();
            history_vector.clear();
            for (int i = 0; i < data_from_doocs->length(); ++i) {
                data_from_doocs->get_ts_float(&seconds, &milliseconds, &status, &history, i);
                time = seconds + milliseconds / 1e3;

                time_vector.push_back(time);
                status_vector.push_back(status);
                history_vector.push_back(history);
            }

            time_list.insert(time_list_it, time_vector.begin(), time_vector.end());
            status_list.insert(status_list_it, status_vector.begin(), status_vector.end());
            history_list.insert(history_list_it, history_vector.begin(), history_vector.end());

            time_list_it = time_list.begin();
            status_list_it = status_list.begin();
            history_list_it = history_list.begin();

            if (std::floor(time_vector[0]) <= start) {
                break;
            } else {
                if (end == static_cast<time_t>(time_vector[0])) {
                    throw PyDoocsException::no_history_available();
                }
                end = static_cast<time_t>(time_vector[0]);
            }
        }

        std::set<double> time_seen;
        while(time_list_it != time_list.end() && status_list_it != status_list.end() && history_list_it != history_list.end()) {
            if (time_seen.find(*time_list_it) == time_seen.end()) {
                time_seen.insert(*time_list_it);
                time_list_it++;
                status_list_it++;
                history_list_it++;
            } else {
                time_list_it = time_list.erase(time_list_it);
                status_list_it = status_list.erase(status_list_it);
                history_list_it = history_list.erase(history_list_it);
            }
        }

        time_list_it = time_list.begin();
        status_list_it = status_list.begin();
        history_list_it = history_list.begin();

        PyObject* history_pylist = PyList_New(time_list.size());

        for (int i = 0; time_list_it != time_list.end() &&
                        status_list_it != status_list.end() &&
                        history_list_it != history_list.end(); time_list_it++, status_list_it++, history_list_it++, ++i){

            PyList_SetItem(history_pylist, i,
                           Py_BuildValue("[ffi]", *time_list_it, *history_list_it, *status_list_it));
        }

        PyObject* built_for_return = build_read('O', data_from_doocs, history_pylist);
        Py_DECREF(history_pylist);

        return built_for_return;
    }
}

PyObject* TsFloatArrayBuilder::ts_float_array_from(EqData* data_from_doocs) const {
    u_int seconds;
    u_short milliseconds;
    double time;
    u_short status;
    float history;

    PyObject* history_list = PyList_New(data_from_doocs->length());
    for (int i = 0; i < data_from_doocs->length(); ++i) {
        data_from_doocs->get_ts_float(&seconds, &milliseconds, &status, &history, i);
        time = seconds + milliseconds/1e3;

        PyList_SetItem(history_list, i, Py_BuildValue("[ffi]", time, history, status));
    }

    PyObject* built_for_return = build_read('O', data_from_doocs, history_list);
    Py_DECREF(history_list);

    return built_for_return;
}

PyObject* TsFloatArrayBuilder::write(EqAdr*, EqData*, EqData*, PyObject*, PyObject*) const {
    throw PyDoocsException::functionality_not_supported_yet();
}
