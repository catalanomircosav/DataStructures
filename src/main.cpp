#include <iostream>
#include <Array/Pila.h>

int main() {
    // Create a stack (Pila) of integers
    Pila<int> stack;

    // Create some nodes
    auto node1 = new Node<int>(1);
    auto node2 = new Node<int>(2);
    auto node3 = new Node<int>(3);

    // Push nodes onto the stack
    stack.push(node1);
    stack.push(node2);
    stack.push(node3);

    // Print the stack
    std::cout << "Stack after pushing nodes: ";
    stack.printArray();
    std::cout << std::endl;

    // Pop the top node
    stack.pop();
    std::cout << "Stack after popping the top node: ";
    stack.printArray();
    std::cout << std::endl;

    return 0;
}
