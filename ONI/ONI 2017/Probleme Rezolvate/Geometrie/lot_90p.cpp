#include <fstream>
#include <vector>
#define dd (double)

using namespace std;

struct coord{
    int x, y;
}dt;

int test;

bool check_same_side(coord p1, coord p2, coord p3, coord p4)
{
    double y = dd (dd p2.y - dd p1.y) / (dd p2.x - dd p1.x);
    int x2 = p3.x-p1.x;
    int y2 = p3.y-p1.y;
    int x3 = p4.x-p1.x;
    int y3 = p4.y-p1.y;
    double z2 = x2 * y;
    double z3 = x3 * y;
    if(y2 < z2 && y3 < z3)
        return true;
    if(y2 > z2 && y3 > z3)
        return true;
    return false;
}

int main()
{
    ifstream fin ("lot.in");
    ofstream fout ("lot.out");
    fin >> test;
    while(test--){
        vector<coord>v;
        int n;
        fin >> n;
        for (int i = 0; i < n; ++i){
            fin >> dt.x >> dt.y;
            v.push_back(dt);
        }
        fin >> dt.x >> dt.y;

        bool ok = true;
        if (n == 3 && ((v[0].x == v[1].x && v[1].x == v[2].x) || (v[0].y == v[1].y && v[1].y == v[2].y)))
            ok = false;
        if((v[n-1].x == v[n-2].x && v[n-2].x == v[0].x) || (v[n-1].y == v[n-2].y && v[n-2].y == v[0].y))
            ok = false;
        if((v[0].x == v[1].x && v[1].x == v[n-1].x) || (v[0].y == v[1].y && v[1].y == v[n-1].y))
            ok = false;
        for (int i = 3; i < n && ok; ++i)
            for (int j = i; j < n && ok; ++j)
                ok = check_same_side(v[i-3], v[i-2], v[i-1], v[j]) && check_same_side(v[i-2], v[i-1], v[i-3], v[j]) && !check_same_side(v[i-3], v[i-1], v[j], v[i-2]) && !check_same_side(v[i-2], v[j], v[i-1], v[i-3]);;
        /*for (int i = 3; i < n && ok; ++i)
            ok = check_same_side(v[i-3], v[i-2], v[i-1], v[i]) && check_same_side(v[i-2], v[i-1], v[i-3], v[i]) && !check_same_side(v[i-3], v[i-1], v[i], v[i-2]) && !check_same_side(v[i-2], v[i], v[i-1], v[i-3]);*/
        fout << ok << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

