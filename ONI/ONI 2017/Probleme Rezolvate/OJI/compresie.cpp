#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int n, nr, len, t;
char s[1000005], v[1005][1005];

void read();
void matrix_size();
void build_matrix(int, int, int, int);
void write();

int main()
{
    read();
    matrix_size();
    build_matrix(1, 1, n, n);
    write();
    return 0;
}

void read()
{
    ifstream fin ("compresie.in");
    fin.getline(s, 1000005);
    len = strlen(s);
    fin.close();
}

void matrix_size()
{
    int k(0), j(0);
    for (int i = 0; i < len; ++i)
        if (s[i] == '*')
            ++nr;
        else if (s[i] >= '0' && s[i] <= '9')
            k = k * 10 + (s[i]-'0');
        else if (s[i] >= 'a' && s[i] <= 'z'){
            if (s[i-1] < 'a' && k)
                j += k, k = 0;
            else ++j;
        }
    n = sqrt(j);
}

void build_matrix(int i1, int j1, int i2, int j2)
{
    if (i1 <= i2 && j1 <= j2 && t < len){
        if (i1 == i2 && j1 == j2){
            v[i1][j1] = s[t++];
            return;
        }
        if (s[t] >= '0' && s[t] <= '9'){
            while(s[t] >= '0' && s[t] <= '9')
                ++t;
            for (int i = i1; i <= i2; ++i)
                for (int j = j1; j <= j2; ++j)
                    v[i][j] = s[t];
            ++t;
            return;
        }
        if (s[t] == '*'){
            ++t;
            int m1 = (i1+i2)/2, m2 = (j1+j2)/2;
            build_matrix(i1, j1, m1, m2);
            build_matrix(i1, m2+1, m1, j2);
            build_matrix(m1+1, j1, i2, m2);
            build_matrix(m1+1, m2+1, i2, j2);
        }
    }
}

void write()
{
    ofstream fout ("compresie.out");
    fout << nr << "\n";
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            fout << v[i][j];
        fout << "\n";
    }
    fout.close();
}