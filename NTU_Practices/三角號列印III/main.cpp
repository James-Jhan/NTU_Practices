#include <iostream>
#include <string>

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

	for (int i = 0; i < cnt; ++i)
	{
		cout << result << endl;
		result[i] = ' ';
	}

	return 0;
}
