#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> v[10005];
int n;
bool ok[10005];
char s[101];

int read(int p)
{
    int x = 0;
    for (int i = p; s[i] >= '0' && s[i] <= '9'; ++i)
        x = x*10 + s[i]-'0';
    return x;
}

int main()
{
    ifstream fin ("program1.in");
    ofstream fout ("program1.out");
    for (int i = 1; 1; ++i){
        fin.getline(s, 101);
        if(s[0] == '.')
            break;
        n = i;
        if(s[0] == 'E')
            v[i].push_back(i+1);
        else{
            v[i].push_back(read(5));
            for (unsigned j = 0; j <= strlen(s); ++j)
                if(s[j] == 'U'){
                    v[i].push_back(read(j+2));
                    break;
                }
        }
    }
    queue<int> q;
    q.push(1);
    ok[1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if(!ok[v[k][i]]){
                ok[v[k][i]] = 1;
                q.push(v[k][i]);
            }
    }
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if(!ok[i])
            ++k;
    fout << k << "\n";
    fin.close();
    fout.close();
    return 0;
}

