# Testing for Motor and PWM functionality

The motor driver and the PWM use the same timer. This leads to the
situation that after the motor driver was in use, some settings are
off and the PWM/Servo functionality does not work anymore.

This is a little test to identify ways to overcome the issue and
how to fix this.

## Hotfix

- re-initialize the timer settings as in the interrupt handler in
`pwmout_api.c`
- use `pin.getAnalogValue()` to force pin to re-initialize

(c) 2017 Calliope gGmbH

Licensed under the Apache Software License 2.0, see LICENSE.