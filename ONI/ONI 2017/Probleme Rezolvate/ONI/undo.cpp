#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("undo.in");
ofstream fout ("undo.out");
int vf;
vector<int> v;
vector<int> p[200005];

void add(int x)
{
    while (vf < v.size()){
        p[v.back()].pop_back();
        v.pop_back();
    }
    v.push_back(x);
    p[x].push_back(++vf);
}

void del(int x)
{
    vf -= x;
}

void put_back(int x)
{
    vf += x;
}

void show(int x)
{
    fout << upper_bound(p[x].begin(), p[x].end(), vf) - p[x].begin() << "\n";
}

int main()
{
    int m;
    fin >> m;
    while(m--){
        int t, x;
        fin >> t >> x;
        switch(t){
            case 1:
                add(x);
                break;
            case 2:
                del(x);
                break;
            case 3:
                put_back(x);
                break;
            case 4:
                show(x);
                break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
