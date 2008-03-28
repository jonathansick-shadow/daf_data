// -*- lsst-c++ -*-


// Suppress swig complaints from DataProperty
// 362: operator=  ignored
// I had trouble getting %warnfilter to work; hence the pragmas
#pragma SWIG nowarn=362

//
// Swig support for DataProperty
//
class lsst::mwi::data::DataProperty;           // needed forward definition

//
// Convert DataProperty::iteratorRangeType to a python iterator -- note the %newobject
//
// Question: can this be done via a typemap?  Answer: probably; I should find out
//
// This code has to go here so that the %ignore ignores the C++ version of this routine,
// which returns an iterator * to python, which swig failed to wrap as anything useful
//
%extend lsst::mwi::data::DataProperty {
    %newobject findAll(PyObject **PYTHON_SELF, const std::string& criteria, const bool deep = true);
    swig::PySwigIterator* findAll(PyObject **PYTHON_SELF, const std::string& criteria, const bool deep = true) {
        DataProperty::iteratorRangeType range = self->findAll(criteria, deep);
        return swig::make_output_iterator(range.first, range.first, range.second, *PYTHON_SELF);
    }
    %ignore findAll;                    // We want to use this version, not the C++ one
}

%extend lsst::mwi::data::DataProperty {
    %newobject searchAll(PyObject **PYTHON_SELF, const std::string& criteria, const bool deep = true);    
    swig::PySwigIterator* searchAll(PyObject **PYTHON_SELF, const std::string& criteria, const bool deep = true) {
        DataProperty::iteratorRangeType range = self->searchAll(criteria, deep);
        return swig::make_output_iterator(range.first, range.first, range.second, *PYTHON_SELF);
    }
    %ignore searchAll;                  // We want to use this version, not the C++ one
}

%extend lsst::mwi::data::DataProperty {
    %newobject getChildren(PyObject **PYTHON_SELF);
    swig::PySwigIterator* getChildren(PyObject **PYTHON_SELF) {
        DataProperty::iteratorRangeType range = self->getChildren();
        return swig::make_output_iterator(range.first, range.first, range.second, *PYTHON_SELF);
    }
    %ignore getChildren;                // We want to use this version, not the C++ one
}

%{
#include "lsst/mwi/persistence/DateTime.h"
%}

%include "lsst/mwi/data/DataProperty.h"

%include "persistenceMacros.i"

%lsst_persistable_shared_ptr(DataPropertyPtrType, lsst::mwi::data::DataProperty)


#if 0                                   // doesn't work (yet)
typedef boost::shared_ptr<DataProperty> DataPropertyPtr;

%contract DataPropertyPtr::DataPropertyPtr {
ensure:
    DataPropertyPtr_ptr.get() > 0;
}
#endif
    
%template(DataPropertyNameSetType) std::set<std::string>;
// %template(DataPropertyPtrType) boost::shared_ptr<lsst::mwi::data::DataProperty>;
%template(DataPropertyContainerType) std::list<lsst::mwi::data::DataProperty::PtrType>;

%extend lsst::mwi::data::DataProperty {
    //
    // Workaround lack of boost::any support
    //
    // Convert bad boost::any_casts to RuntimeErrors
    //
    %exception {
        try {
            $action;
        } catch(boost::bad_any_cast &e) {
            SWIG_exception(SWIG_RuntimeError, e.what());
        }
    }
    //
    // Add constructors for Python-compatible types
    //
    DataProperty(std::string const& name, int const val) {
        return new DataProperty(name, val);
    }
    DataProperty(std::string const& name, long long const val) {
        return new DataProperty(name, val);
    }
    DataProperty(std::string const& name, double const val) {
        return new DataProperty(name, val);
    }
    DataProperty(std::string const& name, std::string const& val) {
        return new DataProperty(name, val);
    }
    %define DataPropertyAddType(type, typeName)
        static DataProperty::Ptr create ## typeName ## DataProperty(
            std::string const& name, const type val) {
            return DataProperty::Ptr(new DataProperty(name, val));
        }
        type getValue ## typeName() {
            return boost::any_cast<const type>(self->getValue());
        }
    %enddef

    DataPropertyAddType(bool, Bool)
    DataPropertyAddType(short, Short)
    DataPropertyAddType(int, Int)
    DataPropertyAddType(long long, Int64)
    DataPropertyAddType(float, Float)
    DataPropertyAddType(double, Double)
    DataPropertyAddType(std::string, String)
    DataPropertyAddType(lsst::mwi::persistence::DateTime, DateTime)
}

%pythoncode %{
import lsst.mwi.utils

def DataPropertyPtr(*args):
    """Return an DataPropertyPtrType that owns its DataProperty"""

    lsst.mwi.utils.Trace("mwi.memory", 5, "creating DataPropertyPtrType")

    md = DataProperty(*args)
    md.this.disown()
    DataPropertyPtr = DataPropertyPtrType(md)

    lsst.mwi.utils.Trace("mwi.memory", 5, "returning DataPropertyPtr")
        
    return DataPropertyPtr
%}
