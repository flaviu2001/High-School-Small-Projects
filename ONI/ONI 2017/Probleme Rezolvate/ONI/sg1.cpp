#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[105][105];
int d1, d2;

void copy(vector<int> &destination, vector<int> cpy)
{
    destination.clear();
    for (unsigned i = 0; i < cpy.size(); ++i)
        destination.push_back(cpy[i]);
}

void sum(vector<int> v1, vector<int> v2, vector<int> &v3)
{
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    v3.clear();
    int n1 = v1.size(), n2 = v2.size(), n = max(n1, n2);
    int t = 0;
    for (int i = 0; i < n; ++i){
        int dig1 = 0, dig2 = 0;
        if(i < n1)
            dig1 = v1[i];
        if(i < n2)
            dig2 = v2[i];
        v3.push_back(dig1+dig2+t);
        t = v3[i]/10;
        v3[i] = v3[i]%10;
    }
    if(t > 0)
        v3.push_back(1);
    reverse(v3.begin(), v3.end());
}

int main()
{
    ifstream fin ("sg1.in");
    ofstream fout ("sg1.out");
    int n, k;
    fin >> n >> k >> d1 >> d2;
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 105; ++j)
            v[i][j].push_back(0);
    for (int j = 1; j <= n; ++j){
        v[j][1].clear();
        if(j < 10)
            v[j][1].push_back(j);
        else if (j < 100){
            v[j][1].push_back(j/10);
            v[j][1].push_back(j%10);
        }else{
            v[j][1].push_back(j/100);
            v[j][1].push_back((j%100)/10);
            v[j][1].push_back(j%10);
        }
        for (int i = 2; i <= k; ++i){
            vector<int> sol;
            sol.push_back(0);
            for (int d = d1; d <= d2; ++d)
                if(j-d-1 >= 0){
                    vector<int> thing;
                    sum(sol, v[j-d-1][i-1], thing);
                    copy(sol, thing);
                }
            copy(v[j][i], sol);
        }
    }
    for (unsigned i = 0; i < v[n][k].size(); ++i)
        fout << v[n][k][i];
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}

