import java.util.*;
import java.io.*;
import java.math.*;

public class Main implements Runnable {
	
	final int MAXN = 1 << 17;
	final BigInteger INF = new BigInteger("100000000000000000000");	
	
	int N;	
	BigInteger C;
	BigInteger[] a = new BigInteger[MAXN];
	BigInteger[] b = new BigInteger[MAXN];
	
	BigInteger getSum(BigInteger x)
	{
		BigInteger sum = BigInteger.ZERO;
		for (int i = 0; i < N; ++i)
		{
			sum = sum.add(x.multiply(a[i]).divide(b[i]));
		}
		return sum.add(BigInteger.valueOf(N));
	}
	
	BigInteger lowerBound()
	{		
		
		BigInteger lo = BigInteger.ONE;
		BigInteger hi = INF;
		
		while (lo.compareTo(hi) <= 0)
		{
			BigInteger mid = lo.add(hi).shiftRight(1);			
			if (getSum(mid).compareTo(C) < 0)
				lo = mid.add(BigInteger.ONE);
			else
				hi = mid.subtract(BigInteger.ONE);
		}
		
		return lo;
	}
	
	BigInteger upperBound()
	{
		BigInteger lo = BigInteger.ONE;
		BigInteger hi = INF;
		
		while (lo.compareTo(hi) <= 0)
		{
			BigInteger mid = lo.add(hi).shiftRight(1);
			if (getSum(mid).compareTo(C) <= 0)
				lo = mid.add(BigInteger.ONE);
			else
				hi = mid.subtract(BigInteger.ONE);
		}
		
		return hi;
	}
	
	public void solve() throws IOException
	{
		N = nextInt();
		C = nextBigInteger();

		for (int i = 0; i < N; ++i)
		{
			a[i] = nextBigInteger();
			b[i] = nextBigInteger();			
		}

		BigInteger answer = upperBound().subtract(lowerBound()).add(BigInteger.ONE);
		
		if (answer.compareTo(INF) == 0)
			writer.println(-1);
		else
			writer.println(answer);		
	}

	public static void main(String[] args) {
		new Main().run();
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