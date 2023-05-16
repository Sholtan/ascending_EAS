#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
   
    RegisterPhysics(new G4HadronPhysicsQGSP_BERT());
    


    RegisterPhysics(new G4EmStandardPhysics());
    //RegisterPhysics(new G4EmStandardPhysics_option3());
    RegisterPhysics(new G4OpticalPhysics());

    //
    //RegisterPhysics(new G4EmStandardPhysics_option1());
    //RegisterPhysics(new G4EmStandardPhysics_option2());
    
    //RegisterPhysics(new G4EmStandardPhysics_option4());
}

MyPhysicsList::~MyPhysicsList()
{}




// std --        23.14 sec
// option1 --    23.16
// option2 --    24.11
// option3 --    23.20
// option4 --    24.58