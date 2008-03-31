// -*- lsst-c++ -*-
/**
  * \class LsstImpl_DC2
  *
  * \ingroup daf
  *
  * \brief The implementation of LsstImpl for DC2.
  *        
  *        While publicly available, it is intended that LsstData realizations
  *        will derive from LsstBase, and not LsstImpl_DC2. This indirection
  *        will isolate LsstData realizations from the exact base 
  *        implementation chosen for a given release of the framework.
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
  * Created:
  * 
  */

#ifndef LSST_MWI_DATA_LSSTIMPL_DC2_H
#define LSST_MWI_DATA_LSSTIMPL_DC2_H

#include <typeinfo>

#include "lsst/daf/base/Citizen.h"
#include "lsst/daf/data/LsstData.h"
#include "lsst/pex/policy/Policy.h"

namespace lsst {
namespace daf {
namespace data {

class LsstImpl_DC2 : public LsstData, public lsst::daf::base::Citizen {
public:
    LsstImpl_DC2(const std::type_info & type);
    /// Virtual destructor, class may be specialized (see Stroustrup 12.4.2)
    virtual ~LsstImpl_DC2();

    /**
      * \brief   Base implementation lsst::daf::base::DataProperty::daf::data:getChildren. 
      *          May be overridden.
      *          Classes deriving from LsstImpl need implement a getChildren
      *          method only if they collect children.
      * \param   depth Specifies how deep to recurse the collection of
      *                children objects when creating the returned collection.
      *                see lsst::daf::data::LsstData.getChildren
      * \return  ContainerType Will always return a pair of iterators giving a NULL range
      *          (i.e. std::distance( first, last) = 0)  
      */
    virtual LsstData::IteratorRangeType getChildren( unsigned depth = 1 );


    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getMetadata().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Metadata.
      * \return  see lsst::daf::data::DataProperty
      */
    virtual lsst::daf::base::DataProperty::PtrType getMetadata() const;

    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getPersistence().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Persistence.
      * \return  see lsst::daf::persistence::Persistence
      */
    virtual lsst::daf::persistence::Persistence::Ptr getPersistence() const;

    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getPolicy().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Policy.
      * \return  see lsst::pex::policy::Policy
      */
    virtual lsst::pex::policy::Policy::Ptr getPolicy() const;

    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getProvenance().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Provenance.
      * \return  see lsst::daf::data::Provenance
      */
    virtual Provenance::PtrType getProvenance() const;

    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getReleaseProcess().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of ReleaseProcess.
      * \return  see lsst::daf::data::ReleaseProcess
      */
    virtual ReleaseProcess::PtrType getReleaseProcess() const;

    /**
      * \brief   Base implementation of lsst::daf::data::LsstData.getSecurity().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Security.
      * \return  see lsst::daf::data::Security
      */
    virtual Security::PtrType getSecurity() const;

    /**
      * \brief   Base implementation of lsst::daf::data::setMetadata(). 
      *          May be overridden. Assigns the given metadata
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setMetadata(lsst::daf::base::DataProperty::PtrType metadata);

    /**
      * \brief   Base implementation of lsst::daf::data::setPersistence(). 
      *          May be overridden. Assigns the given Persistence
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setPersistence(
                lsst::daf::persistence::Persistence::Ptr persistence);

    /**
      * \brief   Base implementation of lsst::daf::data::setPolicy(). 
      *          May be overridden. Assigns the given Policy
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setPolicy(lsst::pex::policy::Policy::Ptr policy);

    /**
      * \brief   Base implementation of lsst::daf::data::setProvenance(). 
      *          May be overridden. Assigns the given Provenance
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setProvenance(Provenance::PtrType provenance);

    /**
      * \brief   Base implementation of lsst::daf::data::setReleaseProcess(). 
      *          May be overridden. Assigns the given ReleaseProcess
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setReleaseProcess(ReleaseProcess::PtrType release);

    /**
      * \brief   Base implementation of lsst::daf::data::setSecurity(). 
      *          May be overridden. Assigns the given Security
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setSecurity(Security::PtrType security);
 
    /**
      * \brief   Base implementation of lsst::daf::data::toString(). 
      *          May be overridden. Returns a short string representation
      *          of the object as implemented by Citizen::repr().
      */
    virtual std::string toString();

private:
    lsst::daf::base::DataProperty::PtrType _metadata;
    lsst::daf::persistence::Persistence::Ptr _persistence;
    lsst::pex::policy::Policy::Ptr _policy;
    Provenance::PtrType _provenance;
    ReleaseProcess::PtrType _releaseProcess;
    Security::PtrType _security;
    LsstData::ContainerType _children;

};

} // namespace data
} // namespace daf
} // namespace lsst

#endif // LSST_MWI_DATA_LSSTIMPL_DC2_H

