object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt
	 	
	def main(args: Array[String]): Unit = {
		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N, K = nextInt
			val digits = in.next map (_.asDigit)
			val products = digits.sliding(K) map (_.product)
			println(products.max)
		}
	}
}
