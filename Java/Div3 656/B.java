//https://codeforces.com/contest/1385/problem/A

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int test = s.nextInt();
        while(test-- > 0) {
            int n = s.nextInt();
            int[] v = new int[2*n];
            int[] f = new int[n];
            int[] sol = new int[n];
            for (int i = 0; i < 2*n; ++i)
                v[i] = s.nextInt()-1;
            int pos = 0;
            for (int i = 0; i < 2*n; ++i) {
                if (f[v[i]] == 0) {
                    sol[pos++] = v[i]+1;
                    ++f[v[i]];
                }
            }
            for (int i = 0; i < n; ++i)
                System.out.print(sol[i] + " ");
            System.out.println();
        }
    }
}
