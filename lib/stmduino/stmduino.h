#ifndef STMDUINO_H //pregunto si ya esta definida la lib
#define STMDUINO_H //la defino
//incluyo recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"
//definir funciones
/*valores de io
 'f': entrada flotante
 'u': entrada PullUp
 'd': entrada PullDown
 'o': salida push pull
*/

void pinMode(int pin, char io);
void digitalWrite(int pin, bool estado);
int digitalRead(int pin);


#endif



