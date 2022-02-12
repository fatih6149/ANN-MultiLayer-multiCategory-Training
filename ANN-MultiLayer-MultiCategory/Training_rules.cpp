#include "Training_rules.h"
#include <cmath>
#include "pch.h"
#include <math.h>
#include "Process.h"

float delta_train(float* Sample, int numSample, float* weights, int bias, float* target, int numClass, int inputDim, int numHideneur, float* Vweights) {

	float* NetK = new float[numClass];
	float* NetJ = new float[numHideneur];
	float* output = new float[numClass];
	float* Voutput = new float[numHideneur];
	float* f_turev = new float[numClass];
	float* V_f_turev = new float[numHideneur];
	float* desired_output = new float[numClass];
	float Error = 0.0;
	float learning_rate = 0.1;

	//================== variables for debug==========================
	float tmp_netJ, tmp_netK, tmp_output, tmp_V_output, tmp_f_turev, tmp_V_f_turev, tmp_weight, tmp_sample;
	//================================================================


	for (int step = 0; step < numSample; step++) {

		//================================== Forward propagation ==============================

		for (int j = 0; j < numHideneur; j++)
			NetJ[j] = 0.0;

		for (int k = 0; k < numClass; k++)
			NetK[k] = 0.0;

		for (int j = 0; j < numHideneur; j++) {
			for (int i = 0; i < inputDim; i++) {
				NetJ[j] += Vweights[j * (inputDim + 1) + i] * Sample[step * inputDim + i];
				tmp_weight = Vweights[j * (inputDim + 1) + i];
				tmp_sample = Sample[step * inputDim + i];
				tmp_netJ = NetJ[j];
			}
			NetJ[j] += Vweights[j * (inputDim + 1) + inputDim] * bias;
			tmp_netJ = NetJ[j];
		}

		for (int j = 0; j < numHideneur; j++) {
			//Voutput[j] = sigmoid(NetJ[j]);
			//V_f_turev[j] = Voutput[j] * (1 - Voutput[j]);
			Voutput[j] = sigmoid_bipolar(NetJ[j]);
			V_f_turev[j] = 0.5 * (1 - (pow(Voutput[j], 2)));
			tmp_V_output = Voutput[j];
			tmp_V_f_turev = V_f_turev[j];

		}

		for (int k = 0; k < numClass; k++) {
			for (int i = 0; i < numHideneur; i++) {
				NetK[k] += weights[k * (numHideneur + 1) + i] * Voutput[i];
				tmp_weight = weights[k * (numHideneur + 1) + i];
				tmp_sample = Voutput[i];
				tmp_netK = NetK[k];
			}
			NetK[k] += weights[k * (numHideneur + 1) + numHideneur] * bias;
			tmp_weight = weights[k * (numHideneur + 1) + numHideneur];
			tmp_netK = NetK[k];
		}

		for (int k = 0; k < numClass; k++) {
			//output[k]= sigmoid(NetK[k]);
			//f_turev[k] = output[k] * (1 - output[k]);
			output[k] = sigmoid_bipolar(NetK[k]);
			f_turev[k] = 0.5 * (1 - (pow(output[k], 2)));
			tmp_output = output[k];
			tmp_f_turev = f_turev[k];
		}

		for (int k = 0; k < numClass; k++) {
			if (k == target[step])
				desired_output[k] = 1.0;
			else
				desired_output[k] = -1.0;
		}

		float temp_error = 0.0;
		for (int k = 0; k < numClass; k++)
			temp_error += 0.5 * pow((desired_output[k] - output[k]), 2);

		Error += temp_error;

		//=====================================================================================


		//=================================== Back propagation ================================

		float LR, DO, OU, f_tur, Vout;
		//update output weights
		for (int k = 0; k < numClass; k++) {
			for (int j = 0; j < numHideneur; j++) {
				weights[k * (numHideneur + 1) + j] += learning_rate * (desired_output[k] - output[k]) * f_turev[k] * Voutput[j];//ilk hata  yerine NetJ[j] kullanilmis 
				LR = learning_rate;
				DO = desired_output[k];
				OU = output[k];
				f_tur = f_turev[k];
				Vout = Voutput[j];
				tmp_weight = weights[k * (numHideneur + 1) + j];
			}
			weights[k * (numHideneur + 1) + numHideneur] += learning_rate * (desired_output[k] - output[k]) * f_turev[k] * bias;
			LR = learning_rate;
			DO = desired_output[k];
			OU = output[k];
			f_tur = f_turev[k];
			tmp_weight = weights[k * (numHideneur + 1) + numHideneur];
		}

		float tmp_val, desout, out, f_ture, tmp_weight;
		//compute the value that come from output layer
		float* val = new float[numHideneur];
		for (int i = 0; i < numHideneur; i++)
			val[i] = 0.0;
		for (int j = 0; j < numHideneur; j++) {
			for (int k = 0; k < numClass; k++) {
				val[j] += (desired_output[k] - output[k]) * f_turev[k] * weights[k * (numHideneur + 1) + j];
				desout = desired_output[k];
				out = output[k];
				f_ture = f_turev[k];
				tmp_weight = weights[k * (numHideneur + 1) + j];
				tmp_val = val[j];
			}
		}

		float V_f_tur, smp, value, v_weight;
		//update input weights
		for (int j = 0; j < numHideneur; j++) {// j means the raw of Vweights
			for (int i = 0; i < inputDim; i++) {// i means the colums of Vweights
				Vweights[j * (inputDim + 1) + i] += learning_rate * V_f_turev[j] * Sample[step * inputDim + i] * val[j];
				V_f_tur = V_f_turev[j];
				smp = Sample[step * inputDim + i];
				value = val[j];
				v_weight = Vweights[j * (inputDim + 1) + i];
			}
			Vweights[j * (inputDim + 1) + inputDim] += learning_rate * V_f_turev[j] * bias * val[j];
			v_weight = Vweights[j * (inputDim + 1) + inputDim];
		}
	}

	return Error;
}