import scala.io._

object Main {

	def main(args: Array[String]) = {
		
		var P = nextInt
		
		def isPrimitiveRoot(x: Int, P: Int): Boolean = {

			def rec(n: Int, powX: Int): Boolean =
				if (n == P - 1)
					powX == 1
				else
					powX != 1 && rec(n + 1, powX * x % P)
				
			rec(1, x)
		}

		val roots = (1 until P) filter (isPrimitiveRoot(_, P))
		
		println(roots.size)
	}

	val in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
	var st = new java.util.StringTokenizer("");

	def next() = {
		while (!st.hasMoreTokens())
			st = new java.util.StringTokenizer(in.readLine());
		st.nextToken();
	}

	def nextInt() = java.lang.Integer.parseInt(next());
	def nextDouble() = java.lang.Double.parseDouble(next());
	def nextLong() = java.lang.Long.parseLong(next());
}