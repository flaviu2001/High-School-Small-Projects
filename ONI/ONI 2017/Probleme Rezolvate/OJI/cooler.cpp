//Odds are that if you stumble upon this code i don't remember what it does
//I would advise against trying to decipher it, but rather think a solution to the problem yourself

#include <fstream>
#include <vector>

using namespace std;

vector< pair<int, int> > r, u;
int test, n, m, p, v[5005], mx2 = 1, k2 = 1;

int lg[5005], rmq1[18][5005], rmq2[18][5005];

void read()
{
    ifstream fin ("cooler.in");
    fin >> test >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    fin.close();
}

int exists(int x)
{
    for (unsigned i = 0; i < r.size(); ++i)
        if(r[i].first == x){
            p = i;
            return r[i].second;
        }
    return 0;
}

int easy()
{
    int k = 0, mx(0);
    for (int i = 1; i <= m; ++i){
        int ex = exists(v[i]);
        if(!ex){
            if(v[i] > mx)
                mx = v[i];
            ++k;
            r.push_back(make_pair(v[i], 1));
        }else if(ex == 1){
            r[p].second = 2;
            --k;
        }
    }
    if(k == m)
        return mx;
    return k;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void range_minim_query()
{
    lg[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i/2]+1;
    for (int i = 1; i <= n; ++i)
        rmq1[0][i] = rmq2[0][i] = v[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j + (1 << i)-1 <= n; ++j){
            rmq1[i][j] = min(rmq1[i-1][j], rmq1[i-1][j+(1<<(i-1))]);
            rmq2[i][j] = max(rmq2[i-1][j], rmq2[i-1][j+(1<<(i-1))]);
        }
}

int help_difficult(unsigned l, int x)
{
    for (; l < r.size(); ++l)
        if(r[l].first == x){
            return r[l].second + 1;
        }
    return 0;
}

void intervals(int lo, int hi, int pass)
{
    for (int i = lo; i <= hi; ++i)
        for (int j = max(i, pass); j <= hi; ++j){
            int diff = j-i+1;
            int ll = lg[diff];
            int mnn = min(rmq1[ll][i], rmq1[ll][i+diff-(1<<ll)]), mxx = max(rmq2[ll][i], rmq2[ll][i+diff-(1<<ll)]);
            if(mxx-mnn+1 == j-i+1 && j-i+1 > mx2){
                mx2 = j-i+1;
                k2 = 1;
            }else if(mxx-mnn+1 == j-i+1 && j-i+1 == mx2)
                ++k2;
        }
}

void bloody_hell_this_is_difficult()
{
    int l = 0;
    r.push_back(make_pair(v[1], 0));
    u.push_back(make_pair(1, 1));
    for (int i = 2; i <= n; ++i){
        int hlp = help_difficult(l, v[i]);
        if(!hlp){
            ++u[u.size()-1].second;
            r.push_back(make_pair(v[i], i-1));
        }
        else{
            u.push_back(make_pair(hlp+1, i));
            l = hlp;
            r.push_back(make_pair(v[i], i-1));
        }
    }

    int pass = 1;
    for (unsigned i = 0; i < u.size(); ++i){
        intervals(u[i].first, u[i].second, pass);
        pass = u[i].second;
    }
}

int main()
{
    read();
    ofstream fout ("cooler.out");
    if(test == 1){
        fout << easy() << "\n";
        fout.close();
        return 0;
    }
    range_minim_query();
    bloody_hell_this_is_difficult();
    fout << mx2 << "\n" << k2 << "\n";
    fout.close();
    return 0;
}

