#include"stdafx.h"
#include "Dengue.h"
#include "virus.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
Dengue::Dengue()
{
	this->DoBorn();
}
Dengue::~Dengue()
{

}
Dengue::Dengue(const Dengue* dengue) :Virus()
{
	m_protein = new char[4];
	this->m_protein = dengue->m_protein;
}
void Dengue::DoBorn()
{
	this->LoadDNAInformation();
	int protein = rand() % 3 + 1;
	if (protein==1)
	{
		this->m_protein = "NS3";
		cout << this->m_protein << " " << endl;
		this->Setm_resistance(InitResistance(rand() % 10 + 1));
	}
	else if (protein==2)
	{
		this->m_protein = "NS5";
		cout << this->m_protein << " " << endl;
		this->Setm_resistance(InitResistance(rand() % 1 + 11));
	}
	else
	{
		this->m_protein = "E";
		cout << this->m_protein << " " << endl;
		this->Setm_resistance(InitResistance(rand() % 11 + 21));
	}
}
list<Virus *> Dengue::DoClone()
{
	Virus *virus_1 = new Dengue(this); 
	Virus *virus_2 = new Dengue(this);	
	list<Virus*> clonevirus;				
	clonevirus.push_back(virus_1);			
	clonevirus.push_back(virus_2);
	return clonevirus;
}
int Dengue::InitResistance(int m_resistance)
{
	return m_resistance;
}
void Dengue::DoDie()
{
	delete this;
}
