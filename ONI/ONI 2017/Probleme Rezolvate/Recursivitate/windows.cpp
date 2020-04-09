#include <fstream>
#include <vector>

struct{
    int a, b, c, d;
}r[105];

std::vector<int> v[105];
bool del[105];
int n, k;

void read(){
    std::ifstream fin ("windows.in");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> r[i].a >> r[i].b >> r[i].c >> r[i].d;
        for (int j = 1; j < i; ++j){
            if(r[j].a >= r[i].a && r[j].a <= r[i].c && r[j].d >= r[i].b && r[j].d <= r[i].d)
                v[j].push_back(i);
        }
    }
    fin.close();
}

void shut_up(int x){
    if (!v[x].size()){
        ++k;
        del[x] = 1;
        return;
    }
    for (unsigned i = 0; i < v[x].size(); ++i)
        if (!del[v[x][i]])
            shut_up(v[x][i]);
    ++k;
    del[x] = 1;
}

void write(){
    std::ofstream fout("windows.out");
    shut_up(1);
    fout << k << "\n";
    fout.close();
}

int main()
{
    read();
    write();
    return 0;
}
