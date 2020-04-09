#include <fstream>

using namespace std;

int n, m, trueN = 1;
//tip - true pentru triunghi sus
int divide_et_impera(int x, int y, bool tip = true, int xmin = 1, int xmax = trueN, int ymin = 1, int ymax = trueN*2-1)
{
    if(tip){
        if(xmax==xmin+1 && ymax==ymin+2){
            if(xmin == x && ymin == y)
                return 0;
            if(ymax == y)
                return 3;
            if(ymin == y)
                return 1;
            return 2;
        }
        if(xmax==xmin && ymax==ymin)
            return 0;
        if(x <= (xmin+xmax)/2)
            return 0 + divide_et_impera(x, y, true, xmin, (xmin+xmax)/2, ymin, (ymin+ymax)/2-1);
        if(y > (ymin+ymax)/2)
            return 3 + divide_et_impera(x, y, true, (xmin+xmax)/2+1, xmax, (ymin+ymax)/2+1, ymax);
        if((x-(xmin+xmax)/2-1)*2+ymin >= y)
            return 1 + divide_et_impera(x, y, true, (xmin+xmax)/2+1, xmax, ymin, (ymin+ymax)/2-1);
        return 2 + divide_et_impera(x, y, false, (xmin+xmax)/2+1, xmax, ymin+1, (ymin+ymax)/2);
    }else{
        if(xmax==xmin+1 && ymax==ymin+2){
            if(xmin == x && ymin == y)
                return 1;
            if(xmax == x)
                return 0;
            if(ymax == y)
                return 3;
            return 2;
        }
        if(x > (xmin+xmax)/2)
            return 0 + divide_et_impera(x, y, false, (xmin+xmax)/2+1, xmax, (ymin+ymax)/2+1, ymax);
        if(y <= (ymin+ymax)/2-1)
            return 1 + divide_et_impera(x, y, false, xmin, (xmin+xmax)/2, ymin, (ymin+ymax)/2-1);
        if((ymin+ymax)/2+1+(x-xmin)*2 > y)
            return 2 + divide_et_impera(x, y, true, xmin, (xmin+xmax)/2, (ymin+ymax)/2, ymax-1);
        return 3 + divide_et_impera(x, y, false, xmin, (xmin+xmax)/2, (ymin+ymax)/2+1, ymax);
    }
    return 0;
}

int main()
{
    ifstream fin ("descompunere.in");
    ofstream fout ("descompunere.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        trueN *= 2;
    while(m--){
        int x, y;
        fin >> x >> y;
        fout << divide_et_impera(x, y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

