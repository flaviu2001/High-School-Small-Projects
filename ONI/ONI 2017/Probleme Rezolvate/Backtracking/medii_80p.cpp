#include <fstream>

using namespace std;

int teza, v[15], n;
double medie;
bool found = false;

bool check()
{
    double sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += v[i];
    sum /= n;
    sum *= 3;
    sum += teza;
    if(sum == medie)
        return true;
    return false;
}

int main()
{
    ifstream fin ("medii.in");
    ofstream fout ("medii.out");
    fin >> medie >> teza;
    medie *= 4;
    for (n = 3; n <= 10; ++n){
        for (int i = 1; i <= n; ++i)
            v[i] = 1;
        while(1){
            if(check()){
                found = true;
                for (int i = 1; i <= n; ++i)
                    fout << v[i] << " ";
                fout << "\n";
            }
            ++v[n];
            if(v[n] == 11){
                int k;
                for (k = n-1; k > 0; --k)
                    if(v[k] != 10)
                        break;
                if(k == 0)
                    break;
                ++v[k];
                for (int i = k+1; i <= n; ++i)
                    v[i] = v[k];
            }
        }
    }
    if(!found)
        fout << "0\n";
    fin.close();
    fout.close();
    return 0;
}

