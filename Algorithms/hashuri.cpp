#include <fstream>
#include <vector>
#define M 666013

using namespace std;

vector<int> v[666100];
int m;

int hsh(int x)
{
    double y = 0.618033;
    double xy = (double)x * y;
    xy -= (int) xy;
    double ans = xy * M;
    return (int) ans;
}

int find_val(int x)
{
    int lst = hsh(x);
    for (unsigned i = 0; i < v[lst].size(); ++i)
        if(x == v[lst][i])
            return 1;
    return 0;
}

void insert_val(int x)
{
    int lst = hsh(x);
    for (unsigned i = 0; i < v[lst].size(); ++i)
        if(v[lst][i] == x)
            return;
    v[lst].push_back(x);
}

void erase_val (int x)
{
    int lst = hsh(x);
    for(unsigned i = 0; i < v[lst].size(); ++i)
        if(v[lst][i] == x)
            v[lst].erase(v[lst].begin()+i);
}

int main()
{
    ifstream fin ("hashuri.in");
    ofstream fout ("hashuri.out");
    fin >> m;
    while(m--){
        int test, x;
        fin >> test >> x;
        switch(test){
            case 1:
                insert_val(x);
                break;
            case 2:
                erase_val(x);
                break;
            case 3:
                fout << find_val(x) << "\n";
                break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

