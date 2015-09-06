object Main {
    val in = {
        val lines = scala.io.Source.stdin.getLines()
        lines map (_ split &#39; &#39;) filter (_.nonEmpty) flatten
    }
    def nextInt = in.next().toInt
    def main(args: Array[String]): Unit = {
        val K, N = nextInt
        val x = Seq.fill(N)(nextInt).sorted
        val ans = x zip (x drop (K-1)) map { case (a, b) => b - a }
        println(ans.min)
    }
}