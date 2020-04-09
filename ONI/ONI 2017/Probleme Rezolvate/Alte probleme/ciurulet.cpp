#include <fstream>

using namespace std;

int n, ones;
char c[1000005];
bool bld[1000005], ok[1000005];

void read()
{
    ifstream fin ("ciurulet.in");
    fin >> n;
    for (int i = 2; i <= n; ++i)
        fin >> c[i];
    fin.close();
}

bool check(int i1)
{
    for (int i = i1 * 2; i <= n; i += i1)
        if(c[i] == '1')
            return false;
    return true;
}

void build()
{
    for (int i = 2; i <= n; ++i){
        if (!ok[i]){
            if(c[i] == '?' && check(i)){
                for (int j = i; j <= n; j += i){
                    bld[j] = 1;
                    ok[j] = 1;
                }
            } else if(c[i] == '1'){
                    for (int j = i; j <= n; j += i){
                        bld[j] = 1;
                        ok[j] = 1;
                    }
                } else if (c[i] == '0')
                    bld[i] = 0;
            //ok[i] = 1;
        }
    }

    for (int i = 2; i <= n; ++i)
        if (bld[i] == 1)
            ++ones;
}

void write()
{
    ofstream fout ("ciurulet.out");
    fout << ones << "\n";
    for(int i = 2; i <= n; ++i)
        fout << bld[i];
    fout << "\n";
    fout.close();
}

int main()
{
    read();
    build();
    write();
    return 0;
}

