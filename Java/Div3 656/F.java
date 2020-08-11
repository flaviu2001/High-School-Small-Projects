//https://codeforces.com/contest/1385/problem/A

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int test = S.nextInt();
        while(test-- > 0) {
            int n, k;
            n = S.nextInt();
            k = S.nextInt();
            ArrayList<ArrayList<Integer>> v = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i <= n; ++i)
                v.add(new ArrayList<Integer>());
            for (int i = 1; i < n; ++i){
                int a, b;
                a = S.nextInt();
                b = S.nextInt();
                v.get(a).add(b);
                v.get(b).add(a);
            }
            if (k == 1){
                System.out.println(n-1);
                continue;
            }
            int[] g = new int[n+1];
            int[] g2 = new int[n+1];
            boolean[] ok = new boolean[n+1];
            int cnt = 0;
            Arrays.fill(ok, false);
            Queue<Integer> q = new LinkedList<Integer>();
            for (int i = 1; i <= n; ++i){
                g[i] = v.get(i).size();
                if ((g[i]-1)%k == 0)
                    ok[i] = true;
                if (g[i] == 1)
                    q.add(i);
            }
            while (q.size() > 0){
                int node = q.remove();
                for (Integer x : v.get(node)){
                    --g[x];
                    ++g2[x];
                    if (g2[x]%k == 0)
                        ++cnt;
                    if (g[x] == 1 && ok[x])
                        q.add(x);
                }
            }
            System.out.println(cnt);
        }
    }
}
