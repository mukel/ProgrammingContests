object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt

	val primes: Stream[Int] = 2 #:: (Stream.from(3, 2) filter (n => primes.view takeWhile (p => p*p <= n) forall (n % _ != 0)))

	def upperBound[T, U](key: U, xs: IndexedSeq[T], from: Int, end: Int, keyExtract: (T) => U = (x:T) => x)(implicit ordering: Ordering[U]): Int = {
		var lo = from
		var hi = end - 1
		while (lo <= hi) {
			val mid = (lo + hi) / 2
			if (ordering.lt(key, keyExtract(xs(mid))))
				hi = mid - 1
			else
				lo = mid + 1
		}
		hi + 1
	}

	def main(args: Array[String]): Unit = {
		val p = primes takeWhile (_ < 1000100) toArray
		val primeSums = p.scanLeft(0L)(_ + _)

		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextInt
			val index = upperBound[Int, Int](N, p, 0, p.size)
			println(primeSums(index))
		}
	}
}
