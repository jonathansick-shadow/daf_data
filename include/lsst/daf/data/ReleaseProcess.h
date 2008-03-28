/**
  * \class ReleaseProcess
  *
  * \ingroup mwi
  *
  * \brief Implements the logic needed to prepare an LsstData 
  *  realization for release and then bring it to a released state.
  * 
  * \note OUT OF SCOPE FOR DC2 - stub implementation
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

#ifndef LSST_MWI_DATA_RELEASEPROCESS_H
#define LSST_MWI_DATA_RELEASEPROCESS_H

#include <boost/shared_ptr.hpp>

#include "lsst/mwi/utils/Utils.h"
#include "lsst/mwi/data/Citizen.h"

namespace lsst {
namespace mwi {
namespace data {

class ReleaseProcess : public Citizen {
public:
    /// Default constructor
    ReleaseProcess();
    /// Copy initialization semantics (NIL in this revision)
    ReleaseProcess(const ReleaseProcess&);
    /// Copy assignment semantics (NIL in this revision)
    ReleaseProcess& operator= (const ReleaseProcess&);
    /// Virtual destructor, class may be specialized (see Stroustrup 12.4.2)
    virtual ~ReleaseProcess();

    /// Reference-counted pointer typedef forinstances of this class
    typedef boost::shared_ptr<ReleaseProcess> PtrType;
    
    /// A short string representation of an instance
    std::string toString();
};
    
} // namespace data
} // namespace mwi
} // namespace lsst

#endif // LSST_MWI_DATA_RELEASEPROCESS_H

