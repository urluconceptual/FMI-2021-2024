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
    arb[nod] = max(arb[nod * 2], arb[nod * 2 + 1]);
}

int maxim(int nod, int st, int dr, int i, int j) {
    if (dr < i || st > j) return 0;
    if (dr <= j && st >= i) return arb[nod];
    return max(maxim(nod * 2, st, (st + dr) / 2, i, j), maxim(nod * 2 + 1, (st + dr) / 2 + 1, dr, i, j));
}

void schimb(int nod, int st, int dr, int i, int j) {
    if (i<st || i>dr) return;
    if (st == dr) {
        arb[nod] = j;
        return;
    }
    if (i <= (st + dr) / 2) schimb(nod * 2, st, (st + dr) / 2, i, j);
    else schimb(nod * 2 + 1, (st + dr) / 2 + 1, dr, i, j);
    arb[nod] = max(arb[nod * 2], arb[nod * 2 + 1]);
}

int main()
{
    ifstream fin("arbint.in");
    ofstream fout("arbint.out");

    int n, m, op, x, y;

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }

    arbore(1, 1, n);

    for (int i = 0; i < m; i++) {
        fin >> op >> x >> y;
        if (!op)
            fout << maxim(1, 1, n, x, y) << "\n";
        else schimb(1, 1, n, x, y);
    }

    fin.close();
    fout.close();
    return 0;
}