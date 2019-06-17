#include "stdafx.h"
#include "Patient.h"
#include "Flu.h"
#include "Dengue.h"
#include "Virus.h"
#include <iostream>

using namespace std;
Patient::Patient()
{
	this->DoStart();
	this->m_resistance = this->InitResistance(m_resistance);
}
Patient::~Patient()
{
}
int Patient::InitResistance(int m_resistance)
{
	m_resistance = rand() % 8001 + 1000;
	cout << "Resistance of Patient: " << m_resistance << endl;
	return m_resistance;
}
int Patient::InitMecdicien_Resistance()
{
	int medicine_resistance = rand() % 60 + 1;
	return medicine_resistance;
}
void Patient::DoStart()
{
	int amounts = rand() % 11 + 10;
	this->m_state = 1;
	Virus* virus;
	for (int i = 0; i < amounts; i++)
	{
		int type = rand() % 2 + 1;
		if (type==1)
		{
			cout << "Flu_Virus ";
			virus = new Flu();		
			this->m_virusList.push_back(virus);
		}
		else
		{
			cout << "Dengue_Virus ";
			virus = new Dengue();		
			this->m_virusList.push_back(virus);
		}
	}
}
void Patient::TakeMedicine(int medicine_resistance)
{
	auto virus = this->m_virusList.begin();
	int size = this->m_virusList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*virus)->ReduceResistance(medicine_resistance) <=0 )
		{
			(*virus)->DoDie();
			this->m_virusList.erase(virus++);
		}
		else
		{
			list<Virus*> clonelist = (*virus)->DoClone();
			this->m_virusList.insert(this->m_virusList.end(), clonelist.begin(), clonelist.end());
			virus++;
		}
	}
}

int Patient::GetState()
{
	return this->m_state;
}

void Patient::SetState(int state)
{
	this->m_state = state;
}

int Patient::GetVirusList()
{
	return this->m_virusList.size();
}

int Patient::ResistanceOfAllVirus()
{
	int totalheal = 0;
	auto member_virusList = this->m_virusList.begin();	
	int size = this->m_virusList.size();
	for (int i = 0; i <size; i++)
	{
		totalheal += (*member_virusList)->Getm_resistance();
		member_virusList++;
	}
	return totalheal;
}

int Patient::GetResistance()
{
	return this->m_resistance;
}
