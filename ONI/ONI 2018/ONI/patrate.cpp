#include <bits/stdc++.h>

using namespace std;

// Include the Int class for large numbers for this code to work as intended

Int x, y, z;
int n;

int main()
{
    ifstream fin ("patrate6.in");
    ofstream fout ("patrate6.out");
    fin >> n;
    y = 1;
    x = 5;
    for (int i = 3; i <= n; ++i){
        z = y;
        y = x;
        x = y*5-z*2;
    }
    if(n == 1)
        fout << "1\n";
    else if (n == 2)
        fout << "5\n";
    else
        fout << x << "\n";
    fin.close();
    fout.close();
    return 0;
}

