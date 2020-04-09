#include <bits/stdc++.h>

using namespace std;

int n;
short v[3][105][205][80];

void sum(short dest[], short x[])
{
    int mn = max(x[79], dest[79]), t=0, szx = x[79], szy = dest[79];
    dest[79] = 0;
    for (int i = 0; i < mn; ++i){
        int X = 0, Y = 0;
        if(szx > i)
            X = x[i];
        if(szy > i)
            Y = dest[i];
        dest[dest[79]++] = X+Y+t;
        t = dest[i]/10;
        dest[i] %= 10;
    }
    if(t)
        dest[dest[79]++] = t;
}

void rec(int state, int elevation, int distance)
{
    if(v[state][elevation][distance][79] > 1 || (v[state][elevation][distance][79] == 1 && v[state][elevation][distance][0] != 0))
        return;
    if(elevation == n-distance){
        v[state][elevation][distance][79] = 1;
        v[state][elevation][distance][0] = 1;
        return;
    }
    if(elevation == 0 && n-distance == 2){
        v[state][elevation][distance][79] = 1;
        v[state][elevation][distance][0] = 1;
        return;
    }
    if(elevation > 1 || (elevation == 1 && state != 1)){
        rec(2, elevation-1, distance+1);
        sum(v[state][elevation][distance], v[2][elevation-1][distance+1]);
    }
    rec(1, elevation+1, distance+1);
    rec(0, elevation, distance+2);
    sum(v[state][elevation][distance], v[1][elevation+1][distance+1]);
    sum(v[state][elevation][distance], v[0][elevation][distance+2]);
}

int main()
{
    ifstream fin ("munte1.in");
    ofstream fout ("munte1.out");
    for (int k = 0; k < 3; ++k)
        for (int i = 0; i < 105; ++i)
            for (int j = 0; j < 205; ++j){
                v[k][i][j][79] = 1;
                v[k][i][j][0] = 0;
            }
    fin >> n;
    n = n*2-2;
    rec(0, 0, 0);
    for(int i = v[0][0][0][79]-1; i >= 0; --i)
        fout << v[0][0][0][i];
    fin.close();
    fout.close();
    return 0;
}

