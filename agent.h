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

#include "population.h"
//===================================================================
//                          Class declaration
//===================================================================
class agent : public population
{
  public:
//-------------------------------------------------------------------
//                          Public attributes
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                            Constructor
//-------------------------------------------------------------------
    agent(void);
//-------------------------------------------------------------------
//                            Destructor
//-------------------------------------------------------------------
   virtual ~agent(void);
//-------------------------------------------------------------------
//                             Getters
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                             Setters
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//                          Public methods
//-------------------------------------------------------------------

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

//-------------------------------------------------------------------
//                         Private methods
//-------------------------------------------------------------------
};

//===================================================================
//                      Getters' definitions
//===================================================================

//===================================================================
//                      Setters' definitions
//===================================================================

//===================================================================
//                      Operators' definitions
//===================================================================

//===================================================================
//                   Inline functions' definitions
//===================================================================

#endif