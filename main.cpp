//===================================================================
//                    Librairies & Project Files
//===================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "population.h"
#include "prey.h"
#include "predator.h"
#include "bwindow.h"
#include "agent.h"

//===================================================================
//                 Declare Miscelaneous Functions
//===================================================================

//===================================================================
//                            Main
//===================================================================
int main()
{
  printf("Hello world!!\n");
//-------------------------------------------------------------------
//Création d'une population
  population Boids=population();
  //Real methods
  /*Boids.define();
  Boids.create();*/

  //Only to tests
  Boids.Set_W(600);
  Boids.Set_H(600);
  Boids.Set_size(2);
  printf("Size= %d, field=%.2f*%.2f\n", Boids.Get_size(), Boids.Get_W(), Boids.Get_H());
//-------------------------------------------------------------------  
//Print data
  Boids.create();
  Boids.alignment(); 

Boids.print(1000000);

  return 0;
} 


//===================================================================
//                  Define Miscelaneous Functions
//===================================================================