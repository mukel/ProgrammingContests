object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt

	def lowerBound[T, U](key: U, iseq: IndexedSeq[T], from: Int, end: Int, keyExtract: (T) => U = (x:T) => x)(implicit ordering: Ordering[U]): Int = {
		var lo = from
		var hi = end - 1
		while (lo <= hi) {
			val mid = lo + (hi - lo - 1) / 2
			if (ordering.lteq(key, keyExtract(iseq(mid))))
				hi = mid - 1
			else
				lo = mid + 1
		}
		hi + 1
	}
	 	
	def main(args: Array[String]): Unit = {

		val pals = for {
				a <- 100 to 999
				b <- a to 999
				p = a * b
				s = p.toString
				if s == s.reverse
			} /* do */
				yield p

		val sortedPals = pals.sorted.toArray		

		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextInt
			val index = lowerBound[Int, Int](N, sortedPals, 0, sortedPals.size)
			println(sortedPals(index - 1))
		}
	}
}
