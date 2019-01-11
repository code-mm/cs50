// Helper functions for music

#include <cs50.h>

#include "helpers.h"

#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
	int numerator = (int) fraction[0] - 48;
	int denominator = (int) fraction[2] - 48;

    if (denominator == 8)
    {
    	return numerator;
    }

    while (denominator < 8)
    {
    	numerator *= 2;
    	denominator *= 2;
    }

	return numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
	/*
	 * analyze note
	 */
	int octave = 0;
	char semitone = 0;
	bool sharp = false;
	bool flat = false;

    if (strlen(note) == 2)
    {
    	octave = (int) note[1] - 48;
    	semitone = note[0];
    }
    else
    {
    	octave = (int) note[2] - 48;
    	semitone = note[0];
    	if ((note[1]) == '#')
    	{
    		sharp = true;
    	}
    	else
    	{
    		flat = true;
    	}
    }

    /*
     * calculate frequency
     */
    double frequency = 440.0; // initialized with frequency of A4

    // octave
    if (octave > 4) {
    	for (int i = octave - 4; i > 0; i--) {
    		frequency = frequency * 2;
    	}
    }

    if (octave < 4) {
    	for (int i = 4 - octave; i > 0; i--) {
    		frequency = frequency / 2;
    	}
    }

    // semitone
    if (semitone == 'B')
    {
    	frequency = frequency * pow(2.0, 2.0/12.0);
    }

    if (semitone == 'C')
    {
    	frequency = frequency * pow(2.0, -9.0/12.0);
    }

    if (semitone == 'D')
    {
    	frequency = frequency * pow(2.0, -7.0/12.0);
    }

    if (semitone == 'E')
    {
    	frequency = frequency * pow(2.0, -5.0/12.0);
    }

    if (semitone == 'F')
    {
    	frequency = frequency * pow(2.0, -4.0/12.0);
    }

    if (semitone == 'G')
    {
    	frequency = frequency * pow(2.0, -2.0/12.0);
    }

    // sharp
    if (sharp) {
    	frequency = frequency * pow(2.0, 1.0/12.0);
    }

    // flat
    if (flat) {
    	frequency = frequency * pow(2.0, -1.0/12.0);
    }

    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
    	return true;
    }

    return false;
}
