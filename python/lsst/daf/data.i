// -*- lsst-c++ -*-
%define data_DOCSTRING
"
Access to the data classes from the mwi library
"
%enddef

%feature("autodoc", "1");
%module(package="lsst.mwi", docstring=data_DOCSTRING) data

%{
#include "lsst/mwi/data/Citizen.h"
%}

%inline %{
namespace lsst { namespace mwi { namespace data { } } }
namespace lsst { namespace mwi { namespace utils { } } }
    
using namespace lsst;
using namespace lsst::mwi::data;
using namespace lsst::mwi::utils;
%}

%init %{
%}
%pythoncode {
    import lsst.mwi.utils
%}

%include "p_lsstSwig.i"
%template(vectorCitizen) std::vector<Citizen *>;
//
// Swig 1.3.33 has problems with std::vector<Citizen const *>, so
// we fake things here.  It's a fake, hence the C-style cast
//
%inline %{
    std::vector<Citizen *> * Citizen_census_for_swig() {
        return (std::vector<Citizen *> *)Citizen::census();
    }
%}
%include "lsst/mwi/data/Citizen.h"

%import "lsst/mwi/persistence/Persistable.h"
%include "SupportFactory.i"
%include "DataProperty.i"

/******************************************************************************/
// Local Variables: ***
// eval: (setq indent-tabs-mode nil) ***
// End: ***
