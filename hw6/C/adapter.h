//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#pragma once
#include "audio.h"
#include "video.h"
#include <iostream>
class VAAdapter{
public:
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void doublespeed() = 0;
	virtual ~VAAdapter(){ }
} ;

class AudioAdapter: public VAAdapter{
	Audio *_myaud;
public:
	AudioAdapter(Audio *);
	void play();
	void pause();
	void doublespeed();
} ;

class VideoAdapter: public VAAdapter{
	Video *_myvid;
public:
	VideoAdapter(Video *);
	void play();
	void pause();
	void doublespeed();
} ;

AudioAdapter::AudioAdapter(Audio *p): _myaud(p){
}

void AudioAdapter::play(){
	_myaud->play();
}

void AudioAdapter::pause(){
	_myaud->pause();
}

void AudioAdapter::doublespeed(){
	std::cout << "audio cannot be double speed" << std::endl;
}

VideoAdapter::VideoAdapter(Video *p): _myvid(p){
}

void VideoAdapter::play(){
	_myvid->playVideo();
}

void VideoAdapter::pause(){
	_myvid->pauseVideo();
}

void VideoAdapter::doublespeed(){
	_myvid->doubleSpeed();
}

