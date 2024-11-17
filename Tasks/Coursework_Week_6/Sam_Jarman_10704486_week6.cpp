#include "mbed.h"
#include "uop_msb.h"

DigitalOut led(LED1); // LED for visual feedback

#define STACK_SIZE 4 // Size of the stack (4 elements)
int stack[STACK_SIZE]; // Stack array
int top = 0; // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        // Handle stack full case
        printf("error: stack is full\n");

    }
    // Push value onto stack and increment top
    stack[top] = value;
    top++;      
}

int pop() {
    if (top <= 0) {
        // Handle stack empty case
        printf("error: stack is full\n");
        return stack[top];
    }
    // Decrement top and return the value
    top--;      
    return stack[top];
}

void display_top() {
    if (top <= 0) {
        // Handle stack empty case
        printf("error: stack is full\n");
    }
    // Display the top value
    printf("%d\n", stack[top-1]);
}

int main() {
    push(88);				// Push first value
    push(99);				// Push second value

    display_top(); 	       // Display top value after pushing

    pop();			      // Pop the top value
    display_top(); 	      // Display new top value after popping

    while (1) {
        led = !led; // Blink LED
        wait_us(500000); // Wait half a second
    }
}
