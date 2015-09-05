object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt	
	 	
	def main(args: Array[String]): Unit = {
		val testCount = nextInt

		val MAXN = 10000
		def square(x: Long) = x * x
		val nums = 1L to MAXN

		val sumOfSquares = (nums map square).scanLeft(0L)(_ + _)
		val squareOfSum = nums.scanLeft(0L)(_ + _) map square

		for (test <- 1 to testCount) {
			val N = nextInt
			println(squareOfSum(N) - sumOfSquares(N))
		}
	}
}
