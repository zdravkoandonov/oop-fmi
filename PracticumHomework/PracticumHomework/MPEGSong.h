#pragma once
#include "Song.h"
#include <iostream>
class MPEGSong :
	public Song
{
public:

	MPEGSong(char *title, char *singer, char *album, char *genre, int length) : Song(title, singer, album, genre, length)
	{
	}

	~MPEGSong()
	{
	}

	// override
	void start()
	{
		std::cout << "MPEG\n";
		format = MPEG;
		Song::start();
	}
};

