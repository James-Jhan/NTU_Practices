#include <iostream>

using namespace std;

int BinarySearch(int n, string *p, string value)
{
    int low=0, high=n, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        cout << mid << ": " << p[mid] << endl;
        if(p[mid] > value)
            high = mid - 1;
        else if(p[mid] < value)
            low = mid+1;
        else
        {
            cout << "found: " << p[mid] << endl;
            return mid;
        }
    }
    cout << "not found " << value << endl;
    return -1;
}

int LinearSearch(int n, string *p, string value)
{
    int i;
    for(i=0; i< n; i++)
    {
        cout << i << ": " << p[i] << endl;;
        if(p[i] == value)
        {
            cout << "found: " << value << endl;
            return i;
        }
    }
    cout << "not found " << endl;
    return -1;
}

int main()
{
    int j, i;
    int op;
    int n = 0;
    string value;
    string data[10] = {};
    int pos;

    while(1)
    {
        cin >> op;

        switch(op)
        {
            case 1:
                cin >> value;
                if (0 == n)
                    data[0] = value;

                for(j=n-1; j>=0 && data[j]>value; j--)
                {
                    data[j+1] = data[j];
                }
                ++n;
                data[j+1] = value;
                break;
            case 2:
                cin >> value;
                LinearSearch(n, data, value);
                break;
            case 3:
                cin >> value;
                BinarySearch(n, data, value);
                break;
            case 4:
                for (i = 0; i < n; ++i)
                    cout << data[i] << " ";

                cout << endl;
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}
