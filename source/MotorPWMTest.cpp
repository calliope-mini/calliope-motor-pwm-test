/**
 * Calliope Motor + PWM Test.
 *
 * @copyright (c) Calliope gGmbH.
 *
 * Licensed under the Apache Software License 2.0 (ASL 2.0)
 *
 * @author Matthias L. Jugel <leo@calliope.cc>
 */


#include <MicroBit.h>

MicroBit uBit;

void onButtonA(MicroBitEvent event) {
    (void) event;

    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(100);
    uBit.io.P12.setAnalogValue(1023);
    uBit.sleep(100);
    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(100);
    if(uBit.io.P12.setServoPulseUs(80) == MICROBIT_OK) uBit.display.print("+"); else uBit.display.print("-");
    uBit.sleep(100);

    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(50);
    uBit.io.P12.setAnalogValue(1023);
    uBit.sleep(50);
    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(50);

    uBit.soundmotor.motorOn(100);
    uBit.soundmotor.motorCoast();
    uBit.sleep(200);

    NRF_TIMER2->SHORTS = TIMER_SHORTS_COMPARE3_CLEAR_Msk;
    NRF_TIMER2->INTENCLR = TIMER_INTENCLR_COMPARE3_Msk;
    NRF_TIMER2->PRESCALER = 4;
    NRF_TIMER2->CC[3] = 20000;
    NRF_TIMER2->TASKS_START = 1;
    NRF_TIMER2->EVENTS_COMPARE[3] = 0;

    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(50);
    uBit.io.P12.setAnalogValue(1023);
    uBit.sleep(50);
    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(50);

    if(uBit.io.P12.setServoPulseUs(80) == MICROBIT_OK) uBit.display.print("!"); else uBit.display.print("/");
    uBit.sleep(100);

    uBit.soundmotor.motorOn(100);
    uBit.soundmotor.motorCoast();
    uBit.sleep(200);

    NRF_TIMER2->SHORTS = TIMER_SHORTS_COMPARE3_CLEAR_Msk;
    NRF_TIMER2->INTENCLR = TIMER_INTENCLR_COMPARE3_Msk;
    NRF_TIMER2->PRESCALER = 4;
    NRF_TIMER2->CC[3] = 20000;
    NRF_TIMER2->TASKS_START = 1;
    NRF_TIMER2->EVENTS_COMPARE[3] = 0;

    uBit.io.P12.getAnalogValue();
    if(uBit.io.P12.setServoPulseUs(80) == MICROBIT_OK) uBit.display.print("!"); else uBit.display.print("/");
    uBit.sleep(100);

    uBit.io.P12.setAnalogValue(0);
    uBit.sleep(100);
    uBit.io.P12.setAnalogValue(1023);
    uBit.sleep(100);
    uBit.io.P12.setAnalogValue(0);

    uBit.display.print("X");
}


int main() {
    uBit.init();
    uBit.serial.baud(115200);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);

    uBit.display.print("!");
    while (true) uBit.sleep(100);
}