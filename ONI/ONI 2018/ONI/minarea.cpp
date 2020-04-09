#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, e, f, mn, sol;

long long min(long long x1, long long x2, long long x3)
{
    return min(x1, min(x2, x3));
}

int main()
{
    ifstream fin ("minarea.in");
    ofstream fout ("minarea.out");
    fin >> a >> b >> c >> d >> e >> f;

    mn = min(c, f);
    sol += 9*mn;
    c -= mn;
    f -= mn;

    mn = min(c, d, e);
    sol += 9*mn;
    c -= mn;
    d -= mn;
    e -= mn;

    mn = min(f, a, b);
    sol += 9*mn;
    f -= mn;
    a -= mn;
    b -= mn;

    mn = min(c, d/3);
    sol += 9*mn;
    c -= mn;
    d -= 3*mn;

    mn = min(f, a/3);
    sol += 9*mn;
    f -= mn;
    a -= 3*mn;

    mn = min(c, a, e/2);
    sol += 12*mn;
    c -= mn;
    a -= mn;
    e -= mn*2;

    mn = min(f, d, b/2);
    sol += 12*mn;
    f -= mn;
    d -= mn;
    b -= mn*2;

    mn = min(c/2, e/3);
    sol += 24*mn;
    c -= mn*2;
    e -= mn*3;

    mn = min(f/2, b/3);
    sol += 24*mn;
    f -= mn*2;
    b -= mn*3;

    mn = min(b, e);
    sol += 4*mn;
    b -= mn;
    e -= mn;

    mn = min(b, d/2);
    sol += 4*mn;
    b -= mn;
    d -= mn*2;

    mn = min(e, a/2);
    sol += 4*mn;
    a -= mn*2;
    e -= mn;

    mn = min(a, d);
    sol += mn;
    a -= mn;
    d -= mn;

    fout << sol << '\n';
    fin.close();
    fout.close();
    return 0;
}

