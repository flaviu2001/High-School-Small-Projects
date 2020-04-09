#include <fstream>

using namespace std;

void gcd2(int &x, int &y, int a, int b)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        gcd2(x, y, b, a%b);
        int aux = x;
        x = y;
        y = aux - (a/b)*y;
    }
}

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    return gcd(y, x%y);
}

int main()
{
    ifstream fin ("euclid3.in");
    ofstream fout ("euclid3.out");
    int t;
    fin >> t;
    while(t--){
        int a, b, d, x, y;
        fin >> a >> b >> d;
        int factor = gcd(a, b);
        if(d%factor != 0){
            fout << "0 0\n";
            continue;
        }
        factor = d / factor;
        gcd2(x, y, a, b);
        fout << x * factor << " " << y * factor << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
