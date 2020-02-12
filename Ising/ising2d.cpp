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
//Constants of size and interaction constant
const int Nx=100;
const int Ny=100;
const int N=100;
const double J=1.;
//We create a matrix
typedef std::vector<std::vector<double> > matrix;
//Definition of functions
void get_mem(matrix & m);
void print(matrix & m);
void Time_Step(matrix & m, double kbT,double h);
//Main function
int main(int argc, char *argv[]){
  srand(1); //seed 

  matrix ising; //Creation of the matrix
 
  get_mem(ising); //Initial conditions, randomly

  int Number=Nx*Ny;
  double kbT=atof(argv[1])/100;
  double h=atof(argv[2])/100;
  //Monte Carlo stabilization
  for (int t=0;t<N*Number;t++){
    Time_Step(ising,kbT,h);
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

void print(matrix & m){
 for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      std::cout<<m[i][j]<<' ';
    }
    std::cout<<std::endl;
  }
}

void Time_Step(matrix & m,double kbT,double h){

  double x=rand()%Nx;  double y=rand()%Ny;
  int xp,xl,yp,yl;
  double E,Eold,Enew,dE,r;
  xp=x+1;xl=x-1; yp=y+1;yl=y-1;
  if(x==0){xl=Nx-1;}
  if(x==Nx-1){xp=0;}
  if(y==0){yl=Ny-1;}
  if(y==Ny-1){yp=0;}
  E=-J*(m[xl][y]+m[xp][y]+m[x][yl]+m[x][yp])+h;
  
  Eold=m[x][y]*E;
  Enew=-m[x][y]*E;
  
  dE=Enew-Eold;
  if(dE<0){
    m[x][y]=-m[x][y];
  }else{
    r=drand48();
    if(r<exp(-dE/kbT)){
      m[x][y]=-m[x][y];
    }
  }
}


