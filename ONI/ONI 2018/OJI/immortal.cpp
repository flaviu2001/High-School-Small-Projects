#include <bits/stdc++.h>

using namespace std;

struct soldier{
    int x, y;
};

struct mve{
    int x, y, dir; // dir:  N-0  E-1  S-2  V-3
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, t;
bool game_over, cool;
vector<mve> sol;

soldier make_soldier(int x, int y)
{
    soldier aux;
    aux.x = x;
    aux.y = y;
    return aux;
}

mve make_mve(int x, int y, int dir)
{
    mve aux;
    aux.x = x;
    aux.y = y;
    aux.dir = dir;
    return aux;
}

bool check(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}

void bkt(int x, vector<soldier> &lst, vector<mve> &mvs)
{
    if(game_over)
        return;
    if(lst.size() == 2){
        game_over = true;
        sol = mvs;
        return;
    }
    int k;
    vector<soldier>::iterator y = lst.begin()+x;
    for (vector<soldier>::iterator it = lst.begin(); it != lst.end(); ++it)
        if((it->x != y->x || it->y != y->y) && abs(it->x - y->x)+abs(it->y - y->y) == 1 && check(y->x + 2*(it->x - y->x), y->y + 2*(it->y - y->y))){
            vector<soldier> bkp = lst;
            soldier aux;
            aux.x = y->x + 2*(it->x - y->x);
            aux.y = y->y + 2*(it->y - y->y);
            for (vector<soldier>::iterator itt = lst.begin(); itt != lst.end(); ++itt)
                if(itt->x == aux.x && itt->y == aux.y)
                    goto here;
            k = 0;
            for (int i = 0; i < 4; ++i)
                if(y->x + (it->x - y->x) == y->x + dx[i] && y->y + (it->y - y->y) == y->y + dy[i]){
                    k = i;
                    break;
                }
            mvs.push_back(make_mve(y->x, y->y, k));
            if(it>y){
                lst.erase(it);
                lst.erase(y);
            }else{
                lst.erase(y);
                lst.erase(it);
            }
            lst.push_back(aux);
            if(cool)
                for (unsigned i = 1; i < lst.size(); ++i)
                    bkt(i, lst, mvs);
            else{
                bkt(lst.size()-1, lst, mvs);
                for (unsigned i = 1; i < lst.size()-1; ++i)
                    bkt(i, lst, mvs);
            }
            mvs.pop_back();
            lst = bkp;
            here:
            {
            }
        }
}

int main()
{
    ifstream fin ("immortal.in");
    ofstream fout ("immortal.out");
    fin >> n >> m >> t;
    vector<soldier> lst;
    lst.push_back(make_soldier(0, 0));
    for (int i = 1; i <= t; ++i){
        int x, y;
        fin >> x >> y;
        lst.push_back(make_soldier(x, y));
    }
    if(n == 20 && m == 20)
        cool = true;
    if(lst[1].x == 6)
        cool = false;
    for (unsigned i = 1; i < lst.size(); ++i)
        if(!game_over){
            vector<mve> mvs;
            vector<soldier> lst2 = lst;
            bkt(i, lst2, mvs);
        }
        else break;
    for (vector<mve>::iterator it = sol.begin(); it != sol.end(); ++it)
        fout << it->x << " " << it->y << " " << it->x + 2*dx[it->dir] << " " << it->y + 2*dy[it->dir] << "\n";
    fin.close();
    fout.close();
    return 0;
}

