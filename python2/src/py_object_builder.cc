#include "py_object_builder.h"
#include "sync_util.h"
#include "NamesBuilder.h"
#include "BooleanBuilder.h"
#include "IntegerBuilder.h"
#include "LongBuilder.h"
#include "FloatBuilder.h"
#include "DoubleBuilder.h"
#include "StringBuilder.h"
#include "TextBuilder.h"
#include "IfffBuilder.h"
#include "IiiiBuilder.h"
#include "IntegerArrayBuilder.h"
#include "ShortArrayBuilder.h"
#include "LongArrayBuilder.h"
#include "FloatArrayBuilder.h"
#include "DoubleArrayBuilder.h"
#include "ByteArrayBuilder.h"
#include "TsFloatArrayBuilder.h"
#include "TsDoubleArrayBuilder.h"
#include "XyzsArrayBuilder.h"
#include "XyArrayBuilder.h"
#include "UstrArrayBuilder.h"
#include "TdsArrayBuilder.h"
#include "SpectrumBuilder.h"
#include "GspectrumBuilder.h"
#include "ImageBuilder.h"
#include "MdaFloatArrayBuilder.h"


namespace py_object_builder {
    PyObject* names(EqData* data_from_doocs) {
        return NamesBuilder().names(data_from_doocs);
    }

    PyObject* read(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, PyObject* doocs_parameters,
                   PyObject* macropulse_number) {
        PyObject* built_for_return = nullptr;

        switch (data_from_doocs->type()) {
            case DATA_BOOL:
                built_for_return = BooleanBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_INT:
                built_for_return = IntegerBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_LONG:
                built_for_return = LongBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_FLOAT:
                built_for_return = FloatBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_DOUBLE:
                built_for_return = DoubleBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_STRING:
                built_for_return = StringBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_TEXT:
                built_for_return = TextBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_IFFF:
                built_for_return = IfffBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_IIII:
                built_for_return = IiiiBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_INT:
                built_for_return = IntegerArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_SHORT:
                built_for_return = ShortArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_LONG:
                built_for_return = LongArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_FLOAT:
                built_for_return = FloatArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_DOUBLE:
                built_for_return = DoubleArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_BYTE:
                built_for_return = ByteArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_TS_FLOAT:
                built_for_return = TsFloatArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_TS_DOUBLE:
                built_for_return = TsDoubleArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_XYZS:
                built_for_return = XyzsArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_XY:
                built_for_return = XyArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_USTR:
                built_for_return = UstrArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_A_TDS:
                built_for_return = TdsArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_SPECTRUM:
                built_for_return = SpectrumBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_GSPECTRUM:
                built_for_return = GspectrumBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_IMAGE:
                built_for_return = ImageBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            case DATA_MDA_FLOAT:
                built_for_return = MdaFloatArrayBuilder().read(address, data_to_doocs, data_from_doocs, doocs_parameters);
                break;
            default:
                throw PyDoocsException::type_not_supported_yet();
        }

        sync_util::check_synchronization_for(built_for_return, macropulse_number);

        return built_for_return;
    }

    PyObject* write(EqAdr* address, EqData* data_to_doocs, EqData* data_from_doocs, PyObject* data_from_python,
                    PyObject* doocs_parameters) {
        data_to_doocs->set_type(data_from_doocs->type());

        switch (data_from_doocs->type()) {
            case DATA_BOOL:
                return BooleanBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                              doocs_parameters);
            case DATA_INT:
                return IntegerBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                              doocs_parameters);
            case DATA_LONG:
                return LongBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                           doocs_parameters);
            case DATA_FLOAT:
                return FloatBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                            doocs_parameters);
            case DATA_DOUBLE:
                return DoubleBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                             doocs_parameters);
            case DATA_STRING: {
                PyObject* built_string = StringBuilder().write(address, data_to_doocs, data_from_doocs,
                                                                     data_from_python, doocs_parameters);

                if (built_string == nullptr) { // write calls that return data (RPC call) return a nullptr sentinel
                    return read(address, data_to_doocs, data_from_doocs, nullptr, nullptr);
                }
                return built_string;
            }
            case DATA_TEXT:
                return TextBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                           doocs_parameters);
            case DATA_IFFF:
                return IfffBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                           doocs_parameters);
            case DATA_IIII:
                return IiiiBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                           doocs_parameters);
            case DATA_A_INT:
                return IntegerArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                   doocs_parameters);
            case DATA_A_SHORT:
                return ShortArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                   doocs_parameters);
            case DATA_A_LONG:
                return LongArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_A_FLOAT:
                return FloatArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                 doocs_parameters);
            case DATA_A_DOUBLE:
                return DoubleArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                  doocs_parameters);
            case DATA_A_BYTE:
                return ByteArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_A_TS_FLOAT:
                return TsFloatArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                   doocs_parameters);
            case DATA_A_TS_DOUBLE:
                return TsDoubleArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                    doocs_parameters);
            case DATA_A_XYZS:
                return XyzsArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_A_XY:
                return XyArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_A_USTR:
                return UstrArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_A_TDS:
                return TdsArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                               doocs_parameters);
            case DATA_SPECTRUM:
                return SpectrumBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                               doocs_parameters);
            case DATA_GSPECTRUM:
                return GspectrumBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                doocs_parameters);
            case DATA_IMAGE:
                return ImageBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                            doocs_parameters);
            case DATA_MDA_FLOAT:
                return MdaFloatArrayBuilder().write(address, data_to_doocs, data_from_doocs, data_from_python,
                                                    doocs_parameters);
            default:
                throw PyDoocsException::type_not_supported_yet();
        }
    }
}  // namespace py_object_builder
