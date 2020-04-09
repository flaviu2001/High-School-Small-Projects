#include <fstream>
#define MAX 100004

using namespace std;

int n, v[55];
bool yay[100005];

int main()
{
    ifstream fin ("monezi2.in");
    ofstream fout ("monezi2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = n; i > 1; --i)
        for (int j = 1; j < i; ++j)
            v[i] += v[j];
    yay[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = v[i]; j <= MAX; ++j)
            if(yay[j-v[i]])
                yay[j] = 1;
    int m;
    fin >> m;
    while(m--){
        int x;
        fin >> x;
        if(yay[x])
            fout << "DA\n";
        else fout << "NU\n";
    }
    fin.close();
    fout.close();
    return 0;
}

