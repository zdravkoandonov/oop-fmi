#include "Song.h"

Song::Song(char *title, char *singer, char *album, char *genre, int length)
	: title(title), singer(singer), album(album), genre(genre), length(length)
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

bool Song::isStarted()
{
	return started;
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