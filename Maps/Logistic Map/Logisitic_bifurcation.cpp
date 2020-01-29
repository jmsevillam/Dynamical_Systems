/*
Mauricio Sevilla. 2019.
Email: jmsevillam@unal.edu.co, jmasevillam@gmail.com
This code is used to build a bifurcation map of the logistic map.

It uses three parameters, the interval and the amount of points.

It only prints one point for each r after 100 iterations.
*/
//Importing libraries
#include <iostream>
#include <cstdio>
#include <random>
//Function Declaration
double logistic(double x, double r);
//Main function
int main(int argc,char* argv[]){
  //Saving the external paramters
  double initial =atof(argv[1]);
  double final=atof(argv[2]);
  int Number=atoi(argv[3]);
  //Random number device definition
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(initial, final);
  std::uniform_real_distribution<> dis2(0, 1);
  //Variable definitions
  double R,x;
  //constructing the data
  for(int i = 0; i<Number;i++){
    //initial conditions
    R=dis(gen);
    x=dis2(gen);
    //evolution on the map
    for(int i = 0; i<100;i++){
      x=logistic(x,R);
    }
    //printing results
    std::cout<<R<<"\t"<<x<<std::endl;
  }
  return 0;
}
//Function Implementation
double logistic(double x, double r){
  return r*x*(1-x);
}
