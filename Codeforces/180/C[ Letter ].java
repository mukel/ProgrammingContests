import java.util.*;
import java.io.*;
import java.math.*;

public class TaskC implements Runnable {
	
	final int MAXN = 1 << 17;
	
	int N;
	String S;	
	int[] low = new int[MAXN];
	int[] upp = new int[MAXN];
	
	public void solve() throws IOException
	{		
		S = nextToken();
		N = S.length();
		
		for (int i = 0; i < N; ++i)
		{
			char c = S.charAt(i);
			if (c >= &#39;a&#39; && &#39;c&#39; <= &#39;z&#39;)
				low[i+1]++;
			else
				upp[i+1]++;
		}
		
		for (int i = 1; i <= N; ++i)
			low[i] += low[i - 1];
		
		for (int i = N; i >= 1; --i)
			upp[i] += upp[i + 1];
		
		int answer = N;
		for (int i = 0; i <= N; ++i)
			answer = Math.min(answer, low[i] + upp[i+1]);
		
		writer.println(answer);
	}

	public static void main(String[] args) {
		new TaskC().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}