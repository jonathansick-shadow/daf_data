// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// LsstDataConfigurator.cc
// Implementation of class LsstDataConfigurator methods
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

#include "lsst/daf/data/LsstDataConfigurator.h"
#include "lsst/pex/logging/Trace.h"
#include <lsst/pex/policy/Policy.h>

using namespace std;

namespace lsst {
namespace daf {
namespace data {

#define EXEC_TRACE  20
static void execTrace( string s ){
    lsst::pex::logging::Trace( "daf.data.LsstDataConfigurator", EXEC_TRACE, s );
}


LsstDataConfigurator* LsstDataConfigurator::_singleton = 0;


LsstDataConfigurator& LsstDataConfigurator::the(){
    if( _singleton == 0 ){
        execTrace( "LsstDataConfigurator::the() - creating singleton");
        _singleton = new LsstDataConfigurator();
    }
    return *(_singleton);
}


LsstDataConfigurator::LsstDataConfigurator(){
    execTrace( "Enter LsstDataConfigurator::LsstDataConfigurator()");
    execTrace( "Exit LsstDataConfigurator::LsstDataConfigurator()") ;
}


LsstDataConfigurator::~LsstDataConfigurator(){
    execTrace( "Enter LsstDataConfigurator::~LsstDataConfigurator()");
    execTrace( "Exit LsstDataConfigurator::~LsstDataConfigurator()");
}


LsstDataConfigurator::LsstDataConfigurator(const LsstDataConfigurator&){
}


LsstDataConfigurator::LsstDataConfigurator& LsstDataConfigurator::operator= (const LsstDataConfigurator&){
	return the();
}


void LsstDataConfigurator::configureSupport(
    LsstData::Ptr data,
    lsst::pex::policy::Policy::Ptr policy
){
    execTrace( 
        boost::str( 
            boost::format( "LsstDataConfigurator::configureSupport(%s, %s)")
                % data->toString() % policy->toString() ) );
    return;
}

}}} // namespace lsst::daf::data

