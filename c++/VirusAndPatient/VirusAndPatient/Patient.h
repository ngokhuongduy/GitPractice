#pragma once
#include "Virus.h"
#include <list>

using namespace std;

class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;

public:
	Patient();
	~Patient();
	void DoStart();
	int InitResistance(int m_resistance);
	int InitMecdicien_Resistance();
	void TakeMedicine(int medicine_resistance);
	int GetState();
	void SetState(int state);
	int GetVirusList();
	int ResistanceOfAllVirus();
	int GetResistance();
};