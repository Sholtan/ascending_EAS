#include "stepping.hh"


MySteppingAction::MySteppingAction(MyEventAction* eventAction)
{
	fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step* aStep)
{


	//fEventAction->add_all_steps_count();
	/*if ((fEventAction->all_steps_count % 1000000) == 0)
	{
		G4cout << fEventAction->all_steps_count << "\n";
	}*/

	G4Track* track = aStep->GetTrack();
	//G4VPhysicalVolume* vol = track->GetVolume();
	//const G4String volname = vol->GetLogicalVolume()->GetName();

	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	//G4double pdgcharge = particleDefinition->GetPDGCharge();
	//G4int pdg = particleDefinition->GetPDGEncoding();
	const G4String& particlename = particleDefinition->GetParticleName();
	//G4double globalTime = track->GetGlobalTime();

	const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	//G4double depositEnergy = aStep->GetTotalEnergyDeposit();
	//G4double kinEnergy = dParticle->GetKineticEnergy();
	G4double Energy = dParticle->GetTotalEnergy();
	//G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	//G4ThreeVector positionParticle = preStepPoint->GetPosition();
	//G4ThreeVector MomentumParticle = preStepPoint->GetMomentum();
	//G4int CurrentStepNumber = track->GetCurrentStepNumber();

/*
	if (CurrentStepNumber < 2  && particlename== "opticalphoton")  // && particlename!= "e-" && particlename!= "e+" && particlename!= "gamma"
	{
		//fEventAction->Addtrigger();
		//G4cout <<"ratatatatatatattata    " << fEventAction ->triggercount << G4endl;
		G4cout << positionParticle[0] << " " << positionParticle[1] << " " << positionParticle[2] << "    volname: " << volname << ", name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << Energy << G4endl;
	}
*/

/*
	if (particlename == "opticalphoton")
	{
		track->SetTrackStatus(fKillTrackAndSecondaries);
	}


//if // && ((Energy/MeV) < 20.) && track->GetTrackID() != 1)    (particlename == "e+" || particlename == "e-")
*/  
	if  ((particlename== "e-" || particlename== "e+")  && ((Energy/MeV) < 20.))   //  && track->GetTrackID() != 1  (particlename != "opticalphoton")
	{
			//G4cout << CurrentStepNumber << "  killed " << positionParticle[0] << " " << positionParticle[1] << " " << positionParticle[2] << "    volname: " << volname << ", name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << (Energy/MeV) << " MeV" << G4endl;	
		track->SetTrackStatus(fStopAndKill);   // fKillTrackAndSecondaries
	}

/*
	if ((particlename == "opticalphoton") && CurrentStepNumber==1)
	{
		fEventAction->add_count_optical_photon();
		G4cout << fEventAction->count_optical_photon << G4endl;
	}*/

	/*if (particlename == "e-" && CurrentStepNumber == 2 && track->GetTrackID() != 1)
	{
		//G4cout << MomentumParticle[0] << "  " << MomentumParticle[1] << "  " << MomentumParticle[2] << "  " << (Energy/MeV) << G4endl;
	}
	if (track->GetTrackID() == 1)
	{
		//G4cout << CurrentStepNumber << "projectile " << positionParticle[0] << " " << positionParticle[1] << " " << positionParticle[2] << "    volname: " << volname << ", name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << (Energy/MeV) << " MeV" << G4endl;
		
	}
	if (CurrentStepNumber == 2 && particlename != "opticalphoton")   // && particlename != "opticalphoton"
	{
		//G4cout << particlename << " , energy: " << (Energy/MeV) << " MeV" << G4endl;
		
	}*/


	 /*if (volname == "logic_Earth")
	 {
	 	G4cout << "    volname: " << volname << "\n";
	 }*/

/*
	if (aStep->IsLastStepInVolume() && particlename != "opticalphoton")
	{
		G4cout << particlename << "  " << positionParticle[0]/m << " m,  " << positionParticle[1]/m << " m,  " << positionParticle[2]/km    << ",   wavelength: " << 1239.8/(Energy/eV) << " nanometers" << G4endl;
	}

*/
/*	if (volname == "Degreelogic"&& aStep->IsFirstStepInVolume()&& particlename == "opticalphoton")    //      
	{
		fEventAction->add_count_optical_photon();
		//G4cout << "\n" << fEventAction->count_optical_photon << "\n";
		G4cout << positionParticle[0] << " " << positionParticle[1] << " " << positionParticle[2] << "    volname: " << volname << ", name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , kinenergy: "  << " , energy: " << Energy << G4endl;
		
		fEventAction->opt_in_disk[0].push_back(Energy / MeV);
		fEventAction->opt_in_disk[1].push_back(positionParticle[0]/m);
		fEventAction->opt_in_disk[2].push_back(positionParticle[1]/m);
		fEventAction->opt_in_disk[3].push_back(positionParticle[2]/m);
		fEventAction->opt_in_disk[4].push_back(MomentumParticle[0] / MeV);
		fEventAction->opt_in_disk[5].push_back(MomentumParticle[1] / MeV);
		fEventAction->opt_in_disk[6].push_back(MomentumParticle[2] / MeV);
		fEventAction->opt_in_disk[7].push_back(globalTime / microsecond);
		track->SetTrackStatus(fStopAndKill);
	}*/

}

