{koder: A^2P}
{PSN 1996 #30 "Vamos para el cine­"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxI = 30;
var
  fin,fout        : text;
  i               : byte;
  c               : array[0..MaxI] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  c[0] := 1;
  for i:=1 to MaxI do
    if odd(i) then c[i] := c[i-1] div (i div 2 + 1) * i
      else c[i] := c[i-1] * 2;

  {dprint}
  repeat
    readln(fin,i);
    writeln(fout,c[i]);
  until eof(fin);

  {fclose}
  close(fin); close(fout);
end.{main}

{
30ş [VAMOS PARA EL CINE!]                               Veszpr‚m '96
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Hay un  cine  muy peque¤o  en  el pueblo con solo 30 asientos, donde
 ocacionalmente una vez al d¡a, tarde en la noche puede ser visto una
 buena  artista  o un  filme  er¢tico. El  lugar es  muy peque¤o, los
 tickets  son totalmente  baratos, 50 Ft  cada  uno, de lo, contrario
 nadie ir¡a all¡.

 Debido a razones de seguridad la caja del dinero est   siempre vac¡a
 cuando la oficina  de tickets abre. Los visitantes  est n  esperando
 con billetes de  50 ¢ 100. Ellos  arrivan  uno  a  uno, y  la cajera
 puede venderle a ellos un ticket solo si ellos pagan  con un billete
 de 50 Ft o ella  puede dar  el cambio , por  ejemplo, si  ella tiene
 al menos un billete de  50 Ft exactamente  en  la  caja  cuando  sea
 necesario. Si ella no puede dar cambio, ella se encuentra  realmente
 en  una situaci¢n  embarazosa, entonces cierra  la oficina y va para
 la casa, el filme para esa noche ser  cancelado.

 Suponga  que le  n£mero  de  los visitantes  esperado es conocido de
 antemano, pero   ellos   llegan  aleatoriamente. Ahora   escriba  un
 programa para determinar  el n£mero de todas las posibles secuencias
 de personas (o sus billetes), arrivando a la  caja, tal  que todo el
 mundo pueda comprar un ticket.

 La  entrada del  programa  estar  en  un  fichero, donde cada  l¡nea
 contiene  un  n£mero  positivo indicando  el n£mero  de lo que ser¡a
 la audiencia para el filme.

 El fichero de salida debe  contener las  correspondientes respuestas
 y el  n£mero  de las  posibles  secuencias, una  en cada  l¡nea. Los
 n£meros en la entrada no exeder n la capacidad del cine.

 ÚÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄ¿
 ³Entrada:³     ³Salida:³
 ÃÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄ´
 ³5       ³     ³10     ³
 ³2       ³     ³2      ³
 ³12      ³     ³924    ³
 ÀÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÙ
}