/*
 *
 */

#include	<iostream> 
#include	<SFML/Audio.hpp>
#include	<vector>
#include	"sound.h"
#include	<cstdlib>
#include	<time.h>
#include	<chrono>
#include	<thread>

using namespace std;

const double sound_freqs[14] = {
        220.00,
        246.94,
        261.63,
        293.66,
        329.63,
        349.23,
        392.00,
        440.00,
        493.88,
        523.25,
        587.33,
        659.26,
        698.46,
	783.99
};

sf::SoundBuffer buffer;
sf::Sound sound1;

double get_freq()
{
	int index = rand() % 14;  // generates random number between 0 and 13
	return sound_freqs[index];
}

void gen_wave(double freq)
{
	vector<sf::Int16> samples;

	for (int i = 0; i < 44100; i++) {
                samples.push_back(sound::SineWave(i, freq, 0.9));
                        // time, frequency, amplitude
	}
	
	buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);

	sound1.setBuffer(buffer);
	sound1.play();
	this_thread::sleep_for(chrono::seconds(1));
	sound1.stop();
	cout<<"Frequency playing: "<<freq<<endl;
}

int main()
{
	int n;
	double freq;

	srand (time(NULL));	// initilize the random seed

	//function to ask user for the number of notes in the melody
	cout<<"Enter number of notes to be played in the melody:"<<endl;
	cin>>n;

	// start loop based on number of frequecies
	while (n > 0) {

		//function to generate random frequencies
		freq = get_freq();
	
		//function to generate the sin wave for the frequecies and play
		//back
		gen_wave(freq);

		n--;
	}

	return 0;
}
