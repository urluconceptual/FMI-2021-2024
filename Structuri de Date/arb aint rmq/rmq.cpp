#include <fstream>

using namespace std;

int a[2000000], arb[5000000];

void rmq(int nod, int st, int dr) {
    if (st == dr) {
        arb[nod] = a[st];
        return;
    }
    rmq(2 * nod, st, (st + dr) / 2);
    rmq(2 * nod + 1, (st + dr) / 2 + 1, dr);
    arb[nod] = min(arb[nod * 2], arb[nod * 2 + 1]);
}

int minim(int nod, int st, int dr, int i, int j) {
    if (dr < i || st > j) return 100001;
    if (dr <= j && st >= i) return arb[nod];
    int m = (st + dr) / 2, minst=100001, mindr=100001;
    if (i <= m) minst = minim(nod * 2, st, m, i, j);
    if (j > m) mindr = minim(nod * 2 + 1, m + 1, dr, i, j);
    return min(minst, mindr);
}

int main()
{
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");

    int n, m, x, y;

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }

    rmq(1, 1, n);

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        fout << minim(1, 1, n, x, y)<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}