#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error_defined = false;
    i_error = 0;
}

void PID::UpdateError(double cte) {
    if (!p_error_defined)
        p_error = cte;
    d_error = cte - p_error;
    i_error = i_error + cte;
    p_error = cte;
    p_error_defined = true;
}

double PID::TotalError() {
    return Kp*p_error + Ki * i_error + Kd* d_error;
}

