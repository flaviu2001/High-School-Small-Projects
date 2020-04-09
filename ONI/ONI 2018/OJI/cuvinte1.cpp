#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[300];

bool isVowel(char q)
{
    return q == 'a' || q == 'e' || q == 'i' || q == 'o' || q == 'u';
}

int main()
{
    while(cin >> s){
        int n = strlen(s);
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if(!isVowel(s[i])){
                ok = false;
                break;
            }
        if(ok){
            for (int i = 0; i < n; ++i)
                cout << s[i];
            cout << " \n";
        }
    }
    return 0;
}

