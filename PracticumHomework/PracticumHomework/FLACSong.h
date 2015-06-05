#pragma once
#include "Song.h"
#include <iostream>
class FLACSong :
	public Song
{
public:

	FLACSong(char *title, char *singer, char *album, char *genre, int length) : Song(title, singer, album, genre, length)
	{
	}

	~FLACSong()
	{
	}

	// override
	void start()
	{
		std::cout << "FLAC\n";
		format = FLAC;
		Song::start();
	}
};

