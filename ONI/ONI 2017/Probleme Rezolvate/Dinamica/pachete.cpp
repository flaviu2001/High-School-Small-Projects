#include <fstream>

using namespace std;

int d[100005], inst[100005], n, v[100005];

int main()
{
    ifstream fin ("pachete.in");
    ofstream fout ("pachete.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> inst[i] >> d[i];

    v[n] = d[n];
    for (int i = n-1; i > 0; --i){
        if(inst[i] >= v[i+1])
            v[i] = d[i];
        else v[i] = d[i] + v[i+1] - inst[i];
    }
    fout << v[1] << "\n";
    fin.close();
    fout.close();
    return 0;
}

