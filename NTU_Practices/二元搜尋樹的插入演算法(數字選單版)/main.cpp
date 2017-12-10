#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 5

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node node;

void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        cout << ptr->data << " ";
        print_inorder(ptr->right);
    }
}

void print_preorder(node* ptr)
{
    if (NULL != ptr)
    {
        cout << ptr->data << " ";
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void print_posorder(node* ptr)
{
    if (NULL != ptr)
    {
        print_posorder(ptr->left);
        print_posorder(ptr->right);
        cout << ptr->data << " ";
    }
}

node* insert_node(node* root, int value)
{
    node* new_node;
    node* current;
    node* parent;

    new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (NULL == root)
        return(new_node);
    else
    {
        current = root;

        while(NULL != current)
        {
            parent = current;

            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

int main(int argc, char *argv[])
{
    int op;
    int value;
    node* root = NULL;

    while (1)
    {
        cin >> op;
        switch(op)
        {
        case 1:
            cin >> value;
            root = insert_node(root, value);
            break;
        case 2:
            print_inorder(root);
            cout << endl;
            break;
        case 3:
            print_preorder(root);
            cout << endl;
            break;
        case 4:
            print_posorder(root);
            cout << endl;
            break;
        case 8:
            return 0;
         }
    }
    return 0;
}
