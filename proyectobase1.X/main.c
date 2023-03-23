/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB® C30 v2.01 or higher

 Proyecto base en Lenguaje C.

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Sebastián Wahler  09/03/16  Initial Release
 Marcelo Gómez     10/03/19  Actualización (Se incorporó campo de bits)
 Sebastián Wahler  22/03/22  Entradas/Salidas Digitales
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include <p33FJ256GP710.h>

int a, b, var_temp;

typedef union {
    struct {
        unsigned int C:1;
        unsigned int Z:1;
        unsigned int OV:1;
        unsigned int N:1;
        unsigned int RA:1;
        unsigned int IPL:3;
        unsigned int DC:1;
        unsigned int DA:1;
        unsigned int SAB:1;
        unsigned int OAB:1;
        unsigned int SB:1;
        unsigned int SA:1;
        unsigned int OB:1;
        unsigned int OA:1;
    } bits;
    struct {
        unsigned int :5;
        unsigned int IPL1:1;
        unsigned int IPL2:1;
        unsigned int IPL3:1;
    }IPLbits;
    unsigned int completo;
} t_sr;
t_sr status_register;

void espera(int valor1, int valor2)
{
    int i,j,k;

    for(i = 0; i < valor1; ++i)
    {
        j = i;
    }

    for(i = 0; i < valor2; ++i)
    {
        k = i;
    }
}

int main(void) {

    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    int x, y;

    
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISB = 0;
    TRISB = 0b1011;
    
    TRISB = 0xFFF3;
    
    var_temp = PORTBbits.RB0;

    
    a = 10;
    b = 3;
    a -= b;
    status_register.completo = SR;
    var_temp = status_register.bits.C;
    var_temp = status_register.bits.IPL;
    a = status_register.IPLbits.IPL2;
    x = 200;
    y = 300;
    espera(x, y);
    x = 0;
    y = 3;
    espera(100, 400);
    b -= b;
    status_register.completo = SR;
    var_temp = status_register.bits.Z;
    var_temp = status_register.bits.N;

    while(1)
    {
        if(x < y)
            x = x + 1;
        else
            x = x - 1;
    }
    
    

}

