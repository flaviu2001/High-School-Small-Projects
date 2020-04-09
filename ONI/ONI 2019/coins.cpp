//problema gasita de pe discul de la oni
#include <bits/stdc++.h>

using namespace std;

int test, pd[(1<<22)];//pd: 0-unvisited, 1-win, 2-lose

void bkt(int x)
{
    if(pd[x] != 0)
        return;
    int lastzero = -1, pw = (1<<21), y = x;
    bool canwin = false;
    while(pw){
        if(y >= pw){
            y -= pw;
            if(lastzero != -1){
                bkt(x-pw+lastzero);
                if(pd[x-pw+lastzero] == 2)
                    canwin = true;
            }
        }else
            lastzero = pw;
        pw /= 2;
    }
    if(canwin)
        pd[x] = 1;
    else pd[x] = 2;
}

int main()
{
    ifstream fin ("coins.in");
    ofstream fout ("coins.out");
    fin >> test;
    int pw = (1<<21), num = 0;
    while(pw){
        num += pw;
        pw /= 2;
        pd[num] = 1;
    }
    for (int i = 0; i < (1<<22); ++i)
        bkt(i);
    int ans = 0;
    while(test--){
        int num = 0, cnt = 0;
        for (int i = 1; i <= 22; ++i){
            int x;
            fin >> x;
            num = num*2+x;
            cnt += x;
        }
        if(pd[num] == 1)
            ans += cnt;
    }
    fout << ans << "\n";
    return 0;
}

