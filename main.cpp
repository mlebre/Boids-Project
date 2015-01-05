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

  //Création d'une population
  population Boids=population();
  Boids.Set_W(200);
  Boids.Set_H(200);
  Boids.Set_size(10);
  


  return 0;
} 


//===================================================================
//                  Define Miscelaneous Functions
//===================================================================