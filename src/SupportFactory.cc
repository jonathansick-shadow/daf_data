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


#include "lsst/mwi/data/SupportFactory.h"

#include "lsst/mwi/utils/Utils.h"
#include "lsst/mwi/utils/Trace.h"

#include <string>
using namespace std;


namespace lsst {
namespace mwi {
namespace data {


SupportFactory* SupportFactory::_singleton = 0;


#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::mwi::utils::Trace( "mwi.data.SupportFactory", level, s );
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


} // namespace data
} // namespace mwi
} // namespace lsst

