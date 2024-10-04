#include "mbed.h"

// structure typedef
typedef struct {
    double real;
    double imag;
} COMPLEX;

// function declaration
COMPLEX complexAbs (COMPLEX c);

int main()
{

    // enter, call function and display the absulute value of the imaginary number entered 
    COMPLEX cval1 = {-12.0, 2.5};
    COMPLEX result = complexAbs(cval1);
    printf("\nAbsulute value is %f\n\n" , result.real+result.imag);


    // loop to repeatedly ask to enter a binary number 
    while (true)
    {
        // convert binary to decimal and then %X to convert to hex
        long int binary, hex = 0, i = 1, remainder;
        printf("Enter the binary number: \n");
        scanf("%ld", &binary);
        while (binary != 0)
        {
            remainder = binary % 10;
            hex = hex + remainder * i;
            i = i * 2;
            binary = binary / 10;
        }
    
        printf("Equivalent hexadecimal value: %lX\n", hex);
    }
}

// function to calculate the absulute value
COMPLEX complexAbs(COMPLEX c)
{
    COMPLEX result = c;
    result.real = (c.real*c.real);
    result.imag = (c.imag*c.imag);
    return result; 
}



