#include <iostream>
#include <stdexcept>

class DynamicArray
{
private:
    int *data;       // Pointer to the array's data.
    size_t capacity; // Current allocated capacity.
    size_t size;     // Current number of elements in the array.

    // Helper function that resizes the array
    void resize(size_t new_capacity)
    {
        int *new_data = new int[new_capacity]; // Allocate new memory with the desired capacity.
        // Copy elements from the old array to the newly allocated one.
        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;           // Deallocate old memory.
        data = new_data;         // Update the data pointer.
        capacity = new_capacity; // Update the capacity.
    }

public:
    DynamicArray(size_t initial_capacity = 4) // Constructor that initializes the dynamic array
    {
        data = new int[initial_capacity];
        capacity = initial_capacity;
        size = 0;
    }

    ~DynamicArray() // Destruction to free allocated memory
    {
        delete[] data;
    }

    // Function to add a new element to the array.
    void push_back(int value)
    {
        // if the current size reaches the capacity, resize the array.
        if (size == capacity)
        {
            resize(capacity * 2); // Double the capacity.
        }
        data[size++] = value; // Add the new value and increase the size.
    }

    // Function to remove the last element from the array
    void pop_back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Array is empty");
        }
        size--;
    }

    size_t get_size() const
    {
        return size;
    }

    // Function to get the element at a specific index
    int &operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // function to get the element at a specific index (const version)
    const int &operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void clear()
    {
        size = 0; // Reset size to 0
    }

    size_t get_capacity() const
    {
        return capacity;
    }
};

int main()
{
    DynamicArray arr;

    // Adding elements to the array
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
        std::cout << "Added: " << i << ", Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << "\n";
    }

    // Accessing elements using the overloaded operator[]
    for (size_t i = 0; i < arr.get_size(); i++)
    {
        std::cout << "Element at index: " << i << ": " << arr[i] << std::endl;
    }

    // Removing elements from the array
    arr.pop_back();
    std::cout << "After pop_back, Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << std::endl;

    // Clearing the array
    arr.clear();
    std::cout << "After clear, Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << std::endl;

    return 0;
}