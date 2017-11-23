//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <iosfwd>                         // for ostream
#include <string>                         // for string
#include <triton/astRepresentation.hpp>   // for AstRepresentation, astRepre...
#include <triton/astContext.hpp>          // for AstContext
#include <triton/exceptions.hpp>          // for SymbolicValue
#include <triton/symbolicValue.hpp>  // for SymbolicValue
#include "triton/ast.hpp"                 // for AbstractNode, newInstance
#include "triton/symbolicEnums.hpp"       // for symkind_e, symkind_e::MEM
#include "triton/tritonTypes.hpp"         // for usize


namespace triton {
  namespace engines {
    namespace symbolic {

      SymbolicValue::SymbolicValue(triton::ast::AbstractNode* node, triton::usize id, symkind_e kind, const std::string& comment):
        kind(kind),
        ast(node),
        comment(comment),
        id(id)
        { }


      triton::usize SymbolicValue::getId(void) const {
        return this->id;
      }

      bool SymbolicValue::isRegister(void) const {
        return (this->kind == triton::engines::symbolic::REG);
      }


      bool SymbolicValue::isMemory(void) const {
        return (this->kind == triton::engines::symbolic::MEM);
      }


      bool SymbolicValue::isSymbolized(void) const {
        // FIXME: Check at build time
        if (this->ast == nullptr)
          return false;
        return this->ast->isSymbolized();
      }


      symkind_e SymbolicValue::getKind(void) const {
        return this->kind;
      }


      void SymbolicValue::setKind(symkind_e k) {
        this->kind = k;
      }


      const std::string& SymbolicValue::getComment(void) const {
        return this->comment;
      }


      void SymbolicValue::setComment(const std::string& comment) {
        this->comment = comment;
      }


      triton::ast::AbstractNode* SymbolicValue::getAst(void) const {
        // FIXME: Check at build time
        if (this->ast == nullptr)
          // FIXME
          throw triton::exceptions::SymbolicVariable("SymbolicValue::getAst(): No AST defined.");
        return this->ast;
      }


      triton::ast::AbstractNode* SymbolicValue::getNewAst(void) const {
        // FIXME: Check at build time
        if (this->ast == nullptr)
          // FIXME
          throw triton::exceptions::SymbolicVariable("SymbolicValue::getNewAst(): No AST defined.");
        return triton::ast::newInstance(this->ast);
      }


      void SymbolicValue::setAst(triton::ast::AbstractNode* node) {
        node->setParent(this->ast->getParents());
        this->ast = node;
        this->ast->init();
      }

    }; /* symbolic namespace */
  }; /* engines namespace */
}; /*triton namespace */

