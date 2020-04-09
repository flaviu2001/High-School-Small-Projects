#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void sum(vector<int> &dest, vector<int> x, vector<int> y)
{
    dest.clear();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int mn = max(x.size(), y.size()), t=0;
    for (int i = 0; i < mn; ++i){
        int X = 0, Y = 0;
        if((int)x.size() > i)
            X = x[i];
        if((int)y.size() > i)
            Y = y[i];
        dest.push_back(X+Y+t);
        t = dest[i]/10;
        dest[i] %= 10;
    }
    if(t)
        dest.push_back(t);
    reverse(dest.begin(), dest.end());
}

void prod(vector<int> &c, vector<int> a, vector<int> b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    c.clear();
    c.resize(a.size() + b.size()-1, 0);
    for (unsigned i = 0; i < a.size(); ++i)
        for (unsigned j = 0; j < b.size(); ++j)
            c[i+j] += a[i] * b[j];
    int t = 0;
    for (unsigned i = 0; i <= a.size() + b.size()-2; ++i){
        c[i] += t;
        t = c[i]/10;
        c[i] %= 10;
    }
    if(t)
        c.push_back(t);
    reverse(c.begin(), c.end());
}

int main()
{
    ifstream fin ("aladdin2.in");
    ofstream fout ("aladdin2.out");
    fin >> n >> m;
    vector<int> e, x1, x2;
    e.push_back(2);
    x1.push_back(1);
    x2.push_back(1);
    while(n)
        if(n%2 == 0){
            prod(e, e, e);
            n /= 2;
        }else{
            prod(x1, x1, e);
            --n;
        }
    x1[x1.size()-1] -= 2;
    e.clear();
    e.push_back(2);
    while(m)
        if(m%2 == 0){
            prod(e, e, e);
            m /= 2;
        }else{
            prod(x2, x2, e);
            --m;
        }
    sum(x1, x1, x2);
    for (unsigned i = 0; i < x1.size(); ++i)
        fout << x1[i];
    fin.close();
    fout.close();
    return 0;
}

