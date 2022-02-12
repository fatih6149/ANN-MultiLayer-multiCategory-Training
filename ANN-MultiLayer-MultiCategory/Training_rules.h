#pragma once
#include "Form1.h"
#include "Process.h"
#include <cmath>



float delta_train(float* Sample, int numSample, float* weights, int bias, float* target, int numClass, int inputDim, int numHideneur, float* Vweights);
