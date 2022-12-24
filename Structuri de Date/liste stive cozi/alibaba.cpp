#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
	ifstream fin("alibaba.in");
	ofstream fout("alibaba.out");

	int n, k;
	char c;
	list<char> nr;
	fin >> n >> k;
	for (int i = 0; i < n; i++) {
		fin >> c;
		while (k > 0 && !nr.empty() && c > nr.back()) {
			nr.pop_back();
			--k;
		}
		nr.push_back(c);
	}

	while (k) {
		nr.pop_back();
		--k;
	}

	while (!nr.empty()) {
		fout << nr.front();
		nr.pop_front();
	}

	fin.close();
	fout.close();
	return 0;
}