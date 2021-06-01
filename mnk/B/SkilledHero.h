#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
protected:
	name2Level sklMap;
public:
	SkilledHero(Hero *p){ p->getSkill(sklMap); }
	void getSkill(name2Level &res){ res = sklMap; }
};

