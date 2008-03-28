// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// Provenance.cc
// Implementation of class Provenance methods
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


#include "lsst/mwi/data/Provenance.h"
#include "lsst/mwi/utils/Trace.h"

#include <string>
using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::mwi::utils::Trace( "mwi.data.Provenance", level, s );
}


namespace lsst {
namespace mwi {
namespace data {


Provenance::Provenance() : Citizen( typeid(this) ){
    execTrace("Enter Provenance::Provenance()");
    execTrace( boost::str( 
        boost::format( 
            "Exit Provenance::Provenance() : %s") % this->toString()));
}


Provenance::Provenance(const Provenance& from) : Citizen( typeid(this) ){
   execTrace("Enter Provenance::Provenance(Provenance&)");
   execTrace("Exit Provenance::Provenance(Provenance&)");
}


Provenance::Provenance& Provenance::operator= (const Provenance&){
    execTrace("Provenance::operator= (const Provenance&)");
    return *this;
}


Provenance::~Provenance(){
    execTrace( boost::str( 
        boost::format(
            "Enter Provenance::~Provenance() : %s") % this->toString()));
    execTrace("Exit Provenance::~Provenance()");
}


std::string Provenance::toString(){
    return repr();  // In Citizen
}


} // namespace data
} // namespace mwi
} // namespace lsst

