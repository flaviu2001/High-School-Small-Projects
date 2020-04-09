#include <fstream>

using namespace std;

int n, v[500005];
bool ok[500005];

void sequence(int i1)
{
    ok[i1] = 1;
    for (int i = i1+1; i <= n; ++i)
        if(v[i-1] < v[i])
            ok[i] = 1;
        else break;
}

int main()
{
    ifstream fin ("predecesor.in");
    ofstream fout ("predecesor.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            ++k;
            sequence(i);
        }
    fout << k << "\n";
    fin.close();
    fout.close();
    return 0;
}

