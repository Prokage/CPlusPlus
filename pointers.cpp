/*
Pointers are variables that store the memory address of another variable. They are powerful tools for dynamic
memory allocation, arrays and passing large structures or classes to functions efficiently
*/

#include <iostream>

// Function to demonstrate basic pointers
void pointerExample()
{
    int a = 42;  // Variable of type int
    int *p = &a; // Pointer p stores the address of a.

    std::cout << "Pointer Example:" << std::endl;
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Pointer p points to: " << p << std::endl;
    std::cout << "Value at address stored in p: " << *p << std::endl; // pointer dereferencing with *p gives the value at address stored in p.
    std::cout << std::endl;
}

// Function to demonstrate pointers and references
void pointerAndReferenceExample()
{
    int a = 42;  // Variable of type int
    int &r = a;  // Reference r refers to a
    int *p = &a; // Pointer p stores the address of a

    std::cout << "Pointer and Reference Example:" << std::endl;
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of r (reference to a): " << r << std::endl;
    std::cout << "Pointer p points to: " << p << std::endl;
    std::cout << "Value at address stored in p: " << *p << std::endl;

    r = 21; // Changing the value of r changes a
    std::cout << "After modifying reference r to 21:" << std::endl;
    std::cout << "New value of a: " << a << std::endl;
    std::cout << "New value of r: " << r << std::endl;
    std::cout << "Value at address stored in p: " << *p << std::endl;
    std::cout << std::endl;
}

void dynamicMemoryAllocation()
{
    int *p = new int; // Allocate memory for an int. 4 bytes, 32 bits, since 1 byte = 8 bits.
    *p = 42;          // Assign a value to the allocated memory.

    std::cout << "Value at allocated memory: " << *p << std::endl;

    delete p; // Free the allocated memory
}

void pointerArithmetic()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // Pointer to the first element of the array

    for (int i = 0; i < 5; ++i)
    {
        std::cout << *(p + i) << " "; // Access each element using pointer arithmetic
    }

    std::cout << std::endl;
}

int main()
{
    std::cout << "Choose an example to run:" << std::endl;
    std::cout << "1. Pointer Example" << std::endl;
    std::cout << "2. Pointer and Reference Example" << std::endl;
    std::cout << "3. Dynamic Memory Allocation Example" << std::endl;
    std::cout << "4. Pointer Arithmetic" << std::endl;
    std::cout << "Enter your choice from the numbers above: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        pointerExample();
        break;
    case 2:
        pointerAndReferenceExample();
        break;
    case 3:
        dynamicMemoryAllocation();
        break;
    case 4:
        pointerArithmetic();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }

    return 0;
}
