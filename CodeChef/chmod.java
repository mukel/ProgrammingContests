import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main implements Runnable {

	BigInteger blockProduct[];
	int[] vals;
	int N;
	int blockSize;

	int queryBlock(int blockId, int mod)
	{
		return blockProduct[blockId].mod(BigInteger.valueOf(mod)).intValue();
	}
	
	int getBlockStart(int blockId)
	{
		return blockId * blockSize;
	}
	
	int getBlockEnd(int blockId)
	{
		return Math.min(N - 1, (blockId + 1) * blockSize - 1);
	}
	
	int query(int lo, int hi, int mod)
	{
		int blo = lo / blockSize;
		int bhi = hi / blockSize;
		
		long ans = 1;
		
		if (blo == bhi)
		{
			for (int i = lo; i <= hi; ++i)
				ans = ans * vals[i] % mod;
				
			return (int)ans;
		}
		
		for (int i = blo + 1; i < bhi; ++i)
			ans = ans * queryBlock(i, mod) % mod;
			
		int bloEnd = getBlockEnd(blo);
		int bhiStart = getBlockStart(bhi);
		
		for (int i = lo; i <= bloEnd; ++i)
			ans = ans * vals[i] % mod;
			
		for (int i = bhiStart; i <= hi; ++i)
			ans = ans * vals[i] % mod;
			
		return (int)ans;
	}

    public void solve() throws IOException
    {
		N = nextInt();
		
		vals = new int[N];
		
		for (int i = 0; i < N; ++i)
		{
			vals[i] = nextInt();
		}
		
		
		blockSize = 316;
		
		blockProduct = new BigInteger[N / blockSize + 100];
		
		for (int b = 0; getBlockStart(b) < N; ++b)
		{
			int start = getBlockStart(b);
			int end = getBlockEnd(b);
			
			BigInteger prod = BigInteger.ONE;
			
			for (int i = start; i <= end; ++i)
			{
				prod = prod.multiply( BigInteger.valueOf(vals[i]) );
			}
			
			blockProduct[b] = prod;
		}
		
		
		int Q = nextInt();
		for (int i = 0; i < Q; ++i)
		{
			int lo, hi, mod;
			lo = nextInt();
			hi = nextInt();
			mod = nextInt();
			
			--lo;
			--hi;
			
			writer.println(query(lo, hi, mod));
		}
    }


    public static void main(String[] args) {
        new Main().run();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    @Override
    public void run() {
        try
        {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    String nextString() throws IOException
    {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
        {
            tokenizer = new StringTokenizer(reader.readLine(), "\n\r\c\t ");
        }
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }

    BigInteger nextBigInteger() throws IOException
    {
        return new BigInteger(nextString());
    }
}
