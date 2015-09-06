object Main {

	val in = {
		val lines = {
			scala.io.Source.stdin.getLines.buffered
			//val bf = new BufferedReader(new InputStreamReader(System.in))
			//Iterator.continually(readLine)
			//Iterator.continually(bf.readLine)
		}
		lines map (_ split &#39; &#39;) filter (_.nonEmpty) flatten
	}
	
	//val out = new PrintWriter(System.out)
	
	def nextInt = in.next().toInt
	def nextLong = in.next().toLong
	
	def main(args: Array[String]): Unit = {
	
		val mirror = "AHIMOTUVWXY"
			
		val name = in.next
		
		if (name == name.reverse && name.forall(mirror.contains(_)))
			println("YES")
		else
			println("NO")
		
	}

}