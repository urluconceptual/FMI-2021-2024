#include <fstream>
#include <queue>

using namespace std;

int main()
{
	ifstream fin("proc2.in");
	ofstream fout("proc2.out");

	priority_queue <int> plib;
	priority_queue <pair<int,int>> pocup;
	int n, m, s, d;

	fin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		plib.push(-i);
	}

	for (int i = 0; i < m; i++)
	{
		fin >> s >> d;
		s = 0 - s;
		while (!pocup.empty() && pocup.top().first >= s)
		{
			plib.push(-pocup.top().second);
			pocup.pop();
		}
		pocup.push({ s - d, -plib.top() });
		fout << -plib.top() << '\n';
		plib.pop();
	}

	fin.close();
	fout.close();

	return 0;
}