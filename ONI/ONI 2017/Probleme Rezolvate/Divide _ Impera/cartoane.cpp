#include <fstream>

using namespace std;

int n, m, a, b;
int r[200][200];

void read()
{
    ifstream fin ("cartoane.in");
    fin >> n >> m >> a >> b;
    for (int i = 0; i < 200; ++i)
        for (int j = 0; j < 200; ++j)
            r[i][j] = -1;
    fin.close();
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int cartoane(int x, int y)
{
    int X = x, Y = y;
    if(r[x][y] != -1)
        return r[x][y];

    if(x%a == 0 && y%b == 0)
        return (x/a) * (y/b);
    if(x%b == 0 && y%a == 0)
        return (x/b) * (y/a);
    if((x < a || y < b) && (x < b || y < a))
        return 0;

    int ver = 0, hor = 0, inver = 0, inhor = 0;
    for (int i = 1; i < y; ++i){
        int x1, y1;
        if(r[x][i] != -1)
            x1 = r[x][i];
        else x1 = cartoane(x, i);
        if(r[x][y-i] != -1)
            y1 = r[x][y-i];
        else y1 = cartoane(x, y-i);
        ver = max(ver, x1 + y1);
    }
    for (int j = 1; j < x; ++j){
        int x1, y1;
        if(r[j][y] != -1)
            x1 = r[j][y];
        else x1 = cartoane(j, y);
        if(r[x-j][y] != -1)
            y1 = r[x-j][y];
        else y1 = cartoane(x-j, y);
        hor = max(hor, x1 + y1);
    }

    int aux = x;
    x = y;
    y = aux;

    for (int i = 1; i < y; ++i){
        int x1, y1;
        if(r[x][i] != -1)
            x1 = r[x][i];
        else x1 = cartoane(x, i);
        if(r[x][y-i] != -1)
            y1 = r[x][y-i];
        else y1 = cartoane(x, y-i);
        inver = max(inver, x1 + y1);
    }
    for (int j = 1; j < x; ++j){
        int x1, y1;
        if(r[j][y] != -1)
            x1 = r[j][y];
        else x1 = cartoane(j, y);
        if(r[x-j][y] != -1)
            y1 = r[x-j][y];
        else y1 = cartoane(x-j, y);
        inhor = max(inhor, x1 + y1);
    }

    r[X][Y] = max(max(ver, hor), max(inver, inhor));
    return r[X][Y];
}

void write()
{
    ofstream fout ("cartoane.out");
    fout << cartoane(n, m) << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}

