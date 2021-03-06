/*
    Copyright 2018 Devin Gund (https://dgund.com)
    https://github.com/dgund/BBBKit/

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include "GPIO.h"

namespace bbbkit {

class StepperMotor {

public:
    enum DIRECTION { CLOCKWISE, COUNTERCLOCKWISE };

private:
    // GPIO pin for stepping motor
    GPIO *gpioStep;
    // GPIO pin for setting motor direction
    GPIO *gpioDirection;
    // GPIO pin for sleeping motor
    GPIO *gpioSleep;

    StepperMotor::DIRECTION direction;
    int stepFactor;
    int stepsPerRevolution;
    float revolutionsPerMinute;
    bool isSleeping;
    // Delay between steps, in microseconds
    int stepDelayUS;

public:
    StepperMotor(GPIO::PIN pinStep, GPIO::PIN pinDirection, GPIO::PIN pinSleep,
                 StepperMotor::DIRECTION direction=StepperMotor::DIRECTION::CLOCKWISE,
                 int stepsPerRevolution=1000, float revolutionsPerMinute=60.0f, int stepFactor=1);
    virtual ~StepperMotor();
    
    // Getters and setters
    
    virtual StepperMotor::DIRECTION getDirection() { return this->direction; }
    virtual int setDirection(StepperMotor::DIRECTION direction);

    virtual int getStepFactor() { return this->stepFactor; }
    virtual int setStepFactor(int stepFactor);

    virtual int getStepsPerRevolution() { return this->stepsPerRevolution; }
    virtual int setStepsPerRevolution(int stepsPerRevolution);

    virtual float getRevolutionsPerMinute() { return this->revolutionsPerMinute; }
    virtual int setRevolutionsPerMinute(float revolutionsPerMinute);
    
    virtual bool getIsSleeping() { return this->isSleeping; }
    virtual int setIsSleeping(bool isSleeping);

    // Stepping

    virtual void step();
    virtual void step(int numberOfSteps);
    virtual void rotate(float degrees);

protected:
    virtual int updateStepDelay();
};

} /* namespace bbbkit */

#endif /* STEPPERMOTOR_H */

