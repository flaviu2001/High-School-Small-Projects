#include <fstream>
#include <cstring>
#define M 1000000007

using namespace std;

int test, n, zero, one;
char s[100005], s1[100005], s2[100005];

void read();
int fibo(int);
void write1();
void previous_number();
void next_number();
void write2();

int main()
{
    read();
    if (test == 1)
        write1();
    else{
        previous_number();
        next_number();
        write2();
    }
    return 0;
}

void read()
{
    ifstream fin ("calc.in");
    fin >> test >> n;
    fin.getline(s, 100005);
    fin.getline(s, 100005);
    for (int i = 0; i < n; ++i)
        if (s[i] == '0')
            ++zero;
        else ++one;
    fin.close();
}

int fibo(int t)
{
    int x, y;
    if (t == 1)
        return 1;
    if (t == 2)
        return 2;
    if (t == 3)
        return 3;
    y = 2; x = 3;
    for (int i = 4; i <= t; ++i){
        int x1 = x;
        x += y;
        y = x1;
        x = x % M;
        y = y % M;
    }
    return x;
}

void write1()
{
    ofstream fout ("calc.out");
    fout << fibo(n) << "\n";
    fout.close();
}

void previous_number()
{
    if (one == 0 || one == 1){
        s1[0] = '-';
        s1[1] = '1';
        s1[2] = '\0';
        return;
    }
    for (int i = 0; i < n; ++i)
        s1[i] = s[i];
    s1[n] = '\0';
    if (s1[n-1] == '0'){
        int k = 0;
        for (int i = n - 1; s1[i] == '0'; --i)
            ++k;
        s1[n-k-1] = '0';
        for (int i = n - k + 1; i < n; ++i)
            s1[i] = '1';
        return;
    }
    int k = 0;
    for (int i = n - 1; s1[i] == '1'; --i)
        ++k;
    if (k%2){
        if (k == 1){
            int y = 1;
            for (int i = n - 2; s1[i] == '0'; --i)
                ++y;
            s1[n-y-1] = '0';
            for (int i = n - y + 1; i < n; ++i)
                s1[i] = '1';
            return;
        }
        s1[n-3] = '1';
        s1[n-2] = '0';
        s1[n-1] = '0';
        return;
    }
    s1[n-2] = '0';
    s1[n-1] = '0';
}

void next_number()
{
    if (zero == 0){
        s2[0] = '-';
        s2[1] = '1';
        s2[2] = '\0';
        return;
    }
    for (int i = 0; i < n; ++i)
        s2[i] = s[i];
    s2[n] = '\0';
    if (s2[n-1] == '0'){
        s2[n-1] = s2[n-2] = '1';
        return;
    }
    int k = 0;
    for (int i = n - 1; s2[i] == '1'; --i)
        ++k;
    if (k%2){
        s2[n-k-2] = '1';
        for (int i = n - k; i < n; ++i)
            s2[i] = '0';
        return;
    }
    s2[n-k-2] = '1';
    for (int i = n - k; i < n; ++i)
        s2[i] = '0';
    s2[n-1] = '1';
}

void write2()
{
    ofstream fout ("calc.out");
    fout << s1 << "\n" << s2 << "\n";
    fout.close();
}

