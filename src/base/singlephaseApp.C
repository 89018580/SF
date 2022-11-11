#include "singlephaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
singlephaseApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

singlephaseApp::singlephaseApp(InputParameters parameters) : MooseApp(parameters)
{
  singlephaseApp::registerAll(_factory, _action_factory, _syntax);
}

singlephaseApp::~singlephaseApp() {}

void
singlephaseApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"singlephaseApp"});
  Registry::registerActionsTo(af, {"singlephaseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
singlephaseApp::registerApps()
{
  registerApp(singlephaseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
singlephaseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  singlephaseApp::registerAll(f, af, s);
}
extern "C" void
singlephaseApp__registerApps()
{
  singlephaseApp::registerApps();
}
