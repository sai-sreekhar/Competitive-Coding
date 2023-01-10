#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1>
void myPrint(T1 *arr, int n)
{
	cout << "myPrint Function output is: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void printTrace(int line, const char *fileName, const char *msg, ...)
{
	va_list args;
	char buffer[1024 + 2] = {0};
	snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
	int stringLength = strnlen(buffer, 1024);
	int remainingBufferSize = 1024 - stringLength;
	va_start(args, msg);
	vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
	va_end(args);
	cout << buffer << "\n"
		 << flush;
}

void solve()
{
	int n;
	cin >> n;

	int arr[n + 1];
	int visited[n + 1];

	for (int i = 1; i < n + 1; i++)
	{
		cin >> arr[i];
		visited[i] = 0;
	}

	int cycles = 0;

	vector<int> links(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			int j = arr[i];

			cycles++;
			links[i] = cycles;
			while (visited[j] != 1)
			{
				visited[j] = 1;
				links[j] = cycles;
				j = arr[j];
			}
		}
	}

	// for (int i = 1; i < n + 1; i++)
	// {
	// 	cout << links[i] << " ";
	// }
	// cout << cycles << "\n";

	int mini = INT_MAX;
	for (int k = 1; k <= n - 1; k++)
	{
		int val1 = k;
		int val2 = k + 1;
		if (links[val1] != links[val2])
		{
			mini = min(mini, n - (cycles - 1));
		}
		else
		{
			mini = min(mini, n - (cycles + 1));
		}
	}

	cout << mini << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}