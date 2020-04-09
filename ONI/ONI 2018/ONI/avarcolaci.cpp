#include <bits/stdc++.h>

using namespace std;

int test, n;

int main()
{
    ifstream fin ("avarcolaci.in");
    ifstream fin2 ("avarcolaci.in");
    ofstream fout ("avarcolaci.out");
    fin >> test; fin2 >> test;
    while(test--){
        int x = -1,k = 0;
        fin2 >> n; fin >> n; n<<=1;
        for (int i = 1; i <= n; ++i){
            int y;
            fin >> y;
            if(y == x)
                ++k;
            if(y != x){
                --k;
                if(k < 0){
                    x = y;
                    k = 1;
                }
            }
        }
        k = 0;
        for (int i = 1; i <= n; ++i){
            int y;
            fin2 >> y;
            if(y == x)
                ++k;
        }
        if(k >= n/2+1)
            fout << x << "\n";
        else fout << "Mozart\n";
    }
    fin.close();
    fout.close();
    return 0;
}

