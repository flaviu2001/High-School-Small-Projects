#include <fstream>
#include <vector>

using namespace std;

vector<int> v1, v2, s1, s2;
int n, m;
bool r1[50005], r2[50005];

void read();
void sum(bool [], vector<int>, vector<int>&);
int sums();
void write();

int main()
{
    read();
    sum(r1, v1, s1);
    sum(r2, v2, s2);
    write();
    return 0;
}

void read()
{
    ifstream fin ("echilibru.in");
    fin >> n >> m;
    int q;
    for (int i = 1; i <= n; ++i){
        fin >> q;
        v1.push_back(q);
    }
    for (int j = 1; j <= m; ++j){
        fin >> q;
        v2.push_back(q);
    }
    fin.close();
}

void sum(bool r[50005], vector<int> v, vector<int>& s){
    for (unsigned i = 0; i < v.size(); ++i){
        vector<int> t;
        for (unsigned j = 0; j < s.size(); ++j)
            if (!r[s[j]+v[i]]){
                r[s[j]+v[i]] = 1;
                t.push_back(s[j]+v[i]);
            }
        for (unsigned j = 0; j < t.size(); ++j)
            s.push_back(t[j]);
        if (!r[v[i]]){
            r[v[i]] = 1;
            s.push_back(v[i]);
        }
    }
}

int sums()
{
    int k(0);
    for (unsigned i = 0; i < s1.size(); ++i)
        for (unsigned j = 0; j < s2.size(); ++j)
            if (s1[i] == s2[j])
                ++k;
    return k;
}

void write()
{
    ofstream fout ("echilibru.out");
    fout << sums() << "\n";
    fout.close();
}
