//*******************************************************************
//                              Population
//*******************************************************************

//===================================================================
//                     Librairies & Project Files
//===================================================================
#include "population.h"


//-------------------------------------------------------------------
//                    Definiton of static attributes
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                           Constructors
//-------------------------------------------------------------------
population::population(void)
{
  size=0;
  nb_prey=0;
  nb_predator=0;
  H=0;
  W=0;
}

//-------------------------------------------------------------------
//                           Destructors
//-------------------------------------------------------------------
population::~population(void)
{
  delete [] tab;
}

//-------------------------------------------------------------------
//                         Public methods
//-------------------------------------------------------------------


//Creation of a population 

void population::define(void)
{
  printf("What is the fiel size? (W*H format, press enter before grasp H)\n");
  scanf("%f" ,&W);
  scanf("%f", &H);
  printf("Grasp the size of prey in population\n");
  scanf("%d", &nb_prey);  
  printf("Grasp the size of predator in population\n");
  scanf("%d", &nb_predator);
  size=nb_predator+nb_prey;
}

void population::create(void)
{
	unsigned int i;
	tab=new agent [size];
  tab[0]=agent(W,H);
	for(i=1; i<size; i++)
	{
      tab[i]=agent(W,H);
      while(tab[i].Get_xposition()==tab[i-1].Get_xposition()) // agent not begin at the same place, this method up calculation size
      {
        tab[i]=agent(W,H);
      }
	}
}


//Print data
void population::print(void)
{
  unsigned int i;
  for(i=0; i<size; i++)
  {
    printf("position: %f; %f\n", tab[i].Get_xposition(), tab[i].Get_yposition());
  }
}



//-------------------------------------------------------------------
//                        Protected methods
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                        Private methods
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                        Non inline accesors
//-------------------------------------------------------------------









