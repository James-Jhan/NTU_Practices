#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    string data_name;
    string data_phone;
    struct Node* left;
    struct Node* right;
};
typedef struct Node node;

void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        cout << "Name: "<< ptr->data_name << endl;
        cout << "Phone: " << ptr->data_phone << endl << endl;
        print_inorder(ptr->right);
    }
}

void print_preorder(node* ptr)
{
    if (NULL != ptr)
    {
        cout << "Name: "<< ptr->data_name << endl;
        cout << "Phone: " << ptr->data_phone << endl << endl;
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
        cout << "Name: "<< ptr->data_name << endl;
        cout << "Phone: " << ptr->data_phone << endl << endl;
    }

}

node* insert_node(node* root, string* name, string* phone)
{
    node* new_node;
    node* current;
    node* parent;

    new_node = (node*)malloc(sizeof(node));
    new_node->data_name = *name;
    new_node->data_phone = *phone;
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

            if (*name < current->data_name)
                current = current->left;
            else
                current = current->right;
        }

        if (*name < parent->data_name)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

node *find_parent(node *ptr, string name, int *pos)
{
    node *parent;

    parent = ptr;
    *pos = 0;
    while(ptr != NULL)
    {
        if(ptr->data_name == name)
            return parent;
        else
        {
            parent = ptr;
            if(ptr->data_name > name)
            {
                *pos = -1;
                ptr = ptr->left;
            }
            else
            {
                *pos = 1;
                ptr = ptr->right;
            }
        }
    }
    return NULL;
}

node *delete_node(node *root, string name)
{
    node *parent;
    node *ptr;
    node *next;
    int pos;

    parent = find_parent(root, name, &pos);
    if(parent != NULL)
    {
        switch(pos)
        {
            case -1:
                ptr = parent->left;
                break;
            case 1:
                ptr = parent->right;
                break;
            case 0:
                ptr = parent;
                break;
        }

        if(ptr->left == NULL)
        {
            if(parent == ptr)
                root = root->right;
            else
            {
                if( pos == 1 )
                    parent->right = ptr->right;
                else
                    parent->left = ptr->right;
            }
            free(ptr);
        }
        else if(ptr->right == NULL)
        {
            if(parent != ptr)
            {
                if( pos == 1 )
                    parent->right = ptr->left;
                else
                    parent->left = ptr->left;
            }
            else
                root = root->left;
            free(ptr);
        }
        else
        {
            parent = ptr;
            next = ptr->left;
            if (next->right != NULL)
            {
                while(next->right != NULL)
                {
                    parent = next;
                    next = next->right;
                }

                parent->right = next->left;
            }
            else
                ptr->left = next->left;

            ptr->data_name = next->data_name;
            ptr->data_phone = next->data_phone;
            free(next);
        }
    }
    return root;
}

node *find_node(node *ptr, string name)
{
    while(ptr != NULL)
    {
        if(ptr->data_name == name)
            return ptr;
        else
        {
            if(ptr->data_name > name)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    char op;
    node* ptr;
    string name;
    string phone;
    node* root = NULL;

    while (1)
    {
        cin >> op;
        switch(op)
        {
        case 'i':
            cin >> name;
            cin >> phone;
            root = insert_node(root, &name, &phone);
            break;
        case 'd':
            cin >> name;
            ptr = find_node(root, name);
            if (ptr != NULL)
            {
                root = delete_node(root, name);
                cout << "delete " << name << " ok" << endl << endl;
            }
            else
                cout << "cannot delete" << endl;
            break;
        case 'l':
            print_inorder(root);
            break;
        case 'm':
            print_preorder(root);
            break;
        case 'n':
            print_posorder(root);
            break;
        case 'f':
            cin >> name;
            ptr = find_node(root, name);
            if (ptr != NULL)
            {
                cout << "found:" << endl;
                cout << "Name: " << ptr->data_name << endl;
                cout << "Phone: " << ptr->data_phone << endl << endl;
            }
            else
                cout << "not found" << endl;
               break;
        case 'q':
            return 0;
         }
    }

    return 0;
}
