#include "pch.h"
#include "Process.h"
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {//* burdaki temp, form1.h da sample olarak donuyor
	float* temp;
	temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)//* fill temp with pervious data 
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)//* fill the last two data(x1, x2) to the last of array
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data

float* Add_Labels(float* Labels, int Size, int label) {//* her class icin bir etiket veriyor
	float* temp;
	temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}

int YPoint(int x, float* w, int Carpan) {// w0x0 + w1x1 + w2b = + => x2 = ( -w2b - w0x0 ) / x1
	return (int)((float)(-1 * (float)Carpan * w[2] - 1 * (w[0] * x)) / (float)(w[1]));
}

float sigmoid(float net) {
	return (1.0 / (1.0 + pow(euler, -net)));
}



float sigmoid_bipolar(float net) {
	return ((2 / (1 + pow(euler, -net))) - 1);
}
