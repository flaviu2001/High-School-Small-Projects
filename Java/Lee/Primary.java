import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Primary {
	
	static int v[][] = new int [501][501]; //The map
	static int n, m, pix, piy, pfx, pfy;
	static int cx[] = new int [501*501];
	static int cy[] = new int [501*501];
	static int dx[] = {0, 1, 0, -1};
	static int dy[] = {1, 0, -1, 0};
	
	public static void main(String[] args){
		
		int p = 0, f = 1;
		try{
			Scanner sc = new Scanner(new File("data.in"));
			
			n = sc.nextInt();
			m = sc.nextInt();
			pix= sc.nextInt();
			piy = sc.nextInt();
			pfx = sc.nextInt();
			pfy = sc.nextInt();
			
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					v[i][j] = sc.nextInt();
			sc.close();
		}catch(Exception ex){
			System.out.println("ERROR. Most likely no such file");
		}
		
		for(int i = 0; i <= n+1; ++i){
			v[i][0] = -1;
			v[i][m+1] = -1;
		}
		for(int i = 0; i <= m+1; ++i){
			v[0][i] = -1;
			v[n+1][i] = -1;
		}
		cx[1] = pix;
		cy[1] = piy;
		while(v[pfx][pfy] == 0){
			++p;
			for (int i = 0; i < 4; ++i)
				if(v[cx[p]+dx[i]][cy[p]+dy[i]] == 0){
					v[cx[p]+dx[i]][cy[p]+dy[i]] = v[cx[p]][cy[p]] + 1;
					cx[++f] = cx[p] + dx[i];
					cy[f] = cy[p] + dy[i];
				}
			if (p == f){
				System.out.println("CANNOT REACH " + cx[p] + " " + cx[f]);
				break;
			}
			if (p == 1)
				v[pix][piy] = -1;
		}
		
		try{
			PrintWriter fout = new PrintWriter("data.out");
			fout.println(v[pfx][pfy]);
			fout.close();
		}catch(Exception e){
			System.out.println("ERROR. UNKNOWN CAUSE");
		}
	}
}
