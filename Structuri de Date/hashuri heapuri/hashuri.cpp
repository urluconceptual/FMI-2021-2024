#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int h(int x) {
    return x % 999331;
}


int main()
{
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");

    int nr, op;
    long int x;
    vector <list<long int>> hash(999331);
    fin >> nr;
    for (int i = 0; i < nr; i++) {
        fin >> op >> x;
        int lista = h(x);
        auto itr = find(hash[lista].begin(), hash[lista].end(), x);
        switch (op) {
        case 1:
            if (itr == hash[lista].end())
                hash[lista].push_back(x);
            break;
        case 2:
            if (itr != hash[lista].end())
                hash[lista].remove(*itr);
            break;
        case 3:
            if (itr == hash[lista].end())
                fout << "0\n";
            else fout << "1\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}