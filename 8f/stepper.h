#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper{
	public:
		void StepLeft(void);
		void StepRight(void);
		void SetLed(Led *);
	private:
		unsigned char ucLedCtr;
		void Step(enum Step);
		Led *pMyLed;

};

#endif
