#pragma once
#include "Song.h"
#include <iostream>
class FLACSong :
	public Song
{
public:

	FLACSong(char *title) : Song(title)
	{
	}

	~FLACSong()
	{
	}

	// override
	void start()
	{
		std::cout << "FLAC\n";
		Song::start();
	}
};

