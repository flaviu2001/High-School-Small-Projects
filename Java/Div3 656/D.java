//https://codeforces.com/contest/1385/problem/A

import java.util.Scanner;

public class Main {
    static String s;

    public static void rec(int[][] pd, int p, int st, int dr, int[][] sp) {
        if (pd[p][st] != -1)
            return;
        if (st == dr) {
            if (s.charAt(st) == 'a'+p)
                pd[p][st] = 0;
            else pd[p][st] = 1;
            return;
        }
        int mid = (st+dr)/2;
        rec(pd, p+1, st, mid, sp);
        rec(pd, p+1, mid+1, dr, sp);
        int cost1 = pd[p+1][st] + (dr-mid) - (sp[p][dr]-sp[p][mid]);
        int cost2 = pd[p+1][mid+1] + (mid-st+1) - (sp[p][mid] - (st == 0 ? 0 : sp[p][st-1]));
        pd[p][st] = Math.min(cost1, cost2);
    }

    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int test = S.nextInt();
        while(test-- > 0) {
            int n = S.nextInt();
            s = S.next();
            int p = 1, ans = 0;
            while(p < n) {
                p *= 2;
                ++ans;
            }
            int[][] pd = new int[ans+1][n];
            int[][] sp = new int['z'-'a'+1][n];
            for (int i = 0; i < n; ++i){
                if (i != 0)
                    for (int j = 0; j < 'z'-'a'+1; ++j)
                        sp[j][i] = sp[j][i-1];
                ++sp[s.charAt(i)-'a'][i];
            }
            for (int i = 0; i <= ans; ++i)
                for (int j = 0; j < n; ++j)
                    pd[i][j] = -1;
            rec(pd, 0, 0, n-1, sp);
            System.out.println(pd[0][0]);
        }
    }
}
