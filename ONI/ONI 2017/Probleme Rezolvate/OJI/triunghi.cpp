#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> v;
int test, n, k, b[50];
bool ye[50];

int main()
{
    std::ifstream fin ("triunghi5.in");
    std::ofstream fout ("triunghi5.out");
    fin >> test >> n >> k;
    if (test == 1){
        long long x, mn(2000000005);
        for (int i = 1; i <= n; ++i){
            fin >> x;
            if (x < mn)
                mn = x;
        }
        x = mn;
        fout << mn << " " << mn << " ";
        for (int i = 3; i <= k; ++i){
            long long aux = mn;
            mn = x;
            x += aux;
            fout << x << " ";
        }
    }
    else{
        long long x, y;
        for (int i = 1; i <= n; ++i){
            fin >> x;
            v.push_back(x);
        }
        std::sort(v.begin(), v.end());

        int pa, pb(2);
        if (v[0] == v[1]){
            b[1] = b[2] = v[0];
            ye[1] = ye[2] = 1;
            pa = 2;
        }
        else{
            b[1] = b[2] = 1;
            if (v[0] == 1){
                ye[1] = 1;
                pa = 1;
            }
            else pa = 0;
        }
        while (pa < n-1){
            x = b[pb] + b[pb-1];
            if (b[pb] + x <= v[pa] && x <= v[pa+1] - v[pa])
                b[++pb] = x;
            else{
                b[++pb] = v[pa++];
                ye[pb] = 1;
            }
        }
        while (pa == n-1){
            x = b[pb] + b[pb-1];
            if (b[pb] <= v[pa]-x)
                b[++pb] = x;
            else{
                b[++pb] = v[pa++];
                ye[pb] = 1;
            }
        }
        while (b[pb] <= 2000000000 - b[pb-1])
            b[pb+1] = b[pb] + b[pb++ - 1];
        for (int i = 1; i <= pb; ++i)
            if (ye[i])
                fout << b[i] << " ";
        x = k - n;
        for (int i = 1; x && i <= pb; ++i)
            if (!ye[i]){
                fout << b[i] << " ";
                --x;
            }
    }
    fin.close();
    fout.close();
    return 0;
}

