#include <cstdio>
#define MAX 100005

using namespace std;

int n, k, v[MAX];
int q1[MAX], v1(1), b1(1);
int q2[MAX], v2(1), b2(1);

void read();
int solve();
int abs(int x);
void write();

int main(){
    read();
    write();
    return 0;
}

void read(){
    freopen ( "vile.in", "r", stdin );
    scanf ( "%d%d", &n, &k );
    for (int i = 1; i <= n; ++i)
        scanf ( "%d", &v[i] );
}

int solve(){
    int max(0);
    q1[1] = 1;
    q2[1] = 1;
    for (int i = 2; i < n; ++i){
        if(v[i] <= v[q1[v1]])
            q1[++v1] = i;
        else{
            while (v1 && v[q1[v1]] < v[i])
                --v1;
            q1[++v1] = i;
        }
        while (i - q1[b1] > k)
            ++b1;

        if (v[i] >= v[q2[v1]])
            q2[++v2] = i;
        else{
            while(v2 && v[q2[v2]] > v[i])
                --v2;
            q2[++v2] = i;
        }
        while (i - q2[b2] > k)
            ++b2;

        if (v[q1[b1]] - v[q2[b2]] > max)
            max = v[q1[b1]] - v[q2[b2]];
        //printf ( "%d %d\n", v[q1[b1]], v[q2[b2]] );
    }
    if (abs(v[q1[b1]] - v[n]) > max)
        max = abs(v[q1[b1]] - v[n]);
    if (abs(v[q2[b2]] - v[n]) > max)
        max = abs(v[q2[b2]] - v[n]);
    return max;
}

int abs(int x){
    if (x >= 0)
        return x;
    return -x;
}

void write(){
    freopen ( "vile.out", "w", stdout );
    printf ( "%d\n", solve() );
    fclose(stdout);
}
