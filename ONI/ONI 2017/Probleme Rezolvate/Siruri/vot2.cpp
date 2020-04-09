#include <fstream>
#define MAX 210

using namespace std;

int v[MAX];

int main()
{
    ifstream fin ("vot2.in");
    ofstream fout ("vot2.out");
    int n, m, p, q, valid_votes(0);
    char c;
    fin >> n >> m;
    while (m--)
    {
        p = 0;
        for ( int i = 1; i <= n; ++i )
        {
            fin >> c;
            if ( c == '+' )
                q = i, ++p;
        }
        if ( p == 1 )
            ++v[q], ++valid_votes;
    }
    for ( int i = 1; i <= n; ++i )
        if ( 20 * v[i] >= valid_votes )
            fout << i << " ";
    fin.close();
    fout.close();
    return 0;
}
