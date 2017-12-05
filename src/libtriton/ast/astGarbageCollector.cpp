//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <triton/astGarbageCollector.hpp>
#include <triton/exceptions.hpp>



namespace triton {
  namespace ast {

    void AstGarbageCollector::extractUniqueAstNodes(std::set<triton::ast::AbstractNode*>& uniqueNodes, triton::ast::AbstractNode* root) const {
      if (root == nullptr)
        return;

      uniqueNodes.insert(root);
      for (auto it = root->getChildren().cbegin(); it != root->getChildren().cend(); it++)
        this->extractUniqueAstNodes(uniqueNodes, it->get());
    }


    void AstGarbageCollector::recordVariableAstNode(const std::string& name, std::shared_ptr<AbstractNode> const& node) {
      if(!this->variableNodes.emplace(name, node).second) {
        throw triton::exceptions::Ast("Can't register this variable as it already exists");
      }
    }


    const std::map<std::string, std::shared_ptr<AbstractNode>>& AstGarbageCollector::getAstVariableNodes(void) const {
      return this->variableNodes;
    }


    std::shared_ptr<AbstractNode> const& AstGarbageCollector::getAstVariableNode(const std::string& name) {
      auto it = this->variableNodes.find(name);
      if (it != this->variableNodes.end())
        return it->second;
      throw triton::exceptions::Ast("Can't find variable node");
    }

    bool AstGarbageCollector::hasAstVariableNode(const std::string& name) const {
      auto it = this->variableNodes.find(name);
      return it != this->variableNodes.end();
    }


    void AstGarbageCollector::setAstVariableNodes(const std::map<std::string, std::shared_ptr<AbstractNode>>& nodes) {
      this->variableNodes = nodes;
    }

  }; /* ast namespace */
}; /*triton namespace */

