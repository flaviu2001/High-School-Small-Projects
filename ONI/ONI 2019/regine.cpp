#include <bits/stdc++.h>

using namespace std;

int n, v[1005], mx, cnt;

int main()
{
    ifstream fin ("regine.in");
    ofstream fout ("regine.out");
    fin >> n;
    cnt = 1;
    for (int i = 2; i <= n; ++i)
        if(i%3 != 2)
            ++cnt;
    v[1] = 1;
    for (int i = 4; i <= 1000; ++i)
        v[i] = v[i-3]+1;
    fout << cnt << "\n";
    if(n%3 == 1){
        int x = v[n], y = 1;
        while(x <= n && y <= x){
            fout << x << " " << y << "\n";
            ++x, y += 2;
        }
        x = v[n]*2, y = 2;
        while(x <= n && y <= x){
            fout << x << " " << y << "\n";
            ++x, y += 2;
        }
    }else if(n%3 == 0){
        fout << "1 1\n";
        int x = v[n-2]+2, y = 2;
        while(x <= n && y <= x){
            if(x != y)
                fout << x << " " << y << "\n";
            ++x, y += 2;
        }
        x = 2*v[n-2]+2, y = 3;
        while(x <= n && y <= x){
            if(x != y)
                fout << x << " " << y << "\n";
            ++x, y += 2;
        }
    }else{
        fout << "1 1\n";
        if(n > 2)
            fout << "3 2\n";
        int x = v[n-4]+4, y = 3;
        while(x <= n && y <= x){
            if(x != y && x != y+1)
                fout << x << " " << y << "\n";
            ++x, y += 2;
        }
        x = v[n-4]*2+4, y = 4;
        while(x <= n && y <= x){
            if(x != y && x != y+1)
                fout << x << " " << y << "\n";
            ++x, y += 2;
        }
    }
    return 0;
}


