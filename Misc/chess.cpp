//This program checks whether there is a mate in one scenario. Doesn't allow pawns though.

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 2, -2, 1, -1, 2, -2}, dy[] = {2, -2, 1, -1, -2, 2, -1, 1};
char m[10][10];
int passantw, passantb;

void init()
{
    memset(m, '.', sizeof(m));
    m[1][1] = 'R';
    m[2][1] = 'N';
    m[3][1] = 'B';
    m[4][1] = 'Q';
    m[5][1] = 'K';
    m[6][1] = 'B';
    m[7][1] = 'N';
    m[8][1] = 'R';
    for (int i = 1; i <= 8; ++i)
        m[i][2] = 'P';
    m[1][8] = 'r';
    m[2][8] = 'n';
    m[3][8] = 'b';
    m[4][8] = 'q';
    m[5][8] = 'k';
    m[6][8] = 'b';
    m[7][8] = 'n';
    m[8][8] = 'r';
    for (int i = 1; i <= 8; ++i)
        m[i][7] = 'p';
}

void show()
{
    for (int i = 8; i >= 1; --i){
        for (int j = 1; j <= 8; ++j)
            cout << m[j][i];
        cout << "\n";
    }
}

bool check(int x, int y)
{
    return x >= 1 && y >= 1 && x <= 8 && y <= 8;
}

int sign(int x)
{
    if(x < 0)
        return -1;
    return 1;
}

bool rook(int i, int j, char target)
{
    for (int t = 1; t <= 8; ++t) //up
        if(check(i, j+t) && m[i][j+t] != '.'){
            if(m[i][j+t] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //down
        if(check(i, j-t) && m[i][j-t] != '.'){
            if(m[i][j-t] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //left
        if(check(i-t, j) && m[i-t][j] != '.'){
            if(m[i-t][j] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //right
        if(check(i+t, j) && m[i+t][j] != '.'){
            if(m[i+t][j] == target)
                return true;
            break;
        }
    return false;
}

bool bishop(int i, int j, char target)
{
    for (int t = 1; t <= 8; ++t) //NE
        if(check(i+t, j+t) && m[i+t][j+t] != '.'){
            if(m[i+t][j+t] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //NW
        if(check(i-t, j+t) && m[i-t][j+t] != '.'){
            if(m[i-t][j+t] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //SW
        if(check(i-t, j-t) && m[i-t][j-t] != '.'){
            if(m[i-t][j-t] == target)
                return true;
            break;
        }
    for (int t = 1; t <= 8; ++t) //SE
        if(check(i+t, j-t) && m[i+t][j-t] != '.'){
            if(m[i+t][j-t] == target)
                return true;
            break;
        }
    return false;
}

int isCheck() //return 0 - no check 1 - white is in check 2 - black is in check 3 - both in check
{
    pair<int, int> kw, kb;
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j)
            if(m[i][j] == 'K')
                kw = {i, j};
            else if (m[i][j] == 'k')
                kb = {i, j};
    if(abs(kw.first-kb.first) <= 1 && abs(kw.second-kb.second) <= 1)
        return 3;
    bool cw = false, cb = false;
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j)
            switch(m[i][j]){
                case 'P':
                    if(m[i-1][j-1] == 'k' || m[i+1][j-1] == 'k')
                        cb = true;
                    break;
                case 'p':
                    if(m[i-1][j-1] == 'K' || m[i+1][j-1] == 'K')
                        cw = true;
                    break;
                case 'N':
                    for (int t = 0; t < 8; ++t)
                        if(check(i+dx[t], j+dy[t]) && m[i+dx[t]][j+dy[t]] == 'k')
                            cb = true;
                    break;
                case 'n':
                    for (int t = 0; t < 8; ++t)
                        if(check(i+dx[t], j+dy[t]) && m[i+dx[t]][j+dy[t]] == 'K')
                            cw = true;
                    break;
                case 'R':
                    if(rook(i, j, 'k'))
                        cb = true;
                    break;
                case 'r':
                    if(rook(i, j, 'K'))
                        cw = true;
                    break;
                case 'B':
                    if(bishop(i, j, 'k'))
                        cb = true;
                    break;
                case 'b':
                    if(bishop(i, j, 'K'))
                        cw = true;
                    break;
                case 'Q':
                    if(rook(i, j, 'k'))
                        cb = true;
                    if(bishop(i, j, 'k'))
                        cb = true;
                    break;
                case 'q':
                    if(rook(i, j, 'K'))
                        cw = true;
                    if(bishop(i, j, 'k'))
                        cw = true;
                    break;
            }
    int ans = 0;
    if(cw)
        ans += 1;
    if(cb)
        ans += 2;
    return ans;
}

bool checkForCheck(char x1, int y1, char x2, int y2, char side)
{
    char bk1 = m[x1][y1], bk2 = m[x2][y2];
    m[x2][y2] = m[x1][y1];
    m[x1][y1] = '.';
    int chk = isCheck();
    m[x1][y1] = bk1;
    m[x2][y2] = bk2;
    if(chk == 3)
        return false;
    if(side == 'w' && chk == 1)
        return false;
    if(side == 'b' && chk == 2)
        return false;
    return true;
}

int Move(char x1, int y1, char x2, int y2, bool simulate, char side) //side w, b
{
    x1 -= 'a'-1;
    x2 -= 'a'-1;
    if(!check(int(x1), y1) || !check(int(x2), y2))
        return 3;
    if(!(side == 'w' || side == 'b'))
        return 2;
    if(m[x1][y1] == '.' || (isupper(m[x1][y1]) && side == 'b') || (islower(m[x1][y1]) && side == 'w'))
        return 1;
    int difx, dify;
    bool found;
    switch(m[x1][y1]){
        case 'P':
            if(y2 == y1+2){
                if(y1 != 2)
                    return 3;
                if(m[x2][y2-1] != '.')
                    return 4;
                if(abs(x1-x2) != 0)
                    return 3;
                if(m[x2][y2] != '.')
                    return 3;
                if(isupper(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'P';
                }
                return 0;
            }
            if(y2 != y1+1)
                return 3;
            if(x2 == x1){
                if(m[x2][y2] != '.')
                    return 4;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'P';
                }
                return 0;
            }
            if(abs(x1-x2) != 1)
                return 3;
            if(m[x2][y2] == '.'){
                if(y1 == 5 && passantb == x2){//en passant
                    if(isupper(m[x2][y2]))
                        return 5;
                    if(!checkForCheck(x1, y1, x2, y2, side))
                        return 6;
                    if(!simulate){
                        m[x1][y1] = '.';
                        m[x2][y2] = 'P';
                        m[x2][y2-1] = '.';
                    }
                    return 0;
                }
                return 3;
            }
            if(isupper(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'P';
            }
            return 0;
        case 'p':
            if(y2 == y1-2){
                if(y1 != 7)
                    return 3;
                if(m[x2][y2+1] != '.')
                    return 4;
                if(abs(x1-x2) != 0)
                    return 3;
                if(m[x2][y2] != '.')
                    return 3;
                if(isupper(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'p';
                }
                return 0;
            }
            if(y2 != y1-1)
                return 3;
            if(x2 == x1){
                if(m[x2][y2] != '.')
                    return 4;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'p';
                }
                return 0;
            }
            if(abs(x1-x2) != 1)
                return 3;
            if(m[x2][y2] == '.'){
                if(y1 == 4 && passantw == x2){//en passant
                    if(islower(m[x2][y2]))
                        return 5;
                    if(!checkForCheck(x1, y1, x2, y2, side))
                        return 6;
                    if(!simulate){
                        m[x1][y1] = '.';
                        m[x2][y2] = 'p';
                        m[x2][y2-1] = '.';
                    }
                    return 0;
                }
                return 3;
            }
            if(islower(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'p';
            }
            return 0;
        case 'N':
            difx = x2-x1, dify = y2-y1;
            found = false;
            for (int t = 0; t < 8; ++t)
                if(dx[t] == difx && dy[t] == dify)
                    found = true;
            if(!found)
                return 3;
            if(isupper(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'N';
            }
            return 0;
        case 'n':
            difx = x2-x1, dify = y2-y1;
            found = false;
            for (int t = 0; t < 8; ++t)
                if(dx[t] == difx && dy[t] == dify)
                    found = true;
            if(!found)
                return 3;
            if(islower(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'n';
            }
            return 0;
        case 'R':
            difx = x2-x1, dify = y2-y1;
            if(difx != 0 && dify != 0)
                return 3;
            if(difx != 0)
                for (int t = 1; t < abs(difx); ++t)
                    if(m[x1+sign(difx)*t][y1] != '.')
                        return 4;
            if(dify != 0)
                for (int t = 1; t < abs(dify); ++t)
                    if(m[x1][y1+t*sign(dify)] != '.')
                        return 4;
            if(isupper(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'R';
            }
            return 0;
        case 'r':
            difx = x2-x1, dify = y2-y1;
            if(difx != 0 && dify != 0)
                return 3;
            if(difx != 0)
                for (int t = 1; t < abs(difx); ++t)
                    if(m[x1+sign(difx)*t][y1] != '.')
                        return 4;
            if(dify != 0)
                for (int t = 1; t < abs(dify); ++t)
                    if(m[x1][y1+t*sign(dify)] != '.')
                        return 4;
            if(islower(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'r';
            }
            return 0;
        case 'B':
            difx = x2-x1, dify = y2-y1;
            if(abs(difx) != abs(dify))
                return 3;
            for (int t = 1; t < abs(difx); ++t)
                if(m[x1+t*sign(difx)][y1+t*sign(dify)] != '.')
                    return 4;
            if(isupper(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'B';
            }
            return 0;
        case 'b':
            difx = x2-x1, dify = y2-y1;
            if(abs(difx) != abs(dify))
                return 3;
            for (int t = 1; t < abs(difx); ++t)
                if(m[x1+t*sign(difx)][y1+t*sign(dify)] != '.')
                    return 4;
            if(islower(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'b';
            }
            return 0;
        case 'Q':
            difx = x2-x1, dify = y2-y1;
            if(difx == 0 || dify == 0){
                if(difx != 0)
                    for (int t = 1; t < abs(difx); ++t)
                        if(m[x1+sign(difx)*t][y1] != '.')
                            return 4;
                if(dify != 0)
                    for (int t = 1; t < abs(dify); ++t)
                        if(m[x1][y1+t*sign(dify)] != '.')
                            return 4;
                if(isupper(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'Q';
                }
                return 0;
            }
            if(abs(difx) == abs(dify)){
                for (int t = 1; t < abs(difx); ++t)
                    if(m[x1+t*sign(difx)][y1+t*sign(dify)] != '.')
                        return 4;
                if(isupper(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'Q';
                }
                return 0;
            }
            return 3;
        case 'q':
            difx = x2-x1, dify = y2-y1;
            if(difx == 0 || dify == 0){
                if(difx != 0)
                    for (int t = 1; t < abs(difx); ++t)
                        if(m[x1+sign(difx)*t][y1] != '.')
                            return 4;
                if(dify != 0)
                    for (int t = 1; t < abs(dify); ++t)
                        if(m[x1][y1+t*sign(dify)] != '.')
                            return 4;
                if(islower(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'q';
                }
                return 0;
            }
            if(abs(difx) == abs(dify)){
                for (int t = 1; t < abs(difx); ++t)
                    if(m[x1+t*sign(difx)][y1+t*sign(dify)] != '.')
                        return 4;
                if(islower(m[x2][y2]))
                    return 5;
                if(!checkForCheck(x1, y1, x2, y2, side))
                    return 6;
                if(!simulate){
                    m[x1][y1] = '.';
                    m[x2][y2] = 'q';
                }
                return 0;
            }
            return 3;
        case 'K':
            difx = x2-x1, dify = y2-y1;
            if(abs(difx) > 1 || abs(dify) > 1)
                return 3;
            if(isupper(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'K';
            }
            return 0;
        case 'k':
            difx = x2-x1, dify = y2-y1;
            if(abs(difx) > 1 || abs(dify) > 1)
                return 3;
            if(islower(m[x2][y2]))
                return 5;
            if(!checkForCheck(x1, y1, x2, y2, side))
                return 6;
            if(!simulate){
                m[x1][y1] = '.';
                m[x2][y2] = 'k';
            }
            return 0;
    }
    return 999;
}

int checkForMate(char side) // 0 - can move, 1 - mate, 2 - stalemate
{
    int chk = isCheck();
    bool incheck = false;
    if(chk == 3)
        incheck = true;
    if(side == 'w' && chk == 1)
        incheck = true;
    if(side == 'b' && chk == 2)
        incheck = true;
    for (char i = 'a'; i <= 'h'; ++i)
        for (int j = 1; j <= 8; ++j){
            if(side == 'w' && !isupper(m[i-'a'+1][j]))
                continue;
            if(side == 'b' && !islower(m[i-'a'+1][j]))
                continue;
            for (char i2 = 'a'; i2 <= 'h'; ++i2)
                for (int j2 = 1; j2 <= 8; ++j2){
                    if(i == i2 && j == j2)
                        continue;
                    if(Move(i, j, i2, j2, true, side) == 0)
                        return 0;
                }
        }
    if(incheck)
        return 1;
    return 2;
}

int main()
{
    init();
    char side = 'b';
    passantw = passantb = -1;
    while(1){
        show();
        cout << "\n\n";
        int mate;
        if(side == 'w'){
            side = 'b';
            mate = checkForMate(side);
            if(mate == 1){
                cout << "White is victorius!\n";
                return 0;
            }
            if(mate == 2){
                cout << "Stalemate\n";
                return 0;
            }
            cout << "Black";
        }else{
            side = 'w';
            mate = checkForMate(side);
            if(mate == 1){
                cout << "Black is victorius!\n";
                return 0;
            }
            if(mate == 2){
                cout << "Stalemate\n";
                return 0;
            }
            cout << "White";
        }

        cout << " to move.\n";
        char x1, x2;
        int y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(side == 'w')
            passantw = -1;
        else passantb = -1;
        int bpw = passantw, bpb = passantb;
        if(m[x1][y1] == 'p' || m[x1][y1] == 'P' || (abs(y2-y1) == 2)){
            if(side == 'b')
                passantb = x1-'a'+1;
            else passantw = x1-'a'+1;
        }
        while(Move(x1, y1, x2, y2, 0, side)){
            passantb = bpb;
            passantw = bpw;
            cout << "Illegal move. Code " << Move(x1, y1, x2, y2, 0, side) << " Try again\n";
            cin >> x1 >> y1 >> x2 >> y2;
            if(m[x1][y1] == 'p' || m[x1][y1] == 'P' || (abs(y2-y1) == 2)){
                if(side == 'b')
                    passantb = x1-'a'+1;
                else passantw = x1-'a'+1;
            }
        }
        cout << "\n";
    }
    return 0;
}

