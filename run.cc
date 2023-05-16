#include "run.hh"

MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->SetNtupleMerging(true);
	man->CreateNtuple("mirror_photons", "mirror_photons");
	man->CreateNtupleDColumn("kin_E");
	man->CreateNtupleDColumn("x");
	man->CreateNtupleDColumn("y");
	man->CreateNtupleDColumn("z");
	man->CreateNtupleDColumn("px");
	man->CreateNtupleDColumn("py");
	man->CreateNtupleDColumn("pz");
	man->CreateNtupleDColumn("t");
	man->FinishNtuple(0);

}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	G4int runID = run->GetRunID();
	std::stringstream strRunID;
	strRunID << runID;
	man->OpenFile("new_layers_mirror" + strRunID.str() + ".root");

}
void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();
}
