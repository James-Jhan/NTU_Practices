#include <iostream>

using namespace std;

void hanoi (int n, char from, char mid, char to,int *cnt)
{
    if(n==0)
        return ;
    hanoi(n-1,from, to, mid, cnt);
    cout << "plate " << n << " from " << from << " -> " << to << endl;
    cnt[n-1]++;
    hanoi(n-1,mid, from, to, cnt);
}

int main()
{
    int num;
    int i;
    int cnt[100] = {0};

    cin >> num;
    hanoi(num, 'A', 'B', 'C', cnt);
    cout << endl;
    for (i = 0; i < num; ++i)
        cout << "plate " << i+1 << " = " << cnt[i] << endl;

    return 0;
}
