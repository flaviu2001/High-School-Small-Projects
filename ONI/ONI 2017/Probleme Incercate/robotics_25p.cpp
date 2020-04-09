#include <fstream>

using namespace std;

int n, m, t, cerinta1, cerinta2 = 1<<30, p1, p2;

struct robot{
    int x, y, type;
}v[2005], r1[2005], r2[2005];

int abs(int x)
{
    return x >= 0 ? x : -x;
}

int manhattan(robot x1, robot x2)
{
    return abs(x1.x-x2.x) + abs(x1.y-x2.y);
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    ifstream fin ("robotics.in");
    ofstream fout ("robotics.out");
    fin >> n >> m >> t;
    for (int i = 1; i <= m; ++i){
        fin >> v[i].x >> v[i].y >> v[i].type;
        if(v[i].type == 1)
            r1[++p1] = v[i];
        else r2[++p2] = v[i];
        robot p1, p2;
        cerinta1 += t*2+1;
        if(v[i].type == 1){
            p1.x = v[i].x-t;
            p1.y = v[i].y+t;
            p2.x = v[i].x+t;
            p2.y = v[i].y-t;
        }else{
            p1.x = v[i].x+t;
            p1.y = v[i].y+t;
            p2.x = v[i].x-t;
            p2.y = v[i].y-t;
        }
        int scad1 = 0, scad2 = 0;
        if(p1.x < 1)
            scad1 = max(scad1, 1-p1.x);
        if(p1.x > n)
            scad1 = max(scad1, p1.x-n);
        if(p1.y < 1)
            scad1 = max(scad1, 1-p1.y);
        if(p1.y > n)
            scad1 = max(scad1, p1.y-n);
        if(p2.x < 1)
            scad2 = max(scad2, 1-p2.x);
        if(p2.x > n)
            scad2 = max(scad2, p2.x-n);
        if(p2.y < 1)
            scad2 = max(scad2, 1-p2.y);
        if(p2.y > n)
            scad2 = max(scad2, p2.y-n);
        cerinta1 -= scad1 + scad2;
    }
    if(m <= 100)
    for (int i = 1; i < p1; ++i)
        for (int j = i+1; j <= p1; ++j)
            for (int i1 = 1; i1 < p2; ++i1)
                for (int j1 = i1+1; j1 <= p2; ++j1){
                    int d1 = manhattan(r1[i], r2[i1]), d2 = manhattan(r1[i], r2[j1]), d3 = manhattan(r1[j], r2[i1]), d4 = manhattan(r1[j], r2[j1]);
                    if(d1%2 || d2%2 || d3%2 || d4%2)
                        continue;
                    else{
                        cerinta2 = min(cerinta2, max(d1/2, max(d2/2, max(d3/2, d4/2))));
                    }
                }
    if(cerinta2 == 1<<30)
        cerinta2 = 0;
    fout << cerinta1 << "\n" << cerinta2;
    return 0;
}

