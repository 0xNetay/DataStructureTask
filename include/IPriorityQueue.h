#ifndef PRIORITYQUEUE_IPRIORITYQUEUE_H
#define PRIORITYQUEUE_IPRIORITYQUEUE_H

#include "internal/ListNode.h"

/**
 * Interface that shows the requirements of a "Priority Queue-able" class.
 * @tparam T Must be numeric primitive type (int, double, float, etc...)
 */
template<class T>
class IPriorityQueue
{

public:
    virtual void Enqueue(T data) = 0;
    virtual T Dequeue() = 0;
    virtual bool IsEmpty() const = 0;
};

#endif //PRIORITYQUEUE_IPRIORITYQUEUE_H
