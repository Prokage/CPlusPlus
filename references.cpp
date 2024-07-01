/*
References are an alternative to pointers. They are often easier to use and less error-prone.
A reference is an alias for another variable.
*/
#include <iostream>

void basicReferenceExample()
{
    int a = 42; // variable of type int
    int &r = a; // reference r refers to a

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of r: " << r << std::endl;

    r = 21; // Changing the value of r changes a, as r references a.

    std::cout << "New value of a: " << a << std::endl;
    std::cout << "New value of r: " << r << std::endl;
}

// References in function parameters, we need a functioin to increment that pases an int by reference.
void increment(int &n)
{
    n++;
}

void referenceInFunctionParameters()
{
    int a = 42;
    increment(a);

    std::cout << "Value of a after increment: " << a << std::endl;
}

// We need a print function for the next example to illustrate Const References

void print(const int &n)
{
    std::cout << n << std::endl;
}

void constReferences()
{
    int a = 42;
    print(a);
    increment(a);
    print(a);
}

int main()
{
    std::cout << "Choose an example to run: " << std::endl;
    std::cout << "1. Basic Reference Example" << std::endl;
    std::cout << "2. Reference In Function Parameters" << std::endl;
    std::cout << "3. Const References" << std::endl;
    std::cout << "Enter your choice from the numbers above: ";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        basicReferenceExample();
        break;
    case 2:
        referenceInFunctionParameters();
        break;
    case 3:
        constReferences();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}