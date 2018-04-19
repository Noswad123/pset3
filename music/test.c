#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int frequency(string note);
int getIndex(string note);

int main(void)
{

  /*  printf("A4: %i\n",frequency("A4"));
    printf("B4: %i\n",frequency("B4"));
    */

    printf("Gb4: %i\n",frequency("Gb4"));
    printf("G#4: %i\n",frequency("G#4"));
    /*printf("G4: %i\n",frequency("G4"));
    printf("G4: %i\n",frequency("G4"));
    printf("G4: %i\n",frequency("G4"));
*/
}

int frequency(string note)
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

int getIndex(string note)
{
    const int noteOrder[] = {'A','X','G','X','F','E','X','D', 'X','C'}; //X is a place holder for the accidentals

    for(int i = 0, length = sizeof(noteOrder)/sizeof(noteOrder[0]); i < length; i++)
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
