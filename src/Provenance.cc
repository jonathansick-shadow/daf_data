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


#include "lsst/daf/base/Citizen.h"
#include "lsst/daf/data/Provenance.h"
#include "lsst/pex/logging/Trace.h"

#include <string>
using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::pex::logging::Trace( "daf.data.Provenance", level, s );
}


namespace lsst {
namespace daf {
namespace data {


Provenance::Provenance() : lsst::daf::base::Citizen( typeid(this) ){
    execTrace("Enter Provenance::Provenance()");
    execTrace( boost::str( 
        boost::format( 
            "Exit Provenance::Provenance() : %s") % this->toString()));
}


Provenance::Provenance(const Provenance& from) : lsst::daf::base::Citizen( typeid(this) ){
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
} // namespace daf
} // namespace lsst

