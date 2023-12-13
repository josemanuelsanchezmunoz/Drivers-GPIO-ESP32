#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../Drivers/gpio.h"

#define SW1 18
const int RED_LED = 16;
const int BLUE_LED = 17;

void app_main(void)
{

	SET_PIN_MODE(SW1, INPUT_MODE);
	ENABLE_RES(SW1, PULLUP_RES);
	SET_PIN_MODE(RED_LED, OUTPUT_MODE);
	SET_PIN_MODE(BLUE_LED, OUTPUT_MODE);

    while (true) {

    	if(READ_PIN(SW1) != 1){
			while(READ_PIN(SW1) != 1);
			for(int i = 0; i < 10; i++){
				WRITE_PIN(RED_LED,HIGH);
				WRITE_PIN(BLUE_LED,LOW);
				usleep(250000);
				WRITE_PIN(RED_LED,LOW);
				WRITE_PIN(BLUE_LED,HIGH);
				usleep(250000);
			}
			WRITE_PIN(RED_LED,LOW);
			WRITE_PIN(BLUE_LED,LOW);
		}
    }
}
