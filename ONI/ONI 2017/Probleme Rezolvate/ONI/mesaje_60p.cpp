#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ppww{
    vector<int> w;
    int k;
}aux;

ppww poww[15100];
char cuv[15100][22];
int p, v[15100], last = 0;

bool cmp(ppww v1, ppww v2)
{
    int i = v1.w.size()-1, j = v2.w.size()-1;
    while(i >= 0 && j >= 0){
        if(v1.w[i] < v2.w[j])
            return false;
        if(v1.w[i] > v2.w[j])
            return true;
        --i;
        --j;
    }
    if(i > j)
        return true;
    else if(i < j)
        return false;
    return false;
}

int main()
{
    freopen("mesaje.in", "r", stdin);
    freopen("mesaje.out", "w", stdout);
    char q;
    do{
        scanf("%c", &q);
        if(q == ' ')
            ++p;
        else if(q >= 'a' && q <= 'z')
            cuv[p][v[p]++] = q;
    }while(q != '\n');

    for (int i = 0; i < 1520; ++i)
        poww[i].k = i,
        poww[i].w.push_back(0);
    /*for (int i = 0; i <= p; ++i){
        for (int j = 0; j < v[i]; ++j)
            printf("%c", cuv[i][j]);
        printf(" ");
    }*/

    int pw = 1;
    while(!feof(stdin)){
        int r = 0, t = 0;
        bool ok = true, empt = true;
        do{
            scanf("%c", &q);
            if(q == ' '){
                if(ok && r == v[t]){
                    if(pw > last)
                        last = pw;
                    poww[t].w.push_back(pw);
                }
                ++t;r = 0;
                ok = true;
            }else if(q >= 'a' && q <= 'z'){
                empt = false;
                if(q != cuv[t][r])
                    ok = false;
                ++r;
            }
        }while(q != '\n');
        if(ok && !empt && r == v[t]){
            if(pw > last)
                last = pw;
            poww[t].w.push_back(pw);
        }
        ++pw;
    }
    //sort(poww+0, poww+p+1, cmp);
    bool ko = true;
    while(ko){
        ko = false;
        for (int i = 1; i <= p; ++i)
            if(cmp(poww[i], poww[i-1])){
                aux = poww[i-1];
                poww[i-1] = poww[i];
                poww[i] = aux;
                ko = true;
            }
    }
    /*printf("%d\n\n", last);
    for (int i = 0; i <= p; ++i){
        printf("%d: ", poww[i].k);
        for (int j = 0; j < poww[i].w.size(); ++j)
            printf("%d ", poww[i].w[j]);
        printf("\n");
    }*/
    int cnt = 0;
    for (int i = 0; i <= p; ++i)
        if(poww[i].w[poww[i].w.size()-1] == last)
            ++cnt;
    printf("%d\n", cnt);
    for (int i = 0; i <= p; ++i)
        if(poww[i].w[poww[i].w.size()-1] == last){
            for (int j = v[poww[i].k]-1; j >= 0; --j)
                printf("%c", cuv[poww[i].k][j]);
            printf(" ");
        }
    return 0;
}

