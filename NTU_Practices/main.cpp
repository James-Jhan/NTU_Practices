#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
	string str = "";
	string mark = "*";
	string result = "";

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		str += mark;
	}

	for (int i = 0; i < cnt; ++i)
	{
		cout << result.assign(str, 0, cnt - i) << endl;
	}

	return 0;
}
