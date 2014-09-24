// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#include "Framework/CouplerData.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace COOLFluiD::Framework;
using namespace COOLFluiD::Config;
using namespace COOLFluiD::Common;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Framework {

//////////////////////////////////////////////////////////////////////////////

void CouplerData::defineConfigOptions(Config::OptionList& options)
{
}

//////////////////////////////////////////////////////////////////////////////

CouplerData::CouplerData(Common::SafePtr<Method> owner)
 : MethodData(owner)
{
  addConfigOptionsTo(this);
}

//////////////////////////////////////////////////////////////////////////////

CouplerData::~CouplerData()
{
}

//////////////////////////////////////////////////////////////////////////////

void CouplerData::configure ( Config::ConfigArgs& args )
{
  MethodData::configure(args);
}

//////////////////////////////////////////////////////////////////////////////

void CouplerData::setup()
{
  MethodData::setup();
}

//////////////////////////////////////////////////////////////////////////////

void CouplerData::unsetup()
{
  MethodData::unsetup();
}

//////////////////////////////////////////////////////////////////////////////

  } // namespace Framework

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////
