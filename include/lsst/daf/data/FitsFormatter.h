// -*- lsst-c++ -*-
/**
  * \class FitsFormatter
  *
  * \ingroup fw
  *
  * \author Jeff Bartels
  * 
  * Contact: jeffbartels@usa.net
  * 
  * Created: 14-Jul-2007
  */

/*
 $Author::                                                                 $
 $Rev::                                                                    $
 $Date::                                                                   $
 $Id::                                                                     $
 */ 

#ifndef LSST_FW_FITSFORMATTER_H
#define LSST_FW_FITSFORMATTER_H

#include <string>

#include "lsst/mwi/data/DataProperty.h"

namespace lsst {
namespace mwi {
namespace data {


/** 
  * A utility class housing functions related to formatting objects for
  * FITS IO purposes
  */
class FitsFormatter
{

public:
    static const std::string formatDataProperty(
                                const DataProperty::PtrType prop, bool includeHead=true);
    static int countFITSHeaderCards( const DataProperty::PtrType prop, bool includeHead=true );
private:
    FitsFormatter();
    ~FitsFormatter();
};

} // namespace data
} // namespace mwi
} // namespace lsst

#endif // LSST_FW_FITSFORMATTER_H
