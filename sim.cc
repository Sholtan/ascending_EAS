#include <iostream>

#include "G4MTRunManager.hh"
#include "G4RunManager.hh"


#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "tools/colors"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include "construction.hh"
#include "physics.hh"
//#include "LBE.hh"






#include <QGSP_BERT.hh>
//#include <FTFP_INCLXX_HP.hh> // almost same results




#include "action.hh"

int main(int argc, char** argv)
{

    int seeed = atof(argv[1]);
    G4Random::setTheSeed(seeed);
    //G4UIExecutive* ui = 0;
    //for (int i=0; i<argc; i++) {
        //G4cout << argv[i] << G4endl;
    //}
   
    G4MTRunManager* runManager = new G4MTRunManager();
    //G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyPhysicsList());
    //runManager->SetUserInitialization(new QGSP_INCLXX);
    //runManager->SetUserInitialization(new FTFP_BERT);
    
    //runManager->SetUserInitialization(new LBE);
    //runManager->SetUserInitialization(new MyPhysicsList());
    

    G4VModularPhysicsList* physics = new QGSP_BERT();
    physics->RegisterPhysics(new G4OpticalPhysics());
    //physics->RegisterPhysics(new G4EmStandardPhysics_option3());
    runManager->SetUserInitialization(physics);


    //runManager->SetUserInitialization(new FTFP_INCLXX_HP());


    runManager->SetUserInitialization(new MyActionInitialization());
    
    runManager->SetNumberOfThreads(10);
    runManager->Initialize();

    //G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    //ui->SessionStart();

    // for statistics:
    G4UImanager* UI = G4UImanager::GetUIpointer();
    UI->ApplyCommand("/control/execute run.mac");



    //for graphics
    
    /*
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    ui->SessionStart();
    */





    delete runManager;
    return 0;
}
