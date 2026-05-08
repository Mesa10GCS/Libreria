#include "display.h"
#include "delay.h"
#define B0 7
int n=0;
int main(void){
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
GPIOB -> CRL&=~(0xF<<B0);
GPIOB -> CRL |= (0x8 << B0);
GPIOB -> BSRR |= (1 << (B0+16));
d7s_init( 0,  1,  2,  3, 4,  5,  6);
delay_init();
while(1){
     if(GPIOB -> IDR & (1<<B0)){
        n++;
        if(n>9)n=0;
        delay_ms(40);
     }

d7s( n,  0,  1,  2,  3,  4,  5,  6);
}
}
