#include <cmath>

#include <common/Exd/ExdDataGenerated.h>
#include <common/Common.h>
#include "Actor/Actor.h"
#include "Actor/Player.h"
#include "CalcBattle.h"


using namespace Core::Math;
using namespace Core::Entity;

extern Core::Data::ExdDataGenerated g_exdDataGen;

/*
   Class used for battle-related formulas and calculations.
   Big thanks to the Theoryjerks group!

   NOTE:
   Formulas here shouldn't be considered final. It's possible that the formula it was based on is correct but 
   wasn't implemented correctly here, or approximated things due to limited knowledge of how things work in retail.
   It's also possible that we're using formulas that were correct for previous patches, but not the current version.

   TODO:

   Damage outgoing calculations. This includes auto-attacks, etc.
   More formulas in general. Most of it was moved to another class, but work can be done in this area as well already.

*/

uint32_t CalcBattle::calculateHealValue( PlayerPtr pPlayer, uint32_t potency )
{
   auto classInfo = g_exdDataGen.get< Core::Data::ClassJob >( static_cast< uint8_t >( pPlayer->getClass() ) );
   auto paramGrowthInfo = g_exdDataGen.get< Core::Data::ParamGrow >( pPlayer->getLevel() );

   if ( !classInfo || !paramGrowthInfo )
      return 0;

   //auto jobModVal = classInfoIt->second;

   // consider 3% variation
   return potency / 10;
}
