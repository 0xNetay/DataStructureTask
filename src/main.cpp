#include <iostream>
#include <random>
#include "BinaryTree.h"
#include "PriorityTree.h"
#include "PriorityList.h"

int main(int argc, const char **argv)
{
    static constexpr int NUM_OF_NODES = 50;

    // Setting up random number generator with even distribution
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, 1000);

    auto *tree = new PriorityTree<>();
    auto *list = new PriorityList<>();

    std::cout << std::endl <<
                 "=-=-=-=-=-=-=-=-=" << std::endl <<
                 "Generating random numbers with even distribution: " << std::endl;

    // Insert to priority queues
    for (auto i = 0; i < NUM_OF_NODES; ++i)
    {
        auto random = dist(mt);
        std::cout << random << std::endl;
        list->Enqueue(random);
        tree->Enqueue(random);
    }

    std::cout << "=-=-=-=-=-=-=-=-=" << std::endl <<
                 std::endl <<
                 "=-=-=-=-=-=-=-=-=" << std::endl <<
                 "Dequeue as list: " << std::endl;

    // Read from priority queues
    while (! list->IsEmpty())
    {
        std::cout << list->Dequeue() << std::endl;
    }

    std::cout << "=-=-=-=-=-=-=-=-=" << std::endl <<
                 std::endl <<
                 "=-=-=-=-=-=-=-=-=" << std::endl <<
                 "Dequeue as tree: " << std::endl;

    while (! tree->IsEmpty())
    {
        std::cout << tree->Dequeue() << std::endl;
    }

    std::cout << "=-=-=-=-=-=-=-=-=" << std::endl;
};