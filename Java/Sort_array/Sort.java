import java.io.*;
import java.util.*;

public class Sort{
	public static void main(String[] args){
		
		int v[] = new int [101], n = 0;
		File fin = new File("data.in");
		try{
			Scanner sc = new Scanner(fin);
			while(sc.hasNextInt())
				v[++n] = sc.nextInt();
			sc.close();
		}
		catch(Exception e){
			System.out.println("Ya fucked");
		}
		
		boolean ok = true;
		int aux;
		while(ok){
			ok = false;
			for (int j = 1; j < n; ++j){
				if (v[j] > v[j+1]){
					aux = v[j];
					v[j] = v[j+1];
					v[j+1] = aux;
					ok = true;
				}
			}
		}
		try{
			PrintWriter fout = new PrintWriter("data.out");
			for(int j = 1; j <= n; ++j){
				fout.print(v[j] + " ");
			}
			fout.close();
		}catch(Exception ex){
			System.out.println("i hate u");
		}
	}
}