#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<char> d[1605], w;
vector<char> sol[1605];

void add_sol(){
    ++m;
    for (int i = 1; i <= n; ++i){
        for (size_t j = 0; j < d[i].size(); ++j)
            sol[m].push_back(d[i][j]);
        sol[m].push_back('\\');
    }
    for (size_t i = 0; i < w.size(); ++i)
        sol[m].push_back(w[i]);
}

void copy_word(int y){
    vector<char> tmp;
    for (size_t i = 0; i < sol[y].size(); ++i)
        tmp.push_back(sol[y][i]);
    sol[y].clear();
    for (size_t i = 0; i < sol[y+1].size(); ++i)
        sol[y].push_back(sol[y+1][i]);
    sol[y+1].clear();
    for (size_t i = 0; i < tmp.size(); ++i)
        sol[y+1].push_back(tmp[i]);
}

int min(int x, int y){
    if (x < y)
        return x;
    return y;
}

int compare(int y){
    int mn = min(sol[y].size(), sol[y+1].size());
    for (int i = 0; i < mn; ++i)
        if (sol[y][i] < sol[y+1][i])
            return 1;
        else if (sol[y][i] > sol[y+1][i])
            return -1;
    if (sol[y].size() < sol[y+1].size())
        return 1;
    if (sol[y].size() > sol[y+1].size())
        return -1;
    return 0;
}

void write(){
    ofstream fout ("dir.out");
    fout << m << "\n";

    bool ok(1);
    while(ok){
        ok = 0;
        for (int i = 1; i < m; ++i)
            if (compare(i) < 0)
                copy_word(i),
                ok = 1;
    }

    for (int i = 1; i <= m; ++i){
        for (size_t j = 0; j < sol[i].size(); ++j)
            fout << sol[i][j];
        fout << "\n";
    }
    fout.close();
}

int main(){
    ifstream fin ("dir.in");
    char q;
    while(fin.good()){
        fin >> q;
        if (q >= 'A' && q <= 'Z'){
            w.clear();
            w.push_back(q);
            do{
                fin >> q;
                w.push_back(q);
            }while((q >= 'A' && q <= 'Z') || (q >= '0' && q <= '9'));
            w.pop_back();

            ++n;
            d[n].clear();
            for (size_t i = 0; i < w.size(); ++i)
                d[n].push_back(w[i]);
        }
        else if (q >= 'a' && q <= 'z'){
            w.clear();
            w.push_back(q);
            do{
                fin >> q;
                w.push_back(q);
            }while((q >= 'a' && q <= 'z') || (q >= '0' && q <= '9'));
            w.pop_back();

            add_sol();

            if (q == ')')
                --n;
        }
        else if (q == ')')
            --n;
        else if (q == ','){
            //The knights who say nii
            //just kidding, the ',' character does nothing in this code
        }
    }
    write();
    return 0;
}
