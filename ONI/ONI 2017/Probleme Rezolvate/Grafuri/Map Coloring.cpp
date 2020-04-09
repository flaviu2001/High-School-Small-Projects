#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

vector<int> v[100];
queue<int> q;
int n, d[100];
bool possible(1);

void read();
void solve();
void write();

int main(){
    read();
    solve();
    write();
    return 0;
}

void read(){
    //ifstream fin ("data.in");
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i){
        while(1){
            cin >> x;
            if (x == 0)
                break;
            v[i].push_back(x);
            v[x].push_back(i);
        }
    }
    //fin.close();
}

void solve(){
    d[1] = 1;
    q.push(1);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned int i = 0; i < v[k].size(); ++i)
            if (!d[v[k][i]])
                d[v[k][i]] = (d[k] == 1 ? 2 : 1),
                q.push(v[k][i]);
            else if (d[v[k][i]] == d[k])
                possible = 0;
    }
}

void write(){
    //ofstream fout ("data.out");
    if (possible)
        for (int i = 1; i <= n; ++i)
            cout << d[i]-1;
    else cout << "-1\n";
    //fout.close();
}
