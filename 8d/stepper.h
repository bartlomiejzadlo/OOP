#ifndef STEPPER_H
#define STEPPER_H

#include "ledinv.h"

class Stepper{
	public:
		void StepLeft(void);
		void StepRight(void);
		void SetMode(unsigned char);
	private:
		unsigned char ucLedCtr;
		void Step(enum Step);
		Led MyLed;
		LedInv MyLedInv;
		unsigned char ucInversion;
};

#endif
