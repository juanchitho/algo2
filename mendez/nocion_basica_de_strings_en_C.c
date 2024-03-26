#include <stdio.h>
//declaro un array de 100 bytes
char mi_texto[100];

//Asigno caracteres a cada posición
//Notar que es posible usar la sintaxis de caracter con las comillas simples, tanto
//como utilizar los números directamente (aunque siempre que se pueda se recomienda
//utilizar la notación de caracteres, para que sea mas claro)
mi_texto[0] = 'H';
mi_texto[1] = 'o';
mi_texto[2] = 'l';
mi_texto[3] = 97; //97 es 'a'

//Hasta este punto, mi_texto no puede ser considerado un string, y no debe ser
//pasado a funciones que esperan un string, ya que no posee el 0 al final,
//y por lo tanto no es posible conocer dónde finaliza dicho string

//La siguiente operación es indefinida, y seguramente cause problemas de memoria
//ya que %s espera un string para mostrar por pantalla, pero mi_texto no lo es.
printf("%s", mi_texto);

mi_texto[4] = 0;
//A partir de este momento, mi_texto puede ser considerado un string.

//Esta otra sintáxis para definir strings utiliza punteros (no es tema de este repaso).
//Define un string otro_texto con el contenido "Hola". En este caso no es necesario
//poner el 0 explícitamente, ya que el compilador lo pone automáticamente.
//Como contrapartida, este string es estático, se encuentra en una zona de sólo
//lectura y no debe ser modificado (a menos que se quiera tener errores de memoria)
char* otro_texto = "Hola";
