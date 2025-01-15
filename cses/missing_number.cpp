#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int logical_xor = 0;
	for (int i = 1; i <=n; ++i)
	{
		/* code */
		logical_xor ^= i;
	}
	for (int i = 0; i < n-1; ++i) {
		int a;
		cin >> a;
		logical_xor ^= a;
	}
	cout << logical_xor;
	return 0;
}
