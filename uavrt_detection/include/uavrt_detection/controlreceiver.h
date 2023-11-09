//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// controlreceiver.h
//
// Code generation for function 'controlreceiver'
//

#ifndef CONTROLRECEIVER_H
#define CONTROLRECEIVER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void controlreceiver(double localIPPort,
                     coder::array<signed char, 2U> &dataReceived);

void controlreceiver_free();

void controlreceiver_init();

#endif
// End of code generation (controlreceiver.h)
