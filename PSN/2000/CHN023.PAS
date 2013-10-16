{koder: A^2P}
{PSN 2000 #23 "Ordenes"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i             : byte;
  s               : string[30];
  freq            : array['a'..'z'] of byte;

    procedure comb(d: byte);
    var ch : char;
    begin
      for ch:='a' to 'z' do
        if freq[ch] > 0 then
          if d = N then
          begin
            s[N] := ch; writeln(fout,s);
          end{then ->}
          else begin
            dec(freq[ch]);
            s[d] := ch; comb(d+1);
            inc(freq[ch]);
          end;{else}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,s); N := byte(s[0]);
  for i:=1 to N do inc(freq[s[i]]);

  {solve}
  comb(1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
23Ý Ordenes                                                China 2000
----------------------------------------------------------------------

El  gerente  de  las tiendas ha ordenado todos los tipos de mercanc¡as
por  el orden alfab‚tico de sus etiquetas.  Se guardan todos los tipos
que  tienen  etiquetas  que  empiezan  con  la misma letra en el mismo
almac‚n  (es  decir  en  el mismo edificio)  etiqueteado, tambi‚n, con
esa  letra. Durante el d¡a el gerente de las tiendas recibe y registra
las  ¢rdenes  de mercanc¡as, de la tienda, que ser n entregadas . Cada
orden  requiere  s¢lo  un tipo de mercanc¡a. El gerente de las tiendas
procesa las demandas en el orden de su registro.

Usted  sabe,  de  antemano,  todos  las  ¢rdenes  que  tendr n que ser
procesadas  hoy  por  el gerente de las tiendas, pero usted no sabe el
orden  de  estas en el registro. Compute todas las posibles maneras de
las  visitas  a los almacenes para que el gerente de las tiendas pueda
establecer todas las demandas, una tr s otra, durante el d¡a.

Entrada:

El  archivo  de la entrada ORDERS.IN contiene una sola l¡nea con todas
las etiquetas de mercanc¡as pedidas (ordenadas al  azar). Cada tipo de
g‚nero  es  representado  por  la letra de comienzo de su etiqueta. Se
usan  s¢lo letras min£sculas del alfabeto ingl‚s. El n£mero de ¢rdenes
no excede a 200.

Salida:

El  archivo  de salida ORDERS.OUT contendr  todas las posibles maneras
en las que el gerente de las tiendas puede visitar sus almacenes. Cada
almac‚n  es  representado  por  una  sola letra min£scula del alfabeto
ingl‚s  -la  letra  de  comienzo  de la etiqueta de la mercanc¡a. Cada
manera  de visitar los almacenes s¢lo se escribe una vez en el archivo
de salida en una l¡nea separada y todas las l¡neas que contienen estas
secuencias de visitas tienen que ser ordenadas alfab‚ticamente (vea el
ejemplo). Ninguna salida exceder  2 megabytes.

Ejemplo:
  +---------+ +----------+
  ÝORDERS.INÝ ÝORDERS.OUTÝ
  +---------Ý +----------Ý
  Ýbbjd     Ý Ýbbdj      Ý
  +---------+ Ýbbjd      Ý
              Ýbdbj      Ý
              Ýbdjb      Ý
              Ýbjbd      Ý
              Ýbjdb      Ý
              Ýdbbj      Ý
              Ýdbjb      Ý
              Ýdjbb      Ý
              Ýjbbd      Ý
              Ýjbdb      Ý
              Ýjdbb      Ý
              +----------+
}
