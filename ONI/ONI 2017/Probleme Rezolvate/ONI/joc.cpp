#include <fstream>

using namespace std;

int n, m, v[55][55], x1, y1, mx, sz;
bool ok[55][55];

bool check(int x, int y, int q)
{
    return (x > 0 && y > 0 && x <= n && y <= m && !ok[x][y] && v[x][y] == q);
}

bool check2(int x, int y, int q)
{
    return (x > 0 && y > 0 && x <= n && y <= m && v[x][y] == q);
}

void fill(int x, int y, int q)
{
    if(check(x, y, q)){
        ok[x][y] = 1;
        ++sz;
        fill(x+1, y, q);
        fill(x, y+1, q);
        fill(x-1, y, q);
        fill(x, y-1, q);
    }
}

int destroy(int x, int y)
{
    sz = 0;
    fill(x, y, v[x][y]);
    return sz;
}

void click(int x, int y, int q)
{
    if(check2(x, y, q)){
        v[x][y] = 0;
        click(x+1, y, q);
        click(x, y+1, q);
        click(x-1, y, q);
        click(x, y-1, q);
    }
}

void compact()
{
    int r[55][55] = {0};
    int jp = 1;
    for (int j = 1; j <= m; ++j){
        bool mpty = true;
        for (int i = 1; i <= n && mpty; ++i)
            if(v[i][j] != 0)
                mpty = false;
        if(mpty)
            continue;
        int ip = n;
        for (int i = n; i > 0; --i)
            if(v[i][j] != 0)
                r[ip--][jp] = v[i][j];
        ++jp;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = r[i][j];
}

int main()
{
    ifstream fin ("joc11.in");
    ofstream fout ("joc11.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            char q;
            fin >> q;
            if(q == 'R')
                v[i][j] = 1;
            else if(q == 'V')
                v[i][j] = 2;
            else if(q == 'A')
                v[i][j] = 3;
        }
    int p = 0;
    do{
        for (int i = 0; i < 55; ++i)
            for (int j = 0; j < 55; ++j)
                ok[i][j] = 0;
        mx = 0;
        for (int j = 1; j <= m; ++j)
            for (int i = n; i > 0; --i)
                if(v[i][j] != 0){
                    int now = destroy(i, j);
                    if(now > mx){
                        mx = now;
                        x1 = i;
                        y1 = j;
                    }
                }
        if(mx > 1){
            click(x1, y1, v[x1][y1]);
            compact();
            ++p;
        }
        /*for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j)
                printf("%d", v[i][j]);
            printf("\n");
        }
        printf("\n\n");*/
    }while(mx > 1);
    /*for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            printf("%d", v[i][j]);
        printf("\n");
    }*/
    fout << p << "\n";
    fin.close();
    fout.close();
    return 0;
}

