// Helper functions for music
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"


int duration(string fraction)       // Converts a fraction formatted as X/Y to eighths
{
    string tmp = &fraction[2];     //used to temporarily hold numerator and denominator whilst trying to separate them
    int denominator = atoi(tmp);
    tmp = &fraction[0];
    int numerator = atoi(tmp);
   return (8/denominator)*numerator;

}

int frequency(string note) // frequency pitch for each string note JE
{
    int octave;
    int octaveDistance;
    int distanceFromA=0;

    if(note[1]=='#'||note[1]=='b')
    {
        if(note[1]=='#')
        {
                 distanceFromA++;
        }
        else
        {
                 distanceFromA--;
        }
        octave=note[2]-'0'; //you will find the octave as the 3rd char due to the accidental
    }
    else
    {
        octave=note[1]-'0';     //you will find the octave as the 2nd char
    }

    if (note[0]=='B')
    {
        distanceFromA +=2 ;
    }
    else{
        if(note[0]!='A'){
            distanceFromA += getIndex(note);
        }
    }

    octaveDistance=octave-4;
    //debugger comment printf("second exponent value %f\n",(1/12.0)*distanceFromA);
    //calculate hertz
    return round(440*exp2(octaveDistance)*exp2((1/12.0)*distanceFromA));
}

bool is_rest(string s)      // Determines whether a string represents a rest
{
//isspace(atoi(s) )

   if(!s[0])
    {printf("true: %s\n",s);
        return true;
    }
    else
    {printf("false: %s\n",s); // prints false: string je
        return false;
    }
}

int getIndex(string note)
{
    const int noteOrder[] = {'A','X','G','X','F','E','X','D', 'X','C'}; //X is a place holder for the accidentals

    for(int i = 0, length = sizeof(noteOrder)/sizeof(noteOrder[0]); i < length; i++) // for loop for note length je
    {
        // debugger comment printf("noteOrder: %c index value: %c\n", noteOrder[i], note[0]);
        //printf("length: %i\n", length);
        if(noteOrder[i]==note[0])
        {
            //debugger comment printf("note: %c index value: %i\n", i, note[0]);

            return -i;
        }

    }
    return 0;
}
// looks good
// style50 helpers.c indicates in need of stlying
// can use more comments
