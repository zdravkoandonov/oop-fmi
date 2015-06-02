#include "Playlist.h"


Playlist::Playlist()
{
	currentSong = 0;
}


Playlist::~Playlist()
{
}

void Playlist::play()
{
	if (songs[currentSong]->isStarted())
	{
		if ((!songs[currentSong]->isPlaying))
		{
			timeCurSongStarted = time(NULL);
			songs[currentSong]->play();
		}
	}
	else
	{
		timeCurSongStarted = time(NULL);
		secondsLeftFromStart = songs[currentSong]->getLength();
		songs[currentSong]->start();
	}

}

void Playlist::pause()
{
	songs[currentSong]->pause();
	secondsLeftFromStart -= (time(NULL) - timeCurSongStarted);
}

void Playlist::next()
{
	// continue playing if currently playing

	if (songs[currentSong]->isPlaying())
	{
		songs[currentSong]->stop();
		songs[(++currentSong) %= songs.size()]->start();
		timeCurSongStarted = time(NULL);
		secondsLeftFromStart = songs[currentSong]->getLength();
	}
	else
	{
		(++currentSong) %= songs.size();;
	}
}

void Playlist::previous()
{
	// continue playing if currently playing

	if (songs[currentSong]->isPlaying())
	{
		songs[currentSong]->stop();
		songs[(--currentSong += songs.size()) %= songs.size()]->start();
		timeCurSongStarted = time(NULL);
		secondsLeftFromStart = songs[currentSong]->getLength();
	}
	else
	{
		(--currentSong += songs.size()) %= songs.size();
	}
}

char* Playlist::now_playing()
{
	char *str = new char[200];
	strcat_s(str, sizeof(songs[currentSong]->getSinger()) * sizeof(char), songs[currentSong]->getSinger());
	strcat_s(str, 3 * sizeof(char), " - ");
	strcat_s(str, sizeof(songs[currentSong]->getTitle()) * sizeof(char), songs[currentSong]->getTitle());
	return str;
}

void Playlist::add_song(Song *song)
{
	songs.push_back(song);
}

void Playlist::erase_song(int index)
{
	if (songs[currentSong]->isPlaying())
		songs[currentSong]->stop();
	songs.erase(songs.begin() + index, songs.begin() + index + 1);

	// current song is now the next song in the list so it could be the first one
	currentSong %= songs.size();
}

int Playlist::total_playtime()
{
	int cnt = songs.size();
	int totalLength = 0;
	for (int i = 0; i < cnt; i++)
		totalLength += (songs[i]->getLength());
	return totalLength;
}

void Playlist::shuffle()
{
	int cnt = songs.size();
	for (int i = 0; i < cnt-1; i++)
	{
		Song *t;
		int randInd = rand() % (cnt - i);
		t = songs[i];
		songs[i] = songs[i + randInd];
		songs[i + randInd] = t;
	}
}

int Playlist::left()
{
	return (songs[currentSong]->isPlaying) ? secondsLeftFromStart - (time(NULL) - timeCurSongStarted) : secondsLeftFromStart;
}
