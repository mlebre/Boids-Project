//*******************************************************************
//                              Population
//*******************************************************************

#ifndef __population_H__
#define __population_H__

//===================================================================
//                     Librairies & Project Files
//===================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>

#include "agent.h"
#include "bwindow.h"
#include "prey.h"
#include "predator.h"
//===================================================================
//                          Class declaration
//===================================================================
class population
{
  public:
//-------------------------------------------------------------------
//                          Public attributes
//-------------------------------------------------------------------

//We want to allow modifications of size's field by users

//-------------------------------------------------------------------
//                            Constructor
//-------------------------------------------------------------------
    population(void);
//-------------------------------------------------------------------
//                            Destructor
//-------------------------------------------------------------------
    ~population(void);
//-------------------------------------------------------------------
//                             Getters
//-------------------------------------------------------------------
    inline unsigned int Get_size(void);
    inline unsigned int Get_nb_prey(void);
    inline unsigned int Get_nb_predator(void);
    inline float Get_W(void);
    inline float Get_H(void);
    inline agent * Get_tab_prey(void);

//-------------------------------------------------------------------
//                             Setters
//-------------------------------------------------------------------
    inline void Set_W(float width);
    inline void Set_H(float height);
    inline void Set_nb_prey(unsigned int nb);
//-------------------------------------------------------------------
//                          Public methods
//-------------------------------------------------------------------
    //Parameters definition & Population creation 
    void define(void);  //Définition population's parameters by user
    void create(void);  //Creation of prey and predator arrays which give them a position.

    //Speed prey calculation
    void alignment(void); //calcul de v1
    void cohesion(void); //calcul de v2
    void split(void);  //calcul de v3

    //Print data
    void print(unsigned int t);




  protected:
//-------------------------------------------------------------------
//                        Protected attributes
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                        Forbiden constructor
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                        Protected methods
//-------------------------------------------------------------------

  private:
//-------------------------------------------------------------------
//                        Private attributes
//-------------------------------------------------------------------
    unsigned int size;
    unsigned int nb_prey;
    unsigned int nb_predator;
    float W;
    float H;
    prey* tab_prey;
    predator* tab_predator;

//-------------------------------------------------------------------
//                         Private methods
//-------------------------------------------------------------------
};

//===================================================================
//                      Getters' definitions
//===================================================================
inline unsigned int population::Get_size(void)
{
  return size;
}

inline unsigned int population::Get_nb_prey(void)
{
  return nb_prey;
}

inline unsigned int population::Get_nb_predator(void)
{
  return nb_predator;
}

inline float population::Get_W(void)
{
  return W;
}

inline float population::Get_H(void)
{
  return H;
}

inline agent * population::Get_tab_prey(void)
{
  return tab_prey;
}
//===================================================================
//                      Setters' definitions
//===================================================================
inline void population::Set_W(float width)
{
  W=width;
}

inline void population::Set_H(float height)
{
  H=height;
}

inline void population::Set_nb_prey(unsigned int nb)
{
  nb_prey=nb;
  size=size+nb_prey;
}

//===================================================================
//                      Operators' definitions
//===================================================================

//===================================================================
//                   Inline functions' definitions
//===================================================================

#endif

