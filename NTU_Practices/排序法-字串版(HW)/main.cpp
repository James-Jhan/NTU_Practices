#include <iostream>
#include <string.h>

using namespace std;

#define N 6

void print(int n,string* p)
{
    for(int i =0; i < n; ++i)
        cout << p[i] << " ";
    cout << endl;
}

void swap_fun(string* a, string* b)
{
    string temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void BobSort(string* data)
{
    int i;
    int j;

    for(i = N; i > 1; --i)
    {
        for(j = 0; j < i -1; ++j)
        {
            if (data[j+1] > data[j])
                swap_fun(&data[j+1], &data[j]);
        }
        print(N, data);
    }
    print(N, data);
}

void SelSort(string* data)
{
    int i;
    int j;
    int pos;

    for(i = 0; i < N - 1; ++i)
    {
        pos = i;

        for(j = i + 1; j < N; ++j)
        {
            if (data[j] > data[pos])
                pos = j;
        }
        swap_fun(&data[i], &data[pos]);
        print(N, data);
    }
    print(N, data);
}

void Inser_sort(string* data)
{
    string key;
    int i;
    int j;

    for(i = 1; i < N; ++i)
    {
        key = data[i];

        for(j = i - 1; j >= 0 && data[j].compare(key) < 0; --j)
            data[j+1] = data[j];
        data[j+1] = key;
        print(N, data);
    }
    print(N, data);
}

int main(int argc, char *argv[])
{
    int op;
    string data[10] = {};

    for(int i = 0; i < N; ++ i)
        cin >> data[i];

    cin >> op;

    switch(op)
    {
    case 1:
        BobSort(data);
        break;
    case 2:
        SelSort(data);
        break;
    case 3:
        Inser_sort(data);
        break;
    }

    return 0;
}
