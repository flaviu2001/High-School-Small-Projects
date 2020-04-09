#include <fstream>
#include <vector>
#include <queue>
#define M 997

using namespace std;

struct coord{
    int x, y;
}p1, p2;

vector< pair<int, int> > v1, v2;
int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int n, m, t, pascal[204][204], mn1 = 1<<29, mn2 = 1<<29, sol1, sol2, v[104][104];

void combs()
{
    pascal[0][0] = 1;
    for (int i = 1; i < 204; ++i){
        pascal[i][0] = 1;
        for (int j = 1; j < 204; ++j)
            pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % M;
    }
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

int main()
{
    combs();
    ifstream fin ("poarta.in");
    ofstream fout ("poarta.out");
    fin >> n >> m >> t >> p1.x >> p1.y >> p2.x >> p2.y;
    for (int i = 1; i <= t; ++i){
        coord px;
        fin >> px.x >> px.y;
        v[px.x][px.y] = -1;
        if(abs(px.x-p1.x) + abs(px.y-p1.y) < mn1){
            v1.clear();
            v1.push_back(make_pair(abs(px.x-p1.x), abs(px.y-p1.y)));
            mn1 = abs(px.x-p1.x) + abs(px.y-p1.y);
        }else if(abs(px.x-p1.x) + abs(px.y-p1.y) == mn1)
            v1.push_back(make_pair(abs(px.x-p1.x), abs(px.y-p1.y)));
        if(abs(px.x-p2.x) + abs(px.y-p2.y) < mn2){
            v2.clear();
            v2.push_back(make_pair(abs(px.x-p2.x), abs(px.y-p2.y)));
            mn2 = abs(px.x-p2.x) + abs(px.y-p2.y);
        }else if (abs(px.x-p2.x) + abs(px.y-p2.y) == mn2)
            v2.push_back(make_pair(abs(px.x-p2.x), abs(px.y-p2.y)));
    }
    int direct = abs(p1.x-p2.x)+abs(p1.y-p2.y);
    if(direct < mn1+mn2+1)
        fout << direct << "\n" << pascal[abs(p1.x-p2.x)+abs(p1.y-p2.y)][abs(p1.x-p2.x)] << "\n";
    else if(direct == mn1+mn2+1){
        for (unsigned i = 0; i < v1.size(); ++i)
            sol1 += pascal[v1[i].first+v1[i].second][v1[i].first],
            sol1 %= M;
        for (unsigned i = 0; i < v2.size(); ++i)
            sol2 += pascal[v2[i].first+v2[i].second][v2[i].first],
            sol2 %= M;
        fout << direct << "\n" << (sol1*sol2+pascal[abs(p1.x-p2.x)+abs(p1.y-p2.y)][abs(p1.x-p2.x)])%M << "\n";
    }else{
        fout << mn1 + mn2 + 1 << "\n";
        for (unsigned i = 0; i < v1.size(); ++i)
            sol1 += pascal[v1[i].first+v1[i].second][v1[i].first],
            sol1 %= M;
        for (unsigned i = 0; i < v2.size(); ++i)
            sol2 += pascal[v2[i].first+v2[i].second][v2[i].first],
            sol2 %= M;
        fout << (sol1*sol2) % M << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

