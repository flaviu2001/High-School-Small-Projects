#include <fstream>
#include <vector>

using namespace std;

vector<char> r;
int q[2000005], t[2000005], a, b, n, p = 1, f = 1;
bool ok[2000005], c[2000005];

void read()
{
    ifstream fin ("multiplu.in");
    fin >> a >> b;
    fin.close();

    n = a * b;
    if (b > a){
        int aux = a;
        a = b;
        b = aux;
    }
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    n /= a;
    q[1] = 1 % n;
    c[1] = 1;
}

void solve()
{
    if (n == 1){
        r.push_back('1');
        return;
    }
    while(p <= f){
        int t1 = (q[p] * 10) % n;
        int t2 = (q[p] * 10 + 1) % n;

        if (t1 == 0){
            r.push_back('0');
            for (int i = p; i >= 1; i = t[i])
                r.push_back(c[i] + '0');
            return;
        }
        else if (t2 == 0){
            r.push_back('1');
            for (int i = p; i >= 1; i = t[i])
                r.push_back(c[i] + '0');
            return;
        }

        if (!ok[t1]){
            ok[t1] = 1;
            q[++f] = t1;
            t[f] = p;
            c[f] = 0;
        }
        if (!ok[t2]){
            ok[t2] = 1;
            q[++f] = t2;
            t[f] = p;
            c[f] = 1;
        }
        ++p;
    }
}

void write()
{
    ofstream fout ("multiplu.out");
    for (int i = r.size()-1; i >= 0; --i)
        fout << r[i];
    fout.close();
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
