#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define iv (i + di[d])
#define jv (j + dj[d])
#define EPS 0.00001
#define DIM 52
#define INF 10.0 * INT_MAX

int di[] = { -1, 0, 1,  0 }, dj[] = { 0, 1, 0, -1 };
double a[DIM][DIM];
int c[DIM][DIM];
double ef[DIM][DIM];

int ip, jp, is, js;
int m, n;
double Lmax;
int c1[20*DIM][2], c2[20*DIM][2];

void Read();
int Ok(int, int);
void Init();
void Solve();
void Write();

int main()
{
	Read();
	Init();
	Solve();
	Write();
	return 0;
}

void Read()
{
	freopen( "excursia.in", "r", stdin);
	scanf("%d%d%lf", &n, &m, &Lmax);
	for ( int i = 1; i <= n; ++i )
       for (int j = 1; j <= m; ++j )
		  scanf ( "%d", &c[i][j] );
  	scanf ( "%d%d%d%d", &ip, &jp, &is, &js );
  	fclose(stdin);
}

void Init()
{
	for ( int i = 1; i <= n; ++i )
		for ( int j = 1; j <= m; ++j )
			ef[i][j] = a[i][j] = (double)INF;
	a[ip][jp]  = 0.;
	ef[ip][jp] = 0.;
}

double Dist(int i1, int j1, int i2, int j2)
{
    return sqrt((c[i2][j2] - c[i1][j1]) * (c[i2][j2] - c[i1][j1]) + 1.);
}

int Ok(int i1, int j1, int i2, int j2)
{
	if ( i2 < 1 || i2 > n || j2 < 1 || j2 > m ) return 0;
	if ( a[i1][j1] + Dist(i1, j1, i2, j2) > Lmax ) return 0;
	return 1;
}

double Efort(int i1, int j1, int i2, int j2)
{
    if ( c[i1][j1] == c[i2][j2] ) return 1.;
    double dif = c[i2][j2] - c[i1][j1];
    double e = dif * sqrt(dif * dif + 1);
    return e > 0 ? e : -(e / 2);
}

void Solve()
{
	int i, j, d, s, l;
	double Ef;
	c1[1][0] = ip;
	c1[1][1] = jp;
	for ( int k = 1; k > 0; k = l, memcpy(c1, c2, sizeof(c2)) )
		for ( l = 0, s = 1 ; s <= k; s++ )
			for ( i = c1[s][0], j = c1[s][1], d = 0; d < 4; d++)
				if (Ok(i, j, iv, jv))
				{
				   Ef = ef[i][j] + Efort(i, j, iv, jv);
				   if (ef[iv][jv] > Ef || fabs(ef[iv][jv] - Ef) < EPS && a[iv][jv] > a[i][j] + Dist(i, j, iv, jv)) // efort egal
					   ef[iv][jv] = Ef,
					   a[iv][jv] = a[i][j] + Dist(i, j, iv, jv),
					   c2[++l][0] = iv,
					   c2[l][1] = jv;
                }
}

void Write()
{
    freopen( "excursia.out", "w", stdout);
    long efin=0, dfin=0;
    efin = ef[is][js] * 1000.0;
    dfin = a[is][js] * 1000.0;
	printf("%.3lf %.3lf\n", efin/1000., dfin/1000.);
}
