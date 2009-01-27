// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// LsstImpl_DC3.cc
// Implementation of class LsstImpl_DC3 methods
//
// $Author::                                                                 $
// $Rev::                                                                    $
// $Date::                                                                   $
// $Id::                                                                     $
// 
// Contact: Jeff Bartels (jeffbartels@usa.net)
// 
// Created: 03-Apr-2007 5:30:00 PM
//////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

#include "lsst/daf/base/Citizen.h"
#include "lsst/daf/base/PropertySet.h"
#include "lsst/daf/data/LsstImpl_DC3.h"
#include "lsst/pex/logging/Trace.h"
#include <lsst/pex/policy/Policy.h>

namespace dafBase = lsst::daf::base;

using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::pex::logging::Trace( "daf.data.LsstImpl", level, s );
}

namespace lsst {
namespace daf {
namespace data {


LsstImpl_DC3::LsstImpl_DC3(const std::type_info & type) : lsst::daf::base::Citizen(type){
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC3::LsstImpl_DC3(%s)") % type.name()));
    _metadata = dafBase::PropertySet::Ptr();
    _persistence = lsst::daf::persistence::Persistence::Ptr();
    _policy = lsst::pex::policy::Policy::Ptr();
    _provenance = Provenance::Ptr();
    _releaseProcess = ReleaseProcess::Ptr();
    _security = lsst::security::Security::PtrType();
    
    execTrace( boost::str( 
        boost::format( 
            "Exit LsstImpl_DC3::LsstImpl_DC3() : %s") % this->toString()));
}


LsstImpl_DC3:: ~LsstImpl_DC3(){
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC3::~LsstImpl_DC3() : %s") % this->toString()));
    execTrace( "Exit LsstImpl_DC3::~LsstImpl_DC3()" );
}


LsstData::IteratorRange LsstImpl_DC3::getChildren( unsigned depth ) {
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC3::getChildren(%d)") % depth ));
    execTrace( "Exit LsstImpl_DC3::getChildren()" );
	return LsstData::IteratorRange( _children.begin(), _children.end() );
}


dafBase::PropertySet::Ptr LsstImpl_DC3::getMetadata() const{
    execTrace( "Enter LsstImpl_DC3::getMetadata()" );
    execTrace( "Exit LsstImpl_DC3::getMetadata()" );
	return _metadata;
}


lsst::daf::persistence::Persistence::Ptr LsstImpl_DC3::getPersistence() const{
    execTrace( "Enter LsstImpl_DC3::getPersistence()" );
    execTrace( "Exit LsstImpl_DC3::getPersistence()" );
	return _persistence;
}


lsst::pex::policy::Policy::Ptr LsstImpl_DC3::getPolicy() const{
    execTrace( "Enter LsstImpl_DC3::getPolicy()" );
    execTrace( "Exit LsstImpl_DC3::getPolicy()" );
	return _policy;
}


Provenance::Ptr LsstImpl_DC3::getProvenance() const {
    execTrace( "Enter LsstImpl_DC3::getProvenance()" );
    execTrace( "Exit LsstImpl_DC3::getProvenance()" );
	return _provenance;
}


ReleaseProcess::Ptr LsstImpl_DC3::getReleaseProcess() const {
    execTrace( "Enter LsstImpl_DC3::getReleaseProcess()" );
    execTrace( "Exit LsstImpl_DC3::getReleaseProcess()" );
	return _releaseProcess;
}


lsst::security::Security::PtrType LsstImpl_DC3::getSecurity() const {
    execTrace( "Enter LsstImpl_DC3::getSecurity()" );
    execTrace( "Exit LsstImpl_DC3::getSecurity()" );
	return _security;
}


void LsstImpl_DC3::setMetadata(lsst::daf::base::PropertySet::Ptr metadata) {
    execTrace( "Enter LsstImpl_DC3::setMetadata()" );
    execTrace( "Exit LsstImpl_DC3::setMetadata()" );
	_metadata = metadata;
}


void LsstImpl_DC3::setPersistence(
            lsst::daf::persistence::Persistence::Ptr persistence) {
    execTrace( "Enter LsstImpl_DC3::setPersistence()" );
    execTrace( "Exit LsstImpl_DC3::setPersistence()" );
	_persistence = persistence;
}


void LsstImpl_DC3::setPolicy(lsst::pex::policy::Policy::Ptr policy) {
    execTrace( "Enter LsstImpl_DC3::setPolicy()" );
    execTrace( "Exit LsstImpl_DC3::setPolicy()" );
	_policy = policy;
}


void LsstImpl_DC3::setProvenance(Provenance::Ptr provenance) {
    execTrace( "Enter LsstImpl_DC3::setProvenance()" );
    execTrace( "Exit LsstImpl_DC3::setProvenance()" );
	_provenance = provenance;
}


void LsstImpl_DC3::setReleaseProcess(ReleaseProcess::Ptr release) {
    execTrace( "Enter LsstImpl_DC3::setReleaseProcess()" );
    execTrace( "Exit LsstImpl_DC3::setReleaseProcess()" );
	_releaseProcess = release;
}


void LsstImpl_DC3::setSecurity(lsst::security::Security::PtrType security) {
    execTrace( "Enter LsstImpl_DC3::setSecurity()" );
    execTrace( "Exit LsstImpl_DC3::setSecurity()" );
	_security = security;
}


std::string LsstImpl_DC3::toString(){
    return repr();  // In Citizen
}


}}} // namespace lsst::daf::data

