#ifndef COOLFluiD_Numerics_SpectralFD_BCMirrorLinEuler2D_hh
#define COOLFluiD_Numerics_SpectralFD_BCMirrorLinEuler2D_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/BaseMethodStrategyProvider.hh"
#include "SpectralFD/BCStateComputer.hh"
#include "SpectralFD/SpectralFDMethodData.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {
    namespace LinearizedEuler {
      class LinEuler2DVarSet;
    }
  }

  namespace SpectralFD {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents a mirror/wall boundary condition for the 2D linearized Euler equations
 * @note the mean flow should also be symmetrical for this boundary condition to make sense.
 *
 * @author Kris Van den Abeele
 */
class BCMirrorLinEuler2D : public BCStateComputer {

public:  // methods

  /// Constructor
  BCMirrorLinEuler2D(const std::string& name);

  /// Destructor
  ~BCMirrorLinEuler2D();

  /// Gets the Class name
  static std::string getClassName()
  {
    return "BCMirrorLinEuler2D";
  }

  /// Set up private data and data
  void setup();

  /**
   * Sets the ghost states in all the boundary points (depends on the boundary condition type)
   */
  void computeGhostStates(const std::vector< Framework::State* >& intStates,
                          std::vector< Framework::State* >& ghostStates,
                          const std::vector< RealVector >& normals,
                          const std::vector< RealVector >& coords);

  /**
   * Sets the ghost gradients in all the boundary points (depends on the boundary condition type)
   */
  void computeGhostGradients(const std::vector< std::vector< RealVector* > >& intGrads,
                             std::vector< std::vector< RealVector* > >& ghostGrads,
                             const std::vector< RealVector >& normals,
                             const std::vector< RealVector >& coords);

protected: // data

  /// physical model (in conservative variables)
  Common::SafePtr<Physics::LinearizedEuler::LinEuler2DVarSet> m_linEulerVarSet;

  /// variable for physical data of ghostSol
  RealVector m_ghostSolPhysData;

  /// variable for physical data of intSol
  RealVector m_intSolPhysData;

}; // class BCMirrorLinEuler2D

//////////////////////////////////////////////////////////////////////////////

  }  // namespace SpectralFD

}  // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif  // COOLFluiD_Numerics_SpectralFD_BCMirrorLinEuler2D_hh

