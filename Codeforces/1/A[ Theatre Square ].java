import java.util.*;
import java.io.*;
import java.math.*;

public class Main implements Runnable
{   
    public void solve() throws IOException
    {
            
        long n = nextInt();
        long m = nextInt();
        long a = nextInt();
        
        writer.println(((n+a-1)/a) * ((m+a-1)/a));
    }

    public static void main(String[] args)
    {
        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

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