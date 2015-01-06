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
  bwindow win(W,H); // carré blanc de taille W*H
  printf("%d\n",win.init());
  win.map();
  for(;;)
  {
    int ev = win.parse_event();
    switch(ev)
    {
        case BKPRESS :
      printf("keypressed\n"); 
      printf("key : %s\n",win.get_lastkey());
        break;
        case BBPRESS:
      printf("buttonpressed\n"); break;
        case BEXPOSE:
      printf("expose\n"); break;
        case BCONFIGURE:
      printf("configure\n"); break;
    }
    win.draw_text(10,10,0x0,"Population au temps 0",strlen("Population au temps 0"));
    for(i=0; i<size; i++)
    {
      win.draw_square(-2+(tab[i].Get_xposition()),-2+(tab[i].Get_xposition()), 2+(tab[i].Get_xposition()), 2+(tab[i].Get_xposition()),0xFF0000);
    }
    
    
    //win.draw_fsquare(400,400,440,440,0xFF00);
  }
  /*for(i=0; i<size; i++)
  {
    printf("position: %f; %f\n", tab[i].Get_xposition(), tab[i].Get_yposition());
  }*/
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




//Affichage graphique
/*bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
  int ev = win.parse_event();
  switch(ev)
  {
      case BKPRESS :
    printf("keypressed\n"); 
    printf("key : %s\n",win.get_lastkey());
    break;
      case BBPRESS:
    printf("buttonpressed\n"); break;
      case BEXPOSE:
    printf("expose\n"); break;
      case BCONFIGURE:
    printf("configure\n"); break;
  }
  win.draw_point(100,100,0xFF00);
  win.draw_line(100,100,200,200,0xFF0000);
  win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
  //affiche un carré (abs coin sup gauche, ord coin sup gauche,abs coin inf droit, ord coin inf droit)
  win.draw_square(200,200,220,220,0xFF00);
  win.draw_fsquare(400,400,440,440,0xFF00);
    }*/





