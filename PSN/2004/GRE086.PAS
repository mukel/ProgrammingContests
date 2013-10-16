{koder: A^2P}
{PSN 2004 #86 "Decode"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i             : byte;
  c               : char;
  pass            : string[26];
  tmp,alpha       : array['A'..'Z'] of char;
  mark            : array['A'..'Z'] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,pass);
  readln(fin,N);

  {solve}
  for i:=1 to length(pass) do
  begin
    tmp[char((i + N - 2) mod 26 + ord('A'))] := pass[i];
    mark[pass[i]] := true;
  end;{for}
  for c:='A' to 'Z' do
    if not mark[c] then
    begin
      tmp[char((i+N - 1) mod 26 + ord('A'))] := c;
      inc(i);
    end;{then}
  for c:='A' to 'Z' do
    alpha[tmp[c]] := c;

  {dprint}
  repeat
    read(fin,c); write(fout,alpha[c]);
  until seekeoln(fin);

  {fclose}
  close(fin); close(fout);
end.{main}

{
86ş Decode.                                                Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un texto puede codificarse tal que sus letras sean reemplazadas por
otras letras. Para hacer esto usamos una tabla de reemplazo que puede
crearse as¡:
Se selecciona una palabra con letras diferentes del alfabeto ingl‚s -
una palabra clave. Se selecciona un entero K menor o igual que 26 - un
n£mero clave. Una tabla de reemplazo tiene dos filas y 26 columnas.
La fila superior contiene las letras ordenadas del alfabeto ingl‚s
(tadas ellas). La palabra clave se escribe letra por letra de
izquierda a derecha en la fila inferior iniciando desde la K-‚sima
posici¢n. Luego de escribir la £ltima letra de la palabra clave,
continuamos escribiendo las otras letras (las que no aparecen en la
palabra clave) ordenadas lexicogr ficamente. Cuando se escribe una
letra en la £ltima posici¢n (26-‚sima) de la fila inferior, el resto
de las letras se escribir n entonces comenzando desde la primera
posici¢n.

Por ejemplo, si la palabra clave es DUBROVNIK y el n£mero clave es 10,
entonces la tabla de reemplazo se puede escribir como:

         A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
         M P Q S T W X Y Z D U B R O V N I K A C E F G H J L

Un texto original puede codificarse tal que cada letra se busque en la
primera fila y  entonces se reemplace  por la letra  escrita debajo de
esta.

Escriba un  programa que  usando una  palabra clave  dada y  un n£mero
clave decodifique un texto codificado dado, es decir, buscar el  texto
original.

Entrada (DECODE.IN)

La primera  l¡nea del  fichero de  entrada contiene  una palabra clave
consistenete  de  letras  may£sculas  del  alfabeto  ingl‚s  (A-Z). La
longitud de una palabra  clave ser  menor o  igual que 26. La  segunda
l¡nea del fichero de entrada contiene un entero K, 1 <= K <= 26, un
n£mero clave. La  tercera l¡nea  del fichero  de entrada  contiene el
texto codificado consistente  de letras  may£sculas del  alfabeto
ingl‚s (A -Z). La longitud del texto codificado ser  menor o igual que
100.

Salida (DECODE.OUT)

La primera y £nica l¡nea del fichero de salida debe contener el texto
decodificado, es decir, el texto original.

Ejemplos de Entrada y Salida

Ejemplo #1         Ejemplo #2               Ejemplo #3
ÚÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³DECODE.IN ³      ³DECODE.IN       ³       ³DECODE.IN         ³
ÃÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³NOVI      ³      ³DUBROVNIK       ³       ³ZAGREB            ³
³15        ³      ³10              ³       ³23                ³
³DTZNMNXAWT³      ³SVPKVSVABZOMSRZY³       ³QYELREDEWEMLFNEIEP³
ÀÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³DECODE.OUT³      ³DECODE.OUT      ³       ³DECODE.OUT        ³
ÃÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³VINODOLSKI³      ³DOBRODOSLINADMIH³       ³OVAJZADATAKJELAGAN³
ÀÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}