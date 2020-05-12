/**
 * print_samples.cpp
 * 
 * Print out to the terminal 3 samples from a normal distribution with
 * mean equal to the GPS position and IMU heading measurements and
 * standard deviation of 2 m for the x and y position and 0.05 radians
 * for the heading of the car. 
 *
 * Author: Olaoluwa Popoola
 */

#include <iostream>
#include <math.h>


/**
 * Prints samples of x, y and theta from a normal distribution
 * @param mu_x   GPS provided x position
 * @param mu_y   GPS provided y position
 * @param sigma_x   GPS provided yaw
 * @param sigma_y
 */
void mv_gaus_prob(double mu_x, double mu_y, double sigma_x, double sigma_y);


int main() {
  
  // Set GPS provided state of the car.
  double mu_x = 0.;
  double mu_y = 5.;
  double x = 2.;
  double y = 1.;
  
  // Sample from the GPS provided position.
  mv_gaus_prob(mu_x, mu_y, x, y);
  
  return 0;
}


void mv_gaus_prob(double mu_x, double mu_y, double x, double y) {
  //double mu_x, mu_y, sigma_x, sigma_y;  // Initialize variables
    double sigma_x = 0.3;
    double sigma_y = 0.3;
  // compute power term
  double pwr_term = ((x-mu_x)*(x-mu_x))/(2*sigma_x*sigma_x)+((y-mu_y)*(y-mu_y))/(2*sigma_y*sigma_y);
  //compute probability
  double prob_xy = (1./(2.*M_PI*sigma_x*sigma_y))*std::exp(-1*pwr_term);

     
    // Print probability to the terminal.
    std::cout << "Probability of xy is: " << prob_xy<< std::endl;
  return;
}