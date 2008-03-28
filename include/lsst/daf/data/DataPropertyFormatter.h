// -*- lsst-c++ -*-
#ifndef LSST_MWI_DATA_DATAPROPERTYFORMATTER_H
#define LSST_MWI_DATA_DATAPROPERTYFORMATTER_H

/** \file
 * \brief Interface for DataPropertyFormatter class
 *
 * \author $Author: ktlim $
 * \version $Revision: 2150 $
 * \date $Date$
 *
 * Contact: Kian-Tat Lim (ktl@slac.stanford.edu)
 * \ingroup mwi
 */

/** \class lsst::mwi::data::DataPropertyFormatter
 * \brief Formatter for persistence of DataProperty instances.
 *
 * \ingroup mwi
 */

#include "lsst/mwi/persistence/Formatter.h"

// Forward declarations of Boost archive types
namespace boost {
namespace archive {
    class xml_oarchive;
    class xml_iarchive;
}} // namespace boost::archive;

namespace lsst {
namespace mwi {
namespace data {

using namespace lsst::mwi::persistence;

class DataPropertyFormatter : public Formatter {
public:
    virtual ~DataPropertyFormatter(void);

    virtual void write(Persistable const* persistable,
                       Storage::Ptr storage,
                       DataProperty::PtrType additionalData);

    virtual Persistable* read(Storage::Ptr storage,
                                  DataProperty::PtrType additionalData);

    virtual void update(Persistable* persistable,
                        Storage::Ptr storage,
                        DataProperty::PtrType additionalData);

    template <class Archive>
    static void delegateSerialize(Archive& ar,
                                  unsigned int const version,
                                  Persistable* persistable);

private:
    DataPropertyFormatter(lsst::mwi::policy::Policy::Ptr policy);

    lsst::mwi::policy::Policy::Ptr _policy;

    static Formatter::Ptr createInstance(
        lsst::mwi::policy::Policy::Ptr policy);

    static FormatterRegistration registration;
};

}}} // namespace lsst::mwi::data

#endif
