/*

The challenge is: generate an audio file made of white noise.

Requirements and instructions:

    Your program must generate an audio file containing only white noise, meaning its intensity is the same for all (reasonable) frequencies and nonzero [see an example plot];
    One must be able to play the audio file on the latest version of VLC [at the time of writing your answer];
    The program doesn't need cryptographically-strong randomness, rand functions or reading from /dev/rand is okay;
    The program must be able to generate at least 1 hour of audio, at least in theory (meaning system limitations like maximum filesize don't apply);
    Your score is the number of bytes in your source code, plus all bonuses that apply;
    Using any third-party, external library is okay;
    The program must work without access to the Internet.

Bonuses are:

    -15%: Allow to specify the format of the audio file (at least two choices; the number of possible choices doesn't change the score);
    -10%: Allow to specify the duration of the audio file;
    -5%: Allow to specify the bitrate of the audio file.

The settings can be stored in variables, files, or given as command line parameters, your choice. Percentages are calculated from the original number of bytes, before any bonus is applied.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <SDL.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

SDL_AudioSpec
initsdl(void)
{
	SDL_AudioSpec spec = {
	    .freq = 48000,
	    .channels = 2,
	    .format = AUDIO_S16LSB,
	    .samples = 4096,
	};
	SDL_AudioSpec obtained;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	if (SDL_OpenAudio(&spec, &obtained) < 0)
		fatal("Failed to open audio device");

	SDL_PauseAudio(0);
	return obtained;
}

void
info(SDL_AudioSpec *s)
{
	printf("frequency %d\n", s->freq);
	printf("channels  %d\n", s->channels);
	printf("samples   %d\n", s->samples);
}

void
fill(SDL_AudioSpec *s, uint8_t *b, size_t n)
{
	size_t i, j;
	uint16_t v;
	uint8_t *p;

	p = b;
	i = 0;
	for (;;) {
		v = rand() & 0xffff;
		for (j = 0; j < s->channels; j++) {
			if (i + 2 >= n)
				return;

			p[0] = v & 0xff;
			p[1] = (v >> 8) & 0xff;
			p += 2;
			i += 2;
		}
	}
}

void
play(SDL_AudioSpec *s)
{
	uint8_t *samples;
	uint64_t last, now;
	double dt;
	int r;

	info(s);

	samples = calloc(1, s->size);
	if (!samples)
		return;

	SDL_Delay(50);
	SDL_QueueAudio(1, samples, s->size);

	last = 0;
	for (;;) {
		now = SDL_GetPerformanceCounter();
		dt = 1.0 * (now - last) / SDL_GetPerformanceFrequency();
		if (last == 0 || dt >= (s->samples * 1.0 / s->freq)) {
			last = now;
			fill(s, samples, s->size);
			r = SDL_QueueAudio(1, samples, s->size);
			if (r != 0)
				printf("Queue Audio: %s\n", SDL_GetError());
		}
	}
	free(samples);
}

int
main(void)
{
	SDL_AudioSpec s;

	srand(time(NULL));
	s = initsdl();
	play(&s);
	return 0;
}
