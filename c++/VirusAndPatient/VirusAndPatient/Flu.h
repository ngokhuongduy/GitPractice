#pragma once
#include"virus.h"
class Flu : public Virus
{
private:
	int m_color;
public:
	Flu();
	~Flu();
	Flu(const Flu* flu);
	void DoBorn() override;
	void DoDie() override;
	list <Virus*> DoClone() override;
	int InitResistance(int m_resistance) override;
	int Color();
};