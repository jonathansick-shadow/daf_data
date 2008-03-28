// -*- lsst-c++ -*-
/**
  * \file FitsFormatter.cc
  *
  * \ingroup mwi
  *
  * \author Jeff Bartels
  *
  * Contact: jeffbartels@usa.net
  *
  */

/*
 $Author::                                                                 $
 $Rev::                                                                    $
 $Date::                                                                   $
 $Id::                                                                     $
 */ 
#include <boost/any.hpp>

#include "lsst/mwi/data/FitsFormatter.h"

#include "lsst/mwi/utils/Trace.h"

using namespace std;

#define EXEC_TRACE  20
static void execTrace( string s, int level = EXEC_TRACE ){
    lsst::mwi::utils::Trace( "mwi.FitsFormatter", level, s );
}


namespace lsst {
namespace mwi {
namespace data {


const std::string FitsFormatter::formatDataProperty(
                                    const DataProperty::PtrType prop, bool includeHead) {

    std::ostringstream sout;
    
    execTrace( boost::str( boost::format( 
        "Entering FitsFormatter::formatDataProperty(%s,%s)" ) 
            % prop->toString() % (includeHead == true ? "true" : "false") ) );
    
    if (includeHead) {
        std::string name = prop->getName();
        boost::any value = prop->getValue();
       if (value.type() == typeid(int)) {
            int tmp = boost::any_cast<const int>(value);
            sout << boost::format("%-8s= %20d%50s") % name % tmp % "";
        } else if (value.type() == typeid(double)) {
            double tmp = boost::any_cast<const double>(value);
            sout << boost::format("%-8s= %20.15g%50s") % name % tmp % "";
        } else if (value.type() == typeid(std::string)) {
            std::string tmp = boost::any_cast<const std::string>(value);
            sout << boost::format("%-8s= '%-67s' ") % name % tmp;
        }
    }

    if (prop->isNode() == true) {
        DataProperty::iteratorRangeType range = prop->getChildren();
        DataProperty::ContainerType::const_iterator iter;
        for ( iter = range.first; iter != range.second; iter++) {
            // note: parameter includeHead in next call ALWAYS defaults to true on recursion
            sout << formatDataProperty((*iter));
        }
    }
    
    execTrace( "Exiting FitsFormatter::formatDataProperty()" );
    return sout.str();
}

int FitsFormatter::countFITSHeaderCards( const DataProperty::PtrType prop, bool includeHead ) {
    execTrace( boost::str( boost::format( 
        "Entering FitsFormatter::countFITSHeaderCards(%s)" ) % prop->toString()  ) );
    
    int ret = 0;
    
    if (includeHead) {
        boost::any value = prop->getValue();
        if (value.type() == typeid(int)
        ||  value.type() == typeid(double)
        ||  value.type() == typeid(std::string)) {
            ret = 1;
        }
    }

    if (prop->isNode() == true) {
        DataProperty::iteratorRangeType range = prop->getChildren();
        DataProperty::ContainerType::const_iterator iter;
        for ( iter = range.first; iter != range.second; iter++) {
            // note: parameter includeHead in next call ALWAYS defaults to true on recursion
            ret += countFITSHeaderCards((*iter));
        }
    }
    
    return ret;
    
    execTrace( "Exiting FitsFormatter::countFITSHeaderCards()" );
}

} // namespace data
} // namespace mwi
} // namespace lsst

