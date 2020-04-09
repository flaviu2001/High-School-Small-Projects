#include <fstream>
#include <algorithm>

using namespace std;

struct data{
    long long x, y;
    long long up, rt;
    bool can_form;
}dt;

long long n;
data v[50005];

bool cmp(data v1, data v2)
{
    if(v1.x < v2.x)
        return true;
    if(v1.x > v2.x)
        return false;
    if(v1.y < v2.y)
        return true;
    return false;
}

long long max(long long x, long long y)
{
    return x > y ? x : y;
}

int main()
{
    ifstream fin ("cabana2.in");
    ofstream fout ("cabana2.out");
    fin >> n;
    for (long long i = 1; i <= n; ++i)
        fin >> v[i].x >> v[i].y;
    sort(v+1, v+n+1, cmp);

    for (long long i = 1; i <= n; ++i){
        if(v[i].x != v[i+1].x)
            continue;
        long long lo = v[i].y, hi = v[i+1].y;
        v[i].up = i+1;
        bool ok = 1;
        for (long long j = i+1; j <= n && ok; ++j){
            if(v[j].x != v[i].x && v[j].y > lo && v[j].y <= hi)
                ok = 0;
            if(v[j].x != v[i].x && v[j].y == lo){
                v[i].rt = j;
                break;
            }
        }
        if(!ok)
            continue;
        v[i].can_form = 1;
    }
    long long mx = 0;
    for (long long i = 1; i <= n; ++i)
        if(v[i].can_form)
            if(v[v[i].up].y ==  v[v[v[i].rt].up].y)
                mx = max(mx, (v[v[i].up].y - v[i].y) * (v[v[i].rt].x - v[i].x) );
    fout << mx << "\n";
    fin.close();
    fout.close();
    return 0;
}

