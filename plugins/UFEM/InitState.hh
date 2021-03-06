#ifndef COOLFluiD_UFEM_InitState_hh
#define COOLFluiD_UFEM_InitState_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/VectorialFunction.hh"
#include "UFEM/UFEMSolverData.hh"
#include "Framework/DataSocketSink.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

    namespace UFEM {

//////////////////////////////////////////////////////////////////////////////

/// This class represents a initalizing solution command
/// @author Tiago Quintino
class UFEM_API InitState : public UFEMSolverCom {
public:

  /// Defines the Config Option's of this class
  /// @param options a OptionList where to add the Option's
  static void defineConfigOptions(Config::OptionList& options);

  /// Constructor.
  explicit InitState(const std::string& name);

  /// Destructor.
  ~InitState();

protected:

  /// Execute Processing actions
  void executeOnTrs();

  /// Configures the command.
  virtual void configure ( Config::ConfigArgs& args );

  /// Returns the DataSocket's that this command needs as sinks
  /// @return a vector of SafePtr with the DataSockets
  std::vector<Common::SafePtr<Framework::BaseDataSocketSink> > needsSockets();

protected: // data

  /// a vector of string to hold the functions
  std::vector<std::string> m_func_str;

  /// the VectorialFunction to use
  Framework::VectorialFunction m_init_func;

  /// socket for State's
  Framework::DataSocketSink<Framework::State*, Framework::GLOBAL> socket_states;

  /// socket for past States's
  Framework::DataSocketSink<Framework::State*> socket_pastStates;

  /// socket for past past States's
  Framework::DataSocketSink<Framework::State*> socket_pastpastStates;

}; // class InitState

//////////////////////////////////////////////////////////////////////////////

    } // namespace UFEM

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_UFEM_InitState_hh

