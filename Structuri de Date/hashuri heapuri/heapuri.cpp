#include <fstream>
#include <set>

using namespace std;

int main()
{
    ifstream fin("heapuri.in");
    ofstream fout("heapuri.out");

    unsigned int pozitie[200001], n, poz=1, op, x;
    set <unsigned int> heap;

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> op;
        switch (op)
        {
        case 1:
            fin >> x;
            heap.insert(x);
            pozitie[poz++] = x;
            break;
        case 2:
            fin >> x;
            heap.erase(pozitie[x]);
            break;
        case 3:
            fout << *(heap.begin()) << "\n";
        }
    }

    fin.close();
    fout.close();

    return 0;
}