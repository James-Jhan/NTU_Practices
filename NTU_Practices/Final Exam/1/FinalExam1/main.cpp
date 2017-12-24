#include <iostream>
#include "string"
#include "vector"

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
         cout << "�O���餣��" << endl;
         exit(1);
     }
     return(p);
 }

node* insert_Pnode(node* head, node* ptr, node data)
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

node* insert_Nnode(node* head, node* ptr, node data)
{
    node* new_node;
    new_node = getnode();
    *new_node = data;
    new_node->next = head;

    if (NULL == ptr)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        if (NULL == ptr->next)
            head = new_node;
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    return(head);
}


int main()
{
    int mode;
    int value;
    bool isPrimeNum;
    string str;
    vector<int> m_Store;

    node* head = NULL;
    node* ptr;
    node n;


    while(1)
    {
        isPrimeNum = true;
        cout << "�п�J�@�ӥ���ơG";
        cin >> value;
        cout << endl;
        if (value <0 || value == 0)
        {
            cout << value << "���O�@�ӥ����" << endl << endl;
            system("pause");
            system("cls");
            continue;
        }

        for (int i = 1; i <= value; ++i)
        {
            if (value%i == 0)
            {
                m_Store.push_back(i);
                if (1 != i && value != i)
                    isPrimeNum = false;
            }
        }

        cout << value << "���]�Ʀ��G";
        for (int i = 0; i < m_Store.size(); ++i)
            cout << m_Store[i] << " ";
        cout << endl;

        str = (true == isPrimeNum) ? "�O���" : "���O���";
        cout << value << str << endl << endl;

        puts("�����ܼҦ��G");
        puts("1. ���ǦL�X�]��");
        puts("2. �ϧǦL�X�]��");
        puts("3. ���}");

        cout << endl << "��ܼҦ��G";
        cin >> mode;
        cout << endl;

        switch(mode)
        {
        case 1:
            for (int i = 0; i < m_Store.size(); ++i)
            {
                n.data = m_Store[i];
                ptr =head;

                if (NULL == head)
                    head = insert_Pnode(head, NULL, n);
                else
                {
                    while(NULL != ptr->next)
                        ptr = ptr->next;
                    head = insert_Pnode(head, ptr, n);
                }
            }

            ptr = head;
            cout << "���ǦC�X�]�ơG" << endl;
            if (NULL != ptr)
            {
                while (NULL != ptr)
                {
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
            }
            break;
        case 2:
            for (int i = 0; i < m_Store.size(); ++i)
            {
                n.data = m_Store[i];
                ptr =head;

                if (NULL == head)
                    head = insert_Nnode(head, NULL, n);
                else
                {
                    while(NULL != ptr->next)
                        ptr = ptr->next;
                    head = insert_Nnode(head, ptr, n);
                }
            }

            ptr = head;
            cout << "�ϧǦC�X�]�ơG" << endl;
            if (NULL != ptr)
            {
                while (NULL != ptr)
                {
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
            }
            break;
        case 3:
            return 0;
        }

        head = NULL;
        m_Store.erase(m_Store.begin(), m_Store.begin() + m_Store.size());

        cout << endl << endl;

        system("pause");
        system("cls");
    }


    return 0;
}
