import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException{
		
		int x, y;
		Scanner sc = new Scanner (new FileReader("adunare.in"));
		
		x = sc.nextInt();
		y = sc.nextInt();
		
		PrintWriter fout = new PrintWriter(new FileOutputStream("adunare.out"));
		fout.print(x + y);
		
		sc.close();
		fout.close();
	}

}
