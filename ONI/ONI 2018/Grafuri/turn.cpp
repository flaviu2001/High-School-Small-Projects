#include <fstream>
#include <vector>

using namespace std;

struct joe{
    int sz, nd;
}zero, x1, x2;

vector<int> v[10005];
vector<joe> lst;
int n, m;
bool ok[10005];

void dfs(int x)
{
    ok[x] = 1;
    ++lst.back().sz;
    for (unsigned i = 0; i < v[x].size(); ++i)
        if(!ok[v[x][i]])
            dfs(v[x][i]);
}

int main()
{
    ifstream fin ("turn1.in");
    ofstream fout ("turn1.out");
    fin >> n >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if(!ok[i]){
            zero.nd = i;
            lst.push_back(zero);
            dfs(i);
        }
    if(lst.size() == 1)
        fout << "1 2\n";
    else{
        x1 = lst[0];
        x2 = lst[1];
        if(x1.sz < x2.sz)
            swap(x1, x2);
        for (unsigned i = 2; i < lst.size(); ++i)
            if(lst[i].sz > x1.sz){
                x2 = x1;
                x1 = lst[i];
            }else if (lst[i].sz > x2.sz)
                x2 = lst[i];
        fout << x1.nd << " " << x2.nd << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
