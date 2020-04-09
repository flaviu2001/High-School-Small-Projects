#include <fstream>
#include <queue>
#define ff first
#define ss second

using namespace std;

vector< pair<int, int> > p1, p2;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int t1, t2, s1, s2, s3, s4, r1, r2, r3, r4, n, m, k;
int v1[1005][1005], v2[1005][1005];

void read();
void wall();
void valid_points();
void lee(int v[1005][1005], int pix, int piy);
bool check(int, int);
int solution();
int min(int, int);
int max(int, int);
void write();

int main()
{
    read();
    wall();
    valid_points();
    lee(v1, r1, r2);
    lee(v2, r3, r4);
    write();
    return 0;
}

void read()
{
    ifstream fin ("ai.in");
    fin >> n >> t1 >> t2 >> s1 >> s2 >> s3 >> s4 >> r1 >> r2 >> r3 >> r4 >> m;
    while(m--){
        int x, y;
        fin >> x >> y;
        v1[x][y] = v2[x][y] = -1;
    }
    v1[t1][t2] = v2[t1][t2] = -2;
    fin.close();
}

void wall()
{
    for (int i = 1; i <= n; ++i){
        int pd[1005];
        for (int ii = 0; ii <= 1004; ++ii)
            pd[ii] = 0;
        for (int j = 1; j <= n; ++j)
            if (v1[i][j] == -1){
                pd[j] = pd[j-1]+1;
                k = max(k, pd[j]);
            }
    }
    for (int i = 1; i <= n; ++i){
        int pd[1005];
        for (int ii = 0; ii <= 1004; ++ii)
            pd[ii] = 0;
        for (int j = 1; j <= n; ++j)
            if (v1[j][i] == -1){
                pd[j] = pd[j-1]+1;
                k = max(k, pd[j]);
            }
    }
}

void valid_points()
{
    int k1 = t1-s1, k2 = t2-s2, k3 = t1-s3, k4 = t2-s4;
    if (k1 == 0)
        k2 = 1 * k2 < 0 ? -1 : 1;
    if (k2 == 0)
        k1 = 1 * k1 < 0 ? -1 : 1;
    if (k3 == 0)
        k4 = 1 * k4 < 0 ? -1 : 1;
    if (k4 == 0)
        k3 = 1 * k3 < 0 ? -1 : 1;
    for (int i = 2; i <= 1005; ++i)
        while(k1%i == 0 && k2%i == 0)
            k1 /= i,
            k2 /= i;
    for (int i = 2; i <= 1005; ++i)
        while(k3%i == 0 && k4%i == 0)
            k3 /= i,
            k4 /= i;
    int i1 = s1, j1 = s2, i2 = s3, j2 = s4;
    while (i1 != t1 || j1 != t2){
        p1.push_back(make_pair(i1, j1));
        i1 += k1;
        j1 += k2;
    }
    while (i2 != t1 || j2 != t2){
        p2.push_back(make_pair(i2, j2));
        i2 += k3;
        j2 += k4;
    }
}

void lee(int v[1005][1005], int pix, int piy)
{
    queue< pair<int, int> > q;
    q.push(make_pair(pix, piy));
    v[pix][piy] = 1;
    while(!q.empty()){
        int k = v[q.front().ff][q.front().ss];
        for (int i = 0; i < 4; ++i){
            int& kk = v[q.front().ff + dx[i]][q.front().ss + dy[i]];
            if (check(q.front().ff + dx[i], q.front().ss + dy[i]) && kk == 0){
                kk = k + 1;
                q.push(make_pair(q.front().ff + dx[i], q.front().ss + dy[i]));
            }
        }
        q.pop();
    }
}

bool check(int x, int y)
{
    if (x > 0 && y > 0 && x <= n && y <= n)
        return true;
    return false;
}

int solution()
{
    int mn = 1 << 30;
    for (unsigned i = 0; i < p1.size(); ++i)
        for (unsigned j = 0; j < p2.size(); ++j)
            if (v1[p1[i].ff][p1[i].ss] > 0 && v2[p2[j].ff][p2[j].ss] > 0)
                mn = min(mn, max(v1[p1[i].ff][p1[i].ss], v2[p2[j].ff][p2[j].ss]));
    for (unsigned i = 0; i < p2.size(); ++i)
        for (unsigned j = 0; j < p1.size(); ++j)
            if (v1[p2[i].ff][p2[i].ss] > 0 && v2[p1[j].ff][p1[j].ss] > 0)
                mn = min(mn, max(v1[p2[i].ff][p2[i].ss], v2[p1[j].ff][p1[j].ss]));
    return mn - 1;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void write()
{
    ofstream fout ("ai.out");
    fout << k << "\n" << solution() << "\n";
    fout.close();
}