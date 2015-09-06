import scala.io._
import java.util.StringTokenizer
import java.io.BufferedReader
	
object Main {

	def main(args: Array[String]): Unit =
	{
		val n = nextInt
		
		if (n % 2 == 0)
			println(-1)
		else
		{			
			val a = (0 until n)
			val b = for (i <- 0 until n) yield ((3 + i) % n) 
			val c = a zip b map {case (a, b) => ((a+b) % n)}
			
			if (c.sorted != (0 until n))
				println("-1")
			else
			{
				println(a mkString(" "))
				println(b mkString(" "))
				println(c mkString(" "))
			}
		}			
	}	
	
	class Tokenizer(in: BufferedReader, splitOn: String = " \n\t\r\f")
	{
		private var tokenizer = new StringTokenizer("")
		def readLine() = in.readLine()		
		def nextToken(): String = {
			while (!tokenizer.hasMoreTokens) {
				val line = readLine
				if (line == null) return null
				tokenizer = new StringTokenizer(line, splitOn)
			}
			tokenizer.nextToken
		}		
		def next[A](f: String => A) = f(nextToken)
	}
	
	implicit val tokenizer = new Tokenizer(Console.in)

	def nextString()(implicit t: Tokenizer) = t.nextToken()
	def nextInt()(implicit t: Tokenizer) = t.next(_.toInt)
	def nextLong()(implicit t: Tokenizer) = t.next(_.toLong)
	def nextDouble()(implicit t: Tokenizer) = t.next(_.toDouble)
	def nextBigInt()(implicit t: Tokenizer) = t.next(BigInt(_))
	def nextSeq[A](f : () => A, count: Int = nextInt()) = for (i <- 0 until count) yield f()
}