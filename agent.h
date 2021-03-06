//*******************************************************************
//                              Agent
//*******************************************************************

#ifndef __agent_H__
#define __agent_H__

//===================================================================
//                     Librairies & Project Files
//===================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>
//===================================================================
//                          Class declaration
//===================================================================
class agent 
{
  public:
//-------------------------------------------------------------------
//                          Public attributes
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//                            Constructor
//-------------------------------------------------------------------
    agent(void);
    agent(double W, double H, unsigned int size);
//-------------------------------------------------------------------
//                            Destructor
//-------------------------------------------------------------------
   virtual ~agent(void);
//-------------------------------------------------------------------
//                             Getters
//-------------------------------------------------------------------
    inline double* Get_speed(void); //inutilisé pour l'instant
    inline double Get_xposition(void);
    inline double Get_yposition(void);
    inline double Get_r(void);
    inline double Get_speed(unsigned int x);
//-------------------------------------------------------------------
//                             Setters
//-------------------------------------------------------------------
    inline void Set_speed(double v, unsigned int i);
//-------------------------------------------------------------------
//                          Public methods
//-------------------------------------------------------------------
   
     



  protected:
//-------------------------------------------------------------------
//                        Protected attributes
//-------------------------------------------------------------------
    unsigned int nb_agents;
    double* speed; //speed at time t
    double* new_speed; //speed at time t+dt
    double xposition; //x-axis position
    double yposition; //y-axis position
    double r; //perception radius

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

//-------------------------------------------------------------------
//                         Private methods
//-------------------------------------------------------------------
};

//===================================================================
//                      Getters' definitions
//===================================================================
inline double* agent::Get_speed(void) //inutilisé pour l'instant
{
  return speed;
}

inline double agent::Get_xposition(void)
{
  return xposition;
}

inline double agent::Get_yposition(void)
{
  return yposition;
}

inline double agent::Get_r(void)
{
  return r;
}

inline double agent::Get_speed(unsigned int x)
{
  return speed[x];
}
//===================================================================
//                      Setters' definitions
//===================================================================
inline void agent::Set_speed(double v, unsigned int i)
{
  speed[i]=v;
}

//===================================================================
//                      Operators' definitions
//===================================================================

//===================================================================
//                   Inline functions' definitions
//===================================================================

#endif
