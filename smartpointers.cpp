/*
C++ 11 introduced smart pointers to handle dynamic memory management automatically.
the std::unique_ptr and std::shared_ptr are commonly used smart pointers.
*/

#include <iostream>
#include <memory>

void uniquePointers()
{
    std::unique_ptr<int> p = std::make_unique<int>(42);
    std::cout << "Value at unique_ptr: " << *p << std::endl;
}

void sharedPointers()
{
    std::shared_ptr<int> p1 = std::make_shared<int>(42);
    std::shared_ptr<int> p2 = p1; // Shared ownership.

    std::cout << "Value at shared_ptr: " << *p1 << std::endl;
    std::cout << "Shared use count: " << p1.use_count() << std::endl;
}

int main()
{
    std::cout << "Choose an example to run: " << std::endl;
    std::cout << "1. Unique Pointers" << std::endl;
    std::cout << "2. Shared Pointers" << std::endl;
    std::cout << "Enter your choice from the numbers above: ";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        uniquePointers();
        break;
    case 2:
        sharedPointers();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}