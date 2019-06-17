#pragma once
#include<list>
using namespace std;

class Virus
{
private:

	char* m_dna;
	int m_resistance;

public:
	Virus();
	~Virus();
	Virus(const Virus *virus);
	void LoadDNAInformation();
	int ReduceResistance(int medicine_resistance);
	virtual void DoBorn() = 0;
	virtual list<Virus *>  DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance(int m_resistance) = 0;
	int Getm_resistance();
	void Setm_resistance(int m_resistance);
};
