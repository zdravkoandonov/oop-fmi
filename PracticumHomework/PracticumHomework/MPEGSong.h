#pragma once
#include "Song.h"
#include <iostream>
class MPEGSong :
	public Song
{
public:

	MPEGSong(char *title) : Song(title)
	{
	}

	~MPEGSong()
	{
	}

	// override
	void start()
	{
		std::cout << "MPEG\n";
		Song::start();
	}
};

