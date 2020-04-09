#include <algorithm>
#include <fstream>

using namespace std;

int v[30], r[15], n, p, mx = -1, sol[30];

int numar()
{
    int w[30], pp = 0;
    for (int i = 1; i <= n; ++i)
        if(v[i] != 0)
            w[i] = v[i];
        else w[i] = r[++pp];
    int k = 0;
    while(w[n] != 1){
        ++k;
        reverse(w+n-w[n]+1, w+n+1);
    }
    return k;
}

int main()
{
    ifstream fin ("cubinvers.in");
    ofstream fout ("cubinvers.out");
    fin >> n;
    bool musai[30] = {0};
    for (int i = 1; i <= n; ++i)
        fin >> v[i],
        musai[v[i]] = 1;
    for (int i = 1; i <= n; ++i)
    if(musai[i] == 0)
        r[++p] = i;
    do{
        int k = numar();
        if(k > mx){
            mx = k;
            int pp = 0;
            for (int i = 1; i <= n; ++i)
                if(v[i] != 0)
                    sol[i] = v[i];
                else sol[i] = r[++pp];
        }
    }while(next_permutation(r+1, r+p+1));
    fout << mx << "\n";
    for (int i = 1; i <= n; ++i)
        fout << sol[i] << " ";
    fin.close();
    fout.close();
}

