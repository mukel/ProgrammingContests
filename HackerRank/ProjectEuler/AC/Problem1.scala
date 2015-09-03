import scala.io.Source

object Solution {
	val in = {
		val lines = Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}
	def nextInt = in.next.toInt

	def sum(n: Int): Long = 1L * n * (n + 1) / 2

	def main(args: Array[String]): Unit = {
		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextInt - 1
			val ans = sum(N/3)*3 + sum(N/5)*5 - sum(N/15)*15
			println(ans)
		}
	}
}