#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        setNode(data, NULL, NULL);
    }

    Node(int data, Node *prev, Node *next)
    {
        setNode(data, prev, next);
    }

    void setNode(int data, Node *prev, Node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList {
    Node *head;
public:
    // Constructor
    DoublyLinkedList()
    {
        head = NULL; // Empty List
    }

    // Destructor
    ~DoublyLinkedList()
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

    // Insert at head
    void insertAtHead(int x)
    {
        Node *node = new Node(x);
        if (node == NULL)
        {
            cout << "Cannot insert" << endl;
            return;
        }

        node->next = head;
        if (head != NULL) head->prev = node;
        head = node;
    }

    // Insert at end
    void insertAtTail(int x)
    {
        Node *node = new Node(x);
        if (node == NULL)
        {
            cout << "Cannot insert" << endl;
            return;
        }

        Node *tmp = head;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = node;
        node->prev = tmp;
    }

    // Insert at nth position
    void insert(int x, int n)
    {
        Node *node = new Node(x);
        if (node == NULL)
        {
            cout << "Cannot insert" << endl;
            return;
        }

        if (n == 1)
        {
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        Node *tmp = head;
        for (int i = 0; i < n-2; i++) tmp = tmp->next;

        node->prev = tmp;
        node->next = tmp->next;
        Node *q = tmp->next;
        if (q != NULL) q->prev = node;
        tmp->next = node;
    }

    // Remove a node from nth position
    void remove(int n)
    {
        if (n == 1)
        {
            Node *tmp = head;
            head = head->next;
            if (head != NULL) head->prev = NULL;
            delete tmp;
            return;
        }

        Node *tmp = head;
        for (int i = 0; i < n-2; i++) tmp = tmp->next;

        Node *target = tmp->next;
        tmp->next = target->next;
        if (target->next != NULL) target->next->prev = tmp;
        delete target;
    }

    // Reverse a doubly linked list
    void reverse()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            // Swap previous and next link of current node
            Node *tmp = cur->prev;
            cur->prev = cur->next;
            cur->next = tmp;

            // Bring head to current node
            head = cur;

            // Move forward
            cur = cur->prev;
        }
    }

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
    }

    void printReverse()
    {
        // Traversing to the end
        Node *tmp = head;
        while (tmp->next != NULL) tmp = tmp->next;

        cout << "Reversed List: ";
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }

        cout << endl;

    }
};


int main()
{
    DoublyLinkedList list;
    list.print();

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.print();


    list.insertAtTail(9);
    list.insertAtTail(10);
    list.insertAtTail(11);
    list.print();

    list.insert(21, 1);
    list.insert(24, 2);
    list.insert(29, 9);
    list.print();

    list.remove(9);
    list.remove(2);
    list.remove(1);
    list.print();

    cout << endl;
    list.printReverse();

    cout << "Reversed Doubly Linked List: ";
    list.reverse();
    list.print();

    list.reverse();
    list.print();

    return 0;
}
