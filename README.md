# Cpp-Mini-Project
Mini Project for C++ Summer Course 2024

## Project statement: 
- Creating an audio application inorder to randomly generate and play a melody.

## C++ and OOP concepts:
- Data Abstraction
- Encapsulation
- Inheritance
- Polymosphism

### Particulars:
- Function overloading
- Namespace
- Access Specifiers
- Objects
- Classes

# How to execute:

The following command compiles ```main.cpp```
```
g++ main.cpp -lsfml-audio -lsfml-system
```
After compilation, run the ```a.out``` file:
```
./a.out
```

# Explanation:

### sound.h

```sound.h``` is a header file that contains mathematical functions such as the generation of the the sin wave.

It also includes some of its attributes such as the cycles, amplitude and time.

### main.cpp

```main.cpp``` consists of the ```main()``` function as well as all functions to be used in the project such as the generation of the random frequencies ```get_freq()``` and the playback of the sin wave ```gen_wave(double freq)```.

### Headers:

- ```SFML/Audio.hpp```	-> main header for audio operations
- ```vector```		-> to store the current samples
- ```sound.h```		-> to define a sin wave
- ```time.h```		-> used for delay
- ```chrono```		-> used for delay
- ```thread```		-> used for delay

### get_freq():

```const double soun_freqs[14]``` contains the soundset used for the generator.

It includes a two octave soundset including the following music notes:
A3 B3 C4 D4 E4 F4 G4 A4 B4 C5 D5 E5 F5 G5

```get_freq()``` obtains a random number within the index range of the soundset (here from 0 to 13) and uses the index to return a random frequency from it.

### gen_wave(double freq):

Takes in the random frequency value generated from ```get_freq()``` and used it in order to generate the sound sample using the sin wave obtained from ```sound.h```.

It then loads the sample into a buffer, which is played back using ```sound1.play```

### main():

The user is asked for the number of notes they would like in their melody and then the functions ```get_freq()``` and ```gen_wave``` is called in a loop based on the number of notes the user has given.
