#include <fstream>
#include <vector>

using namespace std;

vector<long long> v1, v2;
int n;

void qsort(vector<long long> &v, int l, int r)
{
    int i = l, j = r;
    int p = v[(i+j)/2];
    while(i <= j){
        while(v[i] < p)
            ++i;
        while(v[j] > p)
            --j;
        if (i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            ++i;
            --j;
        }
    }
    if (l < j)
        qsort(v, l, j);
    if (i < r)
        qsort(v, i, r);
}

int main()
{
    ifstream fin ("permut.in");
    fin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
        fin >> x,
        v1.push_back(x);
    for (int i = 1; i <= n; ++i)
        fin >> x,
        v2.push_back(x);
    fin.close();

    qsort(v1, 0, n-1);
    qsort(v2, 0, n-1);

    long long k = 0;
    for (int i = 0; i < n; ++i)
        k += v1[i] * v2[i];

    ofstream fout ("permut.out");
    fout << k << "\n";
    fout.close();
    return 0;
}
