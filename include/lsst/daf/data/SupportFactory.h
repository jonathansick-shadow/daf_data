// -*- lsst-c++ -*-
/**
  * \class SupportFactory
  *
  * \ingroup fw
  *
  * \brief Factory class for Support objects
  *
  * Implements a factory object to create instances of the various
  * framework support classes. 
  *  
  * Since this is a singleton class, it provides no
  * callable constructors nor can it be used in an assignment statement. It 
  * cannot be used to derive another class. (It is 'final' or 'sealed').
  *
  * The primary rationale for this object is the assumption that support object 
  * creation will likely require a variety of non-trivial processes and
  * techniques (e.g. return a pooled object, retrieve from a library, etc.). In
  * its initial implementation, this class functions primarily as a place-holder
  * for methods that are expected to be required, and to drive the syntactic
  * form of client code.
  *
  * Usage assuming using namespace lsst::fw:
  *       x = SupportFactory::factoryMethod(...);
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

#ifndef LSST_MWI_DATA_SUPPORTFACTORY_H
#define LSST_MWI_DATA_SUPPORTFACTORY_H

namespace lsst {
namespace daf {
namespace data {

class SupportFactory {
public:
    static SupportFactory& the();

private:
    SupportFactory();
    SupportFactory(const SupportFactory&);
    SupportFactory& operator= (const SupportFactory&);
    ~SupportFactory();
    static SupportFactory* _singleton;
};


}}} // namespace lsst::daf::data

#endif // LSST_MWI_DATA_SUPPORTFACTORY_H

