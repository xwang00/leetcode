#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

class MyLinkedList
{
    struct Node
    {
        int val;
        Node *next;
        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
    };

private:
    int size;
    Node *dummyhead;

public:
    MyLinkedList()
    {
        size = 0;
        dummyhead = new Node(0);
    }

    int get(int index)
    {
        Node *cur = dummyhead;
        if (index > size-1)
            return -1;
        else
        {
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            return cur->next->val;
        }
    }

    void addAtHead(int val)
    {
        if (dummyhead->next != NULL)
        {
            Node *cur = new Node(val);
            cur->next = dummyhead->next;
            dummyhead->next = cur;
        }
        else
        {
            Node *cur = new Node(val);
            dummyhead->next = cur;
            cur->next = NULL;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *cur = dummyhead;
        for (int i = 0; i < size; i++)
        {
            cur = cur->next;
        }
        Node *newcur = new Node(val);
        cur->next = newcur;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        Node *cur = dummyhead;
        if (index > size)
            return;

        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        Node *newcur = new Node(val);
        newcur->next = cur->next;
        cur->next = newcur;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < size)
        {
            Node *cur = dummyhead;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            cur->next = cur->next->next;
            size--;
        }
    }
};

int main(){
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(4);
    std::cout << myLinkedList->get(1) << '\n'; // return 3
    myLinkedList->addAtHead(1);
    myLinkedList->addAtHead(5);
    myLinkedList->deleteAtIndex(3); // now the linked list is 1->3
    myLinkedList->addAtHead(7);
    std::cout << myLinkedList->get(3) << '\n'; // return 3
    std::cout << myLinkedList->get(3) << '\n'; // return 3
    std::cout << myLinkedList->get(3) << '\n'; // return 3
    myLinkedList->addAtHead(1);
    myLinkedList->deleteAtIndex(4); // now the linked list is 1->3
    return 0;
}


/*
int main()
{
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(7);
    myLinkedList->addAtHead(2);
    myLinkedList->addAtHead(1);
    myLinkedList->addAtIndex(3, 0); // linked list becomes 1->2->3
    myLinkedList->deleteAtIndex(2); // now the linked list is 1->3
    myLinkedList->addAtHead(6);
    myLinkedList->addAtTail(4);
    std::cout << myLinkedList->get(4) << '\n'; // return 3
    myLinkedList->addAtHead(4);
    myLinkedList->addAtIndex(5, 0); // linked list becomes 1->2->3
    myLinkedList->addAtHead(6);

    return 0;
}*/

/*
int main()
{
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2); // linked list becomes 1->2->3
    std::cout << myLinkedList->get(1) << '\n';           // return 2
    myLinkedList->deleteAtIndex(1); // now the linked list is 1->3
    std::cout << myLinkedList->get(1)<< '\n';           // return 3
    return 0;
}*/