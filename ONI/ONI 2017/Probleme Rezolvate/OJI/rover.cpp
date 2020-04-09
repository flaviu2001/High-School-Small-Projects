#include <fstream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int test, n, g, v[505][505];

bool check(int x, int y)
{
    if(x > 0 && y > 0 && x <= n && y <= n)
        return true;
    return false;
}

int lee_deque()
{
    int d[n+1][n+1];
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < n+1; ++j)
            d[i][j] = -1;
    deque< pair<int, int> > q;
    q.push_back(make_pair(1, 1));
    d[1][1] = 0;
    while(!q.empty()){
        int qx = q.front().first, qy = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; ++i){
            int qx1 = qx + dx[i], qy1 = qy + dy[i];
            if(check(qx1, qy1) && d[qx1][qy1] == -1){
                if(v[qx1][qy1] < g){
                    q.push_back(make_pair(qx1, qy1));
                    d[qx1][qy1] = d[qx][qy] + 1;
                }else{
                    q.push_front(make_pair(qx1, qy1));
                    d[qx1][qy1] = d[qx][qy];
                }
            }
        }
    }
    return d[n][n];
}

bool lee(int G)
{
    queue < pair<int, int> > q;
    int ok[505][505] = {0};
    q.push(make_pair(1, 1));
    ok[1][1] = 1;
    while(!q.empty()){
        int qx = q.front().first, qy = q.front().second;
        for (int i = 0; i < 4; ++i){
            int qx1 = qx+dx[i], qy1 = qy+dy[i];
            if(check(qx1, qy1) && !ok[qx1][qy1] && v[qx1][qy1] >= G){
                q.push(make_pair(qx1, qy1));
                ok[qx1][qy1] = 1;
            }
        }
        q.pop();
        if(ok[n][n])
            return true;
    }
    return false;
}

int binary_src()
{
    int lo = 1, hi = 11000, m, sol = 0;
    for (m = (lo+hi)>>1; lo <= hi; m = (lo+hi)>>1)
        if(lee(m)){
            sol = m;
            lo = m+1;
        }else
            hi = m-1;
    return sol;
}

int main()
{
    ifstream fin ("rover.in");
    ofstream fout ("rover.out");
    fin >> test >> n;
    if(test == 1)
        fin >> g;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> v[i][j];

    if(test == 1)
        fout << lee_deque() << "\n";
    else
        fout << binary_src() << "\n";
    fin.close();
    fout.close();
    return 0;
}
