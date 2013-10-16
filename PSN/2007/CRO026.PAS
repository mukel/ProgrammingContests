{koder: A^2P}{31 - 3 - 2007}
{PSN 2007 #39 "Configuraciones de teclado (II)"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10;
  MaxM = 5000;
  oo = 1 shl 20;
var
  fin,fout        : text;
  ch              : char;
  N,M,i,j,k,h,d   : longint;
  seq             : array[0..MaxM] of char;
  cost,last       : array[0..MaxM,0..MaxN] of longint;
  t,boton         : array[0..MaxN,'A'..'z'] of longint;
  

  procedure print(i,j: longint);
  var k : longint;
  begin
    if i > 0 then
    begin
      print(i - 1,last[i,j]);
      if last[i,j] <> j then writeln(fout,'#',j);
      write(fout,seq[i],' ');
      for k := 1 to t[j,seq[i]] do
        write(fout,boton[j,seq[i]]);
      writeln(fout);
    end{then}
    else writeln(fout,'#',j);
  end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M);
  for i:=1 to M do read(fin,seq[i]);
  readln(fin);
  readln(fin,N);
  for i:=1 to N do
    for ch:='A' to 'z' do t[i,ch] := oo;

  for i:=1 to N do
  begin
    for h:=1 to 9 do
    begin
      read(fin,j,ch);
      k := 0;
      while not seekeoln(fin) do
      begin
        inc(k);
        read(fin,ch);
        boton[i,ch] := j;
        t[i,ch] := k;
      end;{while}
    end;{for}
    readln(fin);
  end;{for}

  {init}
  for i:=0 to M do
    for j:=0 to N do cost[i,j] := oo;
  for i:=1 to N do cost[0,i] := 1;

  {solve}{dp}
  for i:=1 to M do
    for j:=1 to N do
    begin
      cost[i,j] := cost[i - 1,j] + t[j,seq[i]];
      last[i,j] := j;

      k := 0;
      for h:=1 to N do
        if cost[i - 1,h] < cost[i - 1,k] then k := h;

      if cost[i - 1,k] + t[j,seq[i]] + 1 < cost[i,j] then
      begin
        last[i,j] := k;
        cost[i,j] := cost[i - 1,k] + t[j,seq[i]] + 1;
      end;{then}
    end;{for}

  {dprint}
  h := 0;
  cost[M,0] := oo;
  for i:=1 to N do
    if cost[M,i] < cost[M,h] then h := i;

  writeln(fout,cost[M,h]);
  print(M,h);

  {fclose}
  close(fin); close(fout);
end.{main}

{
26þ Configuraciones de teclado.                           Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La Compa¤¡a IslaMovil ha instalado un nuevo servicio en sus  tel‚fonos
m¢viles con el objetivo de  hacerlos m s baratos. La novedad  consiste
en que al  trasmitir mensajes de  texto cada operaci¢n  de clic  sobre
un caracter en  el teclado tiene   un valor  de 1  centavo. El   nuevo
sistema  tiene  varias  configuraciones  de  teclado   las  cuales  en
dependencia  del  mensaje   se  pueden  ir  alternando.  El  cambio de
configuraci¢n de teclado cuesta solamente 1 centavo. El teclado  va  a
tener siempre 9 teclas y la tecla #, que es la tecla de control. A las
teclas num‚ricas en dependencia de la configuraci¢n se les asigna  una
determinada secuencia de caracteres.

Tomemos inicialmente un  teclado, en cada  tecla pueden existir  uno o
varios caracteres del  alfabeto ingl‚s y  todas las letras  aparecer n
una sola  vez sin  repetici¢n en  una configuraci¢n,  colocadas en  un
orden, por ejemplo si  en la tecla  4  est n las letras ghi,  entonces
para colocar la  letra i  en un  mensaje hay  que oprimir  la tecla  4
tres veces.

Siempre es posible escribir un mensaje usando las configuraciones  del
teclado disponible. El problema entonces radica en minimizar el  gasto
al enviar un mensaje.

Tarea

Hacer un programa que permita:

-	Leer  desde fichero  de entrada  TCONFIG2.IN el  mensaje que se desea
  enviar y las configuraciones del teclado del dispositivo.

-	Determinar el menor costo posible con que puede enviarse el mensaje,
  as¡ como la secuencia de clic que fueron necesarios.

-	Escribir hacia  el fichero  de salida  TCONFIG2.OUT el  menor costo
  encontrado y  la secuencia  de clic  que se  necesitan para   enviar
  el mensaje con ese costo.

Entrada

El fichero de entrada TCONFIG2.IN contiene:
L¡nea 1: N (1 <= N <= 5000) el n£mero de caracteres del mensaje.
L¡nea 2: el mensaje, escrito sin espacios y con caracteres en
min£sculas.
L¡nea 3: C (1 <= C <= 10), cantidad de configuraciones de teclados.
L¡nea 4..C*9 + C-1: Se escribir n para cada configuraci¢n el n£mero de
la tecla y los caracteres asociados a dicha tecla en el orden que
ellos aparecen. Una configuraci¢n se separa de la otra por una l¡nea
en blanco.

Salida

El fichero de salida TCONFIG2.OUT contiene:
L¡nea 1: el entero CM el cual representan el costo del mensaje.
L¡nea 2..en adelante: en cada una  de ellas el car cter del mensaje  y
la tecla a la que le corresponde el car cter la cantidad de veces que
esa tecla se  oprimi¢, en el caso  de ser el car cter de control colocamos
el s¡mbolo de # y la configuraci¢n  para la cual se cambio.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ TCONFIG2.IN  ³ ³ TCONFIG2.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 11           ³ ³ 20           ³
³ computadora  ³ ³ #2           ³
³ 2            ³ ³ c 22         ³
³ 1 w          ³ ³ o 99         ³
³ 2 abc        ³ ³ #1           ³
³ 3 def        ³ ³ m 6          ³
³ 4 ghi        ³ ³ p 7          ³
³ 5 jkl        ³ ³ u 88         ³
³ 6 mno        ³ ³ t 8          ³
³ 7 pqrs       ³ ³ a 2          ³
³ 8 tuv        ³ ³ d 3          ³
³ 9 xyz        ³ ³ #2           ³
³ a 2          ³ ³ o 99         ³
³              ³ ³ r 66         ³
³ 1 yz         ³ ³ a 44         ³
³ 2 gcm        ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 knl        ³
³ 4 ea         ³
³ 5 jbiv       ³
³ 6 xrt        ³
³ 7 dfw        ³
³ 8 ps         ³
³ 9 uoq        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}