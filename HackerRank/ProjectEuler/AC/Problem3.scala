import scala.collection.mutable.ArrayBuffer

object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt
	def nextLong = in.next.toLong
	
 	val primes: Stream[Int] = 2 #:: (Stream.from(3, 2) filter (n => primes.view takeWhile (p => p*p <= n) forall (n % _ != 0)))
	val primes106 = primes takeWhile (_ < 1000100) toArray

	@annotation.tailrec
	def largestPrimeFactor(n: Long, index: Int): Long = {
		val p: Long = primes106(index)
		if (p*p > n) n
		else
		if (n % p == 0) {
			if (n == p) p
			else largestPrimeFactor(n/p, index)
		} else
			largestPrimeFactor(n, index + 1)
	}
	
	def main(args: Array[String]): Unit = {		
		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextLong
			println(largestPrimeFactor(N, 0))
		}
	}
}
