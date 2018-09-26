#ifndef PQ_BTREENODE_H
#define PQ_BTREENODE_H

#include <algorithm>

/**
 * This is a node for the Binary Tree,
 * containing left and right node pointers and the data it holds
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 */
template<class T>
class BTreeNode
{
public:
    inline explicit BTreeNode(const T value) : data(value), left(nullptr), right(nullptr), parent(nullptr)
    {}

    inline constexpr size_t height() const
    {
        auto l = left ? left->height() : 0;  // height of left child, if any
        auto r = right ? right->height() : 0; // height of right child, if any
        return 1 + std::max(l, r);
    }

public:
    T data;
    BTreeNode<T> *left;
    BTreeNode<T> *right;
    BTreeNode<T> *parent;
};

#endif //PQ_BTREENODE_H
