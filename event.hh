#ifndef EVENT_HH
#define EVENT_HH


#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public:
	MyEventAction(MyRunAction*);
	~MyEventAction();

	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event* ev);


	std::map<int, std::vector<double>> opt_in_disk;


	void add_count_optical_photon()
	{
		count_optical_photon += 1;
	}
	void add_all_steps_count()
	{
		all_steps_count += 1;
	}
	int count_optical_photon;
	int all_steps_count;
};
#endif