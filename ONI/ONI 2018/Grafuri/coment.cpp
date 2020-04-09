#include <fstream>

using namespace std;

struct nod{
    int v;
    nod* next;
};

int n;
bool g[105][105], ok[105];
nod* d;

int prev(int x)
{
    for (int i = 1; i <= n; ++i)
        if(!ok[i] && g[i][x])
            return i;
    return 0;
}

int next(int x)
{
    for (int i = 1; i <= n; ++i)
        if(!ok[i] && g[x][i])
            return i;
    return 0;
}

int main()
{
    ifstream fin ("coment.in");
    ofstream fout ("coment.out");
    fin >> n;
    for (int i = 1; i <= n*(n-1)/2; ++i){
        int x, y;
        fin >> x >> y;
        g[x][y] = 1;
    }
    nod* p;
    nod* q;
    nod* pq;
    nod* sf;
    d = new nod;
    d->v = 1;
    d->next = NULL;
    ok[1] = 1;
    sf = d;
    int vf = 1;
    while(vf){
        vf = prev(vf);
        if(vf){
            p = new nod;
            p->v = vf;
            p->next = d;
            d = p;
            ok[vf] = 1;
        }
    }
    vf = 1;
    while(vf){
        vf = next(vf);
        if(vf){
            p = new nod;
            p->v = vf;
            p->next = NULL;
            sf->next = p;
            sf = p;
            ok[vf] = 1;
        }
    }
    for (vf = 2; vf <= n; ++vf)
        if(!ok[vf]){
            ok[vf] = 1;
            pq = d;
            q = d->next;
            while(g[q->v][vf]){
                pq = q;
                q = q->next;
            }
            p = new nod;
            p->v = vf;
            p->next = q;
            pq->next = p;
            ok[vf] = 1;
        }
    while(d){
        fout << d->v << " ";
        d = d->next;
    }
    fout << "\n";
    fin.close();
    fout.close();
}
