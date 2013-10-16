{koder: A^2P}
{PSN 2001 #39 "Escaleras" }
program esc;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i          : word;
   m            : array[1..50,0..1] of real;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,N);

     {solve}
     m[1,0] := 1; m[1,1] := 1;
     for i:=2 to N do
     begin
         m[i,0] := m[i-1,0] + m[i-1,1];
         m[i,1] := m[i-1,0];
     end;

     {dprint}
     write(fout,m[N,0] + m[N,1] :0:0);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
39ş Escaleras                                           Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una empresa se dedica a la construcci¢n  de  escaleras  con  escalones
simples  (un  escal¢n  simple  s¢lo  tiene  un pelda¤o o una unidad de
altura). La  empresa  tiene  mucha  demanda  y  recibe  todo  tipo  de
solicitudes de escaleras, las solicitudes se hacen informando el largo
y  la  altura  que  desean  cubrir  con  una escalera. Un cliente va a
realizar  la  solicitud  y  la  empresa  le muestra todas las posibles
formas que  puede  tener  la  escalera  para que el usuario seleccione
la que desee.

Los ingenieros de la empresa est n trabajando en la b£squeda de  todas
estas formas y necesitan saber cu ntas existen.  Para estos ingenieros
la longitud de la escalera es el n£mero de piezas usadas en la  propia
escalera, cada pieza tiene una unidad  de  longitud.  Una  pieza puede
avanzar  de forma horizontal o de forma vertical, en la forma vertical
sube un pelda¤o el cual ser  simple por lo que no habr  un escal¢n con
dos unidades de altura.

Ejemplo, para una logitud n=4 existen 8 formas las cuales son:

                           É ÍÍÍ ÍÍÍ                    É
                           º                            º
 ÍÍÍ ÍÍÍ ÍÍÍ ÍÍÍ        ÍÍÍ                        É ÍÍÍ
       (1)                   (4)                   º
                                                ÍÍÍ
            É           É ÍÍÍ ÍÍÍ ÍÍÍ                (7)
            º           º
 ÍÍÍ ÍÍÍ ÍÍÍ                 (5)                        É
      (2)                                               º
                              É ÍÍÍ            É ÍÍÍ ÍÍÍ
        É ÍÍÍ                 º                º
        º                É ÍÍÍ
 ÍÍÍ ÍÍÍ                 º                           (8)
      (3)                    (6)

Elabore un programa que determine el n£mero de escaleras que se pueden
construir de longitud n, (1<=n<=50).

Entrada

El archivo de entrada contiene un simple valor que representa a n.

Salida

El archivo de salida deber  contener el n£mero  de  escaleras  que  se
pueden construir de longitud n.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de entrada³ ³ Ejemplo de salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4                 ³ ³ 8                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}

