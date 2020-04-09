#include <fstream>

int v[55][55], r[2505], n;

bool check(int x, int y){
    if (x > 0 && y > 0 && x < 55 && y < 55)
        return 1;
    return 0;
}

void fill_exterior(int x, int y){
    if (check(x, y) && v[x][y] == 0){
        v[x][y] = -2;
        fill_exterior(x+1, y);
        fill_exterior(x, y+1);
        fill_exterior(x-1, y);
        fill_exterior(x, y-1);
    }
}

void fill_interior(int x, int y){
    if (v[x][y] == 0){
        v[x][y] = -1;
        fill_interior(x+1, y);
        fill_interior(x, y+1);
        fill_interior(x-1, y);
        fill_interior(x, y-1);
    }
}

int main()
{
    std::ifstream fin ("zona.in");
    std::ofstream fout ("zona.out");
    int x0, y0, l, x, z, s = 0, f;
    fin >> x0 >> y0 >> n >> l;
    v[x0][y0] = -1;
    for (int i = 1; i <= l; ++i){
        fin >> x;
        r[(x0-1)*n+y0] = i;
        switch(x){
            case 1:
                --x0;
                break;
            case 2:
                ++y0;
                break;
            case 3:
                ++x0;
                break;
            default:
                --y0;
                break;
        }
        v[x0][y0] = -1;
    }
    z = l - r[(x0-1)*n+y0] + 1;
    fout << z << "\n";

    f = r[(x0-1)*n+y0];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (r[(i-1)*n+j] < f)
                v[i][j] = 0;

    for (int i = 1; i < 55; ++i)
        fill_exterior(1, i),
        fill_exterior(i, 1),
        fill_exterior(54, i),
        fill_exterior(i, 54);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (v[i][j] == 0)
                fill_interior(i, j);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (v[i][j] == -1 && v[i+1][j] == -1 && v[i][j+1] == -1 && v[i+1][j+1] == -1)
                ++s;
    fout << s << "\n";
    return 0;
}
