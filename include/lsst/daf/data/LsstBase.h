// -*- lsst-c++ -*-
/*
  * \class LsstBase
  *
  * \ingroup daf
  *
  * \brief Base class implementation for all LsstData derived types
  *
  * LsstBase establishes the true base class implementation for given release
  * of the framework package. All LsstData relizations in that release of the
  * framework will derive from LsstBase.
  * 
  * \note
  * 
  * \author  $Author::                                                        $
  * \version $Rev::                                                           $
  * \date    $Date::                                                          $
  * 
  * $Id::                                                                     $
  * 
  * Contact: Jeff Bartels (jeffbartels@usa.net)
  * 
  * Created: 03-Apr-2007 5:30:00 PM
  * 
  */

#ifndef LSST_MWI_DATA_LSSTBASE_H
#define LSST_MWI_DATA_LSSTBASE_H

#include "lsst/daf/data/LsstImpl_DC3.h"

namespace lsst {
namespace daf {
namespace data {

class LsstBase : public LsstImpl_DC3 {
public:
    /**
      * \brief Construct an instance of the concrete base class for the
      *        current revision of the framework
      * \param type A std::type_info required by the Citizen base class.
      *        (Obtain with a call to std::typeid(...) )
      */
    LsstBase(const std::type_info &type): LsstImpl_DC3(type) {};

    /// Virtual destructor, class may be specialized (see Stroustrup 12.4.2)
    virtual ~LsstBase() {};
};
    
}}} // namespace lsst::daf::data

#endif  // LSST_MWI_DATA_LSSTBASE_H

