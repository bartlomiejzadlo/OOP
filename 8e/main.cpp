#include "stepper.h"
#include "keyboard.h"
#include "led.h"
#include "ledinv.h"

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 10000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main(void)
{
	Stepper MyStepper;
	Keyboard MyKeyboard;
	Led MyLed;
	LedInv MyLedInv;
	
	if(MyKeyboard.eRead() == BUTTON_4){
		MyStepper.SetLed(&MyLedInv);
	}else{
		MyStepper.SetLed(&MyLed);
	}

	while(1){
		Delay(500);
		if(MyKeyboard.eRead() == BUTTON_1){
			MyStepper.StepRight();
		}else if(MyKeyboard.eRead() == BUTTON_2){
			MyStepper.StepLeft();
		}else{
		}
	}
}
