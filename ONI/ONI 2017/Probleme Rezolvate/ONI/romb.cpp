#include <fstream>

using namespace std;

double cx, cy, x, y;
long long k;

long long ausar_the_vile(double mnx, double mxx, double mny, double mxy, long long currentK, long long code)
{
    if(currentK == k)
        return code;

    if(y >= (mny+3*mxy)/4)
        return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, (mny+mxy)/2, mxy, currentK+1, 4*code-3);
    if(x <= (mnx*3+mxx)/4)
        return ausar_the_vile(mnx, (mnx+mxx)/2, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-2);
    if(y <= (mny*3+mxy)/4)
        return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, mny, (mny+mxy)/2, currentK+1, 4*code-1);
    if(x >= (mnx+3*mxx)/4)
        return ausar_the_vile((mnx+mxx)/2, mxx, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-0);

    if(x >= (mnx+mxx)/2 && y >= (mny+mxy)/2){
        double xlo = (mnx+mxx)/2, xhi = (mnx+3*mxx)/4, ylo = (mny+mxy)/2, yhi = (mny+3*mxy)/4;
        if((x-xlo)/(xhi-xlo) > (y-ylo)/(yhi-ylo))
            return ausar_the_vile((mnx+mxx)/2, mxx, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-0);
        return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, (mny+mxy)/2, mxy, currentK+1, 4*code-3);
    }
    if(x <= (mnx+mxx)/2 && y >= (mny+mxy)/2){
        double xlo = (mnx*3+mxx)/4, xhi = (mnx+mxx)/2, ylo = (mny+mxy)/2, yhi = (mny+3*mxy)/4;
        if((yhi-y)/(yhi-ylo) > (x-xlo)/(xhi-xlo))
            return ausar_the_vile(mnx, (mnx+mxx)/2, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-2);
        return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, (mny+mxy)/2, mxy, currentK+1, 4*code-3);
    }
    if(x <= (mnx+mxx)/2 && y <= (mny+mxy)/2){
        double xlo = (mnx*3+mxx)/4, xhi = (mnx+mxx)/2, ylo = (mny*3+mxy)/4, yhi = (mny+mxy)/2;
        if((x-xlo)/(xhi-xlo) > (y-ylo)/(yhi-ylo))
            return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, mny, (mny+mxy)/2, currentK+1, 4*code-1);
        return ausar_the_vile(mnx, (mnx+mxx)/2, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-2);
    }
    double xlo = (mnx+mxx)/2, xhi = (mnx+3*mxx)/4, ylo = (mny*3+mxy)/4, yhi = (mny+mxy)/2;
    if((yhi-y)/(yhi-ylo) > (x-xlo)/(xhi-xlo))
        return ausar_the_vile((mnx*3+mxx)/4, (mnx+3*mxx)/4, mny, (mny+mxy)/2, currentK+1, 4*code-1);
    return ausar_the_vile((mnx+mxx)/2, mxx, (mny*3+mxy)/4, (mny+3*mxy)/4, currentK+1, 4*code-0);
}

int main()
{
    ifstream fin ("romb1.in");
    ofstream fout ("romb1.out");
    long long m;
    fin >> m;
    while(m--){
        fin >> cx >> cy >> k >> x >> y;
        fout << ausar_the_vile(-cx, cx, -cy, cy, 0, 1) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

