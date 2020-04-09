#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ifstream fin ("joc5.in");
    ofstream fout ("joc5.out");
    while(1){
        fin >> n;
        if(n == 0)
            break;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                int x;
                fin >> x;
                if(i == j)
                    ans ^= x;
            }
        if(ans == 0)
            fout << "2\n";
        else fout << "1\n";
    }
    return 0;
}

