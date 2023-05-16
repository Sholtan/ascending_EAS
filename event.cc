#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	opt_in_disk = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, {6, {}}, {7, {}} };
	count_optical_photon = 0;
	all_steps_count = 0;
}
MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	opt_in_disk = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, {6, {}}, {7, {}} };
	count_optical_photon = 0;
	all_steps_count = 0;
}

void MyEventAction::EndOfEventAction(const G4Event* ev)
{
	


/*
	G4int n_event = ev->GetEventID();
	G4cout << "\n\n\n\n event: " << n_event << "\n\n\n\n";
	//G4cout << "###########################  at the end of THE EVENT TOTAL inelastics: " << triggercount << " in " << n_event << G4endl;
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	//if (1) {
	
	//G4cout << n_event << " event, " << G4endl << "reactions: " << triggercount << " , neutrons: " << nF[0].size() << G4endl << G4endl;
	
	int size_opt = opt_in_disk[0].size();
	for (G4int i = 0; i < size_opt; i++) 
	{
		man->FillNtupleDColumn(0, 0, opt_in_disk[0][i]);
		man->FillNtupleDColumn(0, 1, opt_in_disk[1][i]);
		man->FillNtupleDColumn(0, 2, opt_in_disk[2][i]);
		man->FillNtupleDColumn(0, 3, opt_in_disk[3][i]);
		man->FillNtupleDColumn(0, 4, opt_in_disk[4][i]);
		man->FillNtupleDColumn(0, 5, opt_in_disk[5][i]);
		man->FillNtupleDColumn(0, 6, opt_in_disk[6][i]);
		man->FillNtupleDColumn(0, 7, opt_in_disk[7][i]);
		man->AddNtupleRow(0);
	}
	man->FillNtupleIColumn(1, 0, count_optical_photon);
	man->AddNtupleRow(1);
		*/
	
}
