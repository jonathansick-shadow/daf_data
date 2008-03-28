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


#include "lsst/mwi/data/Security.h"
#include "lsst/mwi/utils/Trace.h"

#include <string>
using namespace std;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::mwi::utils::Trace( "mwi.data.ReleaseProcess", level, s );
}


namespace lsst {
namespace mwi {
namespace data {


Security::Security() : Citizen( typeid(this) ){
    execTrace("Enter Security::Security()");
    execTrace( boost::str( 
        boost::format( 
            "Exit Security::Security() : %s") % this->toString()));
}


Security::Security(const Security& from) : Citizen( typeid(this) ){
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
} // namespace mwi
} // namespace lsst

