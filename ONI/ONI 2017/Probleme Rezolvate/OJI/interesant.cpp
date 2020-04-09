#include <cstdio>
#include <vector>

std::vector<char> c[205], cp;
int n, t, v[205];

void copy(int y){
    cp.clear();
    for (unsigned i = 0; i < c[y].size(); ++i)
        cp.push_back(c[y][i]);
}

bool compare(int y){
    for (unsigned i = 0; i < cp.size(); ++i)
        if (cp[i] < c[y][i])
            return false;
        else if (cp[i] > c[y][i])
            return true;
    return false;
}

bool substr(int y2, int y1){
    unsigned i=0, j=0;
    while (i < c[y1].size() && j < c[y2].size()){
        if (c[y1][i] == c[y2][j])
            ++i, ++j;
        else ++i;
        if (i == c[y1].size() && j < c[y2].size())
            return false;
    }
    if (j == c[y2].size())
        return true;
    return false;
}

int main()
{
    freopen("interesant.in", "r", stdin);
    freopen("interesant.out", "w", stdout);
    char q;
    scanf("%d%d%c", &t, &n, &q);
    if(t == 1){
        unsigned mx(0);
        for (int i = 0; i < n; ++i){
            do{
                scanf("%c", &q);
                c[i].push_back(q);
            }while(q != '\n');
            c[i].pop_back();

            if (c[i].size() > mx){
                mx = c[i].size();
                copy(i);
            }
            else if (c[i].size() == mx){
                if (compare(i))
                    copy(i);
            }
        }
        for (unsigned i = 0; i < cp.size(); ++i)
            printf("%c", cp[i]);
    }
    else{
        for (int i = 0; i < n; ++i){
            do{
                scanf("%c", &q);
                c[i].push_back(q);
            }while(q != '\n');
            c[i].pop_back();

            for (int j = 0; j < i; ++j){
                if (!v[j]){
                    if (c[i].size() > c[j].size()){
                        if (substr(j, i))
                            v[j] = 1;
                    }
                    else if (substr(i, j))
                        v[i] = 1;
                }
            }
        }
        int nr = n;
        for (int i = 0; i < n; ++i)
            if (v[i])
                --nr;
        printf("%d\n", nr);
        for (int i = 0; i < n; ++i)
            if (!v[i]){
                for (unsigned j = 0; j < c[i].size(); ++j)
                    printf ("%c", c[i][j]);
                printf ("\n");
            }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

