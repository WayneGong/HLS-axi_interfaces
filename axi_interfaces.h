#ifndef AXI_INTERFACES_H_
#define AXI_INTERFACES_H_
 
#include <stdio.h>

typedef int din_t;
typedef int dout_t;
typedef int dacc_t;

#define CHANNELS 8
#define SAMPLES  4
#define N CHANNELS * SAMPLES

void axi_interfaces (dout_t d_o[N], din_t d_i[N]);

#endif
