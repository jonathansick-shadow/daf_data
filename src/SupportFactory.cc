// -*- lsst-c++ -*-
//////////////////////////////////////////////////////////////////////////////
// SupportFactory.cc
// Implementation of class SupportFactory methods
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

#include "lsst/daf/base/DataProperty.h"
#include "lsst/daf/data/SupportFactory.h"
#include "lsst/pex/logging/Trace.h"

using namespace std;

using lsst::daf::base::DataProperty;

namespace lsst {
namespace daf {
namespace data {


SupportFactory* SupportFactory::_singleton = 0;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::pex::logging::Trace( "daf.data.SupportFactory", level, s );
}


SupportFactory& SupportFactory::the() {
    if( _singleton == 0 )
    {
        execTrace( "SupportFactory::the() - creating singleton" );
        _singleton = new SupportFactory();
    }
    return *(_singleton);
}


SupportFactory::SupportFactory(){
    execTrace( "Enter SupportFactory::SupportFactory()" );
    execTrace( "Exit SupportFactory::SupportFactory()" );
}


SupportFactory::~SupportFactory(){
    execTrace( "Enter SupportFactory::~SupportFactory()");
    execTrace( "Exit SupportFactory::~SupportFactory()" );
}


SupportFactory::SupportFactory(const SupportFactory&){
}


SupportFactory::SupportFactory& SupportFactory::operator= (const SupportFactory&){
    return the();
}


/**
  * \brief Construct a DataProperty object that does not have any descendants
  * \return A reference-counted pointer to the instance
  */
DataProperty::PtrType SupportFactory::createLeafProperty( std::string name, boost::any value ){
    DataProperty::PtrType ret( 
        new DataProperty(name, value) );
    return ret;
}



/**
  * \brief Construct a DataProperty object that can have descendants
  * \return A reference-counted pointer to the instance
  */
DataProperty::PtrType SupportFactory::createPropertyNode( std::string name ){
    DataProperty::ContainerType coll;
    DataProperty::PtrType ret( new DataProperty(name, coll) );
    return ret;
}


}}} // namespace lsst::daf::data
