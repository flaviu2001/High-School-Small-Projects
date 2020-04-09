#include <bits/stdc++.h>

using namespace std;

typedef long double ldb;

int64_t n, sol;
pair<ldb, ldb> v[300], trapeze[300][300];

ldb ycoord(ldb x1, ldb y1, ldb m)
{
    return x1*(-m) + y1;
}

ldb panta(ldb x1, ldb y1, ldb x2, ldb y2)
{
    return (y2-y1)/(x2-x1);
}

int64_t to_substract(int64_t i, int64_t j, int64_t k)
{
    ldb m = panta(v[i].first, v[i].second, v[j].first, v[j].second);
    if(ycoord(v[k].first, v[k].second, m) > ycoord(v[i].first, v[i].second, m))
        return trapeze[i][j].second;
    return trapeze[i][j].first;
}

int main()
{
    ifstream fin ("patrulatere.in");
    ofstream fout ("patrulatere.out");
    fin >> n;
    for (int64_t i = 1; i <= n; ++i){
        ldb x, y;
        fin >> x >> y;
        v[i] = {x, y};
    }
    for (int64_t i = 1; i < n; ++i)
        for (int64_t j = i+1; j <= n; ++j){
            int64_t up = 0, down = 0;
            if(v[i].first == v[j].first)
                continue;
            ldb m = panta(v[i].first, v[i].second, v[j].first, v[j].second);
            for (int64_t k = 1; k <= n; ++k)
                if(k != i && k != j){
                    if(v[i].second == v[j].second){
                        if(v[k].second > v[i].second)
                            ++up;
                        else ++down;
                        continue;
                    }
                    if(v[k].first > v[i].first && v[k].first > v[j].first)
                        continue;
                    if(v[k].first < v[i].first && v[k].first < v[j].first)
                        continue;
                    if(ycoord(v[k].first, v[k].second, m) > ycoord(v[i].first, v[i].second, m))
                        ++up;
                    else ++down;
                }
            trapeze[i][j] = trapeze[j][i] = {up, down};
        }
    sol = n*(n-1)*(n-2)*(n-3)/24;
    for (int64_t i = 1; i <= n-2; ++i)
        for (int64_t j = i+1; j <= n-1; ++j)
            for (int64_t k = j+1; k <= n; ++k){
                int64_t all_the_shit = 0;
                if(v[i].first == v[j].first){
                    all_the_shit = trapeze[k][j].first + trapeze[k][j].second-1;
                    all_the_shit -= to_substract(k, j, i) + to_substract(k, i, j);
                    sol -= all_the_shit;
                }else if (v[i].first == v[k].first){
                    all_the_shit = trapeze[k][j].first + trapeze[k][j].second-1;
                    all_the_shit -= to_substract(k, j, i) + to_substract(j, i, k);
                    sol -= all_the_shit;
                }else if (v[j].first == v[k].first){
                    all_the_shit = trapeze[i][k].first + trapeze[i][k].second-1;
                    all_the_shit -= to_substract(i, k, j) + to_substract(i, j, k);
                    sol -= all_the_shit;
                }
                if(!((v[i].first > v[j].first && v[i].first > v[k].first) || (v[i].first < v[j].first && v[i].first < v[k].first)))
                    all_the_shit = trapeze[j][k].first + trapeze[j][k].second;
                else if (!((v[j].first > v[i].first && v[j].first > v[k].first) || (v[j].first < v[i].first && v[j].first < v[k].first)))
                    all_the_shit = trapeze[i][k].first + trapeze[i][k].second;
                else all_the_shit = trapeze[i][j].first + trapeze[i][j].second;
                all_the_shit -= to_substract(i, j, k) + to_substract(i, k, j) + to_substract(j, k, i)+1;
                sol -= all_the_shit;
            }
    fout << sol << "\n";
    return 0;
}

