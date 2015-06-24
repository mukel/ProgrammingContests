{koder: A^2P}
{PSN 2005 #66 "Pizza"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,a,b,c,sol   : integer;
  s               : string[3];

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,s);
    if s = '1/4' then inc(a)
      else if s = '1/2' then inc(b)
        else {if s = '3/4' then} inc(c);
  end;{for}

  {solve}
  sol := (b+1) div 2 + c; dec(a,c);
  if (a+1) div 2 - (b and 1) > 0
    then inc(sol,(a+3) div 4);

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
66ş Pizza.                                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko est  celebrando su fiesta de cumplea¤os asi que el ha invitado a
sus amigos a comer pizza. Desafortunadamente, los amigos de Mirko son
muy jovenes y no se pueden comer una pizza entera, pero todos ellos
conocen exactamente que cantidad de pizza ellos pueden comer e
insisten en obtener la cantidad exacta de pizza en un pedazo.

Su petici¢n se descompone en tres diferentes pedazos de pizza - un
cuarto, una mitad o tres cuartos de pizza.

Tarea

Escriba un programa que ayude a Mirko a encontrar cual es el numero
minnimo de pizzas que el tiene que comprar tal que todo el mundo
obtenga la cantidad exacta de pizza que ellos quieren.

Entrada

La primera linea del fichero de entrada PIZZA.IN contiene un entero N,
1 <= N <= 10,000, el numero de amigos. En cada una de las proximas
N lineas aparece la cantida de pizza que cada uno de los amigos de
Mirko quiere para comer, esto es la fracci¢n 1/4, 1/2 ¢ 3/4.

Salida

El fichero de salida PIZZA.OUT contiene en la primera y unica linea el
numero minimo de pizzas que Mirko tiene que comprar.

Ejemplo de Entrada y Salida

 Ejemplo # 1     Ejemplo # 2     Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄ¿
³ PIZZA.IN ³    ³ PIZZA.IN ³    ³ PIZZA.IN ³
ÃÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄ´
³ 3        ³    ³ 5        ³    ³ 6        ³
³ 1/2      ³    ³ 1/2      ³    ³ 3/4      ³
³ 3/4      ³    ³ 1/4      ³    ³ 1/2      ³
³ 3/4      ³    ³ 3/4      ³    ³ 3/4      ³
ÀÄÄÄÄÄÄÄÄÄÄÙ    ³ 1/4      ³    ³ 1/2      ³
                ³ 1/2      ³    ³ 1/4      ³
                ÀÄÄÄÄÄÄÄÄÄÄÙ    ³ 1/2      ³
                                ÀÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PIZZA.OUT ³   ³ PIZZA.OUT ³   ³ PIZZA.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³   ³ 3         ³   ³ 4         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
