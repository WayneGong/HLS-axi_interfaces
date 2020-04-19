
#include "axi_interfaces.h"

// The data comes in organized in a single array.
// - The first sample for the first channel (CHAN)
// - Then the first sample for the 2nd channel etc.
// The channels are accumulated independently
// E.g. For 8 channels:
// Array Order :  0  1  2  3  4  5  6  7  8     9     10    etc. 16       etc...
// Sample Order:  A0 B0 C0 D0 E0 F0 G0 H0 A1    B1    C2    etc. A2       etc...
// Output Order:  A0 B0 C0 D0 E0 F0 G0 H0 A0+A1 B0+B1 C0+C2 etc. A0+A1+A2 etc...

void axi_interfaces (dout_t d_o[N], din_t d_i[N]) {
	int i, rem;
	
	// Store accumulated data
	static dacc_t acc[CHANNELS];

	axi_interfaces_label0:for (i=0;i<CHANNELS;i++)	{
		acc[i]	=	0;
	}

	// Accumulate each channel
	For_Loop: for (i=0;i<N;i++) {
		rem=i%CHANNELS;
		acc[rem] = acc[rem] + d_i[i];
		d_o[i] = acc[rem];
	}

}
