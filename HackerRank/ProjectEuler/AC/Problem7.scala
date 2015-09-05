object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt	

	val primes: Stream[Int] = 2 #:: (Stream.from(3, 2) filter (n => primes.view takeWhile (p => p*p <= n) forall (n % _ != 0)))	
	 	
	def main(args: Array[String]): Unit = {
		val testCount = nextInt
		val p = primes take 10000 toArray

		for (test <- 1 to testCount) {
			val N = nextInt
			println(p(N - 1))
		}
	}
}
