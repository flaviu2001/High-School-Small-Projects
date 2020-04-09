#include <bits/stdc++.h>

using namespace std;

struct tronson{
    double a[2];
    double k[2];
    double v;

    bool operator< (const tronson &obj)const{
        return v < obj.v;
    }
};

int n;
double L, A, K;
vector<tronson> v;
vector<double> sol;

tronson make_tronson(double a1, double a2, double k1, double k2, double v)
{
    tronson aux;
    aux.a[0] = a1;
    aux.a[1] = a2;
    aux.k[0] = k1;
    aux.k[1] = k2;
    aux.v = v;
    return aux;
}

int main()
{
    ifstream fin ("xmoto.in");
    ofstream fout ("xmoto.out");
    fin >> n >> L;
    for (int i = 1; i <= n; ++i){
        double a1, a2, k1, k2, V;
        fin >> a1 >> a2 >> k1 >> k2 >> V;
        A += a1;
        K += k1;
        v.push_back(make_tronson(a1, a2, k1, k2, V));
    }
    sort(v.begin(), v.end());
    double s = (L-K)/A;
    if(s <= v[0].v && s <= 10000 && s > 0)
        sol.push_back(s);
    for (int i = 0; i < n; ++i){
        A -= (v[i].a[0]-v[i].a[1]);
        K -= (v[i].k[0]-v[i].k[1]);
        s = (L-K)/A;
        if(s > 10000 || s <= 0)
            continue;
        if(i+1 < n){
            if(s > v[i].v && s <= v[i+1].v)
                sol.push_back(s);
        }else if(s > v[i].v)
            sol.push_back(s);
    }
    fout << sol.size() << "\n";
    for (vector<double>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << fixed << setprecision(10) << *it << "\n";
    fin.close();
    fout.close();
    return 0;
}

