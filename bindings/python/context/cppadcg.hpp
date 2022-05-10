//
// Copyright (c) 2022 INRIA
//

#ifndef __pinocchio_python_context_cppadcg_hpp__
#define __pinocchio_python_context_cppadcg_hpp__

#include "pinocchio/codegen/cppadcg.hpp"

#define PINOCCHIO_PYTHON_SCALAR_TYPE ::CppAD::AD<CppAD::cg::CG<double> >
#include "pinocchio/bindings/python/context/generic.hpp"
#undef PINOCCHIO_PYTHON_SCALAR_TYPE

#define PINOCCHIO_PYTHON_SKIP_COMPARISON_OPERATIONS
#define PINOCCHIO_PYTHON_NO_SERIALIZATION

#include <eigenpy/eigenpy.hpp>
#include <eigenpy/user-type.hpp>

namespace pinocchio
{
  namespace python
  {
    inline void exposeSpecificTypeFeatures() {
      boost::python::import("pycppad");
    };

    inline boost::python::object getScalarType()
    {
      return eigenpy::getInstanceClass<context::Scalar>();
    }
    
  }
}

namespace pinocchio
{
  namespace python
  {
    namespace internal
    {
  
      template<typename T> struct has_operator_equal;
  
      template<typename BaseScalar>
      struct has_operator_equal< ::CppAD::AD<CppAD::cg::CG<BaseScalar> > > : boost::false_type   {};
      
    }
  }
}

#endif // #ifndef __pinocchio_python_context_cppadcg_hpp__
