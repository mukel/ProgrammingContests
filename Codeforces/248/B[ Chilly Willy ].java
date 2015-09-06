
// Alfonso2 Peterssen (mukel)
import java.io.*;
import java.math.*;
import java.util.*;

public class Testing implements Runnable {

	void solve() throws IOException {
		
		final int LCM = 2 * 3 * 5 * 7;
		
		int n = nextInt();
		
		if (n == 1 || n == 2)
		{
			writer.println(-1);
			return ;
		}
		
		if (n == 3)
		{
			writer.println(210);
			return ;
		}
		
		int mod = 1;
		for (int i = 0; i < n - 1; ++i)
			mod = (mod * 10) % LCM;
		
		writer.print(1);
		for (int i = 0; i < n - 4; ++i)
			writer.print(0);
		writer.printf("%03d\n", LCM - mod);
	}
	
	public static void main(String[] args) {
		new Testing().run();
	}
	
	PrintWriter writer;
	BufferedReader reader;	
	StringTokenizer tokenizer;

	public void run() {
		try {	
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();	 
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}		
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreElements()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}	
}
