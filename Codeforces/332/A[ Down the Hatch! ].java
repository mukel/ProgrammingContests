import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

    public void solve() throws IOException
    {
        int N = nextInt();
        String moves = nextString();
        
        int ans = 0;
        
        for (int i = 0; i < moves.length(); ++i)
        {
            if (i + 1 >= 4 && i % N == 0)
            {
                char c = moves.charAt(i - 1);
                if (c == moves.charAt(i - 2) && c == moves.charAt(i - 3))
                    ans++;
            }           
        }       
        writer.println(ans);        
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
            tokenizer = new StringTokenizer(reader.readLine(), "\n\r\t ");
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
