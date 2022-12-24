#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream fin("deque.in");
    ofstream fout("deque.out");

    long long int suma = 0;
    int n, k, curent, * minim = nullptr, * poz = nullptr, inceput = 1, final = 0;

    fin >> n >> k;
    minim = new int[n];
    poz = new int[n];

    for (int i = 1; i <= n; i++) {
        fin >> curent;
        while (final >= inceput && minim[final] >= curent) final--;
        final++;
        poz[final] = i;
        minim[final] = curent;
        if (poz[inceput] <= i - k) inceput++;
        if (i >= k) suma += minim[inceput];
    }
    fout << suma;
    fin.close();
    fout.close();
}