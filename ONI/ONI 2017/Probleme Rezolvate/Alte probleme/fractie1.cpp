#include <fstream>
#include <cstring>

using namespace std;

int n, pi, pj, k, red, a[100], b[100], c[100], na, nb, nc, nines, zeroes, var = 1;
char s[100], perioada[100];
bool virgula = false;

void read()
{
    ifstream fin ("fractie1.in");
    fin.getline(s, 100);
    n = strlen(s);
    fin.close();
}

int reduce()
{
    int p = pj - pi + 1;
    for (int i = 2; i < p; ++i){
        if(p%i != 0)
            continue;
        bool ok = 1;
        for (int j = pi + i; j <= pj; ++j)
            if (s[pi + (j-pi)%i] != s[j]){
                ok = 0;
                break;
            }
        if(ok){
            nines = i;
            return i;
        }
    }
    nines = p;
    return 0;
}

void diff()
{
    int x[101], y[101], nx = na, ny = nb;
    for (int i = 101; i; --i)
        x[i] = y[i] = 0;
    for (int i = na; i; --i)
        x[i] = a[na - i + 1];
    for (int j = nb; j; --j)
        y[j] = b[nb - j + 1];
    int t = 0;
    nc = nx;
    if (ny > nc)
        nc = ny;
    for (int i = 1; i <= nc; ++i){
        c[i] = x[i] - y[i] - t;
        if (c[i] < 0){
            t = 1;
            c[i] += 10;
        }
        else t = 0;
    }
    if(t)
        --nc;
    while(nc > 1 && c[nc] == 0)
        --nc;
    for (int i = 1; i <= nc && c[i] == 0 && zeroes > 0; ++i){
        --zeroes;
        ++var;
    }
}

void magic()
{
    for (int i = 0; i < n; ++i){
        if(virgula)
            ++k;
        if (s[i] == ',')
            virgula = true;
        else if (s[i] == '(')
            pi = i + 1;
        else if (s[i] == ')')
            pj = i - 1;
    }
    if(!virgula)
        return;
    for (int i = n-1; s[i] == '0'; --i)
        --n,
        --k;
    if(pi != 0){ //are perioada
        k -= 2;
        s[n] = 0;
        red = reduce();
        if(red != 0){
            s[pi+red] = ')';
            s[pi+red+1] = 0;
            n = pi+red+1;
            k -= pj - pi + 1 - red;
        }
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == ','){
                pos2 = i + 1;
                break;
            }
        for (int i = pos2; i < n; ++i)
            if(s[i] >= '0' && s[i] <= '9')
                ++zeroes;
            else
                break;
        for (int i = pos1; i < n; ++i)
            if(s[i] >= '0' && s[i] <= '9')
                a[++na] = s[i] - '0';
        for (int i = pos1; i < n; ++i){
            if(s[i] == '(')
                break;
            if(s[i] >= '0' && s[i] <= '9')
                b[++nb] = s[i] - '0';
        }
        diff();
    }
}

void write()
{
    ofstream fout ("fractie1.out");
    if (!virgula)
        fout << s << "\n1\n";
    else if(virgula && pi == 0){
        if (s[0] == '0' && s[1] == ',')
            for (int i = 2; i < n; ++i)
                fout << s[i];
        else
            for (int i = 0; i < n; ++i)
                if (s[i] != ',')
                    fout << s[i];
        fout << "\n1";
        for (int i = 1; i <= k; ++i)
            fout << "0";
    }
    else{
        for (int i = nc; i >= var; --i)
            fout << c[i];
        fout << "\n";
        for (int i = 1; i <= nines; ++i)
            fout << "9";
        for (int i = 1; i <= zeroes; ++i)
            fout << "0";
        fout << "\n";
    }
    fout.close();
}

int main()
{
    read();
    magic();
    write();
    return 0;
}

