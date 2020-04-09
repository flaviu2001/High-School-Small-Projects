#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct qu{
    short x, d, c;
};

struct bullshit{
    short c, d;
} s[1201];

short n, solx = -2, soly = -2;
vector< pair<short, short> > v[1201];

qu make_qu(short x, short d, short c)
{
    qu aux;
    aux.x = x;
    aux.d = d;
    aux.c = c;
    return aux;
}

bullshit make_bullshit(short d, short c)
{
    bullshit aux;
    aux.c = c;
    aux.d = d;
    return aux;
}

void bell()
{
    for (short i = 0; i < 1201; ++i)
        s[i] = make_bullshit(-1, -1);
    queue<short> q;
    q.push(0);
    s[0] = make_bullshit(0, 0);
    while(!q.empty()){
        short K = q.front();
        qu k = make_qu(K, s[K].d, s[K].c);
        q.pop();
        for (vector< pair<short, short> >::iterator it = v[k.x].begin(); it != v[k.x].end(); ++it){
            if(it->ff == k.x+1){
                if(s[it->ff].d == -1 || s[it->ff].d > k.d + 1){
                    s[it->ff] = make_bullshit(k.d+1, k.c);
                    q.push(it->ff);
                }else if (s[it->ff].d == k.d + 1 && s[it->ff].c > k.c){
                    s[it->ff] = make_bullshit(k.d+1, k.c);
                    q.push(it->ff);
                }
            }else{
                for (int i = k.x+1; i <= it->ff && i <= n; ++i){
                    if(s[i].d == -1 || s[i].d > k.d + 1){
                        s[i] = make_bullshit(k.d+1, k.c + it->ss*((i-k.x+1)/2));
                        q.push(i);
                    }else if (s[i].d == k.d + 1 && s[i].c > k.c+it->ss*((i-k.x+1)/2)){
                        s[i] = make_bullshit(k.d+1, k.c + it->ss*((i-k.x+1)/2));
                        q.push(i);
                    }
                }
            }
        }
    }
    solx = s[n].d;
    soly = s[n].c;
}

int main()
{
    ifstream fin ("scara3.in");
    ofstream fout ("scara3.out");
    fin >> n;
    for (short i = 0; i < n; ++i)
        v[i].push_back(make_pair(i+1, 0));
    short m;
    fin >> m;
    for (short i = 1; i <= m; ++i){
        short x, y;
        fin >> x >> y;
        v[x].push_back(make_pair(x+y, 0));
        /*for(short i = x+1; i <= x+y; ++i)
            if(i <= n)
                v[x].push_back(make_pair(i, 0));*/
    }
    fin >> m;
    for (short i = 1; i <= m; ++i){
        short x, y;
        fin >> x >> y;
        v[x].push_back(make_pair(x+y+y, 1));
        /*for (short i = x+1; i <= x+y+y; ++i)
            if(i <= n)
                v[x].push_back(make_pair(i, (i-x+1)/2));*/
    }
    bell();
    fout << solx << " " << soly << "\n";
    fin.close();
    fout.close();
    return 0;
}

