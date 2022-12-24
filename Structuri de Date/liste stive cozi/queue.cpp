#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream fin("queue.in");
    ofstream fout("queue.out");

    int n;
    long long nr = 0;
    string curent;
    stack<long long> unu, doi;

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> curent;
        fout << i + 1 << ": ";
        if (curent[1] == 'u') {
            nr = 0;
            for (int i = 10; curent[i] != ')'; i++)
                nr = nr * 10 + (curent[i] - '0');
            unu.push(nr);
            fout << "read(" << nr << ") push(1," << nr << ")\n";
        }
        else {
            if (!doi.empty()) {
                fout << "pop(2) write(" << doi.top() << ")\n";
                doi.pop();
            }
            else
            {
                while (unu.size() > 1) {
                    doi.push(unu.top());
                    fout << "pop(" << 1 << ") push(2," << unu.top() << ") ";
                    unu.pop();
                }
                fout << "pop(1) write(" << unu.top() << ")\n";
                unu.pop();
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}