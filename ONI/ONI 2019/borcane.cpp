#include <bits/stdc++.h>

using namespace std;

struct thing{
    int i, f;
    bool operator<(const thing &obj)const{
        if(f != obj.f)
            return -f < -obj.f;
        return i < obj.i;
    }
};

const int inf = 2000000000;

int n, v[105];
set<thing> s;

int main()
{
    ifstream fin ("borcane.in");
    ofstream fout ("borcane.out");
    fin >> n;
    int mn = inf, last;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        if(v[i] < mn){
            mn = v[i];
            last = i;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        if(i != last){
            s.insert({i, v[i]});
            sum += v[i];
        }
    while(s.begin()->f != 0){
        int x1 = s.begin()->f, i1 = s.begin()->i;
        set<thing>::iterator it = s.begin();
        ++it;
        int x2 = it->f, i2 = it->i;
        if(x2 == 0){
            fout << last << " " << i1 << " " << i2 << "\n";
            s.erase(s.find({i1, v[i1]}));
            s.erase(s.find({i2, v[i2]}));
            --v[last];
            --v[i1];
            v[i2] += 2;
            ++sum;
            s.insert({i1, v[i1]});
            s.insert({i2, v[i2]});
            continue;
        }
        if(x1 == 2 && x2 == 1 && sum == 3){
            ++it;
            int i3 = it->i;
            fout << last << " " << i1 << " " << i3 << "\n";
            s.erase(s.find({i1, v[i1]}));
            s.erase(s.find({i3, v[i3]}));
            --v[last];
            --v[i1];
            v[i3] += 2;
            ++sum;
            s.insert({i1, v[i1]});
            s.insert({i3, v[i3]});
            continue;
        }
        s.erase(s.find({i1, v[i1]}));
        s.erase(s.find({i2, v[i2]}));
        mn = min(v[i1], v[i2]);
        v[i1] -= mn;
        v[i2] -= mn;
        v[last] += mn*2;
        sum -= mn*2;
        s.insert({i1, v[i1]});
        s.insert({i2, v[i2]});
        for (int i = 1; i <= mn; ++i)
            fout << i1 << " " << i2 << " " << last << "\n";
    }
    return 0;
}
