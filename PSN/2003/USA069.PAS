{koder: A^2P}{2 - 5 - 2007}
{PSN 2003 #69 "Isla"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  oo = 1 shl 29;
  MaxN = 50002;
var
  fin,fout        : text;
  N,i,j,k,sol     : longint;
  d               : array[0..MaxN] of longint;

    function dist(i,j: longint): longint;
    begin
      k := d[j] - d[i];
      if d[N + 1] - k < k then k := d[N + 1] - k;
      dist := k;
    end;{dist}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=2 to N + 1 do
  begin
    readln(fin,d[i]);
    inc(d[i],d[i - 1]);
  end;{for}

  {solve}
  i := 1; j := 2;
  repeat
    while (j <= N) and (dist(i,j + 1) > dist(i,j))
      do inc(j);
    if dist(i,j) > sol then sol := dist(i,j);
    inc(i);
  until j > N;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 69ş Isla.                                                    USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 En Bytelan hay un torneo planificado entre dos equipos antag¢nicos
 de futbol : el equipo Linuxers y el Microsofter: Se sabe que los
 fan ticos de ambos equipos le tienen un profundo odio a los fan ticos
 del otro equipo, ellos deben ver el torneo solamente por TV y deben
 estar ubicados en pueblos que est‚n a la mayor distancia posible  del
 otro ?. Bytelan es una isla, y todos sus pueblos est n a lo largo del
 litoral, una autopista de doble sentido que conecta a todos los
 pueblos a lo largo de la costa. De cada pueblo uno puede alcanzar
 alg£n otro pueblo yendo en el sentido de las manecillas del reloj o en
 contra de ellas. La longitud de la ruta m s corta es la distancia
 entre los dos pueblo.

 Tarea

 Escriba un programa el cual:
 - lea del fichero texto WYS.IN la descripci¢n de la isla,
 - calcule la m xima distancia a la que los fan ticos de un equipo
   pueden estar separados  de los fan ticos de otro equipo,
 - escriba el resultado hcia un fichero texto WYS.OUT.

 Entrada

 En la primera l¡nea  del fichero WYS.IN hay un entero n,
 2<=n<=50000,denotando el n£mero de pueblo en la isla. En los
 siguientes n l¡nea est  las longitudes de las secciones de autopista
 entre pueblo adyacentes. Cada una de las l¡neas contienen un entero
 positivo. En la l¡nea i+1 est  la secci¢n de la autopista entre el
 pueblo i y el pueblo i+1, mientras que en la l¡nea n+1 est  la
 longuitud de la ruta entre los pueblos n y 1. La longuitud cumpleta de
 la autopista no excede 1 000,000,000.

 Salida

 La primera y £nica l¡nea del fichero texto de salida WYS.IN debe
 contener un entero siendo este la distancia m xima que los fan ticos
 pueden estar separados.

 Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
 ³ WYS.IN ³  ³ WYS.OUT ³
 ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
 ³ 5      ³  ³ 7       ³
 ³ 1      ³  ÀÄÄÄÄÄÄÄÄÄÙ
 ³ 2      ³
 ³ 3      ³
 ³ 4      ³
 ³ 5      ³
 ÀÄÄÄÄÄÄÄÄÙ
}
