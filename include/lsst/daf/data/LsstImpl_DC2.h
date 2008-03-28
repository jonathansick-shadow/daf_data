// -*- lsst-c++ -*-
/**
  * \class LsstImpl_DC2
  *
  * \ingroup mwi
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

#include "lsst/mwi/data/LsstData.h"
#include "lsst/mwi/data/Citizen.h"
#include "lsst/mwi/policy/Policy.h"

namespace lsst {
namespace mwi {
namespace data {

using lsst::mwi::policy::Policy;

class LsstImpl_DC2 : public LsstData, public Citizen {
public:
    LsstImpl_DC2(const std::type_info & type);
    /// Virtual destructor, class may be specialized (see Stroustrup 12.4.2)
    virtual ~LsstImpl_DC2();

    /**
      * \brief   Base implementation lsst:DataProperty:::mwi::data:getChildren. May be overridden.
      *          Classes deriving from LsstImpl need implement a getChildren
      *          method only if they collect children.
      * \param   depth Specifies how deep to recurse the collection of
      *                children objects when creating the returned collection.
      *                see lsst::mwi::data::LsstData.getChildren
      * \return  ContainerType Will always return a pair of iterators giving a NULL range
      *          (i.e. std::distance( first, last) = 0)  
      */
    virtual LsstData::IteratorRangeType getChildren( unsigned depth = 1 );


    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getMetadata().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Metadata.
      * \return  see lsst::mwi::data::DataProperty
      */
    virtual DataProperty::PtrType getMetadata() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getPersistence().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Persistence.
      * \return  see lsst::mwi::persistence::Persistence
      */
    virtual lsst::mwi::persistence::Persistence::Ptr getPersistence() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getPolicy().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Policy.
      * \return  see lsst::mwi::data::Policy
      */
    virtual Policy::Ptr getPolicy() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getProvenance().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Provenance.
      * \return  see lsst::mwi::data::Provenance
      */
    virtual Provenance::PtrType getProvenance() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getReleaseProcess().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of ReleaseProcess.
      * \return  see lsst::mwi::data::ReleaseProcess
      */
    virtual ReleaseProcess::PtrType getReleaseProcess() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::LsstData.getSecurity().
      *          May be overridden. Base implementation returns a 
      *          reference-counted pointer to the base object's cached 
      *          instance of Security.
      * \return  see lsst::mwi::data::Security
      */
    virtual Security::PtrType getSecurity() const;

    /**
      * \brief   Base implementation of lsst::mwi::data::setMetadata(). 
      *          May be overridden. Assigns the given metadata
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setMetadata(DataProperty::PtrType metadata);

    /**
      * \brief   Base implementation of lsst::mwi::data::setPersistence(). 
      *          May be overridden. Assigns the given Persistence
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setPersistence(
                lsst::mwi::persistence::Persistence::Ptr persistence);

    /**
      * \brief   Base implementation of lsst::mwi::data::setPolicy(). 
      *          May be overridden. Assigns the given Policy
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setPolicy(Policy::Ptr policy);

    /**
      * \brief   Base implementation of lsst::mwi::data::setProvenance(). 
      *          May be overridden. Assigns the given Provenance
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setProvenance(Provenance::PtrType provenance);

    /**
      * \brief   Base implementation of lsst::mwi::data::setReleaseProcess(). 
      *          May be overridden. Assigns the given ReleaseProcess
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setReleaseProcess(ReleaseProcess::PtrType release);

    /**
      * \brief   Base implementation of lsst::mwi::data::setSecurity(). 
      *          May be overridden. Assigns the given Security
      *          object to the base object's private data member. May result in
      *          the destruction of the currently-cached member object since
      *          the data member is a reference-counted pointer.
      */
    virtual void setSecurity(Security::PtrType security);
 
    /**
      * \brief   Base implementation of lsst::mwi::data::toString(). 
      *          May be overridden. Returns a short string representation
      *          of the object as implemented by Citizen::repr().
      */
    virtual std::string toString();

private:
    DataProperty::PtrType _metadata;
    lsst::mwi::persistence::Persistence::Ptr _persistence;
    Policy::Ptr _policy;
    Provenance::PtrType _provenance;
    ReleaseProcess::PtrType _releaseProcess;
    Security::PtrType _security;
    LsstData::ContainerType _children;

};

} // namespace data
} // namespace mwi
} // namespace lsst

#endif // LSST_MWI_DATA_LSSTIMPL_DC2_H

