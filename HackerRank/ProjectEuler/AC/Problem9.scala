object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt

	def main(args: Array[String]): Unit = {
		val MAXN = 3000
		val pyths = for {
			s <- 1 to MAXN
			t <- s to MAXN
			r = math.sqrt(2 * s * t).toInt
			if r*r == 2 * s * t
			a = r + s
			b = r + t
			c = r + s + t
			sum = a + b + c
			product = a * b * c
		} /* do */
			yield (sum, product)

		val answer = pyths.groupBy(_._1) mapValues (seq => (seq map (_._2)).max)

		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextInt
			println(answer.getOrElse(N, -1))
		}
	}
}
