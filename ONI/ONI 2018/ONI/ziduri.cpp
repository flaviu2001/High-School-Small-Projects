#include <fstream>
#include <queue>

using namespace std;

struct zid{
    int x;
    int z;
}inf;

queue< pair<int, int> > q;
zid d[101][101];
int n, p, v[101][101];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= n && (x != 1 || y != 1);
}

int main()
{
    ifstream fin ("ziduri.in");
    ofstream fout ("ziduri.out");
    fin >> n >> p;
    inf.x = 2000000000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j],
            d[i][j] = inf;
    d[1][1].x = 0;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        int kf = q.front().first, ks = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i){
            if (check(kf+dx[i], ks+dy[i]) && !(v[kf][ks] & (1 << i)) && d[kf+dx[i]][ks+dy[i]].x > d[kf][ks].x + 1){
                d[kf+dx[i]][ks+dy[i]] = d[kf][ks];
                ++d[kf+dx[i]][ks+dy[i]].x;
                q.push(make_pair(kf+dx[i], ks+dy[i]));
            }else if (check(kf+dx[i], ks+dy[i]) && !(v[kf][ks] & (1 << i)) && d[kf+dx[i]][ks+dy[i]].x == d[kf][ks].x + 1 && d[kf+dx[i]][ks+dy[i]].z > d[kf][ks].z){
                d[kf+dx[i]][ks+dy[i]] = d[kf][ks];
                ++d[kf+dx[i]][ks+dy[i]].x;
                q.push(make_pair(kf+dx[i], ks+dy[i]));
            }else if (check(kf+dx[i], ks+dy[i]) && (v[kf][ks] & (1 << i)) && d[kf+dx[i]][ks+dy[i]].x > d[kf][ks].x + p){
                d[kf+dx[i]][ks+dy[i]] = d[kf][ks];
                d[kf+dx[i]][ks+dy[i]].x += p;
                ++d[kf+dx[i]][ks+dy[i]].z;
                q.push(make_pair(kf+dx[i], ks+dy[i]));
            }else if (check(kf+dx[i], ks+dy[i]) && (v[kf][ks] & (1 << i)) && d[kf+dx[i]][ks+dy[i]].x == d[kf][ks].x + p && d[kf+dx[i]][ks+dy[i]].z > d[kf][ks].z + 1){
                d[kf+dx[i]][ks+dy[i]] = d[kf][ks];
                d[kf+dx[i]][ks+dy[i]].x += p;
                ++d[kf+dx[i]][ks+dy[i]].z;
                q.push(make_pair(kf+dx[i], ks+dy[i]));
            }
        }
    }
    fout << d[n][n].x << "\n" << d[n][n].z << "\n";
    fin.close();
    fout.close();
    return 0;
}

