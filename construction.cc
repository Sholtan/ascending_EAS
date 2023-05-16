#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}



G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();

    G4double energy[2] = {1.239841939 / 0.9  * eV, 1.239841939 / 0.2  * eV};
    G4double rindexAtm[2];   // {1.000014438249827, 1.000014438249827}
    G4double rindexWorld[2] = {1.000, 1.000};
    double width_of_world = 1000.;
    double width_of_detector = 10.;

    G4Material *worldMat = new G4Material("worldMat", 1.205e-16 * g / cm3, 3);
    worldMat->AddElement(nist->FindOrBuildElement("N"), 75.5 * perCent);
    worldMat->AddElement(nist->FindOrBuildElement("O"), 23.1 * perCent);
    worldMat->AddElement(nist->FindOrBuildElement("Ar"), 1.4 * perCent);

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld -> AddProperty("RINDEX", energy, rindexWorld, 2);
    worldMat -> SetMaterialPropertiesTable(mptWorld);

    

    G4Box* solidWorld = new G4Box("solidWorld", width_of_world * m, width_of_world * m, 500 * km);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    //G4Material *atmmat = new G4Material("atmmat", 5.742651485982984e-05 * g / cm3, 3);
    //atmmat->AddElement(nist->FindOrBuildElement("N"), 75.5 * perCent);
    //atmmat->AddElement(nist->FindOrBuildElement("O"), 23.1 * perCent);
    //atmmat->AddElement(nist->FindOrBuildElement("Ar"), 1.4 * perCent);

    //G4MaterialPropertiesTable *mptATM = new G4MaterialPropertiesTable();
    //mptATM -> AddProperty("RINDEX", energy, rindexAtm, 2);
    //atmmat -> SetMaterialPropertiesTable(mptATM);

    //G4Box* solidATM = new G4Box("solidATM", width_of_world*m, width_of_world*m, 435.129*km);
    //G4LogicalVolume *logicAtm = new G4LogicalVolume(solidATM, atmmat, "logicAtm");
    //G4VPhysicalVolume *physAtm = new G4PVPlacement(0, G4ThreeVector(0., 0., 435.129), logicAtm, "physAtm", logicWorld, false, 0, true);




    G4Box* solidkorobka = new G4Box("solidkorobka", width_of_detector*m, width_of_detector*m, 1*m);
    logickorobka = new G4LogicalVolume(solidkorobka, worldMat, "logickorobka");

    G4VPhysicalVolume *physkorobka = new G4PVPlacement(0, G4ThreeVector(0., 0., (499998.)*m), logickorobka, "physkorobka",logicWorld, false, 0, true);

    double ATM_density [80];
    double n[80]; 
    
    int count = 0;
    for (double i = 250; i <= 40000; i += 500)  //returns density in g/cm^3
    {

        //U.S. Standard Atmosphere from Corsika guide
        //const double a[5]={-186.555305, -94.919, 0.61289, 0.0, 0.01128292};
          const double b[5]={1222.6562, 1144.9069, 1305.5948, 540.1778, 1.0};
          const double c[5]={994186.38, 878153.55, 636143.04, 772170.16, 1e9};
          if(i>112.8e3)
            ATM_density [count] = 0.0;
          else if(i>100000.0)
            ATM_density [count] = b[4]/c[4];
          else if(i>40000.0)
            ATM_density [count] = b[3]/c[3]*exp(-i*100.0/c[3]);
          else if(i>10000.0)
            ATM_density [count] = b[2]/c[2]*exp(-i*100.0/c[2]);
          else if(i>4000.0)
            ATM_density [count] = b[1]/c[1]*exp(-i*100.0/c[1]);
          else
            ATM_density [count] = b[0]/c[0]*exp(-i*100.0/c[0]);
        //G4cout << ATM_density[count] << G4endl;
        count++;
    }
    //n = 1 + 0.00029 exp(-z/7000) z- hight m

    G4Material *Atm_mat[80];
    G4Box *Atmosphere[80];
    G4LogicalVolume *logic_atm[80];
    G4VPhysicalVolume *physAtm[80];
    for (int i = 0; i < 80; i += 1)
    {
        n[i] = 1 + 0.00029 * exp(-(i * 500)/7000);
        for (int j = 0; j < 2; j++)
        {
            rindexAtm[j] = n[i];

        }
        //G4cout<<std::setprecision(16) <<"ATM_density    " << ATM_density[45] << "rindexAtm"<< n[45]<< G4endl;
        Atm_mat[i] = new G4Material("Atm_mat" + std::to_string(i), ATM_density[i] * g / cm3, 3); 
        Atm_mat[i]->AddElement(nist->FindOrBuildElement("N"), 78. * perCent);
        Atm_mat[i]->AddElement(nist->FindOrBuildElement("O"), 21. * perCent);
        Atm_mat[i]->AddElement(nist->FindOrBuildElement("Ar"), 1. * perCent);
        
        G4MaterialPropertiesTable *mptAtm = new G4MaterialPropertiesTable();
        mptAtm -> AddProperty("RINDEX", energy, rindexAtm, 2);
        Atm_mat[i] -> SetMaterialPropertiesTable(mptAtm);

        Atmosphere[i] = new G4Box("Atmosphere" + std::to_string(i),width_of_world*m,width_of_world*m, 249.999*m);
        logic_atm[i] = new G4LogicalVolume(Atmosphere[i], Atm_mat[i], "logic_atm"+ std::to_string(i));
        //G4cout << G4endl << "centr: " << (i * 500 + 250)*m << G4endl;
        physAtm[i] = new G4PVPlacement(0, G4ThreeVector(0., 0.,(i * 500 + 250)*m), logic_atm[i], "physAtm" + std::to_string(i), logicWorld, false, i, true);
        
    }

 
    return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector* sensDet = new MySensitiveDetector("SensitiveDetector"); ///создание чувствительности детектора
    logickorobka->SetSensitiveDetector(sensDet);
}


// G4double rindexWorld[2] = {1.00029, 1.00029};
// G4Material *worldMat = new G4Material("worldMat", 0.0012 * g / cm3, 3);