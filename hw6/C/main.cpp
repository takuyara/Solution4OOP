//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#include <iostream>
#include "player.h"
#include "adapter.h"
#include "mp3.h"
#include "wav.h"
#include "mp4.h"
#include "avi.h"

int main(){
	std::cout << "Create a player" << std::endl;
	Player* player = new Player();
	MP3* mp3 = new MP3();
	WAV* wav = new WAV();
	MP4* mp4 = new MP4();
	AVI* avi = new AVI();
	AudioAdapter *mp3a, *wava;
	VideoAdapter *mp4a, *avia;
	player->add(mp3a = new AudioAdapter(mp3));
	player->add(wava = new AudioAdapter(wav));
	player->add(mp4a = new VideoAdapter(mp4));
	player->add(avia = new VideoAdapter(avi));
	std::cout << "play all" << std::endl;
	player->play();
	std::cout << "pause all" << std::endl;
	player->pause();
	std::cout << "double speed" << std::endl;
	player->doubleSpeed();
	delete mp3;
	delete wav;
	delete mp4;
	delete avi;
	delete mp3a;
	delete wava;
	delete mp4a;
	delete avia;
	delete player;
	return 0;
}
