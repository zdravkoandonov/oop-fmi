#pragma once
#include "Song.h"
class Playlist
{
public:
	Playlist();
	~Playlist();

	void play();
	void pause();
	void next();
	void previous();
	char* now_playing();
	void add_song(Song*);
	void erase_song(int);
	int total_playtime();
	void shuffle();
	int left();
};

