#include <fstream>
#include <vector>

using namespace std;

vector<int> langs[30], v[30], sol;
int n, m;
bool graf[30][30];

void cpy(vector<int> &x1, vector<int> x2)
{
    x1.clear();
    for (unsigned i = 0; i < x2.size(); ++i)
        x1.push_back(x2[i]);
}

void bkt(vector<int> r)
{
    int x = r.back();
    for (unsigned i = 0; i < r.size()-1; ++i)
        if(!graf[x][r[i]])
            return;
    if(sol.size() < r.size())
        cpy(sol, r);
    for (int i = x+1; i <= n; ++i){
        r.push_back(i);
        bkt(r);
        r.pop_back();
    }
}

int main()
{
    ifstream fin ("dineu.in");
    ofstream fout ("dineu.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        while(x--){
            int y;
            fin >> y;
            langs[i].push_back(y);
        }
        for (int j = 1; j < i; ++j){
            bool ok = 1;
            for (unsigned t1 = 0; t1 < langs[i].size() && ok; ++t1)
                for (unsigned t2 = 0; t2 < langs[j].size() && ok; ++t2)
                    if(langs[i][t1] == langs[j][t2]){
                        ok = 0;
                        v[i].push_back(j);
                        v[j].push_back(i);
                        graf[i][j] = graf[j][i] = 1;
                    }
        }
    }
    for (int i = 1; i <= n; ++i){
        vector<int> r;
        r.push_back(i);
        bkt(r);
    }
    fout << sol.size() << "\n";
    for (unsigned i = 0; i < sol.size(); ++i)
        fout << sol[i] << " ";
    fin.close();
    fout.close();
    return 0;
}

