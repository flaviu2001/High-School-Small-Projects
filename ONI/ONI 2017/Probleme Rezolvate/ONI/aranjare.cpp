#include <fstream>

using namespace std;

ifstream fin ("aranjare.in");
ofstream fout ("aranjare.out");
int n, m, pl; // pl = pozitie libera
char v[15005];

void swap(char &x, char &y)
{
    char aux = x;
    x = y;
    y = aux;
}

void make_simple_move(int pos)
{
    fout << pos << "\n";
    swap(v[pos], v[pl]);
    swap(v[pos+1], v[pl+1]);
    pl = pos;
}

void make_move(int pos)
{
    if(v[pos+1] != 'S')
        make_simple_move(pos);
    else{
        make_simple_move(m-1);
        make_simple_move(pos);
    }
    int k;
    for (k = pos+1; k <= m; ++k)
        if(v[k] == 'F')
            break;
    if(k != m)
        make_simple_move(k);
    else{
        make_simple_move(m-1);
        make_simple_move(pos+2);
        make_simple_move(pos-1);
        make_simple_move(pos+1);
    }
}

int main()
{
    fin >> n; m = 2*n+2;
    for (int i = 1; i <= m; ++i)
        fin >> v[i];
    for (int i = 1; i <= m; ++i)
        if(v[i] == 'S'){
            pl = i;
            break;
        }
    for (int i = 1; i <= n; ++i)
        if(v[i] != 'F')
            make_move(i);
    if(v[n+1] != 'S')
        make_simple_move(n+1);
    return 0;
}

