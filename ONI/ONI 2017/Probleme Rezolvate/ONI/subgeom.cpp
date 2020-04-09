#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int max(int x, int y)
{
    return x > y ? x : y;
}

int subgeom(vector< pair<int, int> > v)
{
    int mx = 1, a[5005];
    int n = v.size();
    vector< pair<int, int> > u = v;
    sort(v.begin(), v.end());
    for (int R = 2; R*R <= 100001; ++R){
        for (int i = 0; i < 5005; ++i)
            a[i] = 1;
        int p1 = 0, p2 = 0;
        while(p2 < n && v[p2].first < v[p1].first * R)
            ++p2;
        while(p2 < n){
            if(v[p2].first == v[p1].first * R){
                int q1 = p1, q2 = p2;
                int sol = 1;
                while(q2 < n && v[q2].first == v[p2].first){
                    while(v[q1].first == v[p1].first && v[q1].second < v[q2].second)
                        sol = max(sol, a[q1++]+1);
                    a[q2] = max(a[q2], sol);
                    ++q2;
                }
                while(v[q1].first == v[p1].first)
                    ++q1;
                p2 = q2;
                p1 = q1;
            }else ++p1;
            while(p2 < n && v[p2].first < v[p1].first * R)
                ++p2;
        }
        for (int i = 0; i < n; ++i)
            mx = max(mx, a[i]);
    }
    if(mx > 1)
        return mx;
    bitset<100005> ok;
    for (int i = 0; i < n; ++i){
        if(ok[u[i].first])
            return 2;
        for (int j = 2*u[i].first; j < 100005; j += u[i].first)
            ok[j] = 1;
    }
    return 1;
}

int main()
{
    ifstream fin ("subgeom.in");
    ofstream fout ("subgeom.out");
    int teste;
    fin >> teste;
    while(teste--){
        vector< pair<int, int> > v;int n;
        fin >> n;
        for (int i = 0; i < n; ++i){
            int x;
            fin >> x;
            v.push_back(make_pair(x, i));
        }
        fout << subgeom(v) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

