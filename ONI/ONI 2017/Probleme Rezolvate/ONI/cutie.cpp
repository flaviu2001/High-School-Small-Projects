#include <fstream>

using namespace std;

int test, n, k, m, r[10005], tip1, tip2, tip3;

int src_left(int x)
{
    int lo = 0, hi = k, m, sol;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(r[m] < x){
            sol = m;
            lo = m+1;
        }else if(r[m] > x)
            hi = m-1;
        else return r[sol];
    return r[sol];
}

int src_right(int x)
{
    int lo = 0, hi = k, m, sol;
    for (m = (lo+hi)/2; lo <= hi; m = (lo+hi)/2)
        if(r[m] > x){
            sol = m;
            hi = m-1;
        }else if(r[m] < x)
            lo = m+1;
        else return r[sol];
    return r[sol];
}

int main()
{
    ifstream fin ("cutie1.in");
    ofstream fout ("cutie1.out");
    fin >> test;
    while(test--){
        fin >> n >> k >> m;
        tip1 = tip2 = tip3 = 0;
        r[0] = 1;
        for (int i = 1; i <= k; ++i)
            fin >> r[i];
        r[++k] = n;
        for (int i = 1; i <= m; ++i){
            int x;
            fin >> x;
            int left = src_left(x);
            int right = src_right(x);
            if((x-left)%2 == 0 && (right-x)%2 == 0)
                ++tip1;
            else if ((x-left)%2 == 1 && (right-x)%2 == 1)
                ++tip2;
            else ++tip3;
        }
        if(tip3 == 0){
            if(tip2%2 == 0)
                fout << "0";
            else fout << "1";
        }else{
            if(tip3%2 == 1)
                fout << "1";
            else if(tip2%2 == 1)
                fout << "1";
            else fout << "0";
        }
    }
    return 0;
}

