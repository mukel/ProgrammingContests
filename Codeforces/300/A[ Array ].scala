import scala.io._
import java.util.StringTokenizer
import java.io.BufferedReader

object Main {
    
    def printList[A](ls: List[A]) = {
        print(ls.size);
        for (x <- ls) print( " " + x )
        println
    }

    def main(args: Array[String]): Unit = {
        var (nums, zeros) = nextSeq(nextInt).toList partition (_ != 0)
        var (neg, pos) = nums partition (_ < 0)
        
        if (pos.isEmpty) {
            pos = neg.take(2)
            neg = neg.drop(2)
        }       
        if (neg.size % 2 == 0) {
            zeros = neg.head :: zeros
            neg = neg.tail
        }
        printList(neg)
        printList(pos)
        printList(zeros)
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
