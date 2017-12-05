#include <stdio.h>
#include <stdlib.h>
#include <iostream>

 using namespace std;

 struct node
 {
    int data;
    struct node* next;
 };

node* getnode()
{
    node* p;
    p = (node*)malloc(sizeof(node));

    if (p == nullptr)
    {
        cout << "°O¾ÐÅé¤£¨¬" << endl;
        exit(1);
    }
    return (p);
}

void freenode(node* p)
{
    free(p);
}

int length(node* head)
{
    int num = 0;
    node* q = head;

    while(nullptr != q)
    {
        num++;
        q = q->next;
    }
    return(num);
}

node* insert_node(node* head, node* ptr, node data)
{
    node* new_node;
    new_node = getnode();
    *new_node = data;
    new_node->next = nullptr;

    if (ptr == nullptr)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        if (ptr->next == nullptr)
            ptr->next = new_node;
        else
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
    return (head);
}

node* find_node(node* head, int num)
{
    node* ptr;
    ptr = head;

    while(ptr != nullptr)
    {
        if (ptr->data == num)
            return(ptr);
        ptr = ptr->next;
    }
    return(ptr);
}

node* delete_node(node* head, node* ptr)
{
    node* previous;

    if (ptr == head)
        head = head->next;
    else
    {
        previous = head;

        while(previous->next != ptr)
            previous = previous->next;

        if (nullptr == ptr->next)
            previous->next = nullptr;
        else
            previous->next = ptr->next;
    }
    freenode(ptr);
    return(head);
}

int main(int argc, char *argv[])
{
    node* head = nullptr;
    node* ptr;
    node n;
    int value;
    char op;

    while(1)
    {
        cin >> op;

        switch(op)
        {
        case 'd':
            cin >> value;
            ptr = find_node(head, value);

            if (nullptr != ptr)
            {
                head = delete_node(head, ptr);
                cout << "Delete OK!" << endl;
            }
            else
                cout << "cannot delete!" << endl;
            break;
        case 'f':
            cin >> value;
            ptr = find_node(head, value);
            if (ptr != nullptr)
                cout << "Find the value: " << value << endl;
            else
                cout << "cannot find value!" << endl;
            break;
        case 'i':
            cin >> value;
            n.data = value;
            ptr = head;

            if (head == nullptr)
                head = insert_node(head, nullptr, n);
            else
            {
                while(ptr->next != nullptr)
                    ptr = ptr->next;
                head = insert_node(head, ptr, n);
            }
            break;
        case 'l':
            ptr = head;
            while(ptr != nullptr)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << "\nQuantity is " << length(head) << endl;
            break;
        case 'q':
            return 0;;
        default:
            cout << "Please key in the correct command!";
            break;
        }

    }

    /*head = (node*)malloc(sizeof(node));
    ptr = head;


    for (int i =0; i < 5; ++i)
    {
        cin >> value;
        ptr->data = value;
        ptr->next = (node*)malloc(sizeof(node));
        ptr = ptr->next;
    }

    ptr = head;
    for (int i = 0; i <5; ++i)
    {
        if (i == 4)
            cout << ptr->data << endl;
        else
            cout << ptr->data << ", ";

        ptr = ptr->next;
    }*/

    return 0;
}
