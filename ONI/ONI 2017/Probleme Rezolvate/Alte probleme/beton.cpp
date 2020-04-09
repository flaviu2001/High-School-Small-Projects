#include <fstream>

using namespace std;

long long x, y, gx, gy, ans, v[5001];

void read()
{
    ifstream fin ("beton.in");
    fin >> x >> y;
    fin.close();
}

void swap(long long &a, long long &b)
{
    long long aux = a;
    a = b;
    b = aux;
}

long long g(long long a)
{
    return a*(a+1)/2;
}

void black_magic_fuckery()
{
    long long t = 0;
    for (int i = 1; i < 10000005; i += t){
        ++t;
        v[t] = i;
    }
    t = 0;
    for (long long i = 1; i < 30000000; i += t){
        ++t;
        if(x >= i && x < i + t)
            gx = t;
        if(y >= i && y < i + t)
            gy = t;
        if(gx && gy)
            break;
    }
    if(x == 1 && gy % 2 == 0){
        ++x;
        gx = 2;
        ++ans;
    }
    if(y == 1 && gx % 2 == 1){
        y = 6;
        gy = 3;
        ++ans;
    }
    if (gx % 2 == 1 && gy % 2 == 1 && gx < gy){
        swap(x, y);
        swap(gx, gy);
    }
    if (gy % 2 == 1 && gx % 2 == 0){
        swap(x, y);
        swap(gx, gy);
    }
    if (gx % 2 == 0 && gy % 2 == 0 && gx > gy){
        swap(x, y);
        swap(gx, gy);
    }

    if(gx == gy)
        for (long long i = x; i <= y; ++i)
            ans += i;
    else if (gx % 2 == 1 && gy % 2 == 1){
        for (long long i = gx - 2; i > gy; i -= 2)
            ans += g(v[i]+i-1) - g(v[i]-1);
        for (long long i = x; i <= v[gx+1]-1; ++i)
            ans += i;
        for (long long i = y; i >= v[gy]; --i)
            ans += i;
    }else if (gx % 2 == 0 && gy % 2 == 0){
        for (long long i = gx + 2; i < gy; i += 2)
            ans += g(v[i]+i-1) - g(v[i]-1);
        for (long long i = x; i <= v[gx+1]-1; ++i)
            ans += i;
        for (long long i = y; i >= v[gy]; --i)
            ans += i;
    }else{
        ++ans;
        int aux1 = 6, gaux1 = 3, aux2 = 2, gaux2 = 2;
        if(gx == gaux1)
            for (long long i = x; i <= aux1; ++i)
                ans += i;
        else{
            for (long long i = gx - 2; i > gaux1; i -= 2)
                ans += g(v[i]+i-1) - g(v[i]-1);
            for (long long i = x; i <= v[gx+1]-1; ++i)
                ans += i;
            for (long long i = aux1; i >= v[gaux1]; --i)
                ans += i;
        }

        if(gaux2 == gx)
            for (long long i = aux2; i <= y; ++i)
                ans += i;
        else{
            for (long long i = gaux2 + 2; i < gy; i += 2)
                ans += g(v[i]+i-1) - g(v[i]-1);
            for (long long i = aux2; i <= v[gaux2+1]-1; ++i)
                ans += i;
            for (long long i = y; i >= v[gy]; --i)
                ans += i;
        }
    }
}

void write()
{
    ofstream fout ("beton.out");
    fout << ans << "\n";
    fout.close();
}

int main()
{
    read();
    black_magic_fuckery();
    write();
    return 0;
}

