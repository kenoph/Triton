//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <triton/exceptions.hpp>
#include <triton/tritonToZ3Ast.hpp>
#include <triton/z3Interface.hpp>
#include <triton/z3ToTritonAst.hpp>



namespace triton {
  namespace ast {
    namespace Z3Interface {

    triton::ast::AbstractNode* simplify(triton::ast::AbstractNode* node) {
      triton::ast::TritonToZ3Ast z3Ast{false};
      triton::ast::Z3ToTritonAst tritonAst{node->getContext()};

      /* From Triton to Z3 */
      z3::expr expr = z3Ast.convert(node);

      /* Simplify and back to Triton's AST */
      return tritonAst.convert(expr.simplify());
    }


    triton::uint512 evaluate(triton::ast::AbstractNode* node) {
      if (node == nullptr)
        throw triton::exceptions::AstTranslations("Z3Interface::evaluate(): node cannot be null.");

      try {
        triton::ast::TritonToZ3Ast z3ast{true};

        /* From Triton to Z3 */
        z3::expr expr = z3ast.convert(node);

        /* Evaluate expr over the simplify function */
        return triton::uint512{Z3_get_numeral_string(expr.ctx(), expr.simplify())};
      } catch (const z3::exception& e) {
        throw triton::exceptions::Ast(e.msg());
      }
    }

    }; /* Z3Interface */
  }; /* ast namespace */
}; /* triton namespace */
