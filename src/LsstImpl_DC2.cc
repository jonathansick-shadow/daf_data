// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// LsstImpl_DC2.cc
// Implementation of class LsstImpl_DC2 methods
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


#include "lsst/mwi/data/LsstImpl_DC2.h"
#include "lsst/mwi/data/SupportFactory.h"
#include "lsst/mwi/utils/Trace.h"

#include <string>
#include <iostream>
using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::mwi::utils::Trace( "mwi.data.LsstImpl", level, s );
}


namespace lsst {
namespace mwi {
namespace data {


LsstImpl_DC2::LsstImpl_DC2(const std::type_info & type) : Citizen(type){
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC2::LsstImpl_DC2(%s)") % type.name()));
    _metadata = DataProperty::PtrType();
    _persistence = lsst::mwi::persistence::Persistence::Ptr();
    _policy = Policy::Ptr();
    _provenance = Provenance::PtrType();
    _releaseProcess = ReleaseProcess::PtrType();
    _security = Security::PtrType();
    
    execTrace( boost::str( 
        boost::format( 
            "Exit LsstImpl_DC2::LsstImpl_DC2() : %s") % this->toString()));
}


LsstImpl_DC2:: ~LsstImpl_DC2(){
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC2::~LsstImpl_DC2() : %s") % this->toString()));
    execTrace( "Exit LsstImpl_DC2::~LsstImpl_DC2()" );
}


LsstData::IteratorRangeType LsstImpl_DC2::getChildren( unsigned depth ) {
    execTrace( boost::str( 
        boost::format(
            "Enter LsstImpl_DC2::getChildren(%d)") % depth ));
    execTrace( "Exit LsstImpl_DC2::getChildren()" );
	return LsstData::IteratorRangeType( _children.begin(), _children.end() );
}


DataProperty::PtrType LsstImpl_DC2::getMetadata() const{
    execTrace( "Enter LsstImpl_DC2::getMetadata()" );
    execTrace( "Exit LsstImpl_DC2::getMetadata()" );
	return _metadata;
}


lsst::mwi::persistence::Persistence::Ptr LsstImpl_DC2::getPersistence() const{
    execTrace( "Enter LsstImpl_DC2::getPersistence()" );
    execTrace( "Exit LsstImpl_DC2::getPersistence()" );
	return _persistence;
}


Policy::Ptr LsstImpl_DC2::getPolicy() const{
    execTrace( "Enter LsstImpl_DC2::getPolicy()" );
    execTrace( "Exit LsstImpl_DC2::getPolicy()" );
	return _policy;
}


Provenance::PtrType LsstImpl_DC2::getProvenance() const {
    execTrace( "Enter LsstImpl_DC2::getProvenance()" );
    execTrace( "Exit LsstImpl_DC2::getProvenance()" );
	return _provenance;
}


ReleaseProcess::PtrType LsstImpl_DC2::getReleaseProcess() const {
    execTrace( "Enter LsstImpl_DC2::getReleaseProcess()" );
    execTrace( "Exit LsstImpl_DC2::getReleaseProcess()" );
	return _releaseProcess;
}


Security::PtrType LsstImpl_DC2::getSecurity() const {
    execTrace( "Enter LsstImpl_DC2::getSecurity()" );
    execTrace( "Exit LsstImpl_DC2::getSecurity()" );
	return _security;
}


void LsstImpl_DC2::setMetadata(DataProperty::PtrType metadata) {
    execTrace( "Enter LsstImpl_DC2::setMetadata()" );
    execTrace( "Exit LsstImpl_DC2::setMetadata()" );
	_metadata = metadata;
}


void LsstImpl_DC2::setPersistence(
            lsst::mwi::persistence::Persistence::Ptr persistence) {
    execTrace( "Enter LsstImpl_DC2::setPersistence()" );
    execTrace( "Exit LsstImpl_DC2::setPersistence()" );
	_persistence = persistence;
}


void LsstImpl_DC2::setPolicy(Policy::Ptr policy) {
    execTrace( "Enter LsstImpl_DC2::setPolicy()" );
    execTrace( "Exit LsstImpl_DC2::setPolicy()" );
	_policy = policy;
}


void LsstImpl_DC2::setProvenance(Provenance::PtrType provenance) {
    execTrace( "Enter LsstImpl_DC2::setProvenance()" );
    execTrace( "Exit LsstImpl_DC2::setProvenance()" );
	_provenance = provenance;
}


void LsstImpl_DC2::setReleaseProcess(ReleaseProcess::PtrType release) {
    execTrace( "Enter LsstImpl_DC2::setReleaseProcess()" );
    execTrace( "Exit LsstImpl_DC2::setReleaseProcess()" );
	_releaseProcess = release;
}


void LsstImpl_DC2::setSecurity(Security::PtrType security) {
    execTrace( "Enter LsstImpl_DC2::setSecurity()" );
    execTrace( "Exit LsstImpl_DC2::setSecurity()" );
	_security = security;
}


std::string LsstImpl_DC2::toString(){
    return repr();  // In Citizen
}


} // namespace data
} // namespace mwi
} // namespace lsst

