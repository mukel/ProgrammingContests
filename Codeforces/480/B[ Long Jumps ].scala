object Main {

  val in =  {
    val lines = scala.io.Source.stdin.getLines
    lines map (_ split &#39; &#39;) filter (_.nonEmpty) flatten
  }
  
  def nextLong = in.next.toLong
  
  def main(args: Array[String]): Unit = {
    
    val N, L, X, Y = nextLong
    val marks = Array.fill(N.toInt)(nextLong)
    
    val s = scala.collection.mutable.Set[Long]()
    marks foreach (s.add(_))

    val xb = marks.exists(x => s.contains(x + X))
    val yb = marks.exists(x => s.contains(x + Y))

    if (xb && yb) {
      println(0)
      System.exit(0)
    }
    
    if (xb) {
      println(1)
      println(Y)
      System.exit(0)
    }
    
    if (yb) {
      println(1)
      println(X)
      System.exit(0)
    }
    
    for (x <- marks) {
      if (s.contains(x + X + Y))
      {
        println(1)
        println(x + X)
        System.exit(0)
      }
    }
    
    def valid(x: Long) = x >= 0 && x <= L
    
    for (x <- marks) {
      if (valid(x + Y) && s.contains(x + Y - X))
      {
        println(1)
        println(x + Y)
        System.exit(0)
      }
      if (valid(x - Y) && s.contains(x - Y + X))
      {
        println(1)
        println(x - Y)
        System.exit(0)
      }
    }
    
    println(2)
    println(X + " " + Y)
  }
}