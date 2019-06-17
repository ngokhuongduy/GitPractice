#include"stdafx.h"
#include "Flu.h"
#include "virus.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Flu::Flu()
{
	this->DoBorn();
}
Flu::~Flu()
{
}
Flu::Flu(const Flu* flu) :Virus()
{
	this->m_color = m_color;
}
void Flu::DoBorn()
{
	this->LoadDNAInformation();
	this->m_color = rand() % 2 + 1;
	if (m_color ==1 )
	{
		cout << "Red" << endl;
		this->Setm_resistance(InitResistance(rand() % 11 + 10));
	}
	else
	{
		cout << "Blue" << endl;
		this->Setm_resistance(InitResistance(rand() % 6 + 10));
	}
}
list<Virus *> Flu::DoClone()
{
	Virus *virus = new Flu(this); 
	list<Virus*> clonevirus; 
	clonevirus.push_back(virus); 
	return clonevirus; 
}
int Flu::InitResistance(int m_resistance)
{
	return m_resistance;
}
void Flu::DoDie()
{
	delete this;
}
int Flu::Color()
{
	return this->m_color;
}