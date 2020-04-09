#include <fstream>

using namespace std;

int n, v, maxx = -2000000000, I(1), J;

void solve();
void write();

int main()
{
    solve();
    write();
    return 0;
}

void solve()
{
    ifstream fin ("ssm.in");
    fin >> n;
    int ax, bst(0), j;
    for ( int i = 1; i <= n; ++i )
    {
        fin >> v;
        ax = bst;
        if ( ax + v >= v )
        {
            bst = ax + v;
            if ( maxx < bst )
                I = j, J = i, maxx = bst;
        }
        else
        {
            j = i;
            bst = v;
            if ( maxx < bst )
                I = j, J = i, maxx = bst;
        }
    }
    fin.close();
}

void write()
{
    ofstream fout ( "ssm.out" );
    fout << maxx << ' ' << I << ' ' << J << "\n";
    fout.close();
}
