#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

node* getnode()
{
    node* ptr;
    ptr = (node*)malloc(sizeof(node));

    if (NULL == ptr)
    {
        cout << "Memory is not enough!" << endl;
        exit(1);
    }
    return(ptr);
}

void freenode(node* ptr)
{
    free(ptr);
}

node* insert_node(node* head, node* ptr, node data)
{
    node* new_node;
    new_node = getnode();
    *new_node = data;
    new_node->next = NULL;

    if (NULL == ptr)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        if (NULL == ptr->next)
            ptr->next = new_node;
        else
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
    return(head);
}

node* delete_node(node* head, node* ptr)
{
    node* previous;

    if (head == ptr)
        head = head->next;
    else
    {
        previous = head;

        while(ptr != previous->next)
            previous = previous->next;

        if (NULL == ptr->next)
            previous->next = NULL;
        else
            previous->next = ptr->next;
    }
    freenode(ptr);
    return(head);
}

int lenght_node(node* head)
{
    int cnt = 0;
    node* q = head;
    while (NULL != q)
    {
        cnt++;
        q = q->next;
    }
    return(cnt);
}

void print_All(node* head)
{
    node* h = head;
    while(NULL != h)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
    return;
}

node* find_node(node* head, int value)
{
    node* ptr;
    ptr = head;

    while (NULL != ptr)
    {
        if (value == ptr->data)
            return(ptr);
        ptr = ptr->next;
    }
    return(ptr);
}

int main(int argc, char *argv[])
{
    int op;
    int value;
    node* head = NULL;
    node* ptr = NULL;
    node n;

    while (1)
    {
        cin >> op;
        switch(op)
        {
        case 1:
            cin >> value;
            n.data = value;
            ptr = head;
            if (NULL == head)
                head = insert_node(head, NULL, n);
            else
            {
                while(NULL != ptr->next)
                    ptr = ptr->next;
                head = insert_node(head, ptr, n);
            }
            break;
        case 2:
            cin >> value;
            ptr = find_node(head, value);

            if (NULL != ptr)
            {
                head = delete_node(head, ptr);
                cout << "Delete ok" << endl;
            }
            else
                cout << "cannot delete!" << endl;

            break;
        case 3:
            cin >> value;
            ptr = find_node(head, value);

            if (NULL != ptr)
                cout << "found " << value << endl;
            else
                cout << "cannot find value" << endl;
            break;
        case 5:
            cout << lenght_node(head) << endl;
            break;
        case 6:
            print_All(head);
            break;
        case 4:
            return 0;
         }
    }
    return 0;
}
