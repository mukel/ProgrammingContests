{koder: A^2P}
{PSN 2005 #15 "Amistades durante la Copa"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 200;
var
  fin,fout        : text;
  N,i,j           : byte;
  mark            : array[0..MaxN] of boolean;
  c               : array[0..MaxN,0..MaxN] of byte;

    procedure dfs(i: byte);
    var j : byte;
    begin
      mark[i] := true;
      for j:=1 to c[i,0] do
        if not mark[c[i,j]] then dfs(c[i,j]);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,c[i,0]);
    for j:=1 to c[i,0] do read(fin,c[i,j]);
    readln(fin);
  end;{for}

  {solve}{articulation-points}
  for i:=1 to N do
  begin
    mark[i] := true;
    dfs(byte(i = 1) + 1);
    for j:=1 to N do
      if not mark[j] then break;
    if not mark[j] then write(fout,i,' ');
    fillchar(mark,sizeof(mark),false);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
15ş Amistades durante la Copa.                            Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

N invitados  se supone  que asistan  a la  Copa Patria,  los invitados
est n  identificados  con  los n£meros  desde 1  hasta N.  Se sabe  de
antemano cual de estas personas son conocidos por cada uno de la otros
invitados. Dos personas ciertamente se convierten en conocidas durante
la Copa, si ellas tienen o hacen un conocido com£n. Los  organizadores
del  evento,  conociendo la  situaci¢n   est n seguros  que  todos los
invitados se convertir n en conocidos. Pero una  persona no asisti¢ al
evento y no todos los invitados pueden convertirse en conocidos.

Tarea

- Lea del  fichero de entrada  AMIGOS.IN el n£mero  de invitados a  la
  Copa Patria y los conocidos por cada persona.
- Hacer  un programa  para determinar  el invitado  que no  asisti¢ al
  evento.
- Escriba hacia el fichero de salida AMIGOS.OUT el n£mero del invitado
  ausente.

Entrada

 El fichero de entrada AMIGOS.IN contiene:
- L¡nea 1: N,  2 <  N <=200), representa el n£mero de invitados.

- L¡nea  2..N+1: en la linea i+1 del fichero se escribe la informaci¢n
  del invitado i. En cada una  de las  lineas el  primer n£mero  es el
  el n£mero P de personas que son conocidas por la persona i antes del
  evento, a continuaci¢n aparecen P n£meros separados por espacio  los
  cuales representan  los n£meros  de los  invitados conocidos  por la
  persona i.

Salida

El fichero de salida AMIGOS.OUT contiene una sola l¡nea con un  entero
el  cual  representa   el  n£mero  del  invitado  ausente.  Si  varias
soluciones (personas ausentes)  existen, solamente   escribir  una  de
ella.

Ejemplo de Entrada  y Salida

AMIGOS.IN               AMIGOS.OUT

7                       4
2 2 7
2 1 4
2 4 5
4 2 3 6 7
2 3 6
2 4 5
2 1 4
}
