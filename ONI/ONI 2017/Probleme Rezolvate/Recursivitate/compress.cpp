#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, p, k = -1;
char s[10005], r[100005];

void read()
{
    ifstream fin ("compress.in");
    fin.getline(r, 100005);
    n = strlen(r);
    fin.close();
}

bool isLetter(char q)
{
    if(q >= 'a' && q <= 'z')
        return true;
    if(q >= 'A' && q <= 'Z')
        return true;
    return false;
}

void i_can_do_recursion_guys(int& it, int itk)
{
    int num;
    ++it;
    itk = k + 1;
    do{
        if(r[it] == '(')
            i_can_do_recursion_guys(it, k);
        else if (isLetter(r[it]))
            s[++k] = r[p];
        ++it;
    }while(r[it] != ')');
    ++it;
    num = r[it] - '0';
    if(r[it+1] >= '0' && r[it+1] <= '9')
        num = num * 10 + r[it+1] - '0',
        ++it;
    int kk = k;
    //printf("%d %d\n", itk, kk);
    for (int j = 1; j < num; ++j)
        for (int i = itk; i <= kk; ++i)
            s[++k] = s[i];
}

void solve()
{
    do{
        if(r[p] == '(')
            i_can_do_recursion_guys(p, k);
        else if(isLetter(r[p]))
            s[++k] = r[p];
        ++p;
    }while(p < n);
}

void write()
{
    ofstream fout ("compress.out");
    for(int i = 0; i <= k; ++i)
        fout << s[i];
    fout << "\n";
    fout.close();
}

int main()
{
    read();
    solve();
    write();
    return 0;
}

