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
        while (!isdigit(c = read_ch()));
        n = c - '0';
        while (isdigit(c = read_ch()))
            n = 10 * n + c - '0';
        return *this;
    }
};

int n, k, ans, lastd1, lastd2;
int v[1000005];

int main()
{
    InParser fin ("secvdist.in");
    ofstream fout ("secvdist.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    deque< pair<int, int> > d1, d2;
    d1.push_back({v[1], 1});
    d2.push_back({v[1], 1});
    for (int i = 2; i <= n; ++i){
        while(!d1.empty() && d1.back().first <= v[i])
            d1.pop_back();
        d1.push_back({v[i], i});
        while(!d2.empty() && d2.back().first >= v[i])
            d2.pop_back();
        d2.push_back({v[i], i});
        while(d1.front().first-d2.front().first > k){
            if(d1.front().second < d2.front().second){
                lastd1 = d1.front().second+1;
                d1.pop_front();
            }else{
                lastd2 = d2.front().second+1;
                d2.pop_front();
            }
        }
        ans = max(ans, i-max(lastd1, lastd2)+1);
    }
    fout << ans << "\n";
    return 0;
}

