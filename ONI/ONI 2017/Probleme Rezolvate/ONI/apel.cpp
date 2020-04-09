#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

char v[300], f[50][300], a[300];
int val[300], p;

int termen(char[], int&, int[]);
int factor(char[], int&, int[]);

int eval(char s[], int& pp, int vl[])
{
    int r = termen(s, pp, vl);
    while(s[pp] == '+' || s[pp] == '-'){
        switch(s[pp]){
            case '+':
                ++pp;
                r += termen(s, pp, vl);
                break;
            case '-':
                ++pp;
                r -= termen(s, pp, vl);
                break;
        }
    }
    return r;
}

int termen(char s[], int& pp, int vl[])
{
    int r = factor(s, pp, vl);
    while(s[pp] == '*' || s[pp] == '/'){
        switch(s[pp]){
            case '*':
                ++pp;
                r *= factor(s, pp, vl);
                break;
            case '/':
                ++pp;
                r /= factor(s, pp, vl);
                break;
        }
    }
    return r;
}

int factor(char s[], int& pp, int vl[])
{
    int r = 0;
    if(s[pp] == '('){
        ++pp;
        r = eval(s, pp, vl);
        ++pp;
    }else{
        if(s[pp] >= '0' && s[pp] <= '9')
            while(s[pp] >= '0' && s[pp] <= '9'){
                r = r * 10 + s[pp] - '0';
                ++pp;
            }
        else if(s[pp] >= 'a' && s[pp] <= 'z')
            r = vl[s[pp]],
            ++pp;
    }
    return r;
}

int fu(char fn, int& in){
    int param[11] = {0}, par = 0, x;
    for (; v[in] != ')';){
        if(v[in] >= '0' && v[in] <= '9'){
            x = 0;
            while(v[in] >= '0' && v[in] <= '9'){
                x = x * 10 + v[in]-'0';
                ++in;
            }
            param[++par] = x;
        }
        else if(v[in] >= 'a' && v[in] <= 'z'){
            param[++par] = val[v[in]];
            ++in;
        }
        else if(v[in] >= 'A' && v[in] <= 'Z'){
            in += 2;
            param[++par] = fu(v[in-2], in);
        }
        else if(v[in] == ')')
            break;
        else ++in;
    }
    ++in;

    int k = 1;
    for (;k <= p && f[k][0] != fn; ++k);
    int I = 0;
    for (; f[k][I] != '='; ++I);
    ++I;

    int vl[300], vlp = 0;
    for (int i = 0; i < 300; ++i)
        vl[i] = -1;
    for (int i = 2; f[k][i] != ')'; ++i)
        if(f[k][i] >= 'a' && f[k][i] <= 'z')
            vl[f[k][i]] = param[++vlp];

    return eval(f[k], I, vl);
}

int fun(int param[], char fn){
    int k = 1;
    for (;k <= p && f[k][0] != fn; ++k);
    int I = 0;
    for (; f[k][I] != '='; ++I);
    ++I;

    int vl[300], vlp = 0;
    for (int i = 0; i < 300; ++i)
        vl[i] = -1;
    for (int i = 2; f[k][i] != ')'; ++i)
        if(f[k][i] >= 'a' && f[k][i] <= 'z')
            vl[f[k][i]] = param[++vlp];

    return eval(f[k], I, vl);
}

int main()
{
    ifstream fin ("apel.in");
    ofstream fout ("apel.out");
    for (int i = 0; i < 300; ++i)
        val[i] = -1;
    fin.getline(v, 300);
    while(fin.getline(a, 300))
        if(a[0] >= 'a' && a[0] <= 'z'){
            val[a[0]] = a[2]-'0';
            if(a[3] != 0)
                val[a[0]] = val[a[0]] * 10 + a[3]-'0';
            if(a[4] != 0)
                val[a[0]] = val[a[0]] * 10 + a[4]-'0';
        }
        else
            strcpy(f[++p], a);
    fin.close();

    int n = strlen(v);
    int param[11]={0}, par = 0;
    for (int i = 2; i < n;){
        if(v[i] >= '0' && v[i] <= '9'){
            int x = 0;
            while(v[i] >= '0' && v[i] <= '9'){
                x = x * 10 + v[i]-'0';
                ++i;
            }
            ++i;
            param[++par] = x;
        } else if(v[i] >= 'a' && v[i] <= 'z'){
            param[++par] = val[v[i]];
            i += 2;
        } else if(v[i] >= 'A' && v[i] <= 'Z'){
            i += 2;
            param[++par] = fu(v[i-2], i);
        } else ++i;
    }
    fout << fun(param, v[0]);
    return 0;
}

