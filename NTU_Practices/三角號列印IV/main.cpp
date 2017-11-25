#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int cnt = 0;
    char result[256] = "";

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		result[i] = '*';
	}

    char buf[256];

	for (int i = 0; i < cnt; ++i)
	{
	    strcpy(buf, result);
	    for (int j = 0; j < (cnt - 1) - i; ++j)
            buf[j] = ' ';
		cout << buf << endl;
	}

	return 0;
}
