#include "stm32h7xx.h"

void bad_delay(long time);
void set_GPIO(void);

int main(void)
{
  set_GPIO();
	while (1){
		uart4_sends("Works!\n");
		bad_delay(1000000);
	}
}

void set_GPIO(void){
	RCC -> AHB4ENR |= RCC_AHB4ENR_GPIOGEN;						// Enable GPIOs from PORTG
	GPIOG -> MODER &= ~GPIO_MODER_MODER0;						// !!! RESET VALUE IS NOT 0 AUTOMATICALLY !!!
	GPIOG -> MODER |= GPIO_MODER_MODER0_0;						// General output mode
	GPIOG -> OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;					// Highest speed mode
	GPIOG -> OTYPER &= ~GPIO_OTYPER_OT_0;						// Push-pull state (reset)
	GPIOG -> PUPDR &= ~GPIO_PUPDR_PUPDR0;						// No internal pull-up or pull-down resistors
}

void bad_delay(long time){
	long i = 0;
	while (i < time) i++;
}
