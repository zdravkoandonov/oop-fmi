#pragma once
class Song
{
private:
	char *title;
	char *singer;
	char *album;
	char *genre;
	int length;
	bool started;
	bool playing;
	int timesPlayed;

protected:
	static const enum formatType { MPEG, FLAC };
	formatType format;

public:
	Song(char *title);
	~Song();

private:
	// disable copying	
	Song(const Song&);

public:
	virtual void start() = 0;
	virtual void stop();
	virtual void play();
	virtual void pause();
	virtual void toggle_play();
	int times_played();
	bool isPlaying();
	bool isStarted();
	char* getTitle();
	char* getSinger();
	char* getAlbum();
	char* getGenre();
	int getLength();
	int getFormat();
};

