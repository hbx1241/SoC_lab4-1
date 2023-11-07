#include "fir.h"

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
	
	int i;
	for(i=0;i<11;i++)
	{
		inputbuffer[i] = inputsignal[i];
		outputsignal[i] = 0;
	}
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
	//write down your fir
	
	int i,j,counter;
	counter = 1;
	for(i=0;i<11;i++)
	{
		for(j=0;j<counter;j++)
		{
			outputsignal[i] += taps[j]*inputbuffer[counter-j-1];
		}
		counter += 1;
	}
	
	
	return outputsignal;
}
		
