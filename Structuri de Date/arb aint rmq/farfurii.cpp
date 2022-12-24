#include <fstream>

using namespace std;

int main()
{
    ifstream fin("farfurii.in");
    ofstream fout("farfurii.out");

    long long int n, k, i, nr;

    fin >> n >> k;

    for (i = 1; i <= n; i++) {
        if (i * (i + 1) / 2 >= k)
            break;
    }

    for (int j = 1; j < n - i; j++) {
        fout << j << " ";
    }

    nr = n - (i * (i + 1) / 2) + k;
    fout << nr << " ";

    for (int j = n; j >= n - i; j--) {
        if (j != nr) {
            fout << j << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}