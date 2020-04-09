
#include <fstream>
#include <vector>
#define dd (double)

using namespace std;

struct coord{
    int x, y;
}dt;

vector<coord> v;
int n;

void read()
{
    ifstream fin ("donald.in");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> dt.x >> dt.y;
        v.push_back(dt);
    }
    fin.close();
}

bool coliniar(coord p1, coord p2, coord p)
{
    if(p1.x == p2.x)
        return (p.x == p1.x);
    if(p1.y == p2.y)
        return (p.y == p1.y);
    double s1 = dd (dd p.y - dd p1.y) / dd (dd p2.y - dd p1.y);
    double s2 = dd (dd p.x - dd p1.x) / dd (dd p2.x - dd p1.x);
    return (s1 == s2);
}

int magic()
{
    int mx = 2;
    for(int i = 0; i < n-2; ++i)
        for (int j = i+1; j < n-1; ++j){
            int k = 2;
            for (int kk = j+1; kk < n; ++kk)
                if(coliniar(v[i], v[j], v[kk]))
                    ++k;
            mx = (k > mx ? k : mx);
        }
    return mx;
}

void write()
{
    ofstream fout ("donald.out");
    fout << magic() << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
