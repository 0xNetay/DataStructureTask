#ifndef PQ_LISTNODE_H
#define PQ_LISTNODE_H

#include <algorithm>

/**
 * This is a Linked List node structure.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 */
template<class T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

    ListNode() : data(0), next(nullptr), prev(nullptr)
    {}
};

template<class T>
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t, const T *, T &>
{
public:

    explicit ListIterator(ListNode<T> *node) : m_node(node)
    {}

    T &operator*()
    {
        return m_node->data;
    }

    ListIterator &operator++()
    {
        if (m_node == nullptr)
        {
            throw std::out_of_range("Iterator overflow");
        }

        m_node = m_node->next;

        return *this;
    }

    const ListIterator operator++(int)
    {
        ListIterator temp = *this;
        ++*this;

        return temp;
    }

    ListIterator &operator--()
    {
        if (m_node == nullptr)
        {
            throw std::out_of_range("Iterator underflow");
        }

        m_node = m_node->prev;

        return *this;
    }

    const ListIterator operator--(int)
    {
        ListIterator temp = *this;
        --*this;

        return temp;
    }

    bool operator==(const ListIterator &other) const
    {
        return m_node == other.m_node;
    }

    bool operator!=(const ListIterator &other) const
    {
        return m_node != other.m_node;
    }

    ListNode<T> *m_node;
};

#endif //PQ_LISTNODE_H
