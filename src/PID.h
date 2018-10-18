#ifndef PID_H
#define PID_H
#include <vector>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double prev_cte;

  /**
   * Error counters
  **/
  long counter;
  double errorSum;
  double minError;
  double maxError;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  /*
  * Twiddle variables
  */
  std::vector<double> dp;
  int param;
  double totalError;
  double bestError;
  bool twiddle;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, bool twiddle);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
