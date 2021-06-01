//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "adapter.h"

class Player{
	std::vector<VAAdapter*> playlist;
public:
	void add(VAAdapter* vad){
		playlist.push_back(vad);
	}
	void play(){
		if (playlist.empty())
			std::cout << "Nothing to play" << std::endl;
		for (VAAdapter* vad: playlist) vad->play();
	}
	void pause(){
		if (playlist.empty())
			std::cout << "Nothing to pause" << std::endl;
		for (VAAdapter* vad: playlist) vad->pause();
	}
	void doubleSpeed(){
		if (playlist.empty())
			std::cout << "Nothing to double speed" << std::endl;
		for (VAAdapter* vad: playlist) vad->doublespeed();
	}
};

#endif
