#include <iostream>
#include <Array/Array.h>
#include <Node.h>

int main() {
    // Create an Array of integers
    Array<int> array;

    // Create some nodes
    auto node1 = new Node<int>(1);
    auto node2 = new Node<int>(2);
    auto node3 = new Node<int>(3);

    // Push nodes to the array
    array.push(node1);
    array.push(node2);
    array.push(node3);

    // Print the array
    std::cout << "Array after pushing nodes: ";
    array.printArray();
    std::cout << std::endl;

    // Insert a node at position 1
    auto node4 = new Node<int>(4);
    array.push(node4, 0);

    std::cout << "Array after inserting node at position 1: ";
    array.printArray();
    std::cout << std::endl;

    // Pop the last node
    array.pop();
    std::cout << "Array after popping the last node: ";
    array.printArray();
    std::cout << std::endl;

    // Pop the node at position 1
    array.pop(1);
    std::cout << "Array after popping the node at position 1: ";
    array.printArray();
    std::cout << std::endl;

    return 0;
}
