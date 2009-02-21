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
%import "lsst/security/securityLib.i"

%lsst_exceptions();

SWIG_SHARED_PTR(LsstData, lsst::daf::data::LsstData);
SWIG_SHARED_PTR(Provenance, lsst::daf::data::Provenance);
SWIG_SHARED_PTR(ReleaseProcess, lsst::daf::data::ReleaseProcess);
SWIG_SHARED_PTR_DERIVED(LsstImpl_DC3, lsst::daf::base::Citizen, lsst::daf::data::LsstImpl_DC3);
SWIG_SHARED_PTR_DERIVED(LsstImpl_DC3, lsst::daf::data::LsstData, lsst::daf::data::LsstImpl_DC3);
SWIG_SHARED_PTR_DERIVED(LsstBase, lsst::daf::data::LsstImpl_DC3, lsst::daf::data::LsstBase);

%ignore lsst::daf::data::LsstData::getChildren;
%ignore lsst::daf::data::LsstDC3_Impl::getChildren;

%include "lsst/daf/data/Provenance.h"
%include "lsst/daf/data/ReleaseProcess.h"
%include "lsst/daf/data/LsstData.h"
%include "lsst/daf/data/LsstImpl_DC3.h"
%include "lsst/daf/data/LsstBase.h"
%include "lsst/daf/data/LsstDataConfigurator.h"
%include "lsst/daf/data/SupportFactory.h"

