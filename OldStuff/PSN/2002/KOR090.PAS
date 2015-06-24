{koder: A^2P}{16 - 3 - 2007}
{PSN 2002 #90 "Planeta"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 20;
var
  fin,fout        : text;
  ch              : char;
  N,i             : longint;
  sol             : string[20];
  s               : array[0..MaxN] of byte;

    procedure comb(i,len: byte);
    var j : byte;
    begin

      if i > N then
      begin
        byte(sol[0]) := len - 1;
        writeln(fout,sol);
        exit;
      end;{then}

      if s[i] = 1 then
      begin
        j := 0;
        while (i <= N) and (j * 2 + s[i] < 10) do
        begin
          j := j * 2 + s[i];
          sol[len] := chr(j + 48);
          inc(i); comb(i,len + 1);
        end;{while}
      end{then ->}
      else begin
        while (i <= N) and (s[i] = 0) do
        begin
          sol[len] := '0';
          inc(i); inc(len);
        end;
        comb(i,len);
      end;{else}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  repeat
    read(fin,ch);
    inc(N); s[N] := byte(ch = '1');
  until seekeoln(fin);

  {solve}
  comb(1,1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
90þ  Planeta                                                Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  grupo de cient¡ficos de la Tierra ha decidido ir hacia  el planeta
Plane,  que  est   m s  distante  del Sol que la Tierra, para realizar
algunas  investigaciones  sobre ‚l. Ellos llevan consigo un equipo que
le transmite a la Tierra todas las investigaciones realizadas.
Transmiten algunos n£meros en c¢digo binario.

Para  transmitir  un  n£mero  los  investigadores  cambian cada digito
decimal  por  su  correspondiente   representaci¢n en binario sin usar
ceros  no  significativos  (por  ejemplo  2 se representa como 10 y no
010),  concatenan  las  representaciones    y  luego  env¡an la cadena
resultante.  Si  por  ejemplo  el  n£mero  a  trasmitir fuera 0230, se
proceder¡a de la siguiente manera:

0 en c¢digo binario es  0
2 en c¢digo binario es 10
3 en c¢digo binario es 11
0 en c¢digo binario es  0

Por lo que la cadena resultante ser¡a 010110.

Al  recibir  en la Tierra la cadena 010110, esta se puede agrupar como
0,  10,  11 y 0 e interpretar como 0230, pero tambi‚n se puede agrupar
como 0, 10, 1 y 10 e interpretar como 0212.

Tarea

Haga  un  programa  que  permita  encontrar todas las interpretaciones
posibles de un n£mero enviado desde Plane.

Entrada: PLANETA.ENT

En  la  primera y £nica l¡nea del archivo  de entrada PLANETA.ENT debe
aparecer  una    cadena    formada  por  los caracteres '0' ¢ '1', sin
espacios entre ellos de longitud entre 1 y 20.

Salida: PLANETA.SAL

En  cada  l¡nea  del  archivo  PLANETA.SAL  debe ir una interpretaci¢n
posible del n£mero enviado. No deben haber repeticiones.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PLANETA.ENT³ ³ PLANETA.SAL ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 010110     ³ ³ 010110      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ ³ 01012       ³
               ³ 01030       ³
               ³ 0106        ³
               ³ 02110       ³
               ³ 0212        ³
               ³ 0230        ³
               ³ 026         ³
               ³ 0510        ³
               ³ 052         ³
               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
