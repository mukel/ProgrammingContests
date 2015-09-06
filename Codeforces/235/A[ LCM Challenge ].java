// mukel
import java.util.*;
import java.io.*;
import java.math.*;

public class JavaRoom implements Runnable {

	long gcd(long a, long b) {
		if (b != 0) {
			return gcd(b, a % b);
		} else {
			return a;
		}
	}

	long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	long lcm3(long a, long b, long c) {
		return lcm(lcm(a, b), c);
	}

	public void solve() throws IOException {

		long n = nextLong();

		long answer = 0;

		for (long a = Math.max(n - 50, 1); a <= n; ++a) {
			for (long b = a; b <= n; ++b) {
				for (long c = b; c <= n; ++c) {
					answer = Math.max(answer, lcm3(a, b, c));
				}
			}
		}

		writer.println(answer);
	}

	public static void main(String[] args) {
		(new JavaRoom()).run();
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
