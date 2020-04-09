#include <fstream>
#include <vector>

using namespace std;

int n, l, langs[25][15], vlg[25], sol, sz;
bool graf[25][25];

void read()
{
    ifstream fin ("dineu.in");
    fin >> n >> l;
    for (int i = 1; i <= n; ++i){
        fin >> vlg[i];
        for (int j = 1; j <= vlg[i]; ++j){
            fin >> langs[i][j];
        }
    }
    fin.close();
}

bool common_lang(int i1, int i2)
{
    for (int i = 1; i <= vlg[i1]; ++i)
        for (int j = 1; j <= vlg[i2]; ++j)
            if(langs[i1][i] == langs[i2][j])
                return true;
    return false;
}

void make_graf()
{
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if(common_lang(i, j)){
                graf[i][j] = 1;
                graf[j][i] = 1;
            }
}

int check_sol(int x)
{
    bool v[25] = {0};
    int p = 0;
    for (int i = 1 << (n-1); i > 0; i /= 2, ++p){
        if(x >= i){
            v[p] = 1;
            x -= i;
        }
    }
    vector<int> r;
    for (int i = 0; i < n; ++i)
        if(v[i])
            r.push_back(i+1);
    for (unsigned i = 0; i < r.size()-1; ++i)
        for (unsigned j = i+1; j < r.size(); ++j)
            if(!graf[r[i]][r[j]])
                return 0;
    return r.size();
}

void bkt()
{
    for (int i = (1 << n) - 1; i > (1<<sz); --i){
        int z = check_sol(i);
        if(z > sz){
            sz = z;
            sol = i;
        }
    }
}

void write()
{
    ofstream fout ("dineu.out");
    fout << sz << "\n";

    bool v[25] = {0};
    int p = 0;
    for (int i = 1 << (n-1); i > 0; i /= 2, ++p){
        if(sol >= i){
            v[p] = 1;
            sol -= i;
        }
    }
    for (int i = 0; i < n; ++i)
        if(v[i])
            fout << i+1 << " ";
    fout.close();
}

int main()
{
    read();
    make_graf();
    bkt();
    write();
    return 0;
}

