//https://codeforces.com/contest/1385/problem/A

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static boolean bad;

    public static void dfs(int node, int[] ok, ArrayList<Integer>[] v, ArrayList<Integer> order) {
        ok[node] = 1;
        for (Integer x : v[node])
            if (ok[x] == 0)
                dfs(x, ok, v, order);
            else if (ok[x] == 1)
                bad = true;
        order.add(node);
        ok[node] = 2;
    }

    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int test = S.nextInt();
        while(test-- > 0) {
            bad = false;
            int n, m;
            n = S.nextInt();
            m = S.nextInt();
            ArrayList<Integer>[] u = new ArrayList[n+1];
            ArrayList<Integer>[] v = new ArrayList[n+1];
            for (int i = 0; i < n+1; ++i){
                u[i] = new ArrayList<Integer>();
                v[i] = new ArrayList<Integer>();
            }
            while (m-- > 0) {
                int a, b, c;
                a = S.nextInt();
                b = S.nextInt();
                c = S.nextInt();
                if (a == 0) {
                    if (b > c){
                        int aux = b;
                        b = c;
                        c = aux;
                    }
                    u[b].add(c);
                }else
                    v[b].add(c);
            }
            int[] ok = new int[n+1];
            Arrays.fill(ok, 0);
            ArrayList<Integer> order = new ArrayList<Integer>();
            for (int i = 1; i <= n; ++i)
                if (ok[i] == 0)
                    dfs(i, ok, v, order);
            Collections.reverse(order);
            if (bad){
                System.out.println("NO");
                continue;
            }
            System.out.println("YES");
            Arrays.fill(ok, 0);
            for (int i = 0; i < n; ++i){
                int x = order.get(i);
                ok[x] = 1;
                for (Integer y : u[x]){
                    if (ok[y] == 0)
                        System.out.println(x + " " + y);
                    else System.out.println(y + " " + x);
                }
            }
            for (int i = 1; i <= n; ++i)
                for (Integer x : v[i])
                    System.out.println(i + " " + x);
        }
    }
}
