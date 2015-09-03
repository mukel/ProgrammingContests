import scala.io.Source

object Solution {
	val in = {
		val lines = Source.stdin.getLines
		lines flatMap (_ split ' ' filter (_.nonEmpty))
	}

	def nextInt = in.next.toInt
	def nextLong = in.next.toLong

	val fibs: Stream[Long] = 1L #:: fibs.scanLeft(2L)(_ + _)

	def main(args: Array[String]): Unit = {
		val testCount = nextInt
		for (test <- 1 to testCount) {
			val N = nextLong
			val evenFibs = fibs takeWhile (_ <= N) filter (_ % 2 == 0)
			println(evenFibs.sum)
		}
	}
}
