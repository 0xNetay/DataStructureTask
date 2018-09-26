#ifndef PQ_LINKEDLIST_H
#define PQ_LINKEDLIST_H

#include <iostream>
#include "internal/ListNode.h"

/**
 * A simple Linked List.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 */
template<class T>
class LinkedList
{
public:
    inline LinkedList() : m_length(0)
    {
        m_head.next = &m_head;
        m_head.prev = &m_head;
    }

    inline ~LinkedList() = default;

    inline void Insert(ListIterator<T> position, const T &data)
    {
        auto *newNode = new ListNode<T>();
        newNode->data = data;

        // Insert before the given position
        newNode->next = position.m_node;
        newNode->prev = position.m_node->prev;

        position.m_node->prev->next = newNode;
        position.m_node->prev = newNode;

        m_length++;
    }

    inline void Delete(const ListIterator<T> position)
    {
        // Change the pointers to the node
        position.m_node->prev->next = position.m_node->next;
        position.m_node->next->prev = position.m_node->prev;

        // Delete the node
        delete position.m_node;
        m_length--;
    }

    inline ListNode<T> *Search(T value)
    {
        ListNode<T> *return_value = &m_head;

        while ((return_value != nullptr) && (return_value->data != value))
        {
            return_value = return_value->next;
        }

        return return_value;
    }

    inline constexpr bool IsEmpty() const
    {
        return m_length == 0;
    }

    inline ListIterator<T> begin()
    {
        return ListIterator<T>(m_head.next);
    }

    inline ListIterator<T> end()
    {
        return ListIterator<T>(&m_head);
    }

    inline T PopHead()
    {
        auto return_value = begin().m_node->data;
        Delete(begin());
        return return_value;
    }

private:
    size_t m_length;
    ListNode<T> m_head;

};

#endif //PQ_LINKEDLIST_H
