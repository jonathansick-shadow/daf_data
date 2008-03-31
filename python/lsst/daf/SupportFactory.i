%{
#include "lsst/daf/data/SupportFactory.h"
%}

%include "lsst/daf/data/SupportFactory.h"

%extend lsst::daf::data::SupportFactory {
    //
    // Workaround lack of boost::any support
    //
    // Convert bad boost::any_casts to RuntimeErrors
    //
    %exception {
        try {
            $action;
        } catch(boost::bad_any_cast &e) {
            SWIG_exception(SWIG_RuntimeError, e.what());
        }
    }
    //
    // Add explicit createLeafProperty functions for the given type
    //
    %define SupportFactoryAddType(type)
        static DataProperty::PtrType createLeafProperty(
            const std::string& name, const type val) {
            return SupportFactory::createLeafProperty(name, val);
        }
    %enddef

    SupportFactoryAddType(bool)
    SupportFactoryAddType(int)
    SupportFactoryAddType(long long)
    SupportFactoryAddType(double)
    SupportFactoryAddType(std::string)
}
