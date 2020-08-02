#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Title: Lab 2
 * Semester: COP4338 - Spring 2021
 * Author Megan Jane Thompson
 *
 * I affirm that this program is entirely my own work
 * and none of it is the work of any other person.
 *
 * This program acts as a calculator based on
 * command line prompts.
 */
float miniCalc(int xflag, int mflag, int mVal, int dflag, int dVal, int aflag, int aVal, int sflag, int sVal, int startVal){
	float finalVal = startVal;              //initializes beginning value with startVal from getopt.c

	if(xflag == 1){                         //if xflag is present, calculate value^2
		finalVal = finalVal*finalVal;
	}
	if(mflag == 1){                         //if mflag is present, calculate finalVal * mVal
		finalVal = finalVal * mVal;
	}
	if(dflag == 1){                         //if dflag is present, calculate finalVal / dVal
		finalVal = finalVal / dVal;
	}
	if(aflag == 1){                         //if aflag is present, calculate finalVal + aVal
		finalVal = finalVal + aVal;
	}
	if(sflag == 1){                         //if sflag is present, calculate finalVal - sVal
		finalVal = finalVal - sVal;
	}

	return finalVal;                       //return calculated value
}

