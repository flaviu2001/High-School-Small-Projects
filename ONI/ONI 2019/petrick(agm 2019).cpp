#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int n, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx2[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy2[] = {2, -2, 2, -2, 1, -1, 1, -1};
char c[10][10], bkp[10][10], bkp2[10][10];

bool check(int a, int b)
{
    return a >= 1 && a <= 8 && b >= 1 && b <= 8;
}

bool checkWhite()
{
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j){
            if(c[i][j] == 'K'){
                for (int d = 0; d < 8; ++d)
                    if(c[i+dx[d]][j+dy[d]] == 'k')
                        return true;
            }
            if(c[i][j] == 'r'){
                int x, y;
                x = i, y = j;
                --x;
                while(c[x][y] == '.')
                    --x;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x;
                while(c[x][y] == '.')
                    ++x;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++y;
                while(c[x][y] == '.')
                    ++y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                --y;
                while(c[x][y] == '.')
                    --y;
                if(c[x][y] == 'K')
                    return true;
            }
            if(c[i][j] == 'n'){
                for (int d = 0; d < 8; ++d)
                    if(check(i+dx2[d], j+dy2[d]) && c[i+dx2[d]][j+dy2[d]] == 'K')
                        return true;
            }
            if(c[i][j] == 'b'){
                int x, y;
                x = i, y = j;
                --x, --y;
                while(c[x][y] == '.')
                    --x, --y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                --x, ++y;
                while(c[x][y] == '.')
                    --x, ++y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x, --y;
                while(c[x][y] == '.')
                    ++x, --y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x, ++y;
                while(c[x][y] == '.')
                    ++x, ++y;
                if(c[x][y] == 'K')
                    return true;
            }
            if(c[i][j] == 'q'){
                int x, y;
                x = i, y = j;
                --x;
                while(c[x][y] == '.')
                    --x;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x;
                while(c[x][y] == '.')
                    ++x;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++y;
                while(c[x][y] == '.')
                    ++y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                --y;
                while(c[x][y] == '.')
                    --y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                --x, --y;
                while(c[x][y] == '.')
                    --x, --y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                --x, ++y;
                while(c[x][y] == '.')
                    --x, ++y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x, --y;
                while(c[x][y] == '.')
                    ++x, --y;
                if(c[x][y] == 'K')
                    return true;
                x = i, y = j;
                ++x, ++y;
                while(c[x][y] == '.')
                    ++x, ++y;
                if(c[x][y] == 'K')
                    return true;
            }
        }
    return false;
}

bool checkBlack()
{
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j){
            if(c[i][j] == 'k'){
                for (int d = 0; d < 8; ++d)
                    if(c[i+dx[d]][j+dy[d]] == 'K')
                        return true;
            }
            if(c[i][j] == 'R'){
                int x, y;
                x = i, y = j;
                --x;
                while(c[x][y] == '.')
                    --x;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x;
                while(c[x][y] == '.')
                    ++x;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++y;
                while(c[x][y] == '.')
                    ++y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                --y;
                while(c[x][y] == '.')
                    --y;
                if(c[x][y] == 'k')
                    return true;
            }
            if(c[i][j] == 'N'){
                for (int d = 0; d < 8; ++d)
                    if(check(i+dx2[d], j+dy2[d]) && c[i+dx2[d]][j+dy2[d]] == 'k')
                        return true;
            }
            if(c[i][j] == 'B'){
                int x, y;
                x = i, y = j;
                --x, --y;
                while(c[x][y] == '.')
                    --x, --y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                --x, ++y;
                while(c[x][y] == '.')
                    --x, ++y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x, --y;
                while(c[x][y] == '.')
                    ++x, --y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x, ++y;
                while(c[x][y] == '.')
                    ++x, ++y;
                if(c[x][y] == 'k')
                    return true;
            }
            if(c[i][j] == 'Q'){
                int x, y;
                x = i, y = j;
                --x;
                while(c[x][y] == '.')
                    --x;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x;
                while(c[x][y] == '.')
                    ++x;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++y;
                while(c[x][y] == '.')
                    ++y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                --y;
                while(c[x][y] == '.')
                    --y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                --x, --y;
                while(c[x][y] == '.')
                    --x, --y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                --x, ++y;
                while(c[x][y] == '.')
                    --x, ++y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x, --y;
                while(c[x][y] == '.')
                    ++x, --y;
                if(c[x][y] == 'k')
                    return true;
                x = i, y = j;
                ++x, ++y;
                while(c[x][y] == '.')
                    ++x, ++y;
                if(c[x][y] == 'k')
                    return true;
            }
        }
    return false;
}

bool Checkmate()
{
    if(!checkBlack())
        return false;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            bkp2[i][j] = c[i][j];
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j){
            if(c[i][j] == 'k'){
                for (int d = 0; d < 8; ++d)
                    if(c[i+dx[d]][j+dy[d]] == '.' || (c[i+dx[d]][j+dy[d]] >= 'A' && c[i+dx[d]][j+dy[d]] <= 'Z')){
                        c[i][j] = '.';
                        c[i+dx[d]][j+dy[d]] = 'k';
                        if(checkBlack()){
                            for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                            continue;
                        }
                        return false;
                    }
            }
            if(c[i][j] == 'n'){
                for (int d = 0; d < 8; ++d)
                    if(check(i+dx2[d], j+dy2[d]) && (c[i+dx2[d]][j+dy2[d]] == '.' || (c[i+dx2[d]][j+dy2[d]] >= 'A' && c[i+dx2[d]][j+dy2[d]] <= 'Z'))){
                        c[i][j] = '.';
                        c[i+dx2[d]][j+dy2[d]] = 'n';
                        if(checkBlack()){
                            for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                            continue;
                        }
                        return false;
                    }
            }
            if(c[i][j] == 'r'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    --x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    ++x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    --y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    ++y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'r';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
            }
            if(c[i][j] == 'b'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    --x;
                    --y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++x;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    ++x;
                    ++y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                --y;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    --y;
                    ++x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++y;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    ++y;
                    --x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'b';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
            }
            if(c[i][j] == 'q'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    --x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    ++x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    --y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    ++y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                --x;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    --x;
                    --y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++x;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    ++x;
                    ++y;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                --y;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    --y;
                    ++x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
                x = i, y = j;
                ++y;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    ++y;
                    --x;
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                        continue;
                    }
                    return false;
                }
                if(c[x][y] >= 'A' && c[x][y] <= 'Z'){
                    c[i][j] = '.';
                    c[x][y] = 'q';
                    if(checkBlack()){
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp2[i1][j1];
                    }else return false;
                }
            }
        }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ifstream cin ("data.in");
    cin >> n;
    memset(c, '.', sizeof(c));
    for (int i = 0; i < 10; ++i)
        c[i][0] = c[i][9] = c[0][i] = c[9][i] = '#';
    for (int i = 1; i <= n; ++i){
        string s1, s2;
        int a, b;
        cin >> s1 >> s2 >> a >> b;
        if(s1 == "king"){
            if(s2 == "white")
                c[a][b] = 'K';
            else c[a][b] = 'k';
        }else if (s1 == "rook"){
            if(s2 == "white")
                c[a][b] = 'R';
            else c[a][b] = 'r';
        }else if (s1 == "queen"){
            if(s2 == "white")
                c[a][b] = 'Q';
            else c[a][b] = 'q';
        }else if (s1 == "bishop"){
            if(s2 == "white")
                c[a][b] = 'B';
            else c[a][b] = 'b';
        }else{
            if(s2 == "white")
                c[a][b] = 'N';
            else c[a][b] = 'n';
        }
    }
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            bkp[i][j] = c[i][j];
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j){
            if(c[i][j] == 'K'){
                for (int d = 0; d < 8; ++d)
                    if(c[i+dx[d]][j+dy[d]] == '.' || (c[i+dx[d]][j+dy[d]] >= 'a' && c[i+dx[d]][j+dy[d]] <= 'z')){
                        c[i][j] = '.';
                        c[i+dx[d]][j+dy[d]] = 'K';
                        if(checkWhite()){
                            for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                            continue;
                        }
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }
            }
            if(c[i][j] == 'N'){
                for (int d = 0; d < 8; ++d)
                    if(check(i+dx2[d], j+dy2[d]) && (c[i+dx2[d]][j+dy2[d]] == '.' || (c[i+dx2[d]][j+dy2[d]] >= 'a' && c[i+dx2[d]][j+dy2[d]] <= 'z'))){
                        c[i][j] = '.';
                        c[i+dx2[d]][j+dy2[d]] = 'N';
                        if(checkWhite()){
                            for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                            continue;
                        }
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }
            }
            if(c[i][j] == 'R'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    --x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                        for (int j1 = 0; j1 < 10; ++j1)
                            c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    ++x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = c[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    --y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    ++y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'R';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
            }
            if(c[i][j] == 'B'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    --x;
                    --y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++x;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    ++x;
                    ++y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                --y;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    --y;
                    ++x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++y;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    ++y;
                    --x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'B';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
            }
            if(c[i][j] == 'Q'){
                int x = i, y = j;
                x = i, y = j;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    --x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    ++x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    --y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    ++y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                --x;
                --y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    --x;
                    --y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++x;
                ++y;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    ++x;
                    ++y;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                --y;
                ++x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    --y;
                    ++x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
                x = i, y = j;
                ++y;
                --x;
                while(c[x][y] == '.'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    ++y;
                    --x;
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                        continue;
                    }
                    if(Checkmate()){
                        cout << "Checkmate!\n";
                        return 0;
                    }
                    for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                }
                if(c[x][y] >= 'a' && c[x][y] <= 'z'){
                    c[i][j] = '.';
                    c[x][y] = 'Q';
                    if(checkWhite()){
                        for (int i1 = 0; i1 < 10; ++i1)
                            for (int j1 = 0; j1 < 10; ++j1)
                                c[i1][j1] = bkp[i1][j1];
                    }else{
                        if(Checkmate()){
                            cout << "Checkmate!\n";
                            return 0;
                        }
                        for (int i1 = 0; i1 < 10; ++i1)
                                for (int j1 = 0; j1 < 10; ++j1)
                                    c[i1][j1] = bkp[i1][j1];
                    }
                }
            }
        }
    cout << "Bad Luck!";
    return 0;
}
