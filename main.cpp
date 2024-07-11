/* 
 * Date: July 11, 2024
 * Name: Justin Carvalho
 * Topic: C++ Mini Project for C++ Summer Course
 *
 * Problem statement:
 *
 * Program in C++ using OOP concepts to randomly generate a musical melody, 
 * based on the number of notes given by the user.
 *
 * Concepts used:
 * 
 * Polymorphism:
 * 1) Function overloading
 * 2) Reference Variable
 *
 * Abstraction:
 * 1) Default parameters
 * 2) Inline function
 * 3) Default Constructor and Deconstructor
 *
 * Encapsulation:
 * 1) Class and objects
 *
 * Inheritance:
 * 1) Derived class
 *
 *
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
#include	<string>

using namespace std;

class SOUNDSETS {					/* Class and object */

	public:

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

		const string notes[14] = {
			"A3",
			"B3",
			"C4",
			"D4",
			"E4",
			"F4",
			"G4",
			"A4",
			"B4",
			"C5",
			"D5",
			"E5",
			"F5",
			"G5"
		};

		SOUNDSETS()			/* Constructor and destructor */
		{
			cout<<"Default Constructor called"<<endl;
		}

		~SOUNDSETS(){cout <<"Destructor called: "<<this<<endl;}
};

SOUNDSETS snd;

sf::SoundBuffer buffer;
sf::Sound sound1;

class FUNCS:public SOUNDSETS {				/* Inheritance */

	public:

		inline int get_freq()			/* Inline Function */
		{
			int index = rand() % 14;  
			// generates random number between 0 and 13
			return index;
		}

		int get_freq(double freq)	/* Function Overloading */
		{
			for ( int i = 0; i < 14; i++ ) {
				if (sound_freqs[i] == freq) {
				return i;
				break;
			}
		}
		cout<<"The frequency entered does not exist in the sound set. Playing default frequency:"<<endl;
		return 0;
	}

	void gen_wave(double freq = 440, int j = 0)	/* Default parameter */
	{
		vector<sf::Int16> samples;
	
		for (int i = 0; i < 44100; i++) {
	                samples.push_back(sound::SineWave(i, freq, 0.9));
	                        // time, frequency, amplitude
		}
		
		buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
	
		sound1.setBuffer(buffer);
		cout<<"Frequency playing: "<<notes[j]<<"\t"<<freq<<endl;
		sound1.play();
		this_thread::sleep_for(chrono::seconds(1));
		sound1.stop();
	}
};

int main()
{
	FUNCS fun;

	int n, i;
	double freq;
	double &freq2 = freq;
	string note;

	srand (time(NULL));	// initilize the random seed
	
	//to playback a single frequency by choice from the soundset
	cout<<"Enter the frequecy to play:"<<endl;
	cin>>freq2;					/* Reference Variable */
	i = fun.get_freq(freq2);
	freq = snd.sound_freqs[i];
	fun.gen_wave(freq, i);


	//function to ask user for the number of notes in the melody
	cout<<"Enter number of notes to be played in the melody:"<<endl;
	cin>>n;

	// start loop based on number of frequecies
	while (n > 0) {

		//function to generate random frequencies
		i = fun.get_freq();
		freq = snd.sound_freqs[i];
		
		//function to generate the sin wave for the frequecies and play
		//back
		fun.gen_wave(freq, i);

		n--;
	}

	return 0;
}
