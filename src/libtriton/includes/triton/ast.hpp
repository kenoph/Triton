//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_AST_H
#define TRITON_AST_H

#include <list>
#include <map>
#include <ostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

#include <triton/astEnums.hpp>
#include <triton/tritonTypes.hpp>



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

    class AstContext;

    //! Abstract node
    class AbstractNode: public std::enable_shared_from_this<AbstractNode> {
      protected:
        //! The kind of the node.
        enum kind_e kind;

        //! The children of the node.
        std::vector<std::shared_ptr<AbstractNode>> children;

        //! The parents of the node. Empty if there is still no parent.
        std::map<AbstractNode*, std::weak_ptr<AbstractNode>> parents;

        //! The size of the node.
        triton::uint32 size;

        //! The value of the tree from this root node.
        triton::uint512 eval;

        //! True if the tree contains a symbolic variable.
        bool symbolized;

        //! True if it's a logical node.
        bool logical;

        //! Contect use to create this node
        AstContext& ctxt;

      public:
        //! Constructor.
        AbstractNode(enum kind_e kind, AstContext& ctxt);

        //! Constructor by copy.
        AbstractNode(const AbstractNode& copy, AstContext& ctxt);

        //! Destructor.
        virtual ~AbstractNode();

        //! Access to its context
        AstContext& getContext(void) const;

        //! Returns the kind of the node.
        enum kind_e getKind(void) const;

        //! Returns the size of the node.
        triton::uint32 getBitvectorSize(void) const;

        //! Returns the vector mask according the size of the node.
        triton::uint512 getBitvectorMask(void) const;

        //! According to the size of the expression, returns true if the MSB is 1.
        bool isSigned(void) const;

        //! Returns true if the tree contains a symbolic variable.
        bool isSymbolized(void) const;

        //! Returns true if it's a logical node.
        bool isLogical(void) const;

        //! Returns true if the current tree is equal to the second one.
        bool equalTo(const AbstractNode&) const;

        //! Returns true if the current tree is equal to the second one.
        bool equalTo(AbstractNode*) const;

        //! Evaluates the tree.
        virtual triton::uint512 evaluate(void) const;

        //! Returns the children of the node.
        std::vector<std::shared_ptr<AbstractNode>>& getChildren(void);

        /*!
         * \brief Returns the parents of node or an empty set if there is still no parent defined.
         *
         * Note that if there is the `AST_DICTIONARIES` optimization enabled, this feature will
         * probably not represent the real tree of your expression.
         */
        std::vector<std::shared_ptr<AbstractNode>> getParents(void);

        void updateParents();

        //! Removes a parent node.
        void removeParent(AbstractNode* p);

        //! Sets a parent node.
        void setParent(AbstractNode* p);

        //! Sets the parent nodes.
        void setParent(std::vector<AbstractNode*>& p);

        //! Sets the size of the node.
        void setBitvectorSize(triton::uint32 size);

        //! Adds a child.
        void addChild(std::shared_ptr<AbstractNode> const& child);

        //! Sets a child at an index.
        void setChild(triton::uint32 index, std::shared_ptr<AbstractNode> const& child);

        //! Init stuffs like size and eval.
        virtual void init(void) = 0;

        //! Returns the has of the tree. The hash is computed recursively on the whole tree.
        virtual triton::uint512 hash(triton::uint32 deep) const = 0;
    };


    //! `(bvadd <expr1> <expr2>)` node
    class BvaddNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvaddNode(AstContext& ctxt);
    };


    //! `(bvand <expr1> <expr2>)` node
    class BvandNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<BvandNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvandNode(AstContext& ctxt);
    };


    //! `(bvashr <expr1> <expr2>)` node
    class BvashrNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvashrNode(AstContext& ctxt);
    };


    //! `(bvlshr <expr1> <expr2>)` node
    class BvlshrNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvlshrNode(AstContext& ctxt);
    };


    //! `(bvmul <expr1> <expr2>)` node
    class BvmulNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvmulNode(AstContext& ctxt);
    };


    //! `(bvnand <expr1> <expr2>)` node
    class BvnandNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvnandNode(AstContext& ctxt);
    };


    //! `(bvneg <expr>)` node
    class BvnegNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr);

      private:
        BvnegNode(AstContext& ctxt);
    };


    //! `(bvnor <expr1> <expr2>)` node
    class BvnorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvnorNode(AstContext& ctxt);
    };


    //! `(bvnot <expr>)` node
    class BvnotNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1);

      private:
        BvnotNode(AstContext& ctxt);
    };


    //! `(bvor <expr1> <expr2>)` node
    class BvorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvorNode(AstContext& ctxt);
    };


    //! `((_ rotate_left rot) <expr>)` node
    class BvrolNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint32 rot, std::shared_ptr<AbstractNode> const& expr);
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& rot, std::shared_ptr<AbstractNode> const& expr);

      private:
        BvrolNode(AstContext& ctxt);
    };


    //! `((_ rotate_right rot) <expr>)` node
    class BvrorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint32 rot, std::shared_ptr<AbstractNode> const& expr);
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& rot, std::shared_ptr<AbstractNode> const& expr);

      private:
        BvrorNode(AstContext& ctxt);
    };


    //! `(bvsdiv <expr1> <expr2>)` node
    class BvsdivNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsdivNode(AstContext& ctxt);
    };


    //! `(bvsge <expr1> <expr2>)` node
    class BvsgeNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsgeNode(AstContext& ctxt);
    };


    //! `(bvsgt <expr1> <expr2>)` node
    class BvsgtNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsgtNode(AstContext& ctxt);
    };


    //! `(bvshl <expr1> <expr2>)` node
    class BvshlNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvshlNode(AstContext& ctxt);
    };


    //! `(bvsle <expr1> <expr2>)` node
    class BvsleNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsleNode(AstContext& ctxt);
    };


    //! `(bvslt <expr1> <expr2>)` node
    class BvsltNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsltNode(AstContext& ctxt);
    };


    //! `(bvsmod <expr1> <expr2>)` node
    class BvsmodNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsmodNode(AstContext& ctxt);
    };


    //! `(bvsrem <expr1> <expr2>)` node
    class BvsremNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsremNode(AstContext& ctxt);
    };


    //! `(bvsub <expr1> <expr2>)` node
    class BvsubNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvsubNode(AstContext& ctxt);
    };


    //! `(bvudiv <expr1> <expr2>)` node
    class BvudivNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvudivNode(AstContext& ctxt);
    };


    //! `(bvuge <expr1> <expr2>)` node
    class BvugeNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvugeNode(AstContext& ctxt);
    };


    //! `(bvugt <expr1> <expr2>)` node
    class BvugtNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvugtNode(AstContext& ctxt);
    };


    //! `(bvule <expr1> <expr2>)` node
    class BvuleNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvuleNode(AstContext& ctxt);
    };


    //! `(bvult <expr1> <expr2>)` node
    class BvultNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvultNode(AstContext& ctxt);
    };


    //! `(bvurem <expr1> <expr2>)` node
    class BvuremNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvuremNode(AstContext& ctxt);
    };


    //! `(bvxnor <expr1> <expr2>)` node
    class BvxnorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvxnorNode(AstContext& ctxt);
    };


    //! `(bvxor <expr1> <expr2>)` node
    class BvxorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        BvxorNode(AstContext& ctxt);
    };


    //! `(_ bv<value> <size>)` node
    class BvNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint512 value, triton::uint32 size, AstContext& ctxt);

      private:
        BvNode(AstContext& ctxt);
    };


    //! `(concat <expr1> <expr2> ...)` node
    class ConcatNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;

        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);
        template <typename T> static std::shared_ptr<AbstractNode> get(const T& exprs, AstContext& ctxt);

      private:
        ConcatNode(AstContext& ctxt);
    };


    //! Decimal node
    class DecimalNode : public AbstractNode {
      protected:
        triton::uint512 value;

      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        triton::uint512 getValue(void);

        static std::shared_ptr<AbstractNode> get(triton::uint512 value, AstContext& ctxt);

      private:
        DecimalNode(AstContext& ctxt);
    };


    //! `(distinct <expr1> <expr2> ...)` node
    class DistinctNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        DistinctNode(AstContext& ctxt);
    };


    //! `(= <expr1> <expr2> ...)` node
    class EqualNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);

      private:
        EqualNode(AstContext& ctxt);
    };


    //! `((_ extract <high> <low>) <expr>)` node
    class ExtractNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint32 high, triton::uint32 low, std::shared_ptr<AbstractNode> const& expr);

      private:
        ExtractNode(AstContext& ctxt);
    };


    //! `(ite <ifExpr> <thenExpr> <elseExpr>)`
    class IteNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& ifExpr, std::shared_ptr<AbstractNode> const& thenExpr, std::shared_ptr<AbstractNode> const& elseExpr);

      private:
        IteNode(AstContext& ctxt);
    };


    //! `(and <expr1> <expr2>)`
    class LandNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;

        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);
        template <class T> static std::shared_ptr<AbstractNode> get(const T& exprs, AstContext& ctxt);

      private:
        LandNode(AstContext& ctxt);
    };


    //! `(let ((<alias> <expr2>)) <expr3>)`
    class LetNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::string alias, std::shared_ptr<AbstractNode> const& expr2, std::shared_ptr<AbstractNode> const& expr3);

      private:
        LetNode(AstContext& ctxt);
    };


    //! `(lnot <expr>)`
    class LnotNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr);

      private:
        LnotNode(AstContext& ctxt);
    };


    //! `(or <expr1> <expr2>)`
    class LorNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& expr1, std::shared_ptr<AbstractNode> const& expr2);
        template <class T> static std::shared_ptr<AbstractNode> get(const T& exprs, AstContext& ctxt);

      private:
        LorNode(AstContext& ctxt);
    };


    //! Reference node
    class ReferenceNode : public AbstractNode {
      protected:
        triton::usize id;
        std::shared_ptr<AbstractNode> ast;

      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::shared_ptr<AbstractNode> const& ast, triton::usize id);

        triton::usize getId() const;
        std::shared_ptr<AbstractNode> const& getAst();

      private:
        ReferenceNode(std::shared_ptr<AbstractNode> const& ast, triton::usize id);
    };


    //! String node
    class StringNode : public AbstractNode {
      protected:
        std::string value;

      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(std::string value, AstContext& ctxt);
        std::string getValue(void);

      private:
        StringNode(std::string value, AstContext& ctxt);
    };


    //! `((_ sign_extend sizeExt) <expr>)` node
    class SxNode : public AbstractNode {
      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> const& expr);

      private:
        SxNode(AstContext& ctxt);
    };


    //! Variable node
    class VariableNode : public AbstractNode {
      protected:
        std::string varName;

      public:
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        std::string const& getVarName() const;
        static std::shared_ptr<AbstractNode> get(std::string const& varName, triton::uint32 size, AstContext& ctxt);

      private:
        VariableNode(std::string const& varName, AstContext& ctxt);
    };


    //! `((_ zero_extend sizeExt) <expr>)` node
    class ZxNode : public AbstractNode {
      public:
        //! Create a zero extend of expr to sizeExt bits
        void init(void);
        triton::uint512 hash(triton::uint32 deep) const;
        static std::shared_ptr<AbstractNode> get(triton::uint32 sizeExt, std::shared_ptr<AbstractNode> const& expr);

      private:
        ZxNode(AstContext& ctxt);
    };


    //! Displays the node in ast representation.
    std::ostream& operator<<(std::ostream& stream, AbstractNode* node);

    //! AST C++ API - Duplicates the AST
    std::shared_ptr<AbstractNode> newInstance(AbstractNode* node);

    //! Custom pow function for hash routine.
    triton::uint512 pow(triton::uint512 hash, triton::uint32 n);

    //! Custom rotate left function for hash routine.
    triton::uint512 rotl(triton::uint512 value, triton::uint32 shift);

    //! Custom modular sign extend for bitwise operation.
    triton::sint512 modularSignExtend(AbstractNode* node);

  /*! @} End of ast namespace */
  };
/*! @} End of triton namespace */
};


#endif /* TRITON_AST_H */
