#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper{
	public:
		void StepLeft(void);
		void StepRight(void);
		Stepper(unsigned char = 0);
	private:
		unsigned char ucLedCtr;
		void Step(enum Step);
		Led MyLed;
};

#endif
