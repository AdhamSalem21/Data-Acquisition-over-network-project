#include <avr/io.h>
#include <util/delay.h>
#include "lol.h"
#include <string.h>


#define BAUD 9600  // defining the communication baud rate.

int main(void){ //
  init();  //calling initialization function    
  DDRD = 0x00; //setting port B to input.
  while(1) // conitnous loop that keeps checking for its contents.
  {
   char buttonstatus [16]="Button pressed\n"; //creating an array of characters.
   
    int button = PINB; // creating a variable that contains the status of PINS in port B.
    if (button==1){.  //if the status of the pin is high.
      uart_transmit(buttonstatus,16); // uart trasnmit function send  the array buttonstatus to the pc's serial monitor.
      _delay_ms(1000); // a delay between each message is used to be able to monitor status easily.
    }
    char led= uart_recieve(); //creating a variable that stores the user input.
    if(led=='h'){ // if the user input is h
      DIO_SetPinDirection('b',3,'o'); // Setting port B pin 3 to output 
      DIO_SetPinState('b',3,'h');// Setting port B pin 3 to high
    }
    else if(led=='l'){ //if the user input is h
      DIO_SetPinDirection('b',3,'o');//Setting port B pin 3 to output
      DIO_SetPinState('b',3,'l');//Setting port B pin 3 to high
    }
  }
  }
    void init(){ // creating a function called init
      uart_init(BAUD); // calling uart init function to set baud rate
    }





