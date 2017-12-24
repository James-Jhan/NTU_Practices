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
        cout << "記憶體不足" << endl;
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

    cout << value << "不是一個正整數" << endl << endl;
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
        cout << "請輸入一個正整數：";
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

        cout << value << " 的因數有 " << cnt << " 個：" << endl;
        for (int i = 0; i < m_Store.size(); ++i)
            cout << m_Store[i] << " ";
        cout << endl << endl;

        str = (true == isPrimeNum) ? " 是質數" : " 不是質數";
        cout << "所以 " << value << str << endl << endl;

        puts("選擇顯示模式：");
        puts("1. 順序印出因數");
        puts("2. 反序印出因數");
        puts("3. 離開");

        cout << endl << "選擇模式：";
        cin >> mode;
        cout << endl;

        switch(mode)
        {
        case 1:
            for (int i = 0; i < m_Store.size(); ++i)
                m_List.insert(m_Store[i], mode);

            cout << "順序列出 " << cnt << " 個因數：" << endl;
            m_List.print();
            break;
        case 2:
            for (int i = 0; i < m_Store.size(); ++i)
                m_List.insert(m_Store[i], mode);

            cout << "反序列出 " << cnt << " 個因數：" << endl;
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
