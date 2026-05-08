#include "stmduino.h"
//para el puerto a
void pinMode(int pin, char io){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    //toupper(char) ; tolower(char)
    io = tolower(io);
    if(pin<8){
        GPIOA->CRL&=~(0xF<<pin*4);
        switch (io)
        {
        case 'f':
            GPIOA->CRL|=(0x4<<pin*4);
            break;
        case 'u':
            GPIOA->CRL|=(0x8<<(pin*4));
            GPIOA->BSRR|= (1<<pin);
            break;
        case 'd':
            GPIOA->CRL|=(0x8<<pin);
              GPIOA->BSRR|=(1<<(pin+16));
            break;
        case 'o':
            GPIOA->CRL|=(0x1<<(pin*4));
            break;
        
        default:
            break;
        }
    }

}
void digitalWrite(int pin, bool estado){
    if(estado) GPIOA->BSRR|=(1<<pin);
    else GPIOA->BSRR|=(1<<(pin+16));
}
int digitalRead(int pin){
    bool estPin = GPIOA->IDR & (1<<pin);
    return estPin;
}



