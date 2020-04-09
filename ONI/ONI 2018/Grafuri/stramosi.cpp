#include <bits/stdc++.h>
#define MAX_BUFF 65536

using namespace std;

vector<int> fii[250005];
int n, t, m[250005][20], tt[250005];
bool ok[250005];
char in[MAX_BUFF];
int pos = MAX_BUFF, buff;

char getChar(FILE *f) {
  if (pos == MAX_BUFF) {
    fread(in, 1, MAX_BUFF, f);
    pos = 0;
  }
  return in[pos++];
}

int freef(FILE *f) {
  int result = 0;
  char c;

  do {
    c = getChar(f);
  } while (!isdigit(c));
  do {
    result = (result << 3) + (result << 1) + c - '0';
    c = getChar(f);
  } while (isdigit(c));
  return result;
}

void df(int x)
{
    ok[x] = 1;
    m[x][0] = tt[x];
    int k = 0;
    while(m[m[x][k]][k] != 0){
        m[x][k+1] = m[m[x][k]][k];
        ++k;
    }
    for (vector<int>::iterator it = fii[x].begin(); it != fii[x].end(); ++it)
        if(!ok[*it])
            df(*it);
}

int pw2(int x)
{
    int p = 1, i;
    for (i = 0; p <= x; ++i)
        p *= 2;
    return i-1;
}

int main()
{
    FILE *f = fopen("stramosi.in", "r");
    n = freef(f);
    t = freef(f);
    for (int i = 1; i <= n; ++i){
        int x;
        x = freef(f);
        fii[x].push_back(i);
        tt[i] = x;
    }
    for (vector<int>::iterator nepot = fii[0].begin(); nepot != fii[0].end(); ++nepot){
        for (vector<int>::iterator it = fii[*nepot].begin(); it != fii[*nepot].end(); ++it)
            df(*it);
    }
    ofstream fout ("stramosi.out");
    while(t--){
        int x, y;
        x = freef(f);
        y = freef(f);
        while(y){
            int p = pw2(y);
            y -= (1<<p);
            x = m[x][p];
        }
        fout << x << "\n";
    }
    return 0;
}

