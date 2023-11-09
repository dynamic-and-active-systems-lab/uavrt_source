//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// channelreceiver.h
//
// Code generation for function 'channelreceiver'
//

#ifndef CHANNELRECEIVER_H
#define CHANNELRECEIVER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void channelreceiver(double localIPPort, bool resetUDP,
                     coder::array<creal32_T, 2U> &dataReceived);

void channelreceiver_free();

void channelreceiver_init();

#endif
// End of code generation (channelreceiver.h)
