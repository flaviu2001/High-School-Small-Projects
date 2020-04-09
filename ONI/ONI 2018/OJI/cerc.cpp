#include <bits/stdc++.h>
#define dd (double)

using namespace std;

struct cerc{
    int x, y, r;
};

struct spectacol{
    double x, y;

    bool operator<(const spectacol &obj)const{
        if(y != obj.y)
            return y < obj.y;
        return x < obj.x;
    }
};

struct thing{
    int x, y;
    vector<cerc> v;

    bool operator<(const thing &obj)const{
        return y*2000+x < obj.y*2000+obj.x;
    }

    bool operator==(const thing &obj)const{
        return y*2000+x == obj.y*2000+obj.x;
    }
};

set <thing> s;
vector<cerc> zero;
int n;

cerc make_cerc(int x, int y, int r)
{
    cerc aux;
    aux.x = x;
    aux.y = y;
    aux.r = r;
    return aux;
}

spectacol make_spectacol (double x, double y)
{
    spectacol aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

thing make_thing(int x, int y, vector<cerc> qwe = zero)
{
    thing aux;
    aux.x = x;
    aux.y = y;
    aux.v = qwe;
    return aux;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

double dist(int x, int y)
{
    double sol = sqrt(dd x*dd x + dd y*dd y);
    return sol;
}

int cnt(vector<cerc> t)
{
    vector<spectacol> e;
    for (vector<cerc>::iterator it = t.begin(); it != t.end(); ++it)
        e.push_back(make_spectacol(dist(it->x, it->y)-it->r, dist(it->x, it->y)+it->r));
    sort(e.begin(), e.end());
    int sol = 1;
    double x = e[0].y;
    for (unsigned i = 1; i < e.size(); ++i)
        if(e[i].x >= x){
            ++sol;
            x = e[i].y;
        }
    return sol;
}

int main()
{
    ifstream fin ("cerc3.in");
    ofstream fout ("cerc3.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x, y, g, z;
        fin >> x >> y >> z;
        g = gcd(x, y);

        set<thing>::iterator th = s.find(make_thing(x/g, y/g));
        if(th != s.end()){
            vector<cerc> vec = th->v;
            vec.push_back(make_cerc(x, y, z));
            s.erase(th);
            s.insert(make_thing(x/g, y/g, vec));
        }else{
            vector<cerc> vec;
            vec.push_back(make_cerc(x, y, z));
            s.insert(make_thing(x/g, y/g, vec));
        }
    }
    fout << s.size() << " ";
    int sol = 0, mx = 0;
    for (set<thing>::iterator it = s.begin(); it != s.end(); ++it){
        int x = cnt(it->v);
        if(x > mx){
            sol = 1;
            mx = x;
        }else if (x == mx)
            ++sol;
    }
    fout << mx << " " << sol << "\n";
    return 0;
}

