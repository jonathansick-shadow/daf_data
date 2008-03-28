// -*- lsst-c++ -*-
/**
  * \class   LsstDataConfigurator
  *
  * \ingroup mwi
  *
  * \brief   Configure the content of LsstData objects
  *
  * Implements a factory object to configure instances of LsstData realizations. 
  *  
  * Since this is a singleton class, it provides no
  * callable constructors nor can it be used in an assignment statement. It 
  * cannot be used to derive another class. (It is 'final' or 'sealed').
  *
  * Usage assuming using namespace lsst::mwi::data:
  *       LsstDataConfigurator::method(...);
  * 
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

#ifndef LSST_MWI_DATA_LSSTDATACONFIGURATOR_H
#define LSST_MWI_DATA_LSSTDATACONFIGURATOR_H

#include "lsst/mwi/utils/Utils.h"

#include "lsst/mwi/policy/Policy.h"
#include "lsst/mwi/data/LsstData.h"

namespace lsst {
namespace mwi {
namespace data {

using lsst::mwi::policy::Policy;

class LsstDataConfigurator {
public:

    /**
      * \brief   Initialize the given LsstData object according to the
      *          content of the given Policy object
      * \param   data The LsstData object to initialize 
      * \param   policy The controlling policy object
      */
    static void configureSupport( LsstData::PtrType data, Policy::Ptr policy);
private:
    // All constructors/destructor, copy constructors, assignment operators
    // are private to preclude specialization and explicit creation
    // of the class
    LsstDataConfigurator();
    LsstDataConfigurator(const LsstDataConfigurator&);
    LsstDataConfigurator& operator= (const LsstDataConfigurator&);
    ~LsstDataConfigurator();
    // The singleton instance (initialized during 1st call to the()
    static LsstDataConfigurator* _singleton;
    // Returns reference to the singleton, creates on first call
    static LsstDataConfigurator& the();
};


} // namespace data
} // namespace mwi
} // namespace lsst

#endif // LSST_MWI_DATA_LSSTDATACONFIGURATOR_H

