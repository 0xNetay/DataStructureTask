#ifndef PQ_PRIORITYTREE_H
#define PQ_PRIORITYTREE_H

#include "IPriorityQueue.h"
#include "BinaryTree.h"

/**
 * A Priority queue based on Binary Tree.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 * @note The @tparam defaults to int
 */
template <class T = int>
class PriorityTree : public IPriorityQueue<T>
{
public:

    inline PriorityTree() = default;

    inline ~PriorityTree() = default;

    virtual inline void Enqueue(const T data)
    {
        m_tree.Insert(data);
    }

    virtual inline T Dequeue()
    {
        T toReturn ;
        BTreeNode<T>* t = m_tree.Maximum();

        if (t == nullptr) throw std::out_of_range("Priority Queue is empty");

        toReturn = t->data;
        m_tree.Remove(t);

        return toReturn;
    }

    virtual inline bool IsEmpty() const
    {
        return m_tree.IsEmpty();
    }

private:
    BinaryTree<T> m_tree;
};

#endif //PQ_PRIORITYTREE_H
