object Solution {
  def execute(program: String, input: Iterator[Char]): Unit = {
    val mem = Array.ofDim[Int](1 << 16)
    var dataPtr, instPtr = 0
    var iterations = 100000
    val twinBracket = Array.ofDim[Int](program.size)
    val s = scala.collection.mutable.Stack[Int]()
	for (i <- program.indices) {
    	if (program(i) == '[') s.push(i)
    	if (program(i) == ']') {
    		twinBracket(i) = s.top
    		twinBracket(s.pop) = i
    	}
    }
    while (iterations > 0 && instPtr < program.size) {
      program(instPtr) match {
        case '+' => mem(dataPtr) = (mem(dataPtr) + 1) % 256
        case '-' => mem(dataPtr) = (mem(dataPtr) - 1 + 256) % 256
        case '.' => print(mem(dataPtr).toChar)
        case ',' => mem(dataPtr) = input.next().toByte
        case '<' => dataPtr -= 1
        case '>' => dataPtr += 1
        case '[' => if (mem(dataPtr) == 0) instPtr = twinBracket(instPtr) - 1
        case ']' => if (mem(dataPtr) != 0) instPtr = twinBracket(instPtr) - 1        
      }
      instPtr += 1
      iterations -= 1
    }
    if (instPtr < program.size)
      println("\nPROCESS TIME OUT. KILLED!!!")
  }

  def main(args: Array[String]): Unit = {
    val programLineCount = (readLine split " ")(1).toInt
    val input = readLine
    val program = Seq.fill(programLineCount)(readLine).mkString.filter ("<>+-.,[]" contains _)
    execute(program, input.toIterator)
  }
}
