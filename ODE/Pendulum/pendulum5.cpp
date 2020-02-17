#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

//const double omega_f=2./3.;
const double g=9.8;
const double l=9.8;

void timestep(double & q, double & p, double& t, double F, double,double,double);
double dqdt(double q, double p, double t, double F, double,double);
double dpdt(double q, double p, double t, double F, double,double);

int main(int argc, char *argv[]) {
  double Force=1.,q1,p1,t1;
  int N=atoi(argv[2]);
  int M=atoi(argv[3]);
  double gamma=0.5;
  double omega;
  double dt;
  std::uniform_real_distribution<double> unif(-M_PI,M_PI);
  std::uniform_real_distribution<double> unif2(0,1);
  
  std::default_random_engine re;
  
  for(int i=0; i<M;i++){
    q1=unif(re);
    p1=0;
    t1=0;
    omega=unif2(re);
    dt=2.*M_PI*0.01/omega;
    for(int j=0; j<N;j++){
      timestep(q1,p1,t1,Force,gamma,omega,dt);
    }
      std::cout<<t1<<' '<<q1<<' '<<p1<<" "<<omega<<std::endl;
  }
  return 0;
}
void timestep(double & q, double & p, double& t, double F,double gamma,double omega,double dt){
  p+=dpdt(q,p,t,F,gamma,omega)*dt;
  q+=dqdt(q,p,t,F,gamma,omega)*dt;
  t=t+dt;
}
double dpdt(double q, double p, double t, double F_f,double gamma0,double omega_f){
  return -(g/l)*sin(q)-gamma0*dqdt(q,p,t,F_f,gamma0,omega_f)+F_f*sin(omega_f*t);
}
double dqdt(double q, double p, double t, double F_f,double gamma0,double omega){
  return p;
}
