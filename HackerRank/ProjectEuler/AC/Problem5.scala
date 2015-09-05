import scala.math.log

object Solution {

	val in = {
		val lines = scala.io.Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt

	val primes = Seq(2, 3, 5, 7, 11, 13, 17 ,19, 23, 29, 31, 37)
	 	
	def main(args: Array[String]): Unit = {
		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextInt
			val primesExp = primes zip (primes map (p => (log(N) / log(p)).toInt))
			val powers = primesExp map { case (p, e) => math.pow(p, e).toLong }
			println(powers.product)
		}
	}
}
