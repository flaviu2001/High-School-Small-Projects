#include <cstdio>
#include <vector>

using namespace std;

vector<long long> r[45*45];
long long v[45*45], n, m;
bool done[45*45];

void read();
bool isdigit(char);
long long value(int);
void write();

int main()
{
    read();
    write();
    return 0;
}

void read()
{
    freopen("mxl.in", "r", stdin);
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= m; ++i){
        long long x, y, p, val;
        char q;
        scanf ("%lld%lld%c", &x, &y, &q);
        p = x * n + y;
        scanf ("%c", &q);
        if (isdigit(q)){
            val = q - '0';
            do{
                scanf ("%c", &q);
                if (isdigit(q))
                    val = val * 10 + q - '0';
            }while(q != '\n');
            v[p] = val;
        }
        else{
            while(q != '\n'){
                x = 0;
                do{
                   scanf("%c", &q);
                   if(isdigit(q))
                        x = x * 10 + q - '0';
                }while(isdigit(q));
                if (q == '+'){
                    v[p] += x;
                    x = 0;
                }
                else if (q == ':'){
                    y = 0;
                    do{
                        scanf("%c", &q);
                        if(isdigit(q))
                            y = y * 10 + q - '0';
                    }while(isdigit(q));
                    r[p].push_back(x*n + y);
                    x = 0;
                }
                else v[p] += x;
            }
        }
    }
    fclose(stdin);
}

bool isdigit(char q)
{
    if (q >= '0' && q <= '9')
        return true;
    return false;
}

long long value(int x)
{
    long long t(0);
    if (!done[x])
        for (unsigned i = 0; i < r[x].size(); ++i)
            t += value(r[x][i]);
    t += v[x];
    done[x] = 1;
    v[x] = t;
    return t;
}

void write()
{
    freopen("mxl.out", "w", stdout);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            printf("%lld ", value(i*n + j));
        printf("\n");
    }
    fclose(stdout);
}
