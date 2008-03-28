// -*- lsst-c++ -*-
/**
  * \class Provenance
  *
  * \ingroup mwi
  *
  * \brief A type of Metadata that captures the processing history 
  * of an LsstData realization.
  * 
  * \note This version is a stub implementation of the class
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

#ifndef LSST_MWI_DATA_PROVENANCE_H
#define LSST_MWI_DATA_PROVENANCE_H

#include <boost/shared_ptr.hpp>

#include "lsst/mwi/utils/Utils.h"
#include "lsst/mwi/data/Citizen.h"

namespace lsst {
namespace mwi {
namespace data {

class Provenance : public Citizen {

public:
    /// Default constructor
    Provenance();
    /// Copy initialization semantics (NIL in this revision)
    Provenance(const Provenance&);
    /// Copy assignment semantics (NIL in this revision)
    Provenance& operator= (const Provenance&);
    /// Virtual destructor, class may be specialized (see Stroustrup 12.4.2)
    virtual ~Provenance();

    /// Reference-counted pointer typedef forinstances of this class
    typedef boost::shared_ptr<Provenance> PtrType;
    
    /// A short string representation of an instance
    std::string toString();
};
    
} // namespace data
} // namespace mwi
} // namespace lsst

#endif // LSST_MWI_DATA_PROVENANCE_H

