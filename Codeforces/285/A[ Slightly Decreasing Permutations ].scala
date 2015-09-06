import scala.io._
import java.util.StringTokenizer
import java.io.BufferedReader

object Main {
    
    def main(args: Array[String]): Unit = {
        val N = nextInt
        val K = nextInt
        (K+1) to 1 by -1 foreach println
        (K+2) to N foreach println
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
        def nextSeq[A](f: () => A, count: Int) = (for (i <- 0 until count) yield f())
    }
    
    implicit val tokenizer = new Tokenizer(Console.in)
    
    def nextInt()(implicit t: Tokenizer) = t.next(_.toInt)
    def nextLong()(implicit t: Tokenizer) = t.next(_.toLong)
    def nextDouble()(implicit t: Tokenizer) = t.next(_.toDouble)
    def nextBigInt()(implicit t: Tokenizer) = t.next(BigInt(_))
    def nextSeq[A](f: () => A, count: Int = nextInt())(implicit t: Tokenizer) =
        (for (i <- 0 until count) yield f())
}
