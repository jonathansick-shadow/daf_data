// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// Security.cc
// Implementation of class Security methods
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
#include "lsst/daf/data/Security.h"
#include "lsst/pex/logging/Trace.h"

#include <string>
using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::pex::logging::Trace( "daf.data.ReleaseProcess", level, s );
}


namespace lsst {
namespace daf {
namespace data {


Security::Security() : lsst::daf::base::Citizen( typeid(this) ){
    execTrace("Enter Security::Security()");
    execTrace( boost::str( 
        boost::format( 
            "Exit Security::Security() : %s") % this->toString()));
}


Security::Security(const Security& from) : lsst::daf::base::Citizen( typeid(this) ){
    execTrace("Enter Security::Security(Security&)");
    execTrace("Exit Security::Security(Security&)");
}


Security::Security& Security::operator= (const Security&){
    execTrace("Security::operator= (const Security&)");
    return *this;
}


Security::~Security(){
    execTrace( boost::str( 
        boost::format(
            "Enter Security::~Security() : %s") % this->toString()));
    execTrace("Exit Security::~Security()");
}


std::string Security::toString(){
    return repr();  // In Citizen
}


} // namespace data
} // namespace daf
} // namespace lsst

