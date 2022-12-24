#include <iostream>
#include <stack>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream fin("paranteze.in");
    ofstream fout("paranteze.out");


    char paranteza;
    int n, lungime = 0, maxim = 0;
    stack<pair<char,int>> stiva;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> paranteza;
        pair<char, int> pereche;
        pereche.first = paranteza;
        pereche.second = i;
        if (strchr("{[(", paranteza)) {
            stiva.push(pereche);
        }
        else
            if (!stiva.empty()) {
                if ((stiva.top().first == '(' && paranteza == ')') || (stiva.top().first == '[' && paranteza == ']') || (stiva.top().first == '{' && paranteza == '}')) {
                    stiva.pop();
                    if (!stiva.empty()) {
                        lungime = i - stiva.top().second;
                        if (lungime > maxim) maxim = lungime;
                    }
                    else maxim = i + 1;
                }
                else
                    stiva.push(pereche);
            }
    }
    fout << maxim;
    fin.close();
    fout.close();
    return 0;
}