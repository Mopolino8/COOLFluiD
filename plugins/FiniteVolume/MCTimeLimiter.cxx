

#include "Environment/ObjectProvider.hh"

#include "FiniteVolume/FiniteVolume.hh"
#include "FiniteVolume/MCTimeLimiter.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace std;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace FiniteVolume {

//////////////////////////////////////////////////////////////////////////////

Environment::ObjectProvider<MCTimeLimiter,
                            TimeLimiter,
                            FiniteVolumeModule,
                            1>
MCTimeLimiterProvider("MC");

//////////////////////////////////////////////////////////////////////////////

void MCTimeLimiter::defineConfigOptions(Config::OptionList& options)
{
}

//////////////////////////////////////////////////////////////////////////////

MCTimeLimiter::MCTimeLimiter(const std::string& name) :
TimeLimiter(name)
{
  addConfigOptionsTo(this);
}

//////////////////////////////////////////////////////////////////////////////

MCTimeLimiter::~MCTimeLimiter()
{
}

//////////////////////////////////////////////////////////////////////////////

CFreal MCTimeLimiter::computeTimeLimiterValue(const CFreal& slopeOLD, const CFreal& slopeNEW)
{

  const CFreal r = slopeOLD/slopeNEW;
  CFreal limiterValue = max(0.,min(min(2.,2.*r),(1.+r)/2));

  limiterValue = min(limiterValue, (CFreal)1.);
  limiterValue = limiterValue*limiterValue;




  return limiterValue;
}

//////////////////////////////////////////////////////////////////////////////

    } // namespace FiniteVolume

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////
