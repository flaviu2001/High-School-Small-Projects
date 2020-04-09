#include <fstream>
#include <vector>

using namespace std;

vector< pair<int, int> > sol;
int n, x1, x2, x3, v[10005];
bool kk[10005];

void read()
{
    ifstream fin ("egipt.in");
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        fin >> v[i];
        switch(v[i]){
            case 1:
                ++x1;
                break;
            case 2:
                ++x2;
                break;
            case 3:
                ++x3;
                break;
        }
    }
    fin.close();
}

void magic()
{
    for (int i = 0; i < x1; ++i){
        if(!kk[i]){
            int I, J;
            bool ok;
            switch (v[i]){
                case 1:
                    break;
                case 2:
                    ok = false;
                    for (int j = x1; j < x1+x2; ++j){
                        if(!kk[j] && v[j] == 1){
                            ok = true;
                            I = j;
                            kk[j] = true;
                            break;
                        }
                        if(!kk[j] && v[j] == 3)
                            J = j;
                    }
                    if(ok)
                        sol.push_back(make_pair(i, I));
                    else
                        for (int j = x1+x2; j < n; ++j)
                            if(!kk[j] && v[j] == 1){
                                sol.push_back(make_pair(i, J));
                                sol.push_back(make_pair(i, j));
                                kk[J] = true;
                                kk[j] = true;
                                break;
                            }
                    break;
                case 3:
                    ok = false;
                    for (int j = x1+x2; j < n; ++j){
                        if(!kk[j] && v[j] == 1){
                            ok = true;
                            I = j;
                            kk[j] = true;
                            break;
                        }
                        if(!kk[j] && v[j] == 2)
                            J = j;
                    }
                    if(ok)
                        sol.push_back(make_pair(i, I));
                    else
                        for (int j = x1; j < x1+x2; ++j)
                            if(!kk[j] && v[j] == 1){
                                sol.push_back(make_pair(i, J));
                                sol.push_back(make_pair(i, j));
                                kk[J] = true;
                                kk[j] = true;
                                break;
                            }
                    break;
            }
        }
        kk[i] = true;
    }
    for (int i = x1; i < x1+x2; ++i){
        if(!kk[i] && v[i] == 3){
            for (int j = x1+x2; j < n; ++j)
                if(!kk[j] && v[j] == 2){
                    sol.push_back(make_pair(i, j));
                    kk[i] = true;
                    kk[j] = true;
                    break;
                }
        }
    }
}

void write()
{
    ofstream fout ("egipt.out");
    fout << sol.size() << "\n";
    for (unsigned i = 0; i < sol.size(); ++i)
        fout << sol[i].first+1 << " " << sol[i].second+1 << "\n";
    fout.close();
}

int main()
{
    read();
    magic();
    write();
    return 0;
}
