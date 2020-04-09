#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n;
bool vic[1005];
vector<int> v[1005], r[1005], lst;

//FILE *fin = fopen("data.in", "r");

void read();
int next_char();
void solve();
bool bfs(int init);

int main()
{
    read();
    solve();
    return 0;
}

void read(){
    char q;
    //fscanf(fin, "%d%c", &n, &q);
    scanf("%d%c", &n, &q);
    int k, t;
    while (1){
        k = next_char();
        if (!k)
            break;
        t = next_char();
        v[t].push_back(k);
        r[k].push_back(t);
    }
    while(!feof(stdin)){
        //fscanf(fin, "%d", &k);
        scanf("%d", &k);
        vic[k] = 1;
        lst.push_back(k);
    }
    lst.pop_back();
    //fclose(fin);
}

void solve(){
    bool ans(0);
    for (int i = 1; i <= n; ++i){
        if (vic[i])
            continue;
        if (bfs(i))
            printf ("%d ", i),
            ans = 1;
    }
    if (!ans)
        printf ("0\n");
}

bool bfs(int init){
    queue<int> q, qq;
    q.push(init);
    qq.push(init);
    bool d[1005], dd[1005];
    for (int i = 0; i < 1005; ++i)
        d[i] = 0, dd[i] = 0;
    d[init] = 1;
    dd[init] = 1;

    while(!q.empty()){
        int k = q.front();
        q.pop();

        for (unsigned i = 0; i < v[k].size(); ++i){
            if (!d[v[k][i]])
                d[v[k][i]] = 1,
                q.push(v[k][i]);
        }
    }

    while(!qq.empty()){
        int k = qq.front();
        qq.pop();

        for (unsigned i = 0; i < r[k].size(); ++i){
            if (!dd[r[k][i]])
                dd[r[k][i]] = 1,
                qq.push(r[k][i]);
        }
    }
    for (unsigned int i = 0; i < lst.size(); ++i)
        if (d[lst[i]] || dd[lst[i]])
            return 0;
    return 1;
}

int next_char(){
    char c;
    int m;
    //fscanf (fin, "%c", &c);
    scanf ("%c", &c);
    if (c == 'B'){
        //fscanf (fin, "%c%c%c%c%c", &c, &c, &c, &c, &c);
        scanf ("%c%c%c%c%c", &c, &c, &c, &c, &c);
        return 0;
    }
    m = c-'0';
    do{
        //fscanf (fin, "%c", &c);
        scanf ("%c", &c);
        if (c >= '0' && c <= '9')
            m = m * 10 + (c-'0');
    }while(c >= '0' && c <= '9');
    return m;
}
