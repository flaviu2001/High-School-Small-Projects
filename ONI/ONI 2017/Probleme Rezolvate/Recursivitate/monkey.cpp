#include <fstream>
#include <vector>

using namespace std;

int n, m, mx;
char s[22][22];
bool model[26];
vector<bool> mdl(&model[0], &model[0]+26);

void read();
void this_function_needs_a_proper_name(vector<bool>, int, int, int);
void write();

int main()
{
    read();
    this_function_needs_a_proper_name(mdl, 1, 1, 0);
    write();
    return 0;
}

void read()
{
    ifstream fin ("monkey.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> s[i][j];
    fin.close();
}

void this_function_needs_a_proper_name(vector<bool> ok, int x, int y, int k)
{
    if (!(x > 0 && y > 0 && x <= n && y <= m))
        return;
    if (!ok[s[x][y] - 'A']){
        ok[s[x][y] - 'A'] = 1;
        if (k + 1 > mx)
            mx = k + 1;
        this_function_needs_a_proper_name(ok, x-1, y, k + 1);
        this_function_needs_a_proper_name(ok, x+1, y, k + 1);
        this_function_needs_a_proper_name(ok, x, y-1, k + 1);
        this_function_needs_a_proper_name(ok, x, y+1, k + 1);
    }
}

void write()
{
    ofstream fout ("monkey.out");
    fout << mx << "\n";
    fout.close();
}
