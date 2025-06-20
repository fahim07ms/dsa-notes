#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node *next;

    Node(int data)
    {
        setNode(data, NULL);
    }

    Node(int data, Node *next)
    {
        setNode(data, next);
    }

    void setNode(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList {
    Node *head;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = NULL; // Empty List
    }

    // Destructor
    ~SinglyLinkedList()
    {
        if (head != NULL)
        {
            while (head->next != NULL)
            {
                Node *tmp = head;
                head = head->next;
                //cout << "Deleting: " << tmp->data << endl;
                delete tmp;
            }
            //cout << "Deleting: " << head->data << endl;
            delete head;
        }
    }

    // Insert an element at front of the linked list
    void insertAtHead(int x)
    {
        this->insert(x, 1);
    }

    // Insert an element at the end of the list
    void insertAtTail(int x)
    {
        Node *node = new Node(x);
        if (node == NULL)
        {
            cout << "Cannot insert" << endl;
            return;
        }

        if (head == NULL) head = node;
        else
        {
            Node *tmp = head;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = node;
        }
    }

    // Insert at nth position
    void insert(int x, int n)
    {
        // Create a node
        Node *node = new Node(x);
        if (node == NULL)
        {
            cout << "Cannot insert" << endl;
            return;
        }

        // If we want to add it in the front
        if (n == 1)
        {
            node->next = head;
            head = node;
            return;
        }

        // Otherwise go to (n-1)th position
        Node *tmp = head;
        for (int i = 0; i < n-2; i++) tmp = tmp->next;

        // And modify the linkings
        node->next = tmp->next;
        tmp->next = node;
    }

    // Remove/Delete a node from the linked list at nth position
    void remove(int n)
    {
        Node *tmp = head;
        if (n == 1)
        {
            head = head->next;
            delete tmp;
            return;
        }

        for (int i = 0; i < n-2; i++)
        {
            tmp = tmp->next;
        }
        Node *x = tmp->next;
        tmp->next = x->next;
        delete x;
    }

    // Reverse the linked list
    void reverse()
    {
        Node *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Reverse using recursion
    void reverse(Node *p)
    {
        if (p->next == NULL)
        {
            head = p;
            return;
        }

        reverse(p->next);
        Node *q = p->next;
        q->next = p;
        p->next = NULL;
    }

    // Traverse the linked list and print the datas
    void print()
    {
        cout << "List: ";
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }

        cout << endl;
        cout << "Length: " << this->getLength() << endl;
    }

    // Get length of the list
    int getLength()
    {
        int len = 0;
        for (Node *tmp = head; tmp != NULL; tmp = tmp->next) len++;
        return len;
    }

    Node* getHead()
    {
        return head;
    }

    // Print elements in recursive way
    void print(Node *head)
    {
        if (head == NULL) return;
        cout << head->data << " ";
        print(head->next);
    }

    // Print elements in reverse order in recursive way
    void printReverse(Node *head)
    {
        if (head == NULL) return;
        printReverse(head->next);
        cout << head->data << " ";
    }

};

int main()
{
    SinglyLinkedList list;
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.print();

    list.insertAtHead(5);
    list.insertAtHead(1);
    list.insertAtHead(9);
    list.print();

    list.insert(10, 2);
    list.insert(19, 5);
    list.insert(25, 8);
    list.print();

    list.remove(8);
    list.remove(5);
    list.remove(2);
    list.print();

    list.reverse();
    list.print();


    cout << "Recursive print: ";
    list.print(list.getHead());
    cout << endl;

    cout << "Reverse print: ";
    list.printReverse(list.getHead());
    cout << endl;

    list.reverse(list.getHead());
    list.print();

    return 0;
}
