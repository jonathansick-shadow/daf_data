// -*- lsst-c++ -*-
%define dataLib_DOCSTRING
"
Access to the lsst::daf::data classes
"
%enddef

%feature("autodoc", "1");
%module(package="lsst.daf.data", docstring=dataLib_DOCSTRING) dataLib

%{
#include "lsst/daf/base.h"
#include "lsst/pex/policy/Policy.h"
#include "lsst/pex/policy/PolicyFile.h"
#include "lsst/daf/persistence.h"
#include "lsst/daf/data/FitsFormatter.h"
#include "lsst/daf/data/LsstBase.h"
#include "lsst/daf/data/LsstData.h"
#include "lsst/daf/data/LsstDataConfigurator.h"
#include "lsst/daf/data/Provenance.h"
#include "lsst/daf/data/ReleaseProcess.h"
#include "lsst/daf/data/SupportFactory.h"
%}

%include "lsst/p_lsstSwig.i"

%import "lsst/daf/base/baseLib.i"
%import "lsst/pex/policy/policyLib.i"
%import "lsst/daf/persistence/persistenceLib.i"

%lsst_exceptions();

%include "lsst/daf/data/FitsFormatter.h"
%include "lsst/daf/data/Provenance.h"
%include "lsst/daf/data/ReleaseProcess.h"
%include "lsst/daf/data/LsstData.h"
%include "lsst/daf/data/LsstImpl_DC3.h"
%include "lsst/daf/data/LsstBase.h"
%include "lsst/daf/data/LsstDataConfigurator.h"
%include "lsst/daf/data/SupportFactory.h"

