#include <fstream>

using namespace std;

pair<int, int> arb[500001];
int reg1[500001], reg2[500001], n, k=1;


void arbore(int rad, int st, int dr) {
    if (reg1[rad] > st) {
        k++;
        arb[rad].first = reg2[k];
        arbore(reg2[k], st, reg1[rad] - 1);
    }
    if (reg1[rad] < dr) {
        k++;
        arb[rad].second = reg2[k];
        arbore(reg2[k], reg1[rad]+ 1, dr);
    }
}

int main()
{
    ifstream fin("curatenie.in");
    ofstream fout("curatenie.out");

    fin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        fin >> x;
        reg1[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        int x;
        fin >> x;
        reg2[i] = x;
    }

    arbore(reg2[1], 1, n);

    for (int i = 1; i <= n; i++) {
        fout << arb[i].first << " " << arb[i].second << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}