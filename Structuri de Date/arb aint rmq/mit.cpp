#include <fstream>

using namespace std;

int arb[500000], bonusuri[500000];

void arbore(int nod, int st, int dr, int poz, int a) {
    if (poz<st || poz>dr) return;
    if (st == dr) {
        arb[nod] = a;
        return;
    }
    arbore(2 * nod, st, (st + dr) / 2, poz, a);
    arbore(2 * nod + 1, (st + dr) / 2 + 1, dr, poz, a);
    arb[nod] = max(arb[nod * 2], arb[nod * 2 + 1]);
}

int maxim(int nod, int st, int dr, int i, int j) {
    if (dr < i || st > j) return 0;
    if (dr <= j && st >= i) return arb[nod]+bonusuri[nod];
    int m = (st + dr) / 2;
    return max(maxim(nod * 2, st, m, i, j), maxim(nod * 2 + 1, m + 1, dr, i, j)) + bonusuri[nod];
}

void bonus(int nod, int st, int dr, int i, int j, int plus) {
    if (j<st || i>dr) return;
    if (st >= i && dr <= j) {
        bonusuri[nod] += plus;
        return;
    }
    int m = (st + dr) / 2;
    bonus(nod * 2, st, m, i, j, plus);
    bonus(nod * 2 + 1, m + 1, dr, i, j, plus);
    arb[nod] = max(arb[nod * 2] + bonusuri[nod * 2], arb[nod * 2 + 1] + bonusuri[nod * 2 + 1]);
}

int main()
{
    ifstream fin("mit.in");
    ofstream fout("mit.out");

    int n, m, op, x, y, plus, a;

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> a;
        arbore(1, 1, n, i, a);
    }

    for (int i = 0; i < m; i++) {
        fin >> op >> x >> y;
        switch (op) {
        case 1:
            fout << maxim(1, 1, n, x, y) << "\n";
            break;
        case 2:
            fin >> plus;
            bonus(1, 1, n, x, y, plus);
        }
    }

    fin.close();
    fout.close();
    return 0;
}