#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int b[nmax], a[nmax], n;

int main()
{
    ifstream fin ("examen.in");
    ofstream fout ("examen.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> b[i];
    int sign;
    switch(n%4){
        case 0:
            fout << "-1\n";
            break;
        case 1:
            sign = 1;
            for (int i = n; i >= 1; i -= 2){
                a[1] += b[i]*sign;
                sign *= -1;
            }
            sign = -1;
            for (int i = n-1; i >= 2; i -= 2){
                a[1] += b[i]*sign;
                sign *= -1;
            }
            a[1] /= 2;
            for (int i = 3; i <= n; i += 2)
                a[i] = b[i-1] - a[i-2];
            a[2] = b[1] - a[n];
            for (int i = 4; i <= n-1; i += 2)
                a[i] = b[i-1] - a[i-2];
            for (int i = 1; i <= n; ++i)
                fout << a[i] << " ";
            break;
        case 2:
            sign = 1;
            for (int i = n; i >= 2; i -= 2){
                a[1] += b[i]*sign;
                sign *= -1;
            }
            a[1] /= 2;
            for (int i = 3; i <= n-1; i += 2)
                a[i] = b[i-1] - a[i-2];
            a[2] = b[1];
            sign = -1;
            for (int i = n-1; i > 1; i -= 2){
                a[2] += b[i]*sign;
                sign *= -1;
            }
            a[2] /= 2;
            for (int i = 4; i <= n; i += 2)
                a[i] = b[i-1] - a[i-2];
            for (int i = 1; i <= n; ++i)
                fout << a[i] << " ";
            break;
        case 3:
            sign = 1;
            for (int i = n; i >= 1; i -= 2){
                a[1] += b[i]*sign;
                sign *= -1;
            }
            sign = 1;
            for (int i = n-1; i >= 2; i -= 2){
                a[1] += b[i]*sign;
                sign *= -1;
            }
            a[1] /= 2;
            for (int i = 3; i <= n; i += 2)
                a[i] = b[i-1] - a[i-2];
            a[2] = b[1] - a[n];
            for (int i = 4; i <= n-1; i += 2)
                a[i] = b[i-1] - a[i-2];
            for (int i = 1; i <= n; ++i)
                fout << a[i] << " ";
            break;
    }
    fin.close();
    fout.close();
    return 0;
}

