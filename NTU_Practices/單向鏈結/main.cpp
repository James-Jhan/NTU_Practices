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
            cout << endl;
            break;
        case 'q':
            return 0;;
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
