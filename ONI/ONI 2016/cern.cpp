#include <fstream>

using namespace std;

int main()
{
    freopen ( "cern.in", "r", stdin );
    freopen ( "cern.out", "w", stdout );
    int sens, grade;
    char point;
    scanf ( "%c%d%d", &point, &sens, &grade );
    grade = grade % 1080;
    if ( point == 'A' && sens == 1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf ( "%d 1", grade );
        else if ( grade > 180 && grade < 240 )
            printf ( "%d 2", 540 - grade );
        else if ( grade > 240 && grade < 540 )
            printf ( "%d 3", ( grade - 120 ) % 360 );
        else if ( grade > 540 && grade < 600 )
            printf ( "%d 2", 780 - grade );
        else if ( grade > 600 && grade < 900 )
            printf ( "%d 2", grade - 600 );
        else if ( grade > 900 && grade < 960 )
            printf ( "%d 3", 1080 - grade );
        else // if ( grade > 960 && grade < 1080 )
            printf ( "%d 1", grade - 720 );
        return 0;
    }
    if ( point == 'A' && sens == -1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf( "%d 1", 360 - grade );
        else if ( grade > 120 && grade < 180 )
            printf( "%d 3", 60 + grade );
        else if ( grade > 180 && grade < 480 )
            printf( "%d 2", 480 - grade );
        else if ( grade > 480 && grade < 540 )
            printf( "%d 1", grade - 300 );
        else if ( grade > 540 && grade < 840 )
            printf( "%d 3", ( 960 - grade ) % 360 );
        else if ( grade > 840 && grade < 900 )
            printf( "%d 2", grade - 540 );
        else  // if ( grade > 900 && grade < 1080 )
            printf( "%d 1", 1080 - grade );
        return 0;
    }
    if ( point == 'B' && sens == 1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf ( "%d 1", 60 + grade );
        else if ( grade > 120 && grade < 180 )
            printf ( "%d 2", 480 - grade );
        else if ( grade > 180 && grade < 480 )
            printf ( "%d 3", ( grade - 60 ) % 360 );
        else if ( grade > 480 && grade < 540 )
            printf ( "%d 2", 720 - grade );
        else if ( grade > 540 && grade < 840 )
            printf ( "%d 2", grade - 540 );
        else if ( grade > 840 && grade < 900 )
            printf ( "%d 3", 900 - grade );
        else // if ( grade > 900 && grade < 1080 )
            printf ( "%d 1", grade - 660 );
        return 0;
    }
    if ( point == 'B' && sens == -1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf( "%d 1", ( 420 - grade ) % 360 );
        else if ( grade > 180 && grade < 240 )
            printf( "%d 3", 120 + grade );
        else if ( grade > 240 && grade < 540 )
            printf( "%d 2", 540 - grade );
        else if ( grade > 540 && grade < 600 )
            printf( "%d 1", grade - 360 );
        else if ( grade > 600 && grade < 900 )
            printf( "%d 3", ( 1020 - grade ) % 360 );
        else if ( grade > 900 && grade < 960 )
            printf( "%d 2", grade - 600 );
        else  // if ( grade > 960 && grade < 1080 )
            printf( "%d 1", 1140 - grade );
        return 0;
    }
    if ( point == 'C' && sens == 1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf ( "%d 2", 120 + grade );
        else if ( grade > 180 && grade < 240 )
            printf ( "%d 3", 300 - grade );
        else if ( grade > 240 && grade < 540 )
            printf ( "%d 1", grade % 360 );
        else if ( grade > 540 && grade < 600 )
            printf ( "%d 2", 900 - grade );
        else if ( grade > 600 && grade < 900 )
            printf ( "%d 3", ( grade - 480 ) % 360 );
        else if ( grade > 900 && grade < 960 )
            printf ( "%d 1", 1140 - grade );
        else // if ( grade > 960 && grade < 1080 )
            printf ( "%d 2", grade - 960 );
        return 0;
    }
    if ( point == 'C' && sens == -1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf( "%d 2", 120 - grade );
        else if ( grade > 120 && grade < 180 )
            printf( "%d 1", 60 + grade );
        else if ( grade > 180 && grade < 480 )
            printf( "%d 3", ( 600 - grade ) % 360 );
        else if ( grade > 480 && grade < 540 )
            printf( "%d 2", grade - 180 );
        else if ( grade > 540 && grade < 840 )
            printf( "%d 1", ( 1080 - grade ) % 360 );
        else if ( grade > 840 && grade < 900 )
            printf( "%d 3", grade - 780 );
        else  // if ( grade > 900 && grade < 1080 )
            printf( "%d 2", 1200 - grade );
        return 0;
    }
    if ( point == 'D' && sens == 1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf ( "%d 2", 180 + grade );
        else if ( grade > 120 && grade < 180 )
            printf ( "%d 3", 240 - grade );
        else if ( grade > 180 && grade < 480 )
            printf ( "%d 1", ( grade + 60 ) % 360 );
        else if ( grade > 480 && grade < 540 )
            printf ( "%d 2", 840 - grade );
        else if ( grade > 540 && grade < 840 )
            printf ( "%d 3", ( grade - 60 ) % 360 );
        else if ( grade > 840 && grade < 900 )
            printf ( "%d 1", 1080 - grade );
        else // if ( grade > 900 && grade < 1080 )
            printf ( "%d 2", grade - 900 );
        return 0;
    }
    if ( point == 'D' && sens == -1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf( "%d 2", 180 - grade );
        else if ( grade > 180 && grade < 240 )
            printf( "%d 1", grade );
        else if ( grade > 240 && grade < 540 )
            printf( "%d 3", ( 660 - grade ) % 360 );
        else if ( grade > 540 && grade < 600 )
            printf( "%d 2", grade - 240 );
        else if ( grade > 600 && grade < 900 )
            printf( "%d 1", ( 1140 - grade ) % 360 );
        else if ( grade > 900 && grade < 960 )
            printf( "%d 3", grade - 840 );
        else  // if ( grade > 960 && grade < 1080 )
            printf( "%d 2", 1260 - grade );
        return 0;
    }
    if ( point == 'E' && sens == 1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf ( "%d 3", ( 240 + grade ) % 360 );
        else if ( grade > 180 && grade < 240 )
            printf ( "%d 1", 420 - grade );
        else if ( grade > 240 && grade < 540 )
            printf ( "%d 2", grade - 240 );
        else if ( grade > 540 && grade < 600 )
            printf ( "%d 3", 660 - grade );
        else if ( grade > 600 && grade < 900 )
            printf ( "%d 1", grade % 360 );
        else if ( grade > 900 && grade < 960 )
            printf ( "%d 2", 1260 - grade );
        else // if ( grade > 960 && grade < 1080 )
            printf ( "%d 3", grade - 840 );
        return 0;
    }
    if ( point == 'E' && sens == -1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf( "%d 3", 240 - grade );
        else if ( grade > 120 && grade < 180 )
            printf( "%d 2", 180 + grade );
        else if ( grade > 180 && grade < 480 )
            printf( "%d 1", ( 720 - grade ) % 360 );
        else if ( grade > 480 && grade < 540 )
            printf( "%d 3", grade - 420 );
        else if ( grade > 540 && grade < 840 )
            printf( "%d 2", 840 - grade );
        else if ( grade > 840 && grade < 900 )
            printf( "%d 1", grade - 660 );
        else  // if ( grade > 900 && grade < 1080 )
            printf( "%d 3", ( 1320 - grade ) % 360 );
        return 0;
    }
    if ( point == 'F' && sens == 1 )
    {
        if ( grade >= 0 && grade < 120 )
            printf ( "%d 3", ( 300 + grade ) % 360 );
        else if ( grade > 120 && grade < 180 )
            printf ( "%d 1", 360 - grade );
        else if ( grade > 180 && grade < 480 )
            printf ( "%d 2", grade - 180 );
        else if ( grade > 480 && grade < 540 )
            printf ( "%d 3", 600 - grade );
        else if ( grade > 540 && grade < 840 )
            printf ( "%d 1", ( grade - 300 ) % 360 );
        else if ( grade > 840 && grade < 900 )
            printf ( "%d 2", 1200 - grade );
        else // if ( grade > 900 && grade < 1080 )
            printf ( "%d 3", grade - 780 );
        return 0;
    }
    if ( point == 'F' && sens == -1 )
    {
        if ( grade >= 0 && grade < 180 )
            printf( "%d 3", 300 - grade );
        else if ( grade > 180 && grade < 240 )
            printf( "%d 2", 120 + grade );
        else if ( grade > 240 && grade < 540 )
            printf( "%d 1", ( 780 - grade ) % 360 );
        else if ( grade > 540 && grade < 600 )
            printf( "%d 3", grade - 480 );
        else if ( grade > 600 && grade < 900 )
            printf( "%d 2", 900 - grade );
        else if ( grade > 900 && grade < 960 )
            printf( "%d 1", grade - 720 );
        else  // if ( grade > 960 && grade < 1080 )
            printf( "%d 2", ( 1480 - grade ) % 360 );
        return 0;
    }
    return 0;
}
