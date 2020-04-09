#include <bits/stdc++.h>

using namespace std;

FILE *fin = fopen("lant.in", "r");
FILE *fout = fopen("lant.out", "w");
vector< vector<char> > c;
int k, sol[155];

bool isequal(vector<char> c1, vector<char> c2)
{
    if(c1.size() != c2.size())
        return false;
    for (unsigned i = 0; i < c1.size(); ++i)
        if(c1[i] != c2[i])
            return false;
    return true;
}

bool nextword(char q[])
{
    char ch;
    int in = 1;
    do{
        if(feof(fin))
            return false;
        fscanf(fin, "%c", &ch);
    }while(!(ch >= 'a' && ch <= 'z'));
    q[0] = ch;
    while(ch >= 'a' && ch <= 'z'){
        fscanf(fin, "%c", &ch);
        q[in++] = ch;
    }
    q[in-1] = 0;
    return true;
}

int similitudine(vector<char> c1, vector<char> c2)
{
    int d[35][35] = {0}, n = c1.size(), m = c2.size();
    for (int j = 0; j <= m; ++j)
        d[n][j] = m-j;
    for (int i = 0; i <= n; ++i)
        d[i][m] = n-i;
    for (int i = n-1; i >= 0; --i)
        for (int j = m-1; j >= 0; --j){
            if(c1[i] == c2[j])
                d[i][j] = min(d[i+1][j+1], 1+d[i][j+1]);
            else d[i][j] = 1+d[i][j+1];
            d[i][j] = min(d[i][j], 1+d[i+1][j]);
        }
    return d[0][0];
}

int main()
{
    fscanf(fin, "%d", &k);
    char q[35];
    while(nextword(q)){
        vector<char> w;
        int n = strlen(q);
        for (int i = 0; i < n; ++i)
            w.push_back(q[i]);
        bool good = true;
        for (vector< vector<char> >::iterator it = c.begin(); it != c.end(); ++it)
            if(isequal(w, *it)){
                good = false;
                break;
            }
        if(good)
            c.push_back(w);
    }
    for (int p = c.size()-1; p >= 0; --p){
        int cnt = 0;
        for (unsigned j = p+1; j < c.size(); ++j)
            if(similitudine(c[p], c[j]) <= k)
                cnt += sol[j];
        sol[p] = max(cnt, 1);
    }
    fprintf(fout, "%d", sol[0]);
    return 0;
}

