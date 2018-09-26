#ifndef PQ_BINARYTREE_H
#define PQ_BINARYTREE_H

#include "internal/BTreeNode.h"

/**
 * A Simple binary tree.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 */
template<class T>
class BinaryTree
{
public:
    inline BinaryTree() : m_root(nullptr)
    {}

    inline ~BinaryTree()
    {
        m_root = MakeEmpty(m_root);
    }

    inline void Insert(const T value)
    {
        BTreeNode<T>* new_node = new BTreeNode<T>(value);
        BTreeNode<T>* previous_parant = nullptr;
        BTreeNode<T>* current_node = m_root;

        while (current_node != nullptr)
        {
            previous_parant = current_node;
            if (new_node->data < current_node->data)
            {
                current_node = current_node->left;
            }
            else
            {
                current_node = current_node->right;
            }
        }

        new_node->parent = previous_parant;

        if (previous_parant == nullptr)
        {
            m_root = new_node;
        }
        else if (new_node->data < previous_parant->data)
        {
            previous_parant->left = new_node;
        }
        else
        {
            previous_parant->right = new_node;
        }
    }

    inline BTreeNode<T> *Remove(BTreeNode<T> *node)
    {
        if (node == nullptr) throw std::out_of_range("Removing from empty Tree");

        BTreeNode<T> *replace_node;
        BTreeNode<T> *temp;

        if ((node->left == nullptr) || (node->right == nullptr))
        {
            replace_node = node;
        }
        else
        {
            replace_node = Successor(node);
        }

        if (node->left != nullptr)
        {
            temp = replace_node->left;
        }
        else
        {
            temp = replace_node->right;
        }

        if (temp != nullptr)
        {
            temp->parent = replace_node->parent;
        }

        if (replace_node->parent == nullptr)
        {
            m_root = temp;
        }
        else if (replace_node == replace_node->parent->left)
        {
            replace_node->parent->left = temp;
        }
        else
        {
            replace_node->parent->right = temp;
        }

        if (replace_node != node)
        {
            node->data = replace_node->data;
        }

        return replace_node;
    }

    inline BTreeNode<T> *Search(const T value) const
    {
        return SearchInNode(m_root, value);
    }

    inline BTreeNode<T> *Successor(const BTreeNode<T> *node) const
    {
        if (node == nullptr) return nullptr;

        if (node->right != nullptr)
        {
            return FindMinimum(node->right);
        }

        BTreeNode<T> *current = node->parent;
        while ((current != nullptr) && (node == current->right))
        {
            node = current;
            current = current->parent;
        }

        return current;
    }

    inline BTreeNode<T> *Predecessor(const BTreeNode<T> *node) const
    {
        if (node == nullptr) return nullptr;

        if (node->left != nullptr)
        {
            return FindMaximum(node->left);
        }

        BTreeNode<T> *current = node->parent;
        while ((current != nullptr) && (node == current->left))
        {
            node = current;
            current = current->parent;
        }

        return current;
    }

    inline BTreeNode<T> *Maximum() const
    {
        return FindMaximum(m_root);
    }

    inline BTreeNode<T> *Minimum() const
    {
        return FindMinimum(m_root);
    }

    inline bool IsEmpty() const
    {
        return m_root == nullptr;
    }

private:

    static BTreeNode<T> *MakeEmpty(BTreeNode<T> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        MakeEmpty(node->left);
        MakeEmpty(node->right);
        node->parent = nullptr;
        delete node;

        return nullptr;
    }

    static BTreeNode<T> *FindMinimum(BTreeNode<T> *t)
    {
        if (t == nullptr)
        {
            return nullptr;
        } else if (t->left == nullptr)
        {
            return t;
        }

        return FindMinimum(t->left);
    }

    static BTreeNode<T> *FindMaximum(BTreeNode<T> *t)
    {
        if (t == nullptr)
        {
            return nullptr;
        } else if (t->right == nullptr)
        {
            return t;
        }

        return FindMaximum(t->right);
    }

    static BTreeNode<T> *SearchInNode(BTreeNode<T> *node, const T value)
    {
        if ((node == nullptr) || (node->data == value))
        {
            return node;
        }

        if (value < node->data)
        {
            return SearchInNode(node->left, value);
        } else
        {
            return SearchInNode(node->right, value);
        }
    }

    inline constexpr size_t height() const
    {
        return m_root->height();
    }

private:
    BTreeNode<T> *m_root;
};

#endif //PQ_BINARYTREE_H
