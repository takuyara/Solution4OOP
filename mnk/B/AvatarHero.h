#pragma once
#include "SkilledHero.h"

class AvatarHero : public SkilledHero {
	// TODO
public:
	AvatarHero(Hero *p): SkilledHero(p){
		++sklMap["Avatar"];
	}
};
