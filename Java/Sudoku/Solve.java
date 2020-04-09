import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.charset.Charset;

public class Solve {
	
	private int v[][] = new int [12][12];
	private int cx[] = new int [82];
	private int cy[] = new int [82];
	private int f = 0;
	
	public void read(){
		
		try{
			
			File fin = new File("data.in");
			BufferedReader reader = new BufferedReader 
					(new InputStreamReader
							(new FileInputStream(fin), Charset.forName("UTF-8")));
			for(int i = 1; i <= 9; ++i)
				for(int j = 1; j <= 11; ++j){
					v[i][j] = reader.read() - '0';
					if (v[i][j] == 0){
						cx[++f] = i;
						cy[f] = j;
					}
				}
			reader.close();
			
		}catch (Exception e){
			System.out.println("wtf am i supposed to do now");
		}
	}
	
	public boolean check_position(int i1, int j1){
		
		for (int i = 1; i < i1; ++i)
	        if (v[i][j1] == v[i1][j1])
	            return false;
	    for (int i = i1+1; i <= 9; ++i)
	        if (v[i][j1] == v[i1][j1])
	            return false;
	    for (int j = 1; j < j1; ++j)
	        if (v[i1][j] == v[i1][j1])
	            return false;
	    for (int j = j1+1; j <= 9; ++j)
	        if (v[i1][j] == v[i1][j1])
	            return false;
	    int I = (i1-1)/3;
	    int J = (j1-1)/3;
	    for (int i = I * 3 + 1; i <= (I + 1) * 3; ++i)
	        for ( int j = J * 3 + 1; j <= (J + 1) * 3; ++j){
	            if ( i == i1 && j == j1 )
	                continue;
	            if ( v[i][j] == v[i1][j1] )
	                return false;
	        }
	    return true;
		
	}
	
	public void sudoku(){
		
		int p = 0;
		
		while (p != f){
			++p;
			do
				++v[cx[p]][cy[p]];
			while( v[cx[p]][cy[p]] <= 9 && !check_position(cx[p], cy[p]));
			
			if (v[cx[p]][cy[p]] == 10){
				v[cx[p]][cy[p]] = 0;
				p -= 2;
			}
		}
	}
	
	public void write(){
		
		try{
			PrintWriter fout = new PrintWriter("data.out");
			for (int i = 1; i <= 9; ++i){
				for (int j = 1; j <= 9; ++j)
					fout.print(v[i][j] + " ");
				fout.println();
			}
			fout.close();
		}catch (Exception ee){
			System.out.println("Dunno, whatevs");
		}
		
	}
}
