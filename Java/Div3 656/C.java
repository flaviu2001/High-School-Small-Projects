//https://codeforces.com/contest/1385/problem/A

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int test = s.nextInt();
        while(test-- > 0) {
            int n = s.nextInt();
            ArrayList<Integer> v = new ArrayList<Integer>();
            for (int i = 0; i < n; ++i) {
                int x = s.nextInt();
                v.add(x);
            }
            int pos = n-1;
            while (pos-1 >= 0 && v.get(pos) <= v.get(pos-1))
                --pos;
            while (pos-1 >= 0 && v.get(pos) >= v.get(pos-1))
                --pos;
            System.out.println(pos);
        }
    }
}
