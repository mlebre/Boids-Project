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
  tab_prey=NULL;
  tab_predator=NULL;
}

//-------------------------------------------------------------------
//                           Destructors
//-------------------------------------------------------------------
population::~population(void)
{
  delete [] tab_prey;
  delete [] tab_predator;
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
	tab_prey=new prey [nb_prey];
  tab_prey[0]=prey(W,H, nb_prey); 
	for(i=1; i<nb_prey; i++)
	{
      tab_prey[i]=prey(W,H, nb_prey);
      //avoid that 2 preys have the same place
      while(tab_prey[i].Get_xposition()==tab_prey[i-1].Get_xposition()|| tab_prey[i].Get_yposition()==tab_prey[i-1].Get_yposition())  // agent not begin at the same place, this method up calculation size
      {
        tab_prey[i]=prey(W,H, nb_prey);
      }
  }
  // refaire même boucle pour tab_predator
}

//Speed calculation
void population::alignment(void)
{
  unsigned int i;
  unsigned int j;
  double wx=0, wy=0, norm;
  printf("V1\n");
  for(i=0; i<nb_prey; i++)
  {
    for(j=0; j<nb_prey; j++)
    {
      //Norme calculation of v1
      norm=sqrt((tab_prey[i].Get_xposition()-tab_prey[j].Get_xposition())*(tab_prey[i].Get_xposition()-tab_prey[j].Get_xposition())+(tab_prey[i].Get_yposition()-tab_prey[j].Get_yposition())*(tab_prey[i].Get_yposition()-tab_prey[j].Get_yposition()));
      if(norm<tab_prey[i].Get_r())
      {
        wx=tab_prey[j].Get_speed(6)-tab_prey[i].Get_speed(6)+wx;
        wy=tab_prey[j].Get_speed(7)-tab_prey[i].Get_speed(7)+wy;
      }
    }
    wx=wx/nb_prey;
    wy=wy/nb_prey;
    tab_prey[i].Set_speed(wx,0);
    tab_prey[i].Set_speed(wy,1);
    //printf("%f\n", tab_prey[i].Get_speed(0));
  }
}

void population::cohesion(void)
{
  unsigned int i;
  unsigned int j;
  double wx=0, wy=0, norm;
  printf("\nV2\n");
  for(i=0; i<nb_prey; i++)
  {
    for(j=0; j<nb_prey; j++)
    {
      //Norme calculation of v2
       norm=sqrt((tab_prey[i].Get_xposition()-tab_prey[j].Get_xposition())*(tab_prey[i].Get_xposition()-tab_prey[j].Get_xposition())+(tab_prey[i].Get_yposition()-tab_prey[j].Get_yposition())*(tab_prey[i].Get_yposition()-tab_prey[j].Get_yposition()));
      if(norm<tab_prey[i].Get_r())
      {
        wx=tab_prey[j].Get_xposition()-tab_prey[i].Get_xposition()+wx;
        wy=tab_prey[j].Get_yposition()-tab_prey[i].Get_yposition()+wy;
      }
    }
    wx=wx/nb_prey;
    wy=wy/nb_prey;
    tab_prey[i].Set_speed(wx,2);
    tab_prey[i].Set_speed(wy,3);
    //printf("%f\n", tab_prey[i].Get_speed(2));
  }
}

void population::split(void)
{
  unsigned int i;
  unsigned int k;
  double wx=0, wy=0, norm;
  printf("\nV3\n");
  for(i=0; i<nb_prey; i++)
  {
    for(k=0; k<nb_prey; k++)
    {
      norm=sqrt((tab_prey[i].Get_xposition()-tab_prey[k].Get_xposition())*(tab_prey[i].Get_xposition()-tab_prey[k].Get_xposition())+(tab_prey[i].Get_yposition()-tab_prey[k].Get_yposition())*(tab_prey[i].Get_yposition()-tab_prey[k].Get_yposition()));
      if(norm<tab_prey[i].Get_r())
      {
        wx=tab_prey[k].Get_xposition()-tab_prey[i].Get_xposition()+wx;
        wy=tab_prey[k].Get_yposition()-tab_prey[i].Get_yposition()+wy;
      }
    }
      wx=-(wx/nb_prey);
      wy=-(wy/nb_prey);
      tab_prey[i].Set_speed(wx,4);
      tab_prey[i].Set_speed(wx,5);
      //printf("%f \n", tab_prey[i].Get_speed(4));
  }

}


//Print data
void population::print(unsigned int t)
{
  unsigned int i, j;
  bwindow win(W,H); // carré blanc de taille W*H
  printf("%d\n",win.init());
  win.map();
  for(j=0;j<t;j++)
  {
    bool condition=false;
    win.draw_square(0,0,W,H,0xFFFFFF); //remet un carré blanc
    while (!condition)
    {
      int ev = win.parse_event();
      switch(ev)
      {
          case BKPRESS :
        printf("keypressed\n"); 
        printf("key : %s\n",win.get_lastkey());
          break;
          case BBPRESS:
          condition = true;
          break; 
          case BEXPOSE:
        printf("expose\n"); break;
          case BCONFIGURE:
        printf("configure\n"); break;
      }
    }
    for(i=0; i<size; i++)

    {
      win.draw_square(-2+(tab_prey[i].Get_xposition()),-2+(tab_prey[i].Get_yposition()), 2+(tab_prey[i].Get_xposition()), 2+(tab_prey[i].Get_yposition()),0xFF0000);
     // win.draw_line(tab_prey[i].Get_xposition(),tab_prey[i].Get_yposition(),tab_prey[i].Get_xspeed(),tab_prey[i].Get_yspeed(),0xFF0000);
    }
    char name[]="Population";
    win.draw_text(10,10,0x0, name,strlen(name));

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





