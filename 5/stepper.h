#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper : public Led{
	public:
		void StepLeft(void);
		void StepRight(void);
	private:
		unsigned char ucLedCtr;
		void Step(enum Step);
};

#endif
