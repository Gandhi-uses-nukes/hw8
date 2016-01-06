#include <iostream>
#include <fstream>
#include <cmath>
//---------------------------------------
using namespace std;
//---------------------------------------
int main(){

  const double tEnd = 20*M_PI;
  const double dt = 0.0005;
  double e = 0.4; // eccentricity of the ellipse

  double q_1 = 1-e;
  double q_2 = 0;
  double p_1 = 0;
  double p_2 = sqrt( (1+e)/(1-e) );

	double tmp_q_1 = 0;
	double tmp_q_2 = 0;
	double tmp_p_1 = 0;
	double tmp_p_2 = 0;

	ofstream out("daten.txt");
  for(double t=0; t<=tEnd; t+=dt)
  {
  	tmp_p_1 = p_1 - dt*( 1.0/( 2.0*pow(q_1+q_2,3.0/2.0) ) );
  	tmp_p_2 = p_2 - dt*( 1.0/( 2.0*pow(q_1+q_2,3.0/2.0) ) );
  	
  	tmp_q_1 = q_1 + dt*( tmp_p_1 );
  	tmp_q_2 = q_2 + dt*( tmp_p_2 );
  	
  	out << tmp_p_1 << "\t" << tmp_p_2 << "\t" << tmp_q_1 << "\t" << tmp_q_2 << "\t" << dt << endl;
  	
  	p_1 = tmp_p_1;
  	p_2 = tmp_p_2;
  	q_1 = tmp_q_1;
  	q_2 = tmp_q_2;
  }
  out.close();

  return 0;
}

