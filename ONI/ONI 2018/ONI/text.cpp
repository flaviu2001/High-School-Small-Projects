#include <bits/stdc++.h>

using namespace std;

int n, v[4][1000005], last2[2][100], last3[3][1000], next2[1000005], next3[1000005];
char c[1000005];

int main()
{
    ifstream fin ("text5.in");
    ofstream fout ("text5.out");
    fin >> n >> (c+1);
    c[n+1] = c[n+2] = c[n+3] = '0';
    memset(last2, -1, sizeof(last2));
    memset(last3, -1, sizeof(last3));
    for (int i = 1; i <= n-1; ++i){
        int p = (c[i]-'0')*10 + c[i+1]-'0';
        last2[i%2] [p] = i;
    }
    for (int i = 1; i <= n-2; ++i){
        int p = (c[i]-'0')*100 + (c[i+1]-'0')*10 + c[i+2]-'0';
        last3[i%3][p] = i;
    }
    int nr2, nr3;
    for (int i = n-1; i; --i){
        //v[2][i]
        nr2 = (c[i]-'0')*10 + c[i+1]-'0';
        if(last2[i%2][nr2] == i){
            next2[i] = i;
            v[2][i] = 1+v[0][i+2];
        }else{
            next2[i] = last2[i%2][nr2];
            for (int k = i+2 ; k <= last2[i%2][nr2]; k = next2[k]+2)
                next2[i] = max(next2[i], next2[k]);
            v[2][i] = 1+v[0][next2[i]+2];
        }

        //v[3][i]
        if(i == n-1){
            v[3][i] = -1;
            next3[i] = -1;
            goto here;
        }
        nr3 = (c[i]-'0')*100 + (c[i+1]-'0')*10 + c[i+2]-'0';
        if(last3[i%3][nr3] == i){
            next3[i] = i;
            v[3][i] = 1+v[0][i+3];
        }else{
            next3[i] = last3[i%3][nr3];
            for (int k = i+3; k <= last3[i%3][nr3]; k = next3[k]+3)
                next3[i] = max(next3[i], next3[k]);
            v[3][i] = 1+v[0][next3[i]+3];
        }

        here:
        //v[0][i]
        v[0][i] = max(v[2][i], v[3][i]);
    }
    fout << v[0][1] << "\n";
    for (int i = 1; i <= n;)
        if(v[2][i] > v[3][i]){
            fout << i << " 2\n";
            i = next2[i]+2;
        }else{
            fout << i << " 3\n";
            i = next3[i]+3;
        }
    fin.close();
    fout.close();
    return 0;
}

