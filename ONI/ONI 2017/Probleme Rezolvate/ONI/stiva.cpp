#include <fstream>
#include <stack>

using namespace std;

int n, v[50006], r[50006], p;

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

bool stiva()
{
    int in = 1;
    stack<int> q;
    for (int i = 1; i <= p; ++i){
        q.push(i);
        while(!q.empty() && q.top() == r[in]){
            ++in;
            q.pop();
        }
    }
    return q.empty();
}

int main()
{
    ifstream fin ("stiva1.in");
    ofstream fout ("stiva1.out");
    fin >> n;
    for (int test = 0; test < 5; ++test){
        int mn = 2000000009, mx1 = 0, mx = 0, in;
        p = 0;
        bool exists[50006] = {0};
        for (int i = 1; i <= n; ++i){
            fin >> v[i];
            mn = min(mn, v[i]);
        }
        if(mn != -1){
            for (int i = 1; i <= n; ++i){
                v[i] -= (mn-1);
                exists[v[i]] = 1;
                mx = max(mx, v[i]);
            }
        }

        for (int i = 1; i <= n; ++i)
            if(v[i] == 1){
                in = i+1;
                break;
            }else mx1 = max(mx1, v[i]);
        for (int i = 1; i < mx1; ++i)
            if(!exists[i])
                r[++p] = i;
        for (int i = 1; i <= n; ++i)
            r[++p] = v[i];
        for (int i = mx; i > mx1; --i)
            if(!exists[i])
                r[++p] = i;
        fout << stiva() << "\n";
    }
    return 0;
}

