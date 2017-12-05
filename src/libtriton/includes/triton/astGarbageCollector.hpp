//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_ASTGARBAGECOLLECTOR_H
#define TRITON_ASTGARBAGECOLLECTOR_H

#include <set>
#include <string>

#include <triton/ast.hpp>
#include <triton/tritonTypes.hpp>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  //! The AST namespace
  namespace ast {
  /*!
   *  \ingroup triton
   *  \addtogroup ast
   *  @{
   */

    //! \class AstGarbageCollector
    /*! \brief The AST garbage collector class */
    class AstGarbageCollector {
      protected:
        //! This map maintains a link between variable name and its matching node.
        std::map<std::string, std::shared_ptr<triton::ast::AbstractNode>> variableNodes;

      public:
        //! Extracts all unique nodes from a partial AST into the uniqueNodes set.
        void extractUniqueAstNodes(std::set<triton::ast::AbstractNode*>& uniqueNodes, triton::ast::AbstractNode* root) const;

        //! Records a variable AST node.
        void recordVariableAstNode(const std::string& name, std::shared_ptr<triton::ast::AbstractNode> const& node);

        //! Returns all variable nodes recorded.
        const std::map<std::string, std::shared_ptr<triton::ast::AbstractNode>>& getAstVariableNodes(void) const;

        //! Returns the node of a recorded variable.
        std::shared_ptr<triton::ast::AbstractNode> const& getAstVariableNode(const std::string& name);

        bool hasAstVariableNode(std::string const& name) const;

        //! Sets all variable nodes recorded.
        void setAstVariableNodes(const std::map<std::string, std::shared_ptr<triton::ast::AbstractNode>>& nodes);
    };

  /*! @} End of ast namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_ASTGARBAGECOLLECTOR_H */

