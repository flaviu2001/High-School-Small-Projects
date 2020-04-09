#include <cstdio>
#include <vector>

using namespace std;

int p, v[26], I;
char c[26][11];
bool ok2 = true;

void read()
{
    freopen("cuvant.in", "r", stdin);
    while(!feof(stdin)){
        char q;
        int k = -1;
        do{
            scanf("%c", &q);
            c[p][++k] = q;
        }while(q != ' ' && !feof(stdin));
        v[p++] = k;
    }
    v[p-1] -= 2;
    fclose(stdin);
    // p si k se itereaza de la 0 pana la p || k exclusiv
}

bool qwer(char s1[], char s2[], int sz1, int sz2)
{
    if(sz1 != sz2)
        return false;
    char s[22];
    for (int i = 0; i < sz1; ++i)
        s[i] = s1[i];
    for (int i = sz1; i < sz1+sz1; ++i)
        s[i] = s1[i-sz1];
    for (int i = 1; i < sz1; ++i){
        bool ok = true;
        for (int j = i; j < i + sz1 && ok; ++j)
            if(s[j] != s2[j-i])
                ok = false;
        if(ok)
            return true;
    }
    return false;
}

void doStuff()
{
    freopen("cuvant.out", "w", stdout);
    vector<int> vv;
    for (int i = 0; i < p; ++i)
        vv.push_back(i);
    //v.erase(v.begin+x); unde x ii pozitia.

    bool ok = 1;
    while(ok){
        ok = 0;
        for (unsigned i = 0; i < vv.size()-1; ++i)
            if(qwer(c[vv[i]], c[vv[i+1]], v[vv[i]], v[vv[i+1]])){
                ok = 1;
                if(ok2){
                    I = i+2;
                    ok2 = false;
                }
                vv.erase(vv.begin()+i+1);
                break;
            }
    }
    printf("%d\n", I);
    for (unsigned i = 0; i < vv.size(); ++i)
        printf("%d ", 1+vv[i]);
    printf("\n");
    fclose(stdout);
}

int main()
{
    read();
    doStuff();
    return 0;
}

