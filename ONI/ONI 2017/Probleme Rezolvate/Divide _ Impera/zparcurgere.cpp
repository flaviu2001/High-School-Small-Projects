#include <fstream>

using namespace std;

int n, t, po = 1;

int bloodMagicFuckery(int x, int y, int lo, int hi, int I1, int J1, int I2, int J2){
    if(hi-lo > 3){
        int p = (hi-lo+1)/4;
        if(x <= (I1+I2)/2 && y <= (J1+J2)/2)
            return p * 0 + bloodMagicFuckery(x, y, lo, lo+p-1, I1, J1, (I1+I2)/2, (J1+J2)/2);
        if(x <= (I1+I2)/2 && y >  (J1+J2)/2)
            return p * 1 + bloodMagicFuckery(x, y, lo+p, lo+p*2-1, I1, (J1+J2)/2+1, (I1+I2)/2, J2);
        if(x >  (I1+I2)/2 && y <= (J1+J2)/2)
            return p * 2 + bloodMagicFuckery(x, y, lo+p*2, lo+p*3-1, (I1+I2)/2+1, J1, I2, (J1+J2)/2);
      //if(x >  (I1+I2)/2 && y >  (J1+J2)/2)
            return p * 3 + bloodMagicFuckery(x, y, lo+p*3, lo+p*4-1, (I1+I2)/2+1, (J1+J2)/2+1, I2, J2);
    }
    if(x == I1 && y == J1)
        return 0;
    if(x == I1 && y == J2)
        return 1;
    if(x == I2 && y == J1)
        return 2;
    return 3;
}

int main()
{
    ifstream fin ("z.in");
    ofstream fout ("z.out");
    fin >> n >> t;
    for (int i = 1; i <= n; ++i)
        po *= 2;
    while(t--){
        int x, y;
        fin >> x >> y;
        fout << bloodMagicFuckery(x, y, 1, po*po, 1, 1, po, po) + 1 << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

