#include "PID.h"
#include <algorithm>
#include <iostream>

// using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, bool twiddle) {
	PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    PID::twiddle = twiddle;
    p_error = d_error = i_error = 0.0;

    // Previous cte.
	prev_cte = 0.0;

	// Counters.
	counter = 0;
	errorSum = 0.0;
	minError = std::numeric_limits<double>::max();
	maxError = std::numeric_limits<double>::min();

	// Twiddle
	dp = {0.1*Kp,0.1*Kd,0.1*Ki};
	param = 0;
	bestError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {
	// Proportional error.
	p_error = cte;

	// Integral error.
	i_error += cte;

	// Diferential error.
	d_error = cte - prev_cte;
	prev_cte = cte;

	errorSum += cte;
	counter++;

}

double PID::TotalError() {
	return 0.0;
}