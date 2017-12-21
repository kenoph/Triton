//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_AST_CONTEXT_H
#define TRITON_AST_CONTEXT_H

#include <triton/ast.hpp>
#include "triton/astRepresentation.hpp"   // for AstRepresentation, astRepre...

#include <vector>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  namespace engines {
    namespace symbolic {
      class SymbolicExpression;
    };
  };

  //! The AST namespace
  namespace ast {
  /*!
   *  \ingroup triton
   *  \addtogroup ast
   *  @{
   */

    //! \class AstContext
    /*! \brief AST Context - Used as AST builder. */
    class AstContext {
      public:
        //! AST C++ API - bv node builder
        std::shared_ptr<AbstractNode> bv(triton::uint512 value, triton::uint32 size);

        //! AST C++ API - bvadd node builder
        std::shared_ptr<AbstractNode> bvadd(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvand node builder
        std::shared_ptr<AbstractNode> bvand(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvashr node builder
        std::shared_ptr<AbstractNode> bvashr(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvfalse node builder
        std::shared_ptr<AbstractNode> bvfalse(void);

        //! AST C++ API - bvlshr node builder
        std::shared_ptr<AbstractNode> bvlshr(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvmul node builder
        std::shared_ptr<AbstractNode> bvmul(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvnand node builder
        std::shared_ptr<AbstractNode> bvnand(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvneg node builder
        std::shared_ptr<AbstractNode> bvneg(std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvnor node builder
        std::shared_ptr<AbstractNode> bvnor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvnot node builder
        std::shared_ptr<AbstractNode> bvnot(std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvor node builder
        std::shared_ptr<AbstractNode> bvor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvrol node builder
        std::shared_ptr<AbstractNode> bvrol(triton::uint32 rot, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvrol node builder
        std::shared_ptr<AbstractNode> bvrol(std::shared_ptr<AbstractNode> rot, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvror node builder
        std::shared_ptr<AbstractNode> bvror(triton::uint32 rot, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvror node builder
        std::shared_ptr<AbstractNode> bvror(std::shared_ptr<AbstractNode> rot, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - bvsdiv node builder
        std::shared_ptr<AbstractNode> bvsdiv(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsge node builder
        std::shared_ptr<AbstractNode> bvsge(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsgt node builder
        std::shared_ptr<AbstractNode> bvsgt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvshl node builder
        std::shared_ptr<AbstractNode> bvshl(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsle node builder
        std::shared_ptr<AbstractNode> bvsle(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvslt node builder
        std::shared_ptr<AbstractNode> bvslt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsmod node builder
        std::shared_ptr<AbstractNode> bvsmod(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsrem node builder
        std::shared_ptr<AbstractNode> bvsrem(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvsub node builder
        std::shared_ptr<AbstractNode> bvsub(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvtrue node builder
        std::shared_ptr<AbstractNode> bvtrue(void);

        //! AST C++ API - bvudiv node builder
        std::shared_ptr<AbstractNode> bvudiv(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvuge node builder
        std::shared_ptr<AbstractNode> bvuge(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvugt node builder
        std::shared_ptr<AbstractNode> bvugt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvule node builder
        std::shared_ptr<AbstractNode> bvule(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvult node builder
        std::shared_ptr<AbstractNode> bvult(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvurem node builder
        std::shared_ptr<AbstractNode> bvurem(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvxnor node builder
        std::shared_ptr<AbstractNode> bvxnor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - bvxor node builder
        std::shared_ptr<AbstractNode> bvxor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - concat node builder
        std::shared_ptr<AbstractNode> concat(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - concat node builder
        template <typename T>
        std::shared_ptr<AbstractNode> concat(const T& exprs);

        //! AST C++ API - decimal node builder
        std::shared_ptr<AbstractNode> decimal(triton::uint512 value);

        //! AST C++ API - distinct node builder
        std::shared_ptr<AbstractNode> distinct(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - equal node builder
        std::shared_ptr<AbstractNode> equal(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - extract node builder
        std::shared_ptr<AbstractNode> extract(triton::uint32 high, triton::uint32 low, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - ite node builder
        std::shared_ptr<AbstractNode> ite(std::shared_ptr<AbstractNode> ifExpr, std::shared_ptr<AbstractNode> thenExpr, std::shared_ptr<AbstractNode> elseExpr);

        //! AST C++ API - land node builder
        std::shared_ptr<AbstractNode> land(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - land node builder
        template <typename T>
        std::shared_ptr<AbstractNode> land(const T& exprs);

        //! AST C++ API - let node builder
        std::shared_ptr<AbstractNode> let(std::string alias, std::shared_ptr<AbstractNode> expr2, std::shared_ptr<AbstractNode> expr3);

        //! AST C++ API - lnot node builder
        std::shared_ptr<AbstractNode> lnot(std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - lor node builder
        std::shared_ptr<AbstractNode> lor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2);

        //! AST C++ API - lor node builder
        template <typename T>
        std::shared_ptr<AbstractNode> lor(const T& exprs);

        //! AST C++ API - reference node builder
        std::shared_ptr<AbstractNode> reference(std::shared_ptr<AbstractNode> ast, triton::usize id);

        //! AST C++ API - string node builder
        std::shared_ptr<AbstractNode> string(std::string value);

        //! AST C++ API - sx node builder
        std::shared_ptr<AbstractNode> sx(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> expr);

        //! AST C++ API - variable node builder
        std::shared_ptr<AbstractNode> variable(std::string const& varName, triton::uint32 size);

        //! AST C++ API - zx node builder
        std::shared_ptr<AbstractNode> zx(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> expr);

        //! Initialize a variable in the context
        void initVariable(const std::string& name, const triton::uint512& value, std::shared_ptr<AbstractNode> const& node);

        //! Get existing variable node if present or nullptr
        std::shared_ptr<AbstractNode> getVariableNode(const std::string& name);

        //! Update a variable value in this context
        void updateVariable(const std::string& name, const triton::uint512& value);

        //! Access a variable value in this context
        const triton::uint512& getValueForVariable(const std::string& varName) const;

        //! Set the representation mode for this astContext
        void setRepresentationMode(triton::uint32 mode);

        //! Get the representations mode of this astContext
        triton::uint32 getRepresentationMode(void) const;

        //! Print the given node with this context representation
        std::ostream& print(std::ostream& stream, AbstractNode* node);

      private:
        //! Map a concrete value and ast node for a variable name.
        // FIXME: Could be a weakptr to avoid leaking these nodes
        std::map<std::string, std::pair<std::shared_ptr<triton::ast::AbstractNode>, triton::uint512>> valueMapping;

        //! String formater for ast
        triton::ast::representations::AstRepresentation astRepresentation;
    };

  /*! @} End of ast namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_AST_CONTEXT_H */
