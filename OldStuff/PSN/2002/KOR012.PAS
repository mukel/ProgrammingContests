{koder: A^2P}
{PSN 2002 #12 "Spiral"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout     : text;
  N,j,k        : real;
  i,X,Y        : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,X,Y);
  read(fin,N);

  {solve}
  while i < N do
  begin inc(i); N := N - i; end;{while}
  case i and 3 of
    0: begin j := -i div 2 ; k := i div 2 - N; end;
    1: begin j := N - i div 2; k := -(i+1) div 2; end;
    2: begin j := i div 2 + 1; k := N - (i+1) div 2; end;
    3: begin j := (i+1) div 2 - N; k := (i+1) div 2; end;
  end;{case}

  {dprint}
  writeln(fout,X + j:0:0,' ',Y + k:0:0);

  {fclose}
  close(fin); close(fout);
end.{main}

{
12� Una espiral cuadrada                                    Korea 2002
����������������������������������������������������������������������

En  una grilla cuadrada de dimensi�n NxN se quiere colocar una espiral
cuadrada cuya longitud es M y parte de un punto P llamado origen, con
coordenadas  enteras positivas. La espiral es colocada cumpliendo las
propiedades siguientes:

-  Dos  lados  consecutivos  tienen  una diferencia de longitud de una
  unidad y el primer lado tiene longitud 1.
- El �ltimo lado puede tener cualquier longitud.
- La espiral siempre comienza hacia el norte.
- La espiral avanza en el sentido de las manecillas del reloj.
-  La  espiral  siempre queda dentro de la grilla, garantizando que la
  misma siempre se podr� colocar dentro de la grilla.
- La espiral puede pasar por cualquiera de los bordes de la grilla.

Tarea

Escribir  un  programa  que  dada las coordenadas (columna y fila) del
punto  P  y  la  longitud  M de la espiral cuadrada encuentre el punto
donde termina la espiral.

Entrada

La  Entrada se realizar� por un fichero texto llamado SPIRAL.IN con la
siguiente estructura:
*  Primera l�nea: dos n�meros  enteros  positivos  separados   por  un
   espacio en blanco, los que representan la columna  y  la  fila  del
   punto origen P.

*  Segunda  l�nea:  un  n�mero  entero  positivo  M, que representa la
   longitud de la espiral.

Salida

La  salida  se realizar� hacia un fichero texto llamado SPIRAL.OUT con
una  �nica  l�nea  que contiene dos enteros positivos, la columna y la
fila del punto donde termina la espiral.

�����������Ŀ  ������������Ŀ
� SPIRAL.IN �  � SPIRAL.OUT �
�����������Ĵ  ������������Ĵ
� 100 100   �  � 100 95     �
� 49        �  ��������������
�������������

  0,0�����������������������������������Ŀ
     �  �  �  �  �  �  �  �  �  �  �  �  �      Restricciones:
     �����������������������������������Ĵ      10 <= N <= 1000000
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �         N
     �����������������������������������Ĵ         �
     �  �  �  �  �  �  �  �  �  �  �  �  �         �
    ���������������������������������������   O ������� E
     �  �  �  �  �  �  �  �  �  �  �  �  �         �
     �����������������������������������Ĵ         S
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �����������������������������������Ĵ
     �  �  �  �  �  �  �  �  �  �  �  �  �
     �������������������������������������
                                          1 mill�n, 1 mill�n
}
