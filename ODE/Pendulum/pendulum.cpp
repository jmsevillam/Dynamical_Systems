#include <iostream>
#include <cstdlib>
#include <cmath>

const double omega_f=2./3.;
const double g=9.8;
const double l=9.8;
const double gamma0=0.5;
const double dt=0.001;
const double timesteps=10000;
const double q0=1;
const double p0=0.0;

void timestep(double & q, double & p, double& t, double F);
double dqdt(double q, double p, double t,double F);
double dpdt(double q, double p, double t, double F);

int main(int argc, char *argv[]) {
  double Force=atof(argv[1]);
  double dq0=atof(argv[3]);
  double q1=q0,p1=p0;
  double q2=q0+dq0,p2=p0;
  double t1=0.0;
  double t2=0.0;
  int N=atoi(argv[2]);
  for(int i=0; i<N;i++){
    std::cout<<t1<<' '<<q1<<' '<<p1<<' '<<q2<<' '<<p2<<std::endl;
    timestep(q1,p1,t1,Force);
    timestep(q2,p2,t2,Force);
  }
  return 0;
}

void timestep(double & q, double & p, double& t, double F){
    p+=dpdt(q,p,t,F)*dt;
    q+=dqdt(q,p,t,F)*dt;
    t=t+dt;
}

double dpdt(double q, double p, double t, double F_f){
    return -(g/l)*sin(q)-gamma0*dqdt(q,p,t,F_f)+F_f*sin(omega_f*t);
  }
double dqdt(double q, double p, double t, double F_f){
    return p;
  }