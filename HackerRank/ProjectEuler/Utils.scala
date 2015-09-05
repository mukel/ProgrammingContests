object Utils {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt

	val fibs: Stream[Long] = 1L #:: fibs.scanLeft(2L)(_ + _)

	val primes: Stream[Int] = 2 #:: (Stream.from(3, 2) filter (n => primes.view takeWhile (p => p*p <= n) forall (n % _ != 0)))

	@annotation.tailrec
	def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

	def lcm(a: Int, b: Int): Int = a / gcd(a, b) * b

	@annotation.tailrec
	def binarySearch[T, U](key: U, xs: IndexedSeq[T], from: Int, end: Int, keyExtract: (T) => U = (x:T) => x)(implicit ordering: Ordering[U]): Option[Int] = {
		if (from >= end) None
		else {
			val mid = (from + end) / 2
			val t = keyExtract(xs(mid))
			val cmp = ordering.compare(key, t)
			if (cmp < 0) binarySearch(key, xs, from, mid, keyExtract)
			else if (cmp > 0) binarySearch(key, xs, mid + 1, end, keyExtract)
			else Some(mid)
		}
	}

	def lowerBound[T, U](key: U, iseq: IndexedSeq[T], from: Int, end: Int, keyExtract: (T) => U = (x:T) => x)(implicit ordering: Ordering[U]): Int = {
		var lo = from
		var hi = end - 1
		while (lo <= hi) {
			val mid = (lo + hi) / 2
			if (ordering.lteq(key, keyExtract(iseq(mid))))
				hi = mid - 1
			else
				lo = mid + 1
		}
		hi + 1
	}

	def upperBound[T, U](key: U, iseq: IndexedSeq[T], from: Int, end: Int, keyExtract: (T) => U = (x:T) => x)(implicit ordering: Ordering[U]): Int = {
		var lo = from
		var hi = end - 1
		while (lo <= hi) {
			val mid = (lo + hi) / 2
			if (ordering.lt(key, keyExtract(iseq(mid))))
				hi = mid - 1
			else
				lo = mid + 1
		}
		hi + 1
	}

}

