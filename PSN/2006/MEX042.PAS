{koder: A^2P}
{PSN 2006 #42 "Party Lamp"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,C,i           : longint;
  lamp,target     : array[0..MaxN] of byte;

    procedure doit(d: byte);
    var i : byte;
    begin
      case d of
        1 : for i:=1 to N do lamp[i] := lamp[i] xor 1;
        2 : for i:=0 to N div 2 do lamp[2 * i + 1] := lamp[2 * i +1] xor 1;
        3 : for i:=1 to N div 2 do lamp[2 * i] := lamp[2 * i] xor 1;
        4 : for i:=0 to N div 3 do lamp[3 * i + 1] := lamp[3 * i +1] xor 1;
      end;{case}
    end;{doit}

    procedure comb(i,k: byte);
    var j : byte;
    begin
      if i = 5 then
      begin
        if (k <= C) and (not odd(C - k)) then
        begin
          for j:=1 to N do
            if (target[j] <> 2) and (lamp[j] <> target[j])
              then exit;
          for j:=1 to N do write(fout,lamp[j]);
          writeln(fout);
        end;{then}
        exit;
      end;{then}
      comb(i+1,k); doit(i);
      comb(i+1,k+1); doit(i);
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  fillchar(lamp,sizeof(lamp),1);
  fillchar(target,sizeof(target),2);
  readln(fin,N); readln(fin,C);
  read(fin,i);
  while i <> -1 do
  begin
    target[i] := 1; read(fin,i);
  end;{while}
  read(fin,i);
  while i <> -1 do
  begin
    target[i] := 0; read(fin,i);
  end;{while}

  {solve}
  comb(1,0);

  {fclose}
  close(fin); close(fout);
end.{main}

{
42ş Party Lamp.                                            M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Para iluminar la cena de gala  de la IOI'98 tenemos un conjunto  de N
 l mparas de color numeradas de 1 a N. Las l mparas est n conectadas a
 4 botones.

 Bot¢n 1: Cuando este bot¢n es presionado, todas las  l mparas cambian
          sus estados. Las que est n  prendidas (en ON)  se apagan (en
          OFF) y las que est n apagadas se prenden.
 Bot¢n 2: Cambia el estado de todas las l mparas con n£mero impar.
 Bot¢n 3: Cambia el estado de todas las l mparas con n£mero par.
 Bot¢n 4: Cambia  el estado de  todas  las l mparas  cuyo n£mero tenga
          la forma 3K+1, con K ò 0, es decir 1, 4, 7, ...

 Hay un  contador que  registra  el n£mero  total  de  pulsaciones  de
 bot¢n. Cuando la fiesta  comienza todas las l mparas est n  prendidas
 y el contador est  en 0.

 Tarea

 Ud. recibe  el valor C del contador  e informaci¢n  sobre  el  estado
 final  requerido  para  algunas  l mparas.  Escriba  un  programa que
 determine  todas  las  posibles  configuraciones  finales  de   las N
 l mparas  que  sean   consistentes   con  la  informaci¢n  dada,  sin
 repeticiones.

 Entrada

 El archivo  llamado PARTY.IN  con  cuatro  l¡neas  que  describen  el
 n£mero N de l mparas, el n£mero  C de veces que debe  apretarse alg£n
 bot¢n y  el  estado  de  algunas  de las l mparas en la configuraci¢n
 final. La  primera  l¡nea  contiene el  n£mero  N   de  l mparas y la
 segunda el  valor final  C del  contador. La  tercera l¡nea lista los
 n£meros  de  las  l mparas  que se  desean   tener  prendidas   en la
 configuraci¢n   final,   separadas  por   un  espacio   en  blanco  y
 terminando con un n£mero -1. La cuarta l¡nea lista los n£meros de las
 l mparas  que  se  desean tener apagadas en la  configuraci¢n  final,
 separadas  por  un  espacio en blanco, terminando con un -1.

 Salida

 El archivo PARTY.OUT debe contener todas las posibles configuraciones
 finales (sin repetici¢n) de todas  las  l mparas. Cada  configuraci¢n
 posible debe ser escrita en  una l¡nea diferente. Las configuraciones
 pueden listarse en cualquier orden. Cada  l¡nea  tiene  N caracteres,
 donde  el primero representa  el estado de la l mpara 1  y  el £ltimo
 representa el estado  de la l mpara N. Un 0  representa  una  l mpara
 apagada y un 1 representa una l mpara prendida.

 Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ PARTY.IN ³
 ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 10       ³
 ³ 1        ³
 ³ -1       ³
 ³ 7 -1     ³
 ÀÄÄÄÄÄÄÄÄÄÄÙ

 En este  caso hay  10  l mparas  y  solo  se  pulsa  a  un  bot¢n. La
 l mpara 7 debe estar apagada en la configuraci¢n final.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ PARTY.OUT  ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 0000000000 ³
 ³ 0110110110 ³
 ³ 0101010101 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ

 En este caso hay tres posibles configuraciones  finales: o  todas las
 l mparas est n apagadas; o lo est n  las  l mparas 1, 4, ,7 ,10 y las
 2, 3, 5, 6, 8 y 9  est n  encendidas  o  las  l mparas 1, 3, 5, 7 y 9
 est n apagadas y las l mparas 2, 4, 6, 8 y 10 est n encendidas.

 Restricciones:

 Los par metros N y C est n restringidos por:
 10 <= N <= 100
 1  <= C <= 100000

 La cantidad de l mparas que se  informa  que deben estar prendidas es
 menor o  igual a  2. La  cantidad de  l mparas que  se informa  deben
 estar  apagadas  es  menor  o  igual  a  2.  Hay  por  lo  menos  una
 configuraci¢n para  cada  fichero  de  datos  de prueba.
}