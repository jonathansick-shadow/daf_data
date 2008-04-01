// -*- lsst-c++ -*-
%define dataLib_DOCSTRING
"
Access to the lsst::daf::data classes
"
%enddef

%feature("autodoc", "1");
%module(docstring=dataLib_DOCSTRING) dataLib

%{
#include "lsst/daf/base/Citizen.h"
%}

%inline %{
namespace lsst { namespace daf { namespace data { } } }
namespace lsst { namespace daf { namespace utils { } } }
    
using namespace lsst;
using namespace lsst::daf::data;
%}

%init %{
%}

%include "p_lsstSwig.i"
%template(vectorCitizen) std::vector<lsst::daf::base::Citizen *>;
//
// Swig 1.3.33 has problems with std::vector<Citizen const *>, so
// we fake things here.  It's a fake, hence the C-style cast
//
%inline %{
    std::vector<lsst::daf::base::Citizen *> * Citizen_census_for_swig() {
        return (std::vector<lsst::daf::base::Citizen *> *)Citizen::census();
    }
%}
%include "lsst/daf/base/Citizen.h"

%import "lsst/daf/base/Persistable.h"
%include "supportFactoryLib.i"

/******************************************************************************/
// Local Variables: ***
// eval: (setq indent-tabs-mode nil) ***
// End: ***
