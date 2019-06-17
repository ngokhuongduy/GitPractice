#pragma once
#include"virus.h"
class Dengue : public Virus
{
private:
	string m_protein;
public:
	Dengue();
	~Dengue();
	Dengue(const Dengue* dengue);
	void DoBorn() override;
	void DoDie() override;
	list <Virus*> DoClone() override;
	int InitResistance(int m_resistance) override;
};