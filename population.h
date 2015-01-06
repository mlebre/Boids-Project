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

#include "agent.h"
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
    inline agent * Get_tab(void);

//-------------------------------------------------------------------
//                             Setters
//-------------------------------------------------------------------
    inline void Set_W(float width);
    inline void Set_H(float height);
    inline void Set_size(unsigned int nb);
//-------------------------------------------------------------------
//                          Public methods
//-------------------------------------------------------------------
    //Parameters definition & Population creation 
    void define(void);
    void create(void);



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
    agent* tab;

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

inline agent * population::Get_tab(void)
{
  return tab;
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

inline void population::Set_size(unsigned int nb)
{
  size=nb;
}

//===================================================================
//                      Operators' definitions
//===================================================================

//===================================================================
//                   Inline functions' definitions
//===================================================================

#endif

