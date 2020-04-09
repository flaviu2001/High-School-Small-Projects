#include <fstream>
#include <vector>
#include <queue>
#define MAX 50005
#define INF 1 << 30

using namespace std;

struct data{
    int edge, weight;
} nd;

vector<data> v[MAX];
queue<int> q;

int nodes, edges, d[MAX], c[MAX];
bool negCycle(0);

void read();
void bell();
void write();

int main(){
    read();
    bell();
    write();
    return 0;
}

void read(){
    ifstream fin ("bellmanford.in");
    fin >> nodes >> edges;
    int x, y ,z;
    for (int i = 1; i <= edges; ++i){
        fin >> x >> y >> z;
        nd.edge = y, nd.weight = z;
        v[x].push_back(nd);
    }
    for (int i = 1; i <= nodes; ++i)
        d[i] = INF;

    fin.close();
}

void bell(){
    d[1] = 0;
    q.push(1);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned int j = 0; j < v[k].size(); ++j)
            if (d[v[k][j].edge] > d[k] + v[k][j].weight){
                ++c[v[k][j].edge];
                if (c[v[k][j].edge] == nodes){
                    negCycle = 1;
                    return;
                }
                d[v[k][j].edge] = d[k] + v[k][j].weight;
                q.push(v[k][j].edge);
            }
    }
}

void write(){
    ofstream fout ("bellmanford.out");
    if (negCycle){
        fout << "Ciclu negativ!\n";
        fout.close();
        return;
    }
    for (int i = 2; i <= nodes; ++i)
        fout << d[i] << " ";
    fout.close();
}