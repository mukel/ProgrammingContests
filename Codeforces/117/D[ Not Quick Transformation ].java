/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #87 (Div. 1 Only)
*/
import java.util.*;
import java.io.*;
import java.math.*;

public class D implements Runnable
{
	long N, Q, MOD, begin, end, lb, ub;

	long sum(long f ,long gap, long n)
	{
		++n;

		f %= MOD;
		n %= MOD;
		gap %= MOD;
		
		return (n * f % MOD + n*(n - 1)/2 % MOD * gap) % MOD;
	}

	long getSum(long lo, long hi, long roof, long first, long gap)
	{
		if (lo > hi || lo > end || hi < begin || first > roof)
			return 0;		

		if (lo >= begin && hi <= end)
		{
			long n = (roof - first) / gap;
			n = Math.min(n, hi - lo);
			return sum(first, gap, n);
		}

		long mid = (lo + hi) / 2;

		return
			(getSum(lo, mid, roof, first, gap * 2) +
			getSum(mid + 1, hi, roof, first + gap, gap * 2)) % MOD;
	}
	
	void solve() throws IOException
	{
		N = nextLong();
		Q = nextLong();
		MOD = nextLong();

		while (Q-- > 0)
		{
			begin = nextLong();
			end = nextLong();
			lb = nextLong();
			ub = nextLong();

			writer.println((getSum(1, N, ub, 1, 1) - getSum(1, N, lb - 1, 1, 1) + MOD) % MOD);
		}		
	}

	public static void main(String args[])
	{
		new D().run();
	}

	BufferedReader reader;
	PrintWriter writer;
	StringTokenizer tokenizer;

	public void run()
	{
		try
		{
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();			
		}
		catch (Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}		
	}

	int nextInt() throws IOException
	{
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException
	{
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException
	{
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException
	{
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens())
		{
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
