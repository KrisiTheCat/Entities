#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::init()
{
	fstream stream;

	string tmp, background, slice, bomb;

	stream.open(SOUND_FOLDER + "music.txt");

	stream >> tmp >> background;
	stream >> tmp >> slice;
	stream >> tmp >> bomb;

	stream.close();

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}

	m_backgroundMusic = Mix_LoadWAV((SOUND_FOLDER + background).c_str());
	m_sliceSound = Mix_LoadWAV((SOUND_FOLDER + slice).c_str());
	m_bombExplosionSound = Mix_LoadWAV((SOUND_FOLDER + bomb).c_str());

	playSound(SOUND::BACKGROUND);
}

void SoundManager::playSound(SOUND sound)
{
	Mix_AllocateChannels(5);

	switch (sound)
	{
	case SOUND::BACKGROUND:
		Mix_PlayChannel(1, m_backgroundMusic, -1);
		Mix_Volume(1, 10);
		break;
	case SOUND::SLICE_MUSIC:
		Mix_PlayChannel(2, m_sliceSound, 0);
		Mix_Volume(2, 10);
		break;
	case SOUND::BOMB_EXPLOSION:
		Mix_PlayChannel(3, m_bombExplosionSound, 0);
		Mix_Volume(3, 10);
		break;
	default:
		break;
	}
}

void SoundManager::destroy()
{
	Mix_FreeChunk(m_backgroundMusic);
	m_backgroundMusic = NULL;

	Mix_FreeChunk(m_sliceSound);
	m_sliceSound = NULL;

	Mix_FreeChunk(m_bombExplosionSound);
	m_bombExplosionSound = NULL;
}