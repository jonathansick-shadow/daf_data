// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// ReleaseProcess.cc
// Implementation of class ReleaseProcess methods
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
#include "lsst/daf/data/ReleaseProcess.h"
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


ReleaseProcess::ReleaseProcess() : lsst::daf::base::Citizen( typeid(this) ){
    execTrace("Enter ReleaseProcess::ReleaseProcess()");
    execTrace( boost::str( 
        boost::format( 
            "Exit ReleaseProcess::ReleaseProcess() : %s") % this->toString()));
}


ReleaseProcess::ReleaseProcess(const ReleaseProcess& from) : lsst::daf::base::Citizen( typeid(this) ){
    execTrace("Enter ReleaseProcess::ReleaseProcess(ReleaseProcess&)");
    execTrace("Exit ReleaseProcess::ReleaseProcess(ReleaseProcess&)");
}


ReleaseProcess::ReleaseProcess& ReleaseProcess::operator= (const ReleaseProcess&){
    execTrace("ReleaseProcess::operator= (const ReleaseProcess&)");
    return *this;
}


ReleaseProcess::~ReleaseProcess(){
    execTrace( boost::str( 
        boost::format(
            "Enter ReleaseProcess::~ReleaseProcess() : %s") % this->toString()));
    execTrace("Exit ReleaseProcess::~ReleaseProcess()");
}


std::string ReleaseProcess::toString(){
    return repr();  // In Citizen
}


} // namespace data
} // namespace daf
} // namespace lsst

