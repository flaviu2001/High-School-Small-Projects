#include <fstream>
#include <queue>

using namespace std;

struct data{
int x, y;
}pi, pf, dt;

vector<int> r;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, v[145][145], pos[145*145];
bool p[145][145][4];

void read();
void add(int, int, int, int);
void swap(int&, int&);
void lee();
bool check(int, int);
void make_road();
int otherI(int);
void write();

int main()
{
    read();
    lee();
    make_road();
    write();
    return 0;
}

void read()
{
    ifstream fin ("paianjen.in");
    int t;
    fin >> n >> m >> pi.x >> pi.y >> pf.x >> pf.y >> t;
    while(t--){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        add(a, b, c, d);
    }
    fin.close();
}

void add(int a, int b, int c, int d)
{
    if (a > c)
        swap(a, c);
    if (b > d)
        swap(b, d);

    if (a == c)
        for (int i = 1; i <= d - b; ++i)
            p[a][b+i-1][1] = p[a][b+i][3] = 1;
    if (b == d)
        for (int i = 1; i <= c - a; ++i)
            p[a+i-1][b][2] = p[a+i][b][0] = 1;
}

void swap(int &x, int &y)
{
    int aux = x;
    x = y;
    y = aux;
}

void lee()
{
    queue<data> q;
    q.push(pi);
    v[pi.x][pi.y] = 1;
    while(!q.empty()){
        int k = v[q.front().x][q.front().y];
        for (int i = 0; i < 4; ++i){
            int& kk = v[q.front().x + dx[i]][q.front().y + dy[i]];
            if (check(q.front().x + dx[i], q.front().y + dy[i]) && !p[q.front().x][q.front().y][i] && kk == 0){
                kk = k + 1;
                pos[(q.front().x + dx[i]) * m + q.front().y + dy[i]] = q.front().x * m + q.front().y;
                dt.x = q.front().x + dx[i]; dt.y = q.front().y + dy[i];
                q.push(dt);
            }
            if (v[pf.x][pf.y])
                return;
        }
        q.pop();
    }
}

bool check(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

void make_road()
{
    int I = pf.x, J = pf.y, k = v[pf.x][pf.y];
    r.push_back(pf.x * m + pf.y);
    while(k > 1)
        for (int i = 0; i < 4; ++i){
            if (check(I+dx[i], J+dy[i]) && v[I + dx[i]][J + dy[i]] == k - 1 && !p[I+dx[i]][J+dy[i]][otherI(i)]){
                I += dx[i], J += dy[i];
                r.push_back(I * m + J);
                --k;
                break;
            }
        }
}

int otherI(int i)
{
    switch(i){
        case 0: return 2;
        case 1: return 3;
        case 2: return 0;
        case 3: return 1;
    }
    return 0;
}

void write()
{
    ofstream fout ("paianjen.out");
    fout << v[pf.x][pf.y] - 1 << "\n";
    for (unsigned i = r.size() - 1; i != 0; --i)
        fout << r[i] / m << " " << r[i] % m << "\n";
    fout << pf.x << " " << pf.y << "\n";
    fout.close();
}
