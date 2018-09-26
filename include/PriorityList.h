#ifndef PQ_PRIORITYLIST_H
#define PQ_PRIORITYLIST_H

#include "IPriorityQueue.h"
#include "LinkedList.h"

/**
 * A Priority queue based on Linked List.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 * @note The @tparam defaults to int
 */
template<class T = int>
class PriorityList : public IPriorityQueue<T>
{
public:
    inline PriorityList() = default;

    inline ~PriorityList() = default;

    virtual inline void Enqueue(const T data)
    {
        auto i = m_list.begin();

        // Run through the list and stop if reached end or if
        // the desired location was found.
        for (;
            (i != m_list.end()) && (*i > data);
            i++)
        {}

        m_list.Insert(i, data);
    }

    virtual inline T Dequeue()
    {
        return m_list.PopHead();
    }

    virtual inline bool IsEmpty() const
    {
        return m_list.IsEmpty();
    }

private:
    LinkedList<T> m_list;
};

#endif //PQ_PRIORITYLIST_H
