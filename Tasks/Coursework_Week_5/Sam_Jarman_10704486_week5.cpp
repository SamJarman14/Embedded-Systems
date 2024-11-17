#include "mbed.h"

// Define pins
    // Temperature sensor input (PA_0) - potentiometer
    AnalogIn AIN(PA_0);
    // PWM output for LED (choose any pin)
    PwmOut led(LED1);

int main() {
           // Variables to store the temperature
           float temp;
           float tempDeg;
    
    while (true) {
        // Step 1: Read the analog input from the temperature sensor
        // Read analog value (0.0 to 1.0)
        temp = AIN.read();
        
        // Step 2: Convert the analog reading to temperature in degrees Celsius
        // Convert to temperature (0°C to 100°C)
        tempDeg = temp*100;


        // Scale brightness proportionally between 20°C and 40°C
        // Step 3: Adjust the brightness of the LED based on the temperature
        if (tempDeg <= 20.0){
            tempDeg = 0;
        }
        else if (tempDeg >= 40.0){
            tempDeg = 1;
        }
        else {
            tempDeg = (tempDeg-20)/20;
        }

        // Step 4: Set the PWM duty cycle to control LED brightness
        // Set LED brightness (0.0 = off, 1.0 = fully on)
        led.write(tempDeg);
            
    }
        // Step 5: Wait for the polling interval (100 ms)
        // 100 ms polling interval 
        wait_us(100000);    
}