//https://codeforces.com/contest/1385/problem/A

import java.util.Scanner;

public class Main {
	public static int max(int a, int b) {
		return a > b ? a : b;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int test = s.nextInt();
		while(test-- > 0) {
			int a, b, c;
			a = s.nextInt();
			b = s.nextInt();
			c = s.nextInt();
			int mx = max(a, b);
			mx = max(mx, c);
			int cnt = 0;
			if (a == mx)
				++cnt;
			if (b == mx)
				++cnt;
			if (c == mx)
				++cnt;
			if (cnt < 2){
				System.out.println("NO");
				continue;
			}
			int x, y, z;
			x = mx;
			y = mx;
			z = mx;
			if (a != mx){
				x = a;
				y = a;
			}
			if (b != mx){
				y = b;
				z = b;
			}
			if (c != mx){
				z = c;
				x = c;
			}
			System.out.println("YES\n" + x + " " + y + " " + z);
		}
	}
}