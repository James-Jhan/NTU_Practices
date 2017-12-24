#include <iostream>
#include "string"
#include "vector"

using namespace std;

class node
{
    private:
        int data;
        node *next;
        friend class LinkedList;
};

class LinkedList
{
    public:
        LinkedList();
        void insert(int value, int mode);
        void print();
        void Dele();
    private:
        node* getnode();
        void freenode(node *p) ;
        void insert_node(node *ptr, int value, int mode);

        node *head;
};

LinkedList::LinkedList()
{
    head = NULL;
}

node* LinkedList::getnode()
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

void LinkedList::Dele()
{
    free(head);
    head = NULL;
}

void LinkedList::insert(int value, int mode)
{
    node *ptr;

    ptr = head;
    if(head==NULL)
    {
        insert_node(NULL, value, mode);
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        insert_node(ptr, value, mode);
    }
}

void LinkedList::insert_node(node* ptr, int value, int mode)
{
    node* new_node;
    new_node = getnode();
    new_node->data = value;
    new_node->next = (1 == mode) ? NULL : head;

    if (NULL == ptr)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        if (NULL == ptr->next)
        {
            if (1 == mode)
                ptr->next = new_node;
            else
                head = new_node;
        }
        else
        {
            if (1 == mode)
            {
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
        }
    }
}

void LinkedList::print()
{
    node *q = head;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
}

bool isNatureNum(int value)
{
    if (0 < value)
        return true;

    cout << value << "���O�@�ӥ����" << endl << endl;
    system("pause");
    system("cls");
    return false;
}

int main()
{
    int mode;
    int value;
    int cnt;
    bool isPrimeNum;
    string str;
    vector<int> m_Store;

    LinkedList m_List;


    while(1)
    {
        cnt = 0;
        isPrimeNum = true;
        cout << "�п�J�@�ӥ���ơG";
        cin >> value;
        cout << endl;
        if (false == isNatureNum(value))
            continue;

        for (int i = 1; i <= value; ++i)
        {
            if (value%i == 0)
            {
                m_Store.push_back(i);
                if (1 != i && value != i)
                    isPrimeNum = false;
                ++cnt;
            }
        }

        cout << value << " ���]�Ʀ� " << cnt << " �ӡG" << endl;
        for (int i = 0; i < m_Store.size(); ++i)
            cout << m_Store[i] << " ";
        cout << endl << endl;

        str = (true == isPrimeNum) ? " �O���" : " ���O���";
        cout << "�ҥH " << value << str << endl << endl;

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
                m_List.insert(m_Store[i], mode);

            cout << "���ǦC�X " << cnt << " �Ӧ]�ơG" << endl;
            m_List.print();
            break;
        case 2:
            for (int i = 0; i < m_Store.size(); ++i)
                m_List.insert(m_Store[i], mode);

            cout << "�ϧǦC�X " << cnt << " �Ӧ]�ơG" << endl;
            m_List.print();
            break;
        case 3:
            return 0;
        }

        m_List.Dele();
        m_Store.erase(m_Store.begin(), m_Store.begin() + m_Store.size());

        cout << endl << endl;

        system("pause");
        system("cls");
    }


    return 0;
}
