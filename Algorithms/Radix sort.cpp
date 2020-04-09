#include <bits/stdc++.h>

using namespace std;

const int64_t base = 256;
int n, v[10000005], r[10000005];

void counting_sort(int a[], int b[], int64_t byte)
{
    int64_t cnt[260] = {0}, index[260] = {0};
    for(int64_t i = 0; i < n; ++i){
        int64_t dig = (a[i]>>(byte*8))&255;
        ++cnt[dig];
    }
    for (int64_t i = 1; i < 256; ++i)
        index[i] = index[i-1]+cnt[i-1];
    for (int64_t i = 0; i < n; ++i){
        int64_t dig = (a[i]>>(byte*8))&255;
        b[index[dig]++] = a[i];
    }
}

int main()
{
    ifstream fin ("radixsort.in");
    ofstream fout ("radixsort.out");
    fin >> n;
    int64_t a, b, c;
    fin >> a >> b >> c;
    v[0] = b%c;
    for (int64_t i = 1; i < n; ++i)
        v[i] = (1LL*a*v[i-1]%c+b)%c;
    for (int64_t i = 0; i < 4; ++i)
        if(i%2==0)
            counting_sort(v, r, i);
        else counting_sort(r, v, i);
    for (int64_t i = 0; i < n; i += 10)
        fout << v[i] << " ";
    return 0;
}

