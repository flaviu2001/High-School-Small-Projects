#include <bits/stdc++.h>

using namespace std;

const int BUF_SIZE = 1<<17;
vector<int> v[300005];
int n, test, c[300005], tt[300005], mxTT[300005], mxL[300005];
multiset<int> s;
char buf[BUF_SIZE];
int pos=BUF_SIZE;
FILE *fin;

inline char nextch(){
    if(pos==BUF_SIZE) fread(buf, BUF_SIZE, 1, fin), pos=0;
    return buf[pos++];
}

inline int read(){
    int x=0;
    char ch=nextch();
    while(!isdigit(ch)) ch=nextch();
    while(isdigit(ch)){
        x=10*x+ch-'0';
        ch=nextch();
    }
    return x;
}

void dfmxTT(int x)
{
    mxTT[x] = max(mxTT[tt[x]], c[x]);
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        dfmxTT(*it);
}

void dfmxL(int x)
{
    s.erase(s.find(-c[x]));
    mxL[x] = -(*s.begin());
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); ++it)
        dfmxL(*it);
    s.insert(-c[x]);
}

int main()
{
    FILE *fout;
    fin = fopen("arbvalmax.in", "r");
    fout = fopen("arbvalmax.out", "w");
    n = read();
    test = read();
    for (int i = 2; i <= n; ++i){
        int x = read();
        v[x].push_back(i);
        tt[i] = x;
    }
    for (int i = 1; i <= n; ++i)
        c[i] = read();
    dfmxTT(1);
    for (int i = 1; i <= n; ++i)
        s.insert(-c[i]);
    dfmxL(1);
    while(test--){
        int x, y;
        x = read();
        y = read();
        fprintf(fout, "%d\n", max(mxTT[tt[x]], mxL[y]));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

