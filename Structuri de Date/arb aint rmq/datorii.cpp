#include <fstream>

using namespace std;

int a[2000000], arb[5000000];

void arbore(int nod, int st, int dr) {
    if (st == dr) {
        arb[nod] = a[st];
        return;
    }
    arbore(2 * nod, st, (st + dr) / 2);
    arbore(2 * nod + 1, (st + dr) / 2 + 1, dr);
    arb[nod] = arb[nod * 2] + arb[nod * 2 + 1];
}

int interogare(int nod, int st, int dr, int i, int j) {
    if (dr < i || st > j) return 0;
    if (dr <= j && st >= i) return arb[nod];
    int m = (st + dr) / 2;
    return interogare(nod * 2, st, m, i, j) + interogare(nod * 2 + 1, m + 1, dr, i, j);
}

void achitare(int nod, int st, int dr, int i, int j) {
    if (i<st || i>dr) return;
    if (st == dr) {
        arb[nod] -= j;
        return;
    }
    int m = (st + dr) / 2;
    if (i <= m) achitare(nod * 2, st, m, i, j);
    else achitare(nod * 2 + 1, m + 1, dr, i, j);
    arb[nod] = arb[nod * 2] + arb[nod * 2 + 1];
}

int main()
{
    ifstream fin("datorii.in");
    ofstream fout("datorii.out");

    int n, m, op, x, y;

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }

    arbore(1, 1, n);

    for (int i = 0; i < m; i++) {
        fin >> op >> x >> y;
        if (!op)
            achitare(1, 1, n, x, y);
        else
            fout << interogare(1, 1, n, x, y) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}