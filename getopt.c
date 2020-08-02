#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Title: Lab 2
 * Semester: COP4338 - Spring 2021
 * Author Megan Jane Thompson
 *
 * I affirm that the revisions of this program is entirely
 * my own work and none of it is the work of any other person.
 *
 * This program extracts the flag values from the command line
 * prompt and calls minicalc to complete the calculations.
 */
float miniCalc(int xflag, int mflag, int mNum, int dflag, int dNum, int aflag, int aNum, int sflag, int sNum, int value);
int debug = 0;

int main(int argc, char **argv){
	extern char *optarg;
	extern int optind;
	float finalValue = 0;
	int c, err=0, aNum=1, dNum=1, mNum=1, sNum=1, value=1;
	int aflag=0, dflag=0, mflag=0, sflag=0, xflag=0;
	static char usage[] = "usage: minicalc [-a num] [-d num] [-m num] [-s num] [-x] value\n";

	//loop to check for flags and set corresponding values from command line prompt
	while ((c = getopt(argc, argv, "a:d:m:s:x")) != -1){
		switch (c) {
		case 'a':
			aflag = 1;
			aNum = atoi(optarg);
			break;
		case 'd':
			dflag = 1;
			dNum = atoi(optarg);
			break;
		case 'm':
			mflag = 1;
			mNum = atoi(optarg);
			break;
		case 's':
			sflag = 1;
			sNum = atoi(optarg);
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
		}
	}

	if ((optind+1) > argc) {                 //need one argument
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s %s\n", "Missing Start Value", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	else if (err) {                          //general error
		fprintf(stderr, "%s %s %s", "General Error.", usage, argv[0]);
		exit(1);
	}
	else if (value < 1 || value > 50) {      //checks value constraints
		fprintf(stderr, "%s %s %s", "Start Value to be Between 1 and 50, Inclusive.", usage, argv[0]);
		exit(1);
	}
	else if (mNum < 1 || mNum > 5) {        //checks mNum constraints
		fprintf(stderr, "%s %s %s", "-m Value to be Between 1 and 5, Inclusive.", usage, argv[0]);
		exit(1);
	}
	else if (dNum < 1 || dNum > 5) {        //checks dNum constraints
		fprintf(stderr, "%s %s %s", "-d Value to be Between 1 and 5, Inclusive.", usage, argv[0]);
		exit(1);
	}
	else if (aNum < 1 || aNum > 500) {      //checks aNum constraints
		fprintf(stderr, "%s %s %s", "-n Value to be Between 1 and 500, Inclusive.", usage, argv[0]);
		exit(1);
	}
	else if (sNum < 1 || sNum > 500) {      //checks sNum constraints
		fprintf(stderr, "%s %s %s", "-s Value to be Between 1 and 500, Inclusive.", usage, argv[0]);
		exit(1);
	}

	// these are the arguments after the command-line options
	if (optind < argc){
		for (; optind < argc; optind++)
			value = atoi(argv[optind]);     //sets starting value
	}
	else {
		printf("No arguments left to process\n");
	}


	//call to obtain calculation pertaining to flags and values entered at command line
	finalValue = miniCalc(xflag, mflag, mNum, dflag, dNum, aflag, aNum, sflag, sNum, value);
	printf("Final value is: %.2f\n", finalValue);     //prints the final calculated value

	exit(0);
}

