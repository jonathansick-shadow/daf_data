// -*- lsst-c++ -*-
%define dataLib_DOCSTRING
"
Access to the lsst::daf::data classes
"
%enddef

%feature("autodoc", "1");
%module(package="lsst.daf.data", docstring=dataLib_DOCSTRING) dataLib

%{
#include "lsst/daf/data/FitsFormatter.h"
#include "lsst/daf/data/LsstBase.h"
#include "lsst/daf/data/LsstData.h"
#include "lsst/daf/data/LsstDataConfigurator.h"
#include "lsst/daf/data/Provenance.h"
#include "lsst/daf/data/ReleaseProcess.h"
#include "lsst/daf/data/SupportFactory.h"
%}

%inline %{
namespace lsst { namespace daf { namespace data { } } }
    
using namespace lsst::daf::data;
%}

%init %{
%}

%include "lsst/p_lsstSwig.i"

%include "lsst/daf/data/FitsFormatter.h"
%include "lsst/daf/data/LsstBase.h"
%include "lsst/daf/data/LsstData.h"
%include "lsst/daf/data/LsstDataConfigurator.h"
%include "lsst/daf/data/Provenance.h"
%include "lsst/daf/data/ReleaseProcess.h"
%include "lsst/daf/data/SupportFactory.h"


/******************************************************************************/
// Local Variables: ***
// eval: (setq indent-tabs-mode nil) ***
// End: ***
