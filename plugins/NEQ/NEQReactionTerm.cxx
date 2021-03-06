#include "NEQReactionTerm.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace COOLFluiD::Framework;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {

    namespace NEQ {

//////////////////////////////////////////////////////////////////////////////

NEQReactionTerm::NEQReactionTerm(const std::string& name) :
  BaseTerm(name)
{
}

//////////////////////////////////////////////////////////////////////////////

NEQReactionTerm::~NEQReactionTerm()
{
}

//////////////////////////////////////////////////////////////////////////////

void NEQReactionTerm::resizePhysicalData(RealVector& physicalData)
{
  // resize the physical data
  cf_assert(getDataSize() > 0);
  physicalData.resize(getDataSize());
}

//////////////////////////////////////////////////////////////////////////////

void NEQReactionTerm::setupPhysicalData()
{
  cf_assert(getDataSize() > 0);

  // set the size of each physical data in the StatesData
  resizePhysicalData(m_physicalData);
  resizePhysicalData(m_refPhysicalData);
}

//////////////////////////////////////////////////////////////////////////////

    } // namespace NEQ

  } // namespace Physics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////
