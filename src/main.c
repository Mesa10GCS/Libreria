
#include "stmduino.h"
#define LED 3
#define PUL 8
int main(void){
    pinMode(LED, 'o');
    pinMode(PUL, 'd');
    while(1){
        if(digitalRead(PUL)) digitalWrite(LED, 1);
        else digitalWrite(LED, 0);
    }
    return 0;
}

