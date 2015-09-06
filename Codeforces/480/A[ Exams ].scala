object Main {

  val in =  {
    val lines = scala.io.Source.stdin.getLines
    lines map (_ split &#39; &#39;) filter (_.nonEmpty) flatten
  }
  
  def nextInt = in.next.toInt
  
  def main(args: Array[String]): Unit = {
    
    val N = nextInt
    val vals = Array.fill(N){
      val a, b = nextInt
      (a, b)
    }.sorted
    
    var best = 0
    for ((a, b) <- vals) {
      if (b >= best) best = b
      else best = a
    }
    
    println(best)
  }
}