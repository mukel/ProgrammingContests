{koder: A^2P}
{PSN 1999 #94 "Dos m quinas"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,k         : word;
  s,min           : array[1..2] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  min[1] := 1 shl 30; min[2] := 1 shl 30;
  for i:=1 to N do
  begin
    readln(fin,j,k);
    inc(s[1],j); if j < min[1] then min[1] := j;
    inc(s[2],k); if k < min[2] then min[2] := k;
  end;{for}

  {dprint}
  if (s[1] > s[2]) or ((s[1] = s[2]) and (min[1] < min[2]))
    then write(fout,s[1] + min[2])
      else write(fout,s[2] + min[1]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
 94þ Dos m quinas 																				Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 En la comarca de Su Majestad exist¡a un taller donde hab¡an dos
 m quinas A y B. Con estas m quinas se realizaban diferentes trabajos.
 Un trabajo pasaba por la m quina B si y solo si ya hab¡a pasado por
 la A. Los trabajos ten¡an diferentes tiempos de procesamiento en cada
 una de las m quinas.

 A continuaci¢n le mostramos un ejemplo en que el taller de la comarca
 realiza cinco trabajos en una cantidad m¡nima de tiempo.

 Dado los tiempos de procesamiento de los trabajos en las m quinas A
 y B :

			 No. del				Tiempo de demora		Tiempo de demora
			 trabajo. 			de A. 							de B.

			 1							5 									2
			 2							1 									6
			 3							9 									7
			 4							3 									8
			 5							10									4

 el funcionamiento del taller es como sigue :

										M quina A 					 M quina B
										Tiempo de 					 Tiempo de
	 Trabajo			Entrada 	Salida		 Entrada	 Salida
		 2						 0				 1					1 				7
		 4						 1				 4					7 			 15
		 3						 4				13				 15 			 22
		 5						13				23				 23 			 27
		 1						23				28				 28 			 30

	 ( Tiempo de demora 30 seg.)

 Haga un programa que dado los tiempos de demora de los trabajos en
 cada m quina minimize el tiempo de procesamiento de todos los
 trabajos.

 Fichero de Entrada.

 En la primera l¡nea aparecer  el n£mero N (0 < N <= 10000) de
 trabajos a procesar. Luego aparecer n N l¡neas con dos enteros cada
 una expresa el tiempo (en segundos ) de demora de cada trabajo
 para las m quinas A y B respectivamente.

 Fichero de Salida.

 Un n£mero entero que expresa el tiempo( en seg .) m¡nimo de
 procesamiento de los trabajos. Los trabajos empiezan en el segundo 0.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³³Fichero de salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 5								³³ 38 						 ³
 ³ 1 2							³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 2 4							³
 ³ 5 1							³
 ³ 7 10 						³
 ³ 1 20 						³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Nota : Los tiempos de demora de las m quinas no ser n mayores que
			 65000.
}