#pragma once
#include "Song.h"
#include <vector>
#include <ctime>

using std::vector;

class Playlist
{
private:
	vector<Song*> songs;
	int currentSong;
	time_t timeCurSongStarted;
	int secondsLeftFromStart;

public:
	Playlist();
	~Playlist();

private:
	Playlist(const Playlist&);

public:
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

