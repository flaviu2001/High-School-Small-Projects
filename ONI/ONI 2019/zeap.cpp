#include <bits/stdc++.h>

using namespace std;

set<int> s;
multiset<int> dif;
char line[100];

int main()
{
    ifstream fin ("zeap.in");
    ofstream fout ("zeap.out");
    while(fin.good()){
        fin.getline(line, 100);
        int test = -1, p = 0, y = -1;
        if(line[p] == 'I')
            test = 1;
        else if(line[p] == 'S')
            test = 2;
        else if(line[p] == 'C')
            test = 3;
        else if (line[p] == 'M'){
            ++p;
            if(line[p] == 'A')
                test = 4;
            else test = 5;
        }
        if(test >= 1 && test <= 3){
            while(!(line[p] >= '0' && line[p] <= '9'))
                ++p;
            y = 0;
            while(line[p] >= '0' && line[p] <= '9'){
                y = y*10+line[p]-'0';
                ++p;
            }
        }
        if(test == -1)
            break;
        switch(test){
            case 1:
                if(s.find(y) != s.end())
                    break;
                if(s.size() == 0){
                    s.insert(y);
                    break;
                }
                if(y < *s.begin()){
                    dif.insert(*s.begin()-y);
                    s.insert(y);
                }else if(y > *s.rbegin()){
                    dif.insert(y-*s.rbegin());
                    s.insert(y);
                }else{
                    set<int>::iterator high = s.upper_bound(y), low;
                    low = high;
                    --low;
                    dif.erase(dif.find(*high-*low));
                    dif.insert(y-*low);
                    dif.insert(*high-y);
                    s.insert(y);
                }
                break;
            case 2:
                if(s.find(y) == s.end()){
                    fout << "-1\n";
                    break;
                }
                if(s.size() == 1){
                    s.clear();
                    break;
                }
                if(y == *s.begin()){
                    s.erase(s.begin());
                    dif.erase(dif.find(*s.begin()-y));
                }else if(y == *s.rbegin()){
                    s.erase(s.find(*s.rbegin()));
                    dif.erase(y-*s.rbegin());
                }else{
                    set<int>::iterator now = s.find(y), low, high;
                    low = now;
                    --low;
                    high = now;
                    ++high;
                    dif.insert(*high-*low);
                    dif.erase(dif.find(y-*low));
                    dif.erase(dif.find(*high-y));
                    s.erase(now);
                }
                break;
            case 3:
                if(s.find(y) != s.end())
                    fout << "1\n";
                else fout << "0\n";
                break;
            case 4:
                if(s.size() < 2){
                    fout << "-1\n";
                    break;
                }
                fout << (*s.rbegin())-(*s.begin()) << "\n";
                break;
            case 5:
                if(dif.size() == 0){
                    fout << "-1\n";
                    break;
                }
                fout << (*dif.begin()) << "\n";
                break;
        }
    }
    return 0;
}

