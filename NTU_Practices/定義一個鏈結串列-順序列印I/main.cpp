#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 5

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

     if (NULL == p)
     {
         cout << "記憶體不足" << endl;
         exit(1);
     }
     return(p);
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

int main(int argc, char *argv[])
{
    node* head = NULL;
    node* ptr;
    int value;
    int i;
    node n;

    for (i = 0; i < N; ++i)
    {
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
    }

    ptr = head;
    if (NULL != ptr)
    {
        for (i = 0; i < N; ++i)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    return 0;
}
