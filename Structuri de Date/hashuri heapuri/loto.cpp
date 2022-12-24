#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

struct grup {
	int i, j, k;
};

int main()
{
	ifstream fin("loto.in");
	ofstream fout("loto.out");

	int nr, suma, * v, s, d, gasit=0;
	unordered_map <int, grup> bilet;
	fin >> nr >> suma;
	v = new int[nr];
	for (int i = 0; i < nr; i++) {
		fin >> v[i];
	}
	for (int i = 0; i < nr; i++)
		for (int j = i; j < nr; j++)
			for (int k = j; k < nr; k++) {
				grup x;
				x.i = v[i];
				x.j = v[j];
				x.k = v[k];
				s = x.i + x.j + x.k;
				bilet[s] = x;
			}
	for (auto itr1 = bilet.begin(); itr1 != bilet.end() && gasit == 0; itr1++) {
		d = suma - (itr1->first);
			if (bilet.find(d)!=bilet.end()) {
				auto itr2 = bilet.find(d);
				fout << (itr1->second).i << " " << (itr1->second).j << " " << (itr1->second).k << " " << (itr2->second).i << " " << (itr2->second).j << " " << (itr2->second).k;
				gasit = 1;
			}
		}
	if (!gasit)
		fout << -1;

	delete[] v;
	fin.close();
	fout.close();
}