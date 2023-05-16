#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) :
G4VSensitiveDetector(name)
{
}
MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory*ROhist)
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	G4Track* track = aStep->GetTrack();
	G4double globalTime = track->GetGlobalTime();
	const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	G4double Energy = dParticle->GetTotalEnergy();

	G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	G4ThreeVector positionParticle = preStepPoint->GetPosition();
	G4ThreeVector MomentumParticle = preStepPoint->GetMomentum();

	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	const G4String& particlename = particleDefinition->GetParticleName();
	G4double pdgcharge = particleDefinition->GetPDGCharge();

/*
	if (particlename == "opticalphoton")
	{	
		const G4VProcess* creatorProcess = track->GetCreatorProcess();
		G4String pname = creatorProcess->GetProcessName();
		//creatorProcess->DumpInfo();																							// << "    volname: " << volname  << ", name: " << particlename << " , charge: " << pdgcharge
		//G4cout << pname << "  " << particlename << "  " << positionParticle[0]/m << " m,  " << positionParticle[1]/m << " m,  " << positionParticle[2]/km    << " km,  time: " << globalTime/microsecond   << " microsecond,   Energy: " << (Energy/MeV) << " MeV" << G4endl;
	}*/
	G4cout << particlename << "  " << positionParticle[0]/m << " m,  " << positionParticle[1]/m << " m,  " << positionParticle[2]/km    << " km,  time: " << globalTime/microsecond   << " microsecond,   wavelength: " << 1239.8/(Energy/eV) << " nanometers" << G4endl;
	man->FillNtupleDColumn(0, 0, Energy / MeV);
	man->FillNtupleDColumn(0, 1, positionParticle[0]/m);
	man->FillNtupleDColumn(0, 2, positionParticle[1]/m);
	man->FillNtupleDColumn(0, 3, positionParticle[2]/m);
	man->FillNtupleDColumn(0, 4, MomentumParticle[0] / MeV);
	man->FillNtupleDColumn(0, 5, MomentumParticle[1] / MeV);
	man->FillNtupleDColumn(0, 6, MomentumParticle[2] / MeV);
	man->FillNtupleDColumn(0, 7, globalTime / nanosecond);
	man->AddNtupleRow(0);

	return true;
}



// wavelength of photon can be calculated 1239.8/(Energy/eV) nanometers