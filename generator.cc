#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4IonTable* Iontable = particleTable->GetIonTable();
    //G4ParticleDefinition* particle = particleTable->FindParticle(22); // electron(11)  gamma (22)
    //G4ParticleDefinition* particle = particleTable->FindParticle(211); // pion0-111   pion_minus- -211; pion+ - 211
    G4ParticleDefinition *particle = particleTable->FindParticle(2212); //  proton 

    //G4int massnumber = 1;

    G4ThreeVector pos(0.,0.,0.);  // 
    //G4ThreeVector mom(sin(1*M_PI/180),0.,cos(1*M_PI/180));
    G4ThreeVector mom(0.,0.,1.);

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(10*TeV);

    fParticleGun->GeneratePrimaryVertex(anEvent);

}

// size -- 10
// 1000 GeV -- 2:20:58   
// 1100 GeV -- 2:30:00
// 1400 GeV -- 3:11:75    (with instant killing opticalphoton 2:53:19)



