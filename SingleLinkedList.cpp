#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class SingleLinkedList
{
private:
    Node *head;

public:
    SingleLinkedList() : head(nullptr) {}
    /*
    5->8->12
    newNode -> ? (first line of function)
    newNode -> 5 (second line of function)
    head -> newNode (third line of function)
    result: newNode -> 5 -> 8 -> 12
    */
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data); // Create a new node to insert.
        newNode->next = head;           // the new node (data we want to insert at the beginning of the list) now points to the head
        head = newNode;                 // the head of the list now points to the new node.
    }

    /*
    5->8->12
    newNode -> ? (first line of function)
    temp -> head (first line after if check)
    1st it:
    head is 5
    temp->next = 8
    temp = temp -> next
    temp = 8
    2nd it:
    temp->next = 12
    temp = temp->next
    temp = 12
    3rd it:
    temp->next = NULL
    break out of while loop
    temp->next = newNode
    */
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head) // check if there is a head.
        {
            head = newNode;
            return;
        }
        Node *temp = head; // store a temporary node to traverse the list
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverseLinkedList()
    {
        Node *previous = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    void printLinkedList()
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL"
                  << "\n";
    }
};
int main()
{
    SingleLinkedList l1;
    l1.insertAtEnd(5);
    l1.insertAtEnd(8);
    l1.insertAtEnd(12);
    l1.printLinkedList();
    l1.reverseLinkedList();
    l1.printLinkedList();
}