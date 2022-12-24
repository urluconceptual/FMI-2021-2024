#include <fstream>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream fin("muzica.in");
    ofstream fout("muzica.out");

    long long int n, m, A, B, C, D, E, nr = 0, aux;
    unordered_set <long long int> playlist(100001);

    fin >> n >> m >> A >> B >> C >> D >> E;

    for (int i = 0; i < n; i++) {
        fin >> aux;
        if (aux == A || aux == B) {
            nr++;
        }
        else
            playlist.insert(aux);
    }

    for (int i = 3; i <= m; i++) {
        aux = (C * B + D * A) % E;
        if (playlist.find(aux) != playlist.end()) {
            playlist.erase(aux);
            nr++;
        }

        A = B;
        B = aux;
    }

    fout << nr;

    fin.close();
    fout.close();

    return 0;
}