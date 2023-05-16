#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"

#include "G4EmStandardPhysics.hh"
//#include "G4EmStandardPhysics_option1.hh"
//#include "G4EmStandardPhysics_option2.hh"
#include "G4EmStandardPhysics_option3.hh"
//#include "G4EmStandardPhysics_option4.hh"

#include "G4OpticalPhysics.hh"
//#include "LBE.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"
//#include "G4HadronPhysicsQGSP_INCLXX.hh"    


class MyPhysicsList : public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    ~MyPhysicsList();
};

#endif

