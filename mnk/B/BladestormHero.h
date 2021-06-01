#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
	// TODO
public:
	BladestormHero(Hero *p): SkilledHero(p){
		++sklMap["Bladestorm"];
	}
};
