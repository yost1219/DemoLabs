/*
Author: Yost
Title: Demo Lab 6
Date: 16 July 2018
*/


///////////////////////////////////////////////////////////////////////////////
/////////////////////////DEMONSTRATION LAB I.1.g-6 ////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Input a uint32_t
// Drop the four right-most bits off the uint32_t using a Bitwise Shift Right
// Replace the four left-most bits of the uint32_t with the dropped bits
// Print the I/O in uppercase Hexadecimal, field width 8, leading zeros
///////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>
#define solution2 // This source file contains four solutions to the given Demonstration Lab
#ifdef solution3
#include <math.h>
#endif


int main (void)
{
    uint32_t input = 0, number = 0, tnumber = 0;
    printf ("Input a number: ");
    scanf ("%u", &input);
    printf ("Your number is: %u\n", input);
    printf ("Your number represented in hexadecimal is: 0x%08X\n", input); //automatically converts decimal input to hexadecimal output

/*
    //SOLUTION 1
    tnumber = input;
    number = input >> 4; //shifts right 4 binary numbers or 1 hexadecimal number
    tnumber = (input << ((sizeof(tnumber) * 8) - 4)); //transports the 4 cut-off digits from above to the left of the new number
    number = number | tnumber;
*/
/*
    //SOLUTION 2
    tnumber = input & 0x0000000F; //ands the input by binary 1111 to get the last 4 of the input
    tnumber = tnumber << ((sizeof(tnumber) * 8) - 4); //shifts the last 4 all the way to the left
    input = input >> 4; //shifts input right, cutting off 4 digits
    number = input | tnumber;
*/
/*
    //SOLUTION 3
    tnumber = input & 0x0000000F; //ands the input by binary 1111 to get the last 4 of the input
    tnumber = tnumber * 268435456; //multiplies temp by 2^28 to slide number all the way to the left (32 total digits - sliding right 4 = 28)
    input = input >> 4; //shifts input right 4 digits
    number = input | tnumber;
*/
/*
    //SOLUTION 4
    number = (input >> 4) | (input << ((sizeof (input) * 8) - 4)); //puts all of the steps above into one line; shifts input 4 right then ORs that with input shifted 28 left
*/

    printf ("Your new number is: 0x%08X\n", number);

    return 0;
}