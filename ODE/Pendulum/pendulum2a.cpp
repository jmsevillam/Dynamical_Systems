#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

const double omega_f=2./3.;
const double g=9.8;
const double l=9.8;
const double dt=3*M_PI*0.01;
const  double gamma0=0.5;

void timestep(double & q, double & p, double& t, double F);
double dqdt(double q, double p, double t,double F);
double dpdt(double q, double p, double t, double F);

int main(int argc, char *argv[]) {
  double Force,q1,p1,t1;
  int N=atoi(argv[2]);
  int M=atoi(argv[3]);
  std::uniform_real_distribution<double> unif(-M_PI,M_PI);
  std::uniform_real_distribution<double> unif2(1.,1.5);
  
  std::default_random_engine re;
  
  for(int i=0; i<M;i++){
    q1=unif(re);
    p1=0;
    t1=0;
    Force=unif2(re);
    for(int j=0; j<N;j++){
      timestep(q1,p1,t1,Force);
    }
      std::cout<<t1<<' '<<q1<<' '<<p1<<" "<<Force<<std::endl;
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
