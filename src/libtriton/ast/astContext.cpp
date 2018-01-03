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

    std::shared_ptr<AbstractNode> AstContext::bv(triton::uint512 value, triton::uint32 size) {
      return BvNode::create(value, size, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::bvadd(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvaddNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvand(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvandNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvashr(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvashrNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvfalse(void) {
      return this->bv(0, 1);
    }

    std::shared_ptr<AbstractNode> AstContext::bvlshr(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvlshrNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvmul(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvmulNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvnand(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvnandNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvneg(std::shared_ptr<AbstractNode> expr) {
      return BvnegNode::create(expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvnor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvnorNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvnot(std::shared_ptr<AbstractNode> expr) {
      return BvnotNode::create(expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvorNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvrol(triton::uint32 rot, std::shared_ptr<AbstractNode> expr) {
      return BvrolNode::create(rot, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvrol(std::shared_ptr<AbstractNode> rot, std::shared_ptr<AbstractNode> expr) {
      return BvrolNode::create(rot, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvror(triton::uint32 rot, std::shared_ptr<AbstractNode> expr) {
      return BvrorNode::create(rot, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvror(std::shared_ptr<AbstractNode> rot, std::shared_ptr<AbstractNode> expr) {
      return BvrorNode::create(rot, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsdiv(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsdivNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsge(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsgeNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsgt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsgtNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvshl(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvshlNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsle(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsleNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvslt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsltNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsmod(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsmodNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsrem(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsremNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvsub(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvsubNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvtrue(void) {
      return this->bv(1, 1);
    }

    std::shared_ptr<AbstractNode> AstContext::bvudiv(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvudivNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvuge(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvugeNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvugt(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvugtNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvule(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvuleNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvult(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvultNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvurem(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvuremNode::create(expr1, expr2);
    }

     std::shared_ptr<AbstractNode> AstContext::bvxnor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvxnorNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::bvxor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return BvxorNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::concat(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return ConcatNode::create(expr1, expr2);
    }

    template std::shared_ptr<AbstractNode> AstContext::concat(const std::vector<std::shared_ptr<AbstractNode>>& exprs);
    template std::shared_ptr<AbstractNode> AstContext::concat(const std::list<std::shared_ptr<AbstractNode>>& exprs);
    template <typename T>
    std::shared_ptr<AbstractNode> AstContext::concat(const T& exprs) {
      return ConcatNode::create(exprs, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::decimal(triton::uint512 value) {
      return DecimalNode::create(value, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::distinct(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return DistinctNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::equal(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return EqualNode::create(expr1, expr2);
    }

    std::shared_ptr<AbstractNode> AstContext::extract(triton::uint32 high, triton::uint32 low, std::shared_ptr<AbstractNode> expr) {
      /* Optimization: If we extract the full size of expr, just return expr */
      if (low == 0 && (high + 1) == expr->getBitvectorSize())
        return expr;

      return ExtractNode::create(high, low, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::ite(std::shared_ptr<AbstractNode> ifExpr, std::shared_ptr<AbstractNode> thenExpr, std::shared_ptr<AbstractNode> elseExpr) {
      return IteNode::create(ifExpr, thenExpr, elseExpr);
    }

    std::shared_ptr<AbstractNode> AstContext::land(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return LandNode::create(expr1, expr2);
    }

    template std::shared_ptr<AbstractNode> AstContext::land(const std::vector<std::shared_ptr<AbstractNode>>& exprs);
    template std::shared_ptr<AbstractNode> AstContext::land(const std::list<std::shared_ptr<AbstractNode>>& exprs);
    template <typename T>
    std::shared_ptr<AbstractNode> AstContext::land(const T& exprs) {
      return LandNode::create(exprs, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::let(std::string alias, std::shared_ptr<AbstractNode> expr2, std::shared_ptr<AbstractNode> expr3) {
      return LetNode::create(alias, expr2, expr3);
    }

    std::shared_ptr<AbstractNode> AstContext::lnot(std::shared_ptr<AbstractNode> expr) {
      return LnotNode::create(expr);
    }

    std::shared_ptr<AbstractNode> AstContext::lor(std::shared_ptr<AbstractNode> expr1, std::shared_ptr<AbstractNode> expr2) {
      return LorNode::create(expr1, expr2);
    }

    template std::shared_ptr<AbstractNode> AstContext::lor(const std::vector<std::shared_ptr<AbstractNode>>& exprs);
    template std::shared_ptr<AbstractNode> AstContext::lor(const std::list<std::shared_ptr<AbstractNode>>& exprs);
    template <typename T>
    std::shared_ptr<AbstractNode> AstContext::lor(const T& exprs) {
      return LorNode::create(exprs, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::reference(std::shared_ptr<AbstractNode> ast, triton::usize id) {
      return ReferenceNode::create(ast, id);
    }

    std::shared_ptr<AbstractNode> AstContext::string(std::string value) {
      return StringNode::create(value, *this);
    }

    std::shared_ptr<AbstractNode> AstContext::sx(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> expr) {
      /* Optimization: Just return expr if the extend is zero */
      if (sizeExt == 0)
        return expr;

      return SxNode::create(sizeExt, expr);
    }

    std::shared_ptr<AbstractNode> AstContext::variable(std::string const& varName, triton::uint32 size) {

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

    std::shared_ptr<AbstractNode> AstContext::zx(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> expr) {
      /* Optimization: Just return expr if the extend is zero */
      if (sizeExt == 0)
        return expr;

      return ZxNode::create(sizeExt, expr);
    }

    void AstContext::initVariable(const std::string& name, const triton::uint512& value, std::shared_ptr<AbstractNode> const& node) {
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

    std::shared_ptr<AbstractNode> AstContext::getVariableNode(const std::string& name) {
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
