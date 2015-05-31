#include "Song.h"


Song::Song(char *title)
{
}


Song::~Song()
{
}

void Song::stop()
{
	playing = false;
}

void Song::play()
{
	playing = true;
}

void Song::pause()
{
	playing = false;
}

void Song::toggle_play()
{
	if (playing)
		pause();
	else
		play();
}

int Song::times_played()
{
	return timesPlayed;
}

bool Song::isPlaying()
{
	return playing;
}

char* Song::getTitle()
{
	return title;
}

char* Song::getSinger()
{
	return singer;
}

char* Song::getAlbum()
{
	return album;
}

char* Song::getGenre()
{
	return genre;
}

int Song::getLength()
{
	return length;
}

int Song::getFormat()
{
	return format;
}