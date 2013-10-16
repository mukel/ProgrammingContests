{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #18 "El c lculo romano"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  oo = 1 shl 29;
  alpha = 'IVXLCDM';
  value : array[1..7] of longint = (1,5,10,50,100,500,1000);
  roman : array[1..4,0..9] of string =
   (('','I','II','III','IV','V','VI','VII','VIII','IX'),
    ('','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'),
    ('','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'),
    ('','M','MM','MMM','','','','','',''));
var
  fin,fout        : text;
  N,i,j,idx,sol   : longint;
  expr            : string;

    function ToRoman(value: longint): string;
    begin
      ToRoman := roman[4,value div 1000] +
                 roman[3,(value mod 1000) div 100] +
                 roman[2,(value mod 100) div 10] +
                 roman[1,value mod 10];
    end;{ToRoman}

    function ToDec(st: string): longint;
    var i,res : longint;
    begin
      res := value[pos(st[length(st)],alpha)];
      for i:=length(st) - 1 downto 1 do
        if pos(st[i],alpha) >= pos(st[i + 1],alpha)
          then inc(res,value[pos(st[i],alpha)])
          else dec(res,value[pos(st[i],alpha)]);
      ToDec := res;
    end;{ToDec}

    function expresion: longint; forward;

    function factor: longint;
    var A,start : longint;
    begin
      if expr[idx] = '(' then
      begin
        inc(idx);
        factor := expresion;
        exit;
      end;{then}

      if expr[idx] in ['0'..'9'] then
      begin
        A := 0;
        while expr[idx] in ['0'..'9'] do
        begin
          A := A * 10 + ord(expr[idx]) - ord('0');
          inc(idx);
        end;{while}
        factor := A;
        exit;
      end;{then}

      start := idx;
      while expr[idx] in ['I','V','X','L','C','D','M']
        do inc(idx);
      factor := ToDec(copy(expr,start,idx - start));
    end;{factor}

    function termino: longint;
    var A,B,op : longint;
    begin
      A := factor;
      while expr[idx] in ['*','/'] do
      begin
        op := idx; inc(idx);
        B := factor;
        case expr[op] of
          '*' : A := A * B;
          '/' : A := A div B; { fuck 0 }
        end;{case}
      end;{while}
      termino := A;
    end;{termino}

    function expresion: longint;
    var A,B,op : longint;
    begin
      A := termino;
      while expr[idx] in ['+','-'] do
      begin
        op := idx; inc(idx);
        B := termino;
        case expr[op] of
          '+' : A := A + B;
          '-' : A := A - B
        end;{case}
      end;{while}
      if expr[idx] = ')' then inc(idx);
      expresion := A;
    end;{expresion}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,expr);
    expr := expr + ')';
    idx := 1;
    sol := expresion;

    {dprint}
    writeln(fout,sol,' ',ToRoman(sol));
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
18ş El c lculo romano.                                     Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Josephus,  un    ni¤o   romano quiere  ser cuando  sea  grande alguien
importante en  el gobierno  y ser un gran amigo del C‚sar, pero le han
dicho    que  el    emperador  escoge    siempre a  sus seguidores m s
inteligentes  y  capacitados  en  la matem tica. Sabiendo esto el ni¤o
Josephus, ingresa en un  curso  de matem tica,  pero no le han ido muy
bien  con    ellas      y    tiene  una tarea  que  si no  la lleva al
profesor, este lo suspende y no puede cumplir sus sue¤os.

Usted  es  amigo  del  ni¤o y  ha decidido ayudarlo. La tarea del ni¤o
consiste      en  la suma, resta, multiplicaci¢n y divisi¢n de n£meros
romanos, a lo cual el profesor le incluy¢ el sistema decimal.

Para  esta  tarea  el  ni¤o le entrega la tabla de n£meros romanos que
ser¡a la siguiente:
&
I - 1   V - 5   X - 10  L - 50  C - 100  D - 500  M - 1000
&
Hay algunas propiedades que usted debe saber para poder operar con los
n£meros romanos dentro de las que entran las siguientes :

- No pueden haber m s de 3 letras iguales, es decir  escribir el 9 de
  la forma VIIII ser¡a un error por lo que se toma IX.

- No  pueden  aparecer  dos  o  m s  letras  a  la derecha  con  mayor
  valor,  es    decir   el 54 se  puede escribir LIV, pero no se puede
  escribir  ILV,  pues  I  presenta  a su  derecha dos letras de mayor
  valor, L y V.

Usted  de  repente  tiene  una duda y se la plantea al ni¤o la cual es
como formar los  n£meros romanos, lo  cual ‚l le plantea que forme los
n£meros    por    las cifras, comenzando por los millares, seguido las
centenas,  las  decenas y por £ltimo las  unidades. Por ejemplo, el 49
no  se escribe IL, sino que se escribir¡a el 40, XL y seguido el 9 IX,
por lo tanto, ser¡a XLIX.

Tarea

Dada    la    tabla de  numeros romanos  usted  debe ayudar  al ni¤o a
encontrar  las respuestas  de sus tareas. Las operaciones presentes en
las  igualdades    es la suma (+), la  resta (-), la  multiplica- ci¢n
(*)  y  la    divisi¢n  (/), las cuales  pueden estar  acompa¤adas por
parentesis.  Se    garantiza  que    los  n£meros    con  los  que  se
trabajar n en el problema se encuentran entre 1 y 3000.

Entrada

El fichero de entrada ROMAN.IN tiene el siguiente formato:

Linea 1: un  n£mero  N (1 <= N <= 5), el cual representa los N
         ejercicios de la tarea de Josephus.
Linea 2..N+1: Presenta los ejercicios que Josephus debe resolver,
         estos  no  se excederan de  256  caracteres, y los caracteres
         de  la    expresion  se  limitaran  a  ser las letras de  los
         numeros,    las  operaciones, los  pa- rentesis y los digitos
         del 0 hasta el 9.

Salida

El fichero de salida ROMAN.OUT debera tener el siguiente formato:

Linea 1..N: la    soluci¢n   dada  por  usted  en sistema  decimal  al
            i-‚simo      ejercicio  seguido  por  un  espacio   con la
            soluci¢n en n£meros romanos.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ ROMAN.IN          ³   ³ ROMAN.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3                 ³   ³ 84 LXXXIV ³
³ (123-CII)*(I+3)   ³   ³ 7 VII     ³
³ (CLVI+124)/(L-X)  ³   ³ 805 DCCCV ³
³ (CCCXVIII*5+20)/2 ³   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
