#include "stepper.h"

enum Step{LEFT,RIGHT};

extern unsigned char ucInversion;

void Stepper::Step(enum Step eStep){
	if(eStep == LEFT){
		Stepper::ucLedCtr--;
		Stepper::ucLedCtr = Stepper::ucLedCtr % 4;
		if(ucInversion == 1){
			Stepper::MyLedInv.On(Stepper::ucLedCtr);
		}else{
			Stepper::MyLed.On(Stepper::ucLedCtr);
		}
	}
	else if(eStep == RIGHT){
		Stepper::ucLedCtr++;
		Stepper::ucLedCtr = Stepper::ucLedCtr % 4;
		if(ucInversion == 1){
			Stepper::MyLedInv.On(Stepper::ucLedCtr);
		}else{
			Stepper::MyLed.On(Stepper::ucLedCtr);
		}
	}else{
	}
}

void Stepper::StepLeft(void){
	Stepper::Step(LEFT);
}


void Stepper::StepRight(void){
	Stepper::Step(RIGHT);
}


void Stepper::SetMode(unsigned char ucMode){
	Stepper::ucInversion = ucMode;
}

