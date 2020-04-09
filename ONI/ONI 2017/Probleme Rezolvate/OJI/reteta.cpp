#include <cstdio>
#include <vector>

using namespace std;

vector <char> c[105], cc;
int s, n, k, v[105];

void copy_word(int y){
    vector<char> tmp;
    for (size_t i = 0; i < c[y].size(); ++i)
        tmp.push_back(c[y][i]);
    c[y].clear();
    for (size_t i = 0; i < c[y+1].size(); ++i)
        c[y].push_back(c[y+1][i]);
    c[y+1].clear();
    for (size_t i = 0; i < tmp.size(); ++i)
        c[y+1].push_back(tmp[i]);
}

int min(int x, int y){
    if (x < y)
        return x;
    return y;
}


int compare(int y){
    int mn = min(c[y].size(), c[y+1].size());
    for (int i = 0; i < mn; ++i)
        if (c[y][i] < c[y+1][i])
            return 1;
        else if (c[y][i] > c[y+1][i])
            return -1;
    if (c[y].size() < c[y+1].size())
        return 1;
    if (c[y].size() > c[y+1].size())
        return -1;
    return 0;
}

int find_recipe(){
    for (int i = 1; i <= n; ++i){
        if (c[i].size() != cc.size())
            continue;
        bool ok(1);
        for (unsigned j = 0; j < cc.size(); ++j)
            if (c[i][j] != cc[j]){
                ok = 0;
                break;
            }
        if (ok)
            return i;
    }
    return 0;
}

int main(){
    freopen ("reteta.in", "r", stdin);
    freopen ("reteta.out", "w", stdout);
    char q;
    while (!feof(stdin)){
        scanf ("%c", &q);
        if(q >= 'a' && q <= 'z'){
            cc.clear();
            cc.push_back(q);
            do{
                scanf ("%c", &q);
                cc.push_back(q);
            }while(q >= 'a' && q <= 'z');
            cc.pop_back();

            scanf ("%d", &k);
            int m = find_recipe();
            if (!m){
                ++n;
                for (unsigned i = 0; i < cc.size(); ++i)
                    c[n].push_back(cc[i]);
                v[n] += k;
            }else{
                v[m] += k;
            }
        }
        else if (q == ')'){
            scanf ("%d", &k);
            s += k;
        }
    }

    bool ok(1);
    while(ok){
        ok = 0;
        for (int i = 1; i < n; ++i)
            if (compare(i) < 0){
                copy_word(i);
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                ok = 1;
            }
    }
    printf ("%d\n", s);
    for (int i = 1; i <= n; ++i){
        for (unsigned j = 0; j < c[i].size(); ++j)
            printf ("%c", c[i][j]);
        printf (" %d\n", v[i]);
    }
    return 0;
}
