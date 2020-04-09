import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	static ArrayList<Integer>[] vx = (ArrayList<Integer>[]) new ArrayList[50009];
	static ArrayList<Integer>[] vy = (ArrayList<Integer>[]) new ArrayList[50009];
	static LinkedList<Integer> q = new LinkedList<Integer>();
	static int[] d = new int[50009];
	static int n, m;
	static final int INF = 2147483647;
	
	public static void read(){
		
		for (int i = 0; i < 50009; ++i){
			vx[i] = new ArrayList<Integer>();
			vy[i] = new ArrayList<Integer>();
		}
		
		File fin = new File("dijkstra.in");
		
		try{
			Scanner sc = new Scanner(fin);
			n = sc.nextInt();
			m = sc.nextInt();
			for (int i = 1; i <= m; ++i){
				int x, y, z;
				x = sc.nextInt();
				y = sc.nextInt();
				z = sc.nextInt();
				vx[x].add(y);
				vy[x].add(z);
			}
			sc.close();
		}catch(Exception e){
			System.out.println("ERROR. LIKELY MISSING FILE");
		}
		
		for (int i = 0; i < 50009; ++i)
			d[i] = INF;
		
	}
	
	public static void solve(int initial_point){
		d[initial_point] = 0;
		q.add(initial_point);
		
		while(q.size() > 0){
			int k = q.remove();
			
			for (int i = 0; i < vx[k].size(); ++i)
				if (d[vx[k].get(i)] > d[k] + vy[k].get(i)){
					d[vx[k].get(i)] = d[k] + vy[k].get(i);
					q.add(vx[k].get(i));
				}
		}
	}
	
	public static void write(){
		
		try{
			PrintWriter fout = new PrintWriter("dijkstra.out");
			for(int i = 2; i <= n; ++i){
				if (d[i] != INF)
					fout.print(d[i] + " ");
				else
					fout.print("0 ");
			}
			fout.close();
		}catch(Exception ex){
			System.out.println("UNKNOWN EXCEPTION OCCURED");
		}
		
	}
	
	public static void main(String[] args) {
		read();
		solve(1);
		write();
	}

}
