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


#include "lsst/mwi/data/LsstDataConfigurator.h"
#include "lsst/mwi/utils/Trace.h"
#include "lsst/mwi/utils/Utils.h"

#include <string>
using namespace std;


namespace lsst {
namespace mwi {
namespace data {


#define EXEC_TRACE  20
static void execTrace( string s ){
    lsst::mwi::utils::Trace( "mwi.data.LsstDataConfigurator", EXEC_TRACE, s );
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


void LsstDataConfigurator::configureSupport( LsstData::PtrType data, Policy::Ptr policy){
    execTrace( 
        boost::str( 
            boost::format( "LsstDataConfigurator::configureSupport(%s, %s)")
                % data->toString() % policy->toString() ) );
    return;
}


} // namespace data
} // namespace mwi
} // namespace lsst

