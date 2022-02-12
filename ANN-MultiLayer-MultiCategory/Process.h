#pragma once

const double euler = 2.7182;

float* Add_Data(float* sample, int Size, float* x, int Dim);
float* Add_Labels(float* Labels, int Size, int label);

int YPoint(int x, float* w, int Carpan = 1);

float sigmoid(float net);

float sigmoid_bipolar(float net);