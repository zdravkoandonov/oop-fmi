#pragma once
class Song
{
	char *title;
	char *singer;
	char *album;
	char *genre;
	int length;
	int format;
	bool playing;
	int timesPlayed;
public:
	Song(char *title);
	~Song();

	virtual void start() = 0;
	virtual void stop();
	virtual void play();
	virtual void pause();
	virtual void toggle_play();
	int times_played();
	bool isPlaying();
	char* getTitle();
	char* getSinger();
	char* getAlbum();
	char* getGenre();
	int getLength();
	int getFormat();
};

