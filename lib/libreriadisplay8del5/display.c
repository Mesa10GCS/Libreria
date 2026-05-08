#include "display.h"
int an [10][7]={
        {1,1,1,1,1,1,0},
        {0,1,1,0,0,0,0},
        {1,1,0,1,1,0,1},
        {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1},
        {1,0,1,1,0,1,1},
        {1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1},
        {1,1,1,0,0,1,1}
        };
void d7s_init(int a, int b, int c, int d, int e, int f, int g){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int l[7]= {a, b, c, d, e, f, g};
for(int i=0; i<7; i++){
    if(l[i]<8){
        GPIOA -> CRL &=~(0xF<< (l[i]*4));
        GPIOA -> CRL |= (0x1 << (l[i] * 4));
    } else {
        GPIOA -> CRL &=~(0xF<< (l[i]%8)*4);
        GPIOA -> CRH |= (0x1 <<(l[i]%8)*4);
    }
}
}
void d7s(int num, int a, int b, int c, int d, int e, int f, int g){
    int l[7]= {a, b, c, d, e, f, g};

    for(int i=0; i<7; i++){
        if(an[num][i]) GPIOA -> BSRR |= (1<<l[i]);
          else GPIOA -> BSRR |= (1<<(l[i]+16));
    
}

}