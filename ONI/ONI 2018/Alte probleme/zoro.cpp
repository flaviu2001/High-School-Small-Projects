#include <bits/stdc++.h>

using namespace std;

class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};

const int nmax = 1005;
int n, m, v[nmax][nmax], start, finish, lin[nmax], col[nmax];
pair<int, int> pos[nmax*nmax];

int main()
{
    InParser fin ("zoro.in");
    ofstream fout ("zoro.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            fin >> v[i][j];
            pos[v[i][j]] = {i, j};
        }
    start = v[n][m]; finish = v[1][1];
    lin[n] = col[m] = 1;
    if(start == finish){
        fout << "1\n";
        return 0;
    }
    for (int i = start+1; i <= finish; ++i){
        int x = pos[i].first, y = pos[i].second;
        if(lin[x] == 0 && col[y] == 0)
            continue;
        int bstx = lin[x]+1;
        int bsty = col[y]+1;
        lin[x] = max(bstx, bsty);
        col[y] = max(bstx, bsty);
        if(i == finish)
            fout << max(bstx, bsty) << "\n";
    }
    return 0;
}
