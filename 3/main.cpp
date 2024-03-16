#include "led.h"
#include "stepper.h"

Led MyLed;

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 10000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

int main(void)
{
	Stepper MyStepper;
	MyLed.Init();

	while(1){
		Delay(100);
		MyStepper.StepLeft();
	}
}
