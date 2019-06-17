#include"stdafx.h"
#include"virus.h"
#include<iostream>
#include<fstream>

using namespace std;
Virus::Virus()
{
	m_dna = "";
	m_resistance = 0;
}
Virus::~Virus()
{

}
Virus::Virus(const Virus* virus)
{
	this->m_dna = virus->m_dna;
	this->m_resistance = virus->m_resistance;
}
void Virus::LoadDNAInformation()
{
	ifstream f;
	f.open("ATGX.bin");
	if (f.is_open())
	{
		char a[100];
		f >> a;
		m_dna = (char *)a;
	}
	else
	{
		cout << "File isn't open" << endl;
	}
	
}
int Virus::ReduceResistance(int medicine_resistance)
{

	return this->m_resistance = this->m_resistance - medicine_resistance;
}

int Virus::Getm_resistance()
{
	return this-> m_resistance;
}

void Virus::Setm_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
	cout << this->m_resistance << endl;
}
