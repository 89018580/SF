//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "singlephaseTestApp.h"
#include "singlephaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
singlephaseTestApp::validParams()
{
  InputParameters params = singlephaseApp::validParams();
  return params;
}

singlephaseTestApp::singlephaseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  singlephaseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

singlephaseTestApp::~singlephaseTestApp() {}

void
singlephaseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  singlephaseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"singlephaseTestApp"});
    Registry::registerActionsTo(af, {"singlephaseTestApp"});
  }
}

void
singlephaseTestApp::registerApps()
{
  registerApp(singlephaseApp);
  registerApp(singlephaseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
singlephaseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  singlephaseTestApp::registerAll(f, af, s);
}
extern "C" void
singlephaseTestApp__registerApps()
{
  singlephaseTestApp::registerApps();
}
