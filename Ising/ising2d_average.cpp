/*
Jose Mauricio Sevilla Moreno
02.2020
This code uses the Metropolos algorithm to
simulate the ising model at a given 
temperature and external magnetic field.
going 100 times on average on each site
*/
//Libraries included
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>
#include <random>
#include<ctime>
//Constants of size and interaction constant
const int Nx=100;
const int Ny=100;
const int N=200;
const double J=1.;

//We create a matrix
typedef std::vector<std::vector<int> > matrix;
//Definition of functions
void get_mem(matrix & m);
void print(const matrix & m);
void Step(matrix & m, double kbT,double h);
//Main function
int main(int argc, char *argv[]){

  srand(time(NULL)+(unsigned int) atoi(argv[3]));
  srand48(time(NULL)+(unsigned int) atoi(argv[3]));
  
  matrix ising; //Creation of the matrix
 
  get_mem(ising); //Initial conditions, randomly

  int Number=Nx*Ny;
  double kbT=atof(argv[1])/100;
  double h=atof(argv[2])/100;
  //Monte Carlo stabilization
  for (int t=0;t<N*Number;t++){
    Step(ising,kbT,h);
    if(t==((int) N*Number/4)){h=0.0;}
  }
  //Print the final matrix
  print(ising);
  return 0;
}

void get_mem(matrix & m){
  m.resize(Nx);
  for(int i=0;i<Nx;i++){
    m[i].resize(Ny);
    for(int j=0;j<Ny;j++){
      m[i][j]=2*(rand() % 2)-1;
    }
  }
}

void print(const matrix & m){
 for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      std::cout<<m[i][j]<<' ';
    }
    std::cout<<std::endl;
  }
}

void Step(matrix & m,double kbT,double h){
  //Auxiliar variables
  double x=rand()%Nx;  double y=rand()%Ny;
  int xp,xl,yp,yl;
  double E,Eold,Enew,dE,r;
  //Neighbors calculation and
  //periodic Boundary conditions applied
  xp=x+1;xl=x-1; yp=y+1;yl=y-1;
  if(x==0){xl=Nx-1;}
  if(x==Nx-1){xp=0;}
  if(y==0){yl=Ny-1;}
  if(y==Ny-1){yp=0;}
  //Calculation of the Energy
  E=-J*(m[xl][y]+m[xp][y]+m[x][yl]+m[x][yp])+h;

  Eold=m[x][y]*E;
  Enew=-m[x][y]*E;

  dE=Enew-Eold;
  //Metropolis acceptance 
  if(dE<0){
    m[x][y]=-m[x][y];
  }else{
    r=drand48();
    if(r<exp(-dE/kbT)){
      m[x][y]=-m[x][y];
    }
  }
}
 
