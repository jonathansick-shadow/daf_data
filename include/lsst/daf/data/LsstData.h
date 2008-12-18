// -*- lsst-c++ -*-
/**
  * \class LsstData
  *
  * \ingroup daf
  *
  * \brief LsstData is the pure abstract base type (interface) for all core 
  *        LSST data types
  *
  * LsstData is the pure abstract base type for all core LSST data types that
  * have provenance and meta-data associated with them.  Classes that realize
  * LsstData are the core astronomical objects of the Framework.
  *
  * See LsstData package for realizations of this type.
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
  * Created: 24-Mar-2007 10:20:57 AM
  * 
  */

#ifndef LSST_MWI_DATA_LSSTDATA_H
#define LSST_MWI_DATA_LSSTDATA_H

#include <list>
#include <string>

#include "lsst/daf/base/PropertySet.h"
#include "lsst/daf/persistence/Persistence.h"
#include "lsst/pex/policy/Policy.h"
#include "lsst/daf/data/Provenance.h"
#include "lsst/daf/data/ReleaseProcess.h"
#include "lsst/security/Security.h"

namespace lsst {
namespace daf {
namespace data {

class LsstData {
public:
    /// Reference-counted pointer typedef for LsstData instances
    typedef boost::shared_ptr<LsstData> Ptr;
    /// The returned child collection type for all LsstData realizations
    typedef std::list<Ptr> Container;
    /// The child collection iterator type for all LsstData realizations
    typedef std::list<Ptr>::const_iterator ContainerIterator;
    /// The child collection iterator begin/end pair
    typedef std::pair< ContainerIterator, ContainerIterator > IteratorRange;
    
    /// Virtual destructor, pure virtual base class (see Stroustrup 12.4.2)
    virtual ~LsstData() {};
    
    /**
      * \brief All classes implementing this interface will return iterator access to 
      *        a collection of references to its children (if any), as
      *        LsstData::Ptr.
      * \param depth How deep below the current object to go in gathering the
      *              list of children.
      *              1 = this object only
      *              2 = this object plus the children of any of its children
      *              ...
      *              UINT_MAX = completely recurse all children of this object
      *                  (see limits.h)
      * \return An IteratorRange, a pair of iterators giving begin() and end()
      *         to allow the caller to iterate over the collection of children.
      * \note If the specific LsstData realization does not aggregate children, the 
      *       returned iterator range will be 0. This can be tested on the return value
      *       with a call to std::distance( range.first, range.second ).
      */
    virtual IteratorRange getChildren( unsigned depth = 1 ) = 0;

    /**
      * \brief   Accessor for object's Metadata
      * \return  see lsst::daf::data::PropertySet
      */
    virtual lsst::daf::base::PropertySet::Ptr getMetadata() const =0;

    /**
      * \brief   Accessor for an LsstData instance's Persistence
      *          see lsst::daf::data::Persistence
      * \return 
      */
    virtual lsst::daf::persistence::Persistence::Ptr getPersistence() const =0;

    /**
      * \brief   Accessor for an LsstData instance's Policy
      * \return  see lsst::daf::data::Policy
      */
    virtual lsst::pex::policy::Policy::Ptr getPolicy() const =0;

    /**
      * \brief   Accessor for an LsstData instance's Provenance
      * \return  see lsst::daf::data::Provenance
      */
    virtual Provenance::Ptr getProvenance() const =0;

    /**
      * \brief   Accessor for an LsstData instance's ReleaseProcess
      * \return  see lsst::daf::data::ReleaseProcess
      */
    virtual ReleaseProcess::Ptr getReleaseProcess() const =0;

    /**
      * \brief   Accessor for an LsstData instance's Security
      * \return  see lsst::daf::data::Security
      */
    virtual lsst::security::Security::PtrType getSecurity() const =0;


    /**
      * \brief   Store the given Metadata object in an LsstData instance
      */
    virtual void setMetadata(lsst::daf::base::PropertySet::Ptr metadata) =0;

    /**
      * \brief   Store the given Persistence object in an LsstData instance
      */
    virtual void setPersistence(
                lsst::daf::persistence::Persistence::Ptr persistence) =0;

    /**
      * \brief   Store the given Policy object in an LsstData instance
      */
    virtual void setPolicy(lsst::pex::policy::Policy::Ptr policy) =0;

    /**
      * \brief   Store the given Provenance object in an LsstData instance
      */
    virtual void setProvenance(Provenance::Ptr provenance) =0;

    /**
      * \brief   Store the given ReleaseProcess object in an LsstData instance
      */
    virtual void setReleaseProcess(ReleaseProcess::Ptr release) =0;

    /**
      * \brief   Store the given Security object in an LsstData instance
      */
    virtual void setSecurity(lsst::security::Security::PtrType security) =0;
 
    /**
      * \brief   Return a short string representation of an instance
      */
    virtual std::string toString() =0;
};
    
} // namespace data
} // namespace daf
} // namespace lsst

#endif // LSST_MWI_DATA_LSSTDATA_H

