#include "stepper.h"

enum Step{LEFT,RIGHT};

void Stepper::Step(enum Step eStep){
	if(eStep == LEFT){
		Stepper::ucLedCtr--;
		Stepper::ucLedCtr = Stepper::ucLedCtr % 4;
		Stepper::MyLed.On(Stepper::ucLedCtr);
	}
	else if(eStep == RIGHT){
		Stepper::ucLedCtr++;
		Stepper::ucLedCtr = Stepper::ucLedCtr % 4;
		Stepper::MyLed.On(Stepper::ucLedCtr);
	}else{
	}
}

void Stepper::StepLeft(void){
	Stepper::Step(LEFT);
}


void Stepper::StepRight(void){
	Stepper::Step(RIGHT);
}


Stepper::Stepper(unsigned char ucLedStart){
		Stepper::ucLedCtr = ucLedStart;
		Stepper::MyLed.On(Stepper::ucLedCtr);
};
