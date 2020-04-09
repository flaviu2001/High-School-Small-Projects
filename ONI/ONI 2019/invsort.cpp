#include <bits/stdc++.h>

using namespace std;

ofstream fout ("invsort.out");
const int nmax = 32005;
int v[nmax], r[nmax], n;

int int_to_bit(int x, int k)
{
    return (x > k);
}

void separate(int lo, int hi, int k) //less than k or equal is 0, higher is 1
{
    int bit = int_to_bit(v[lo], k), cnt = 1;
    for (int i = lo+1; i <= hi; ++i)
        if(int_to_bit(v[i], k) != int_to_bit(v[i-1], k))
            ++cnt;
    if(cnt == 1)
        return;
    if(cnt == 2){
        if(bit == 1){
            reverse(v+lo, v+hi+1);
            fout << lo << " " << hi << "\n";
        }
        return;
    }
    if(cnt == 3){
        if(bit == 0){
            for (int i = lo; i <= hi; ++i)
                if(int_to_bit(v[i], k) != bit){
                    reverse(v+i, v+hi+1);
                    fout << i << " " << hi << "\n";
                    break;
                }
        }else{
            for (int i = hi; i >= lo; --i)
                if(int_to_bit(v[i], k) != bit){
                    reverse(v+lo, v+i+1);
                    fout << lo << " " << i << "\n";
                    break;
                }
        }
        return;
    }
    int last_non_bit = -1, second_last_non_bit = -1, yes = 0;
    for (int i = lo; i <= hi; ++i){
        if(i != lo && int_to_bit(v[i], k) == bit && int_to_bit(v[i-1], k) != bit){
            if(yes){
                reverse(v+second_last_non_bit+1, v+i);
                fout << second_last_non_bit+1 << " " << i-1 << "\n";
            }
            yes = 1-yes;
        }
        if(int_to_bit(v[i], k) != bit){
            if(i != last_non_bit+1)
                second_last_non_bit = last_non_bit;
            last_non_bit = i;
        }
    }
    if(int_to_bit(v[hi], k) != bit && yes){
        reverse(v+second_last_non_bit+1, v+hi+1);
        fout << second_last_non_bit+1 << " " << hi << "\n";
    }
    separate(lo, hi, k);
}

void invsort(int lo, int hi)
{
    if(hi-lo <= 1){
        if(v[lo] > v[hi] && lo <= hi){
            swap(v[lo], v[hi]);
            fout << lo << " " << hi << "\n";
        }
        return;
    }
    int k = r[lo];
    if(r[hi]-r[lo] == 1){
        separate(lo, hi, k);
        int m = lo;
        for (int i = lo; i <= hi; ++i)
            if(v[i] <= k)
                m = i;
    }else{
        int mn = 2000000000, m = lo;
        for (int i = lo+1; i <= hi; ++i)
            if(r[i] != r[i-1]){
                if(mn > max(hi-i, i-lo)){
                    m = i-1;
                    mn = max(hi-i, i-lo);
                    k = r[i-1];
                }
            }
        separate(lo, hi, k);
        invsort(lo, m);
        invsort(m+1, hi);
    }
}

int main()
{
    ifstream fin ("invsort.in");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> v[i];
        r[i] = v[i];
    }
    sort(r+1, r+n+1);
    invsort(1, n);
    return 0;
}

