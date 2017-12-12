#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "string.h"

using namespace std;

struct Node
{
    char name[128];
    char mail[128];
    char phone[128];
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
        cout << h->name << endl;
        cout << h->mail << endl;
        cout << h->phone << endl;
        cout << endl;
        h = h->next;
    }
    return;
}

node* find_node(node* head, char name[])
{
    node* ptr;
    ptr = head;
    while (NULL != ptr)
    {
        if (0 == strcmp(name, ptr->name))
            return(ptr);
        ptr = ptr->next;
    }
    return(ptr);
}

int main(int argc, char *argv[])
{
    char op;
    char name[128];
    char mail[128];
    char phone[128];
    node* head = NULL;
    node* ptr = NULL;
    node n;
    int cnt;
    int temp;
    while (1)
    {
        cnt = 0;
        cin >> op;
        switch(op)
        {
        case 'i':
            cin >> name;
            cin >> mail;
            cin >> phone;

            for (int i =0; i < 10; ++i)
            {
                if ('\0' == phone[i] && 0 == cnt)
                    cnt = i;
            }

            if (0 != cnt)
            {
                temp = cnt - 1;
                for (int i = 9; i > (9 - cnt); --i)
                {
                    phone[i] = phone[temp];
                    temp--;
                }
                for (int i = 0; i < 10 - cnt; ++i)
                    phone[i] = '0';
                phone[10] = '\0';
            }
            strcpy(n.name, name);
            strcpy(n.mail, mail);
            strcpy(n.phone, phone);
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
        case 'd':
            cin >> name;
            ptr = find_node(head, name);

            if (NULL != ptr)
            {
                head = delete_node(head, ptr);
                cout << "Delete ok" << endl;
            }
            else
                cout << "cannot delete!" << endl;

            break;
        case 'f':
            cin >> name;
            ptr = find_node(head, name);

            if (NULL != ptr)
            {
                cout << "found"<< endl;
                cout << ptr->name << endl;
                cout << ptr->mail << endl;
                cout << ptr->phone << endl;
            }
            else
                cout << "cannot find value" << endl;
            cout << endl;
            break;
        case 'l':
            print_All(head);
            break;
        case 'q':
            return 0;
         }
    }
    return 0;
}
