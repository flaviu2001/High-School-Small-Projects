#include <fstream>
#include <queue>
#define INF 1<<30

using namespace std;

int dx[] = {-1, 0, 1}, dy[] = { 0, 1, 0};
int n, m, tk, v, e;
int a[253][253], M[253][253], timp[253][253];

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

bool caut(int i1, int j1, int r, int ts)
{
    for (int i = max(1, i1-r); i <= min(n, i1+r); ++i)
        for (int j = max(1, j1-r); j <= min(m, j1+r); ++j)
            if(a[i][j] > 0)
                if(ts%((a[i][j]/100)+(a[i][j]%100)) >= a[i][j]/100)
                    return false;
    return true;
}

bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

void lee()
{
    queue< pair<int, int> >q;
    q.push(make_pair(v, 1));
    timp[v][1] = 1;
    while(!q.empty()){
        pair<int, int> k = q.front(); q.pop();
        int cx = k.first, cy = k.second;
        for (int i = 0; i < 3; ++i){
            int vx = cx+dx[i], vy = cy+dy[i];
            if(check(vx, vy)){
                if((M[vx][vy] > 0 && caut(vx, vy, M[vx][vy], timp[cx][cy])) || M[vx][vy] == 0)
                    if(timp[vx][vy] > timp[cx][cy]+1){
                        timp[vx][vy] = timp[cx][cy] + 1;
                        q.push(make_pair(vx, vy));
                    }else if(timp[vx][vy] <= timp[cx][cy]){
                        timp[vx][vy] = timp[cx][cy] + 1;
                        q.push(make_pair(vx, vy));
                    }
            }
        }
        if(timp[e][m] != INF)
            break;
    }
}

int main()
{
    ifstream fin ("gheizere.in");
    ofstream fout ("gheizere.out");
    fin >> n >> m >> tk >> v >> e;
    for (int it = 1; it <= tk; ++it){
        int i1, j1, r, t, d;
        fin >> i1 >> j1 >> r >> t >> d;
        a[i1][j1] = 100*t+d;
        for (int i = max(1, i1-r); i <= min(n, i1+r); ++i)
            for (int j = max(1, j1-r); j <= min(m, j1+r); ++j)
                M[i][j] = max(M[i][j], r);
        for (int i = 0; i < 253; ++i)
            for (int j = 0; j < 253; ++j)
                timp[i][j] = INF;
    }
    lee();
    fout << timp[e][m] << "\n";
}

