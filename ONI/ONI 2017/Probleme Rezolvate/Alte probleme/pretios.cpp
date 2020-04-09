#include <iostream>
#include <cmath>
#define ull unsigned long long

using namespace std;

ull a, b;

void read();
bool isPrime(int x);
ull pow(int x, int y);
ull solve();
void write();

int main()
{
    read();
    write();
    return 0;
}

void read(){
    cin >> a >> b;
}

bool isPrime(int x){
    if (x == 3 || x == 2 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 || x == 23 || x == 29 || x == 31 || x == 37 || x == 41 || x == 43 || x == 47 || x == 53 || x == 59 || x == 61)
        return 1;
    return 0;
}

ull pow(int x, int y){
    ull t = 1;
    while(y--)
        t *= x;
    return t;
}

ull solve(){
    ull t(0);
    int x = log2(a)+1, y = log2(b);
    if (isPrime(x))
        t += (pow(2, x) - a);
    for (int i = x; i < y; ++i)
        if (isPrime(i+1))
            t += pow(2, i);
    if (isPrime(y+1))
        t += (b - pow(2, y)+1);
    return t;
}

void write(){
    cout << solve() << "\n";
}
