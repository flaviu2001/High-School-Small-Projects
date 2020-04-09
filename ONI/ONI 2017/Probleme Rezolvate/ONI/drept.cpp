#include <fstream>
#include <algorithm>

using namespace std;

struct eveniment{
    int val, nr;
    bool tip;
};

eveniment evx[21000], evy[21000];
bool activ[11000];
int n, nevx, nevy;

bool cmp(eveniment e1, eveniment e2)
{
    if(e1.val < e2.val)
        return true;
    else if(e1.val > e2.val)
        return false;
    if(e1.tip == 1 && e2.tip == 0)
        return true;
    return false;
}

int main()
{
    ifstream fin ("drept2.in");
    ofstream fout ("drept2.out");
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x, y, d;
        fin >> x >> y >> d;
        ++nevx; evx[nevx].val = x; evx[nevx].nr = i; evx[nevx].tip = 0;
        ++nevx; evx[nevx].val = x+d; evx[nevx].nr = i; evx[nevx].tip = 1;
        ++nevy; evy[nevy].val = y; evy[nevy].nr = i; evy[nevy].tip = 0;
        ++nevy; evy[nevy].val = y+d; evy[nevy].nr = i; evy[nevy].tip = 1;
    }
    sort(evx+1, evx+nevx+1, cmp);
    sort(evy+1, evy+nevy+1, cmp);

    // Algoritmul de baleire
    int linie = 0, mx = 0, sol = 0, liniey = 0;
    for (int i = 1; i <= nevx; ++i){
        int lx = evx[i].val-linie, ly = 0, drepte_active = 0;
        if(lx > 0){
            for (int j = 1; j <= nevy; ++j)
                if(activ[evy[j].nr]){
                    if(drepte_active > 0)
                        ly += evy[j].val-liniey;
                    if(evy[j].tip == 1)
                        --drepte_active;
                    else ++drepte_active;
                    if(mx < drepte_active)
                        mx = drepte_active;
                    liniey = evy[j].val;
                }
        }
        sol += lx*ly;
        if(evx[i].tip == 1)
            activ[evx[i].nr] = 0;
        else activ[evx[i].nr] = 1;
        linie = evx[i].val;
    }

    fout << sol << "\n" << mx << "\n";
    fin.close();
    fout.close();
    return 0;
}

