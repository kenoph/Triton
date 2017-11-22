//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_SOLVERENGINE_H
#define TRITON_SOLVERENGINE_H

#include <cstdlib>
#include <list>
#include <map>
#include <string>

#include <z3++.h>

#include <triton/ast.hpp>
#include <triton/solverModel.hpp>
#include <triton/tritonTypes.hpp>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */
  //! The Engines namespace
  namespace engines {
  /*!
   *  \ingroup triton
   *  \addtogroup engines
   *  @{
   */
    //! The Solver namespace
    namespace solver {
    /*!
     *  \ingroup engines
     *  \addtogroup solver
     *  @{
     */

      /*! 
       * \ingroup solver
       * \addtogroup SolverEngine
       * @{
       */
      namespace SolverEngine {

          //! Computes and returns a model from a symbolic constraint.
          /*! \brief map of symbolic variable id -> model
           *
           * \details
           * **item1**: symbolic variable id<br>
           * **item2**: model
           */
          std::map<triton::uint32, SolverModel> getModel(triton::ast::AbstractNode* node);

          //! Computes and returns several models from a symbolic constraint. The `limit` is the number of models returned.
          /*! \brief list of map of symbolic variable id -> model
           *
           * \details
           * **item1**: symbolic variable id<br>
           * **item2**: model
           */
          std::list<std::map<triton::uint32, SolverModel>> getModels(triton::ast::AbstractNode* node, triton::uint32 limit);
      /*! @} End of SolverEngine namespace */
      };

    /*! @} End of solver namespace */
    };
  /*! @} End of engines namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_SOLVERENGINE_H */
