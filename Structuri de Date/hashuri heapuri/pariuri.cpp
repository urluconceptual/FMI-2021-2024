#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin("pariuri.in");
    ofstream fout("pariuri.out");

    unordered_map <int, int> castig;
    int n, m, timp, bani;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> m;
        for (int j = 0; j < m; j++) {
            fin >> timp >> bani;
            if (castig.find(timp) != castig.end()) {
                castig[timp] += bani;
            }
            else
                castig.insert({ timp, bani });
        }
    }
    fout << castig.size() << "\n";
    for (auto x : castig) {
        fout << x.first << " " << x.second << " ";
    }

    fin.close();
    fout.close();

    return 0;
}