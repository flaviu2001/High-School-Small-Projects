#include <fstream>

using namespace std;

int p, i, x, y, s, xm, xM, ym, yM, sens;
char a, b, c;

int main()
{
    ifstream fin ("ape.in");
    ofstream fout("ape.out");
    fin >> p >> a;
    c = a;
    for ( i = 2; i <= p + 1; ++i )
    {
        if ( i > p )
            b = c;
        else fin >> b;
        if ( a == 'N' )
            switch(b)
            {
                case 'N':
                    s -= x + 1; ++y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'V':
                    s -= x + 1; --x;
                    break;
            }
        else if ( a == 'S' )
            switch(b)
            {
                case 'S':
                    s += x; --y;
                    break;
                case 'V':
                    --x;
                    break;
                case 'E':
                    s += x++;
                    break;
            }
        else if ( a == 'V' )
            switch(b)
            {
                case 'N':
                    ++y;
                    break;
                case 'V':
                    --x;
                    break;
                case 'S':
                    s += x; --y;
                    break;
            }
        else switch(b)
            {
                case 'S':
                    --y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'N':
                    s -= x + 1;
                    ++y;
                    break;
            }
        if ( x > xM )
            xM = x;
        if ( x < xm )
            xm = x;
        if ( y > yM )
            yM = y;
        if ( y < ym )
            ym = y;
        a = b;
    }
    fout << xM - xm - 1 << " " << yM - ym - 1 << " ";
    if ( s < 0 )
        sens = 1, s = -s, s -=p;
    else sens = 0;
    fout << sens << " " << s << '\n';
    fin.close();
    fout.close();
    return 0;
}
