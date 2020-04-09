#include <bits/stdc++.h>

using namespace std;

int n, t;
int aib[100005];

void update(int idx, int val)
{
    while(idx <= n){
        aib[idx] += val;
        idx += (idx & (-idx));
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx){
        sum += aib[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main()
{
    ifstream fin ("aib.in");
    ofstream fout ("aib.out");
    fin >> n >> t;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        update(i, x);
    }
    while(t--){
        int c, x, y;
        fin >> c;
        switch(c){
            case 0:
                fin >> x >> y;
                update(x, y);
                break;
            case 1:
                fin >> x >> y;
                fout << read(y)-read(x-1) << "\n";
                break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

