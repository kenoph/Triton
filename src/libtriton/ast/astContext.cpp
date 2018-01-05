//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <triton/ast.hpp>
#include <triton/astContext.hpp>
#include <triton/exceptions.hpp>



namespace triton {
  namespace ast {

    SharedAbstractNode AstContext::bv(triton::uint512 value, triton::uint32 size) {
      return BvNode::create(value, size, *this);
    }

    SharedAbstractNode AstContext::bvadd(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvaddNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvand(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvandNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvashr(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvashrNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvfalse(void) {
      return this->bv(0, 1);
    }

    SharedAbstractNode AstContext::bvlshr(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvlshrNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvmul(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvmulNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvnand(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvnandNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvneg(SharedAbstractNode expr) {
      return BvnegNode::create(expr);
    }

    SharedAbstractNode AstContext::bvnor(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvnorNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvnot(SharedAbstractNode expr) {
      return BvnotNode::create(expr);
    }

    SharedAbstractNode AstContext::bvor(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvorNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvrol(triton::uint32 rot, SharedAbstractNode expr) {
      return BvrolNode::create(rot, expr);
    }

    SharedAbstractNode AstContext::bvrol(SharedAbstractNode rot, SharedAbstractNode expr) {
      return BvrolNode::create(rot, expr);
    }

    SharedAbstractNode AstContext::bvror(triton::uint32 rot, SharedAbstractNode expr) {
      return BvrorNode::create(rot, expr);
    }

    SharedAbstractNode AstContext::bvror(SharedAbstractNode rot, SharedAbstractNode expr) {
      return BvrorNode::create(rot, expr);
    }

    SharedAbstractNode AstContext::bvsdiv(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsdivNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsge(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsgeNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsgt(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsgtNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvshl(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvshlNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsle(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsleNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvslt(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsltNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsmod(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsmodNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsrem(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsremNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvsub(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvsubNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvtrue(void) {
      return this->bv(1, 1);
    }

    SharedAbstractNode AstContext::bvudiv(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvudivNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvuge(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvugeNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvugt(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvugtNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvule(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvuleNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvult(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvultNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvurem(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvuremNode::create(expr1, expr2);
    }

     SharedAbstractNode AstContext::bvxnor(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvxnorNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::bvxor(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return BvxorNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::concat(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return ConcatNode::create(expr1, expr2);
    }

    template SharedAbstractNode AstContext::concat(const std::vector<SharedAbstractNode>& exprs);
    template SharedAbstractNode AstContext::concat(const std::list<SharedAbstractNode>& exprs);
    template <typename T>
    SharedAbstractNode AstContext::concat(const T& exprs) {
      return ConcatNode::create(exprs, *this);
    }

    SharedAbstractNode AstContext::decimal(triton::uint512 value) {
      return DecimalNode::create(value, *this);
    }

    SharedAbstractNode AstContext::distinct(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return DistinctNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::equal(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return EqualNode::create(expr1, expr2);
    }

    SharedAbstractNode AstContext::extract(triton::uint32 high, triton::uint32 low, SharedAbstractNode expr) {
      /* Optimization: If we extract the full size of expr, just return expr */
      if (low == 0 && (high + 1) == expr->getBitvectorSize())
        return expr;

      return ExtractNode::create(high, low, expr);
    }

    SharedAbstractNode AstContext::ite(SharedAbstractNode ifExpr, SharedAbstractNode thenExpr, SharedAbstractNode elseExpr) {
      return IteNode::create(ifExpr, thenExpr, elseExpr);
    }

    SharedAbstractNode AstContext::land(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return LandNode::create(expr1, expr2);
    }

    template SharedAbstractNode AstContext::land(const std::vector<SharedAbstractNode>& exprs);
    template SharedAbstractNode AstContext::land(const std::list<SharedAbstractNode>& exprs);
    template <typename T>
    SharedAbstractNode AstContext::land(const T& exprs) {
      return LandNode::create(exprs, *this);
    }

    SharedAbstractNode AstContext::let(std::string alias, SharedAbstractNode expr2, SharedAbstractNode expr3) {
      return LetNode::create(alias, expr2, expr3);
    }

    SharedAbstractNode AstContext::lnot(SharedAbstractNode expr) {
      return LnotNode::create(expr);
    }

    SharedAbstractNode AstContext::lor(SharedAbstractNode expr1, SharedAbstractNode expr2) {
      return LorNode::create(expr1, expr2);
    }

    template SharedAbstractNode AstContext::lor(const std::vector<SharedAbstractNode>& exprs);
    template SharedAbstractNode AstContext::lor(const std::list<SharedAbstractNode>& exprs);
    template <typename T>
    SharedAbstractNode AstContext::lor(const T& exprs) {
      return LorNode::create(exprs, *this);
    }

    SharedAbstractNode AstContext::reference(SharedAbstractNode ast, triton::usize id) {
      return ReferenceNode::create(ast, id);
    }

    SharedAbstractNode AstContext::string(std::string value) {
      return StringNode::create(value, *this);
    }

    SharedAbstractNode AstContext::sx(triton::uint32 sizeExt, SharedAbstractNode expr) {
      /* Optimization: Just return expr if the extend is zero */
      if (sizeExt == 0)
        return expr;

      return SxNode::create(sizeExt, expr);
    }

    SharedAbstractNode AstContext::variable(std::string const& varName, triton::uint32 size) {

      // try to get node from variable pool
      auto it = this->valueMapping.find(varName);
      if(it != this->valueMapping.end()) {
        auto& node = it->second.first;

        if(node->getBitvectorSize() != size)
          throw triton::exceptions::Ast("Node builders - Missmatching variable size.");

        // This node already exist, just return it
        return node;
      } else {
        // if not found, create a new variable node
        return VariableNode::create(varName, size, *this);
      }
    }

    SharedAbstractNode AstContext::zx(triton::uint32 sizeExt, SharedAbstractNode expr) {
      /* Optimization: Just return expr if the extend is zero */
      if (sizeExt == 0)
        return expr;

      return ZxNode::create(sizeExt, expr);
    }

    void AstContext::initVariable(const std::string& name, const triton::uint512& value, SharedAbstractNode const& node) {
      // FIXME: Use insert and check result
      auto it = this->valueMapping.find(name);
      if (it == this->valueMapping.end())
        this->valueMapping.insert(std::make_pair(name, std::make_pair(node, value)));
      else
        throw triton::exceptions::Ast("Ast variable already initialized");
    }

    void AstContext::updateVariable(const std::string& name, const triton::uint512& value) {
      auto& kv = this->valueMapping.at(name);
      kv.second = value;
      kv.first->init();
    }

    SharedAbstractNode AstContext::getVariableNode(const std::string& name) {
      auto it = this->valueMapping.find(name);
      if (it == this->valueMapping.end())
        return nullptr;
      else
        return it->second.first;
    }

    const triton::uint512& AstContext::getValueForVariable(const std::string& varName) const {
      try {
        return this->valueMapping.at(varName).second;
      } catch(const std::out_of_range& e) {
        throw triton::exceptions::Ast("AstContext::getValueForVariable(): Variable doesn't exists");
      }
    }

    void AstContext::setRepresentationMode(triton::uint32 mode) {
      this->astRepresentation.setMode(mode);
    }

    triton::uint32 AstContext::getRepresentationMode(void) const {
      return astRepresentation.getMode();
    }

    std::ostream& AstContext::print(std::ostream& stream, AbstractNode* node) {
      return astRepresentation.print(stream, node);
    }

  }; /* ast namespace */
}; /* triton namespace */
