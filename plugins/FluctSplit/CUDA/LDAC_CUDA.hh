#ifndef COOLFluiD_Numerics_FluctSplit_LDAC_CUDA_hh
#define COOLFluiD_Numerics_FluctSplit_LDAC_CUDA_hh

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

    namespace FluctSplit {

//////////////////////////////////////////////////////////////////////////////
             
extern "C" {
    
  void addToKplusCUDA(int msize, 
		      double* dev_a,  double* dev_b, double* dev_c, double* dev_d, 
		      double* k0,  double* k1,  double* k2, double* sumKplus);
}
  
//////////////////////////////////////////////////////////////////////////////

    } // namespace FluctSplit

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_FluctSplit_LDAC_CUDA_hh
