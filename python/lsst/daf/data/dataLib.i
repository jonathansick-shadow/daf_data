// -*- lsst-c++ -*-

/* 
 * LSST Data Management System
 * Copyright 2008, 2009, 2010 LSST Corporation.
 * 
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <http://www.lsstcorp.org/LegalNotices/>.
 */
 
%define dataLib_DOCSTRING
"
Access to the lsst::daf::data classes
"
%enddef

%feature("autodoc", "1");
%module(package="lsst.daf.data", docstring=dataLib_DOCSTRING) dataLib

%{
#include "lsst/daf/base.h"
#include "lsst/pex/policy.h"
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

