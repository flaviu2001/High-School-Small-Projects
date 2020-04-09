#include <cstdio>

using namespace std;

struct coord
{
    int x, y;
}c[82];

int v[10][10], p, f;

void read();
bool check_position(int i1, int j1);
void solve();
void write();

int main()
{
    read();
    solve();
    write();
    return 0;
}

void read()
{
    freopen ( "sudoku.in", "r", stdin );
    char q;
    for ( int i = 1; i <= 9; ++i )
        for ( int j = 1; j <= 10; ++j )
        {
            scanf ( "%c", &q );
            if ( q == '0' )
                c[++f].x = i, c[f].y = j;
            if (j != 10)
                v[i][j] = int(q-'0');
        }
    fclose(stdin);
}

void solve()
{
    while(p != f)
    {
        ++p;
        do
            ++v[c[p].x][c[p].y];
        while ( v[c[p].x][c[p].y] <= 9 && !check_position(c[p].x, c[p].y) );

        if ( v[c[p].x][c[p].y] == 10 )
            v[c[p].x][c[p].y] = 0,
            p -= 2;
        //printf ( "%d\n", p );
    }
}

bool check_position(int i1, int j1)
{
    for ( int i = 1; i < i1; ++i )
        if ( v[i][j1] == v[i1][j1] )
            return 0;
    for ( int i = i1+1; i <= 9; ++i )
        if ( v[i][j1] == v[i1][j1] )
            return 0;
    for ( int j = 1; j < j1; ++j )
        if ( v[i1][j] == v[i1][j1] )
            return 0;
    for ( int j = j1+1; j <= 9; ++j )
        if ( v[i1][j] == v[i1][j1] )
            return 0;

    if ( i1 >= 1 && i1 <= 3 && j1 >= 1 && j1 <= 3  )
        for ( int i = 1; i <= 3; ++i )
            for ( int j = 1; j <= 3; ++j )
            {
                if ( i == i1 && j == j1 )
                    continue;
                if ( v[i][j] == v[i1][j1] )
                    return 0;
            }
    else if ( i1 >= 1 && i1 <= 3 && j1 >= 4 && j1 <= 6  )
        for ( int i = 1; i <= 3; ++i )
                for ( int j = 4; j <= 6; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    else if ( i1 >= 1 && i1 <= 3 && j1 >= 7 && j1 <= 9  )
        for ( int i = 1; i <= 3; ++i )
                for ( int j = 7; j <= 9; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    else if ( i1 >= 4 && i1 <= 6 && j1 >= 1 && j1 <= 3  )
        for ( int i = 4; i <= 6; ++i )
            for ( int j = 1; j <= 3; ++j )
            {
                if ( i == i1 && j == j1 )
                    continue;
                if ( v[i][j] == v[i1][j1] )
                    return 0;
            }

    else if ( i1 >= 4 && i1 <= 6 && j1 >= 4 && j1 <= 6  )
        for ( int i = 4; i <= 6; ++i )
                for ( int j = 4; j <= 6; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    else if ( i1 >= 4 && i1 <= 6 && j1 >= 7 && j1 <= 9  )
        for ( int i = 4; i <= 6; ++i )
            for ( int j = 7; j <= 9; ++j )
            {
                if ( i == i1 && j == j1 )
                    continue;
                if ( v[i][j] == v[i1][j1] )
                    return 0;
            }
    else if ( i1 >= 7 && i1 <= 9 && j1 >= 1 && j1 <= 3  )
        for ( int i = 7; i <= 9; ++i )
                for ( int j = 1; j <= 3; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    else if ( i1 >= 7 && i1 <= 9 && j1 >= 4 && j1 <= 6  )
        for ( int i = 7; i <= 9; ++i )
                for ( int j = 4; j <= 6; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    else if ( i1 >= 7 && i1 <= 9 && j1 >= 7 && j1 <= 9  )
        for ( int i = 7; i <= 9; ++i )
                for ( int j = 7; j <= 9; ++j )
                {
                    if ( i == i1 && j == j1 )
                        continue;
                    if ( v[i][j] == v[i1][j1] )
                        return 0;
                }
    return 1;
}

void write()
{
    freopen ( "sudoku.out", "w", stdout );
    for ( int i = 1; i <= 9; ++i )
    {
        for ( int j = 1; j <= 9; ++j )
            printf ( "%d", v[i][j] );
        printf ( "\n" );
    }
    fclose(stdout);
}
