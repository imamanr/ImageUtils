#include <stdio.h>
#include <stdlib.h>

#define INPUT_NUM_ROW 18
#define INPUT_NUM_COL 24
#define OUTPUT_NUM_ROW 9 /* Fill you code here */
#define OUTPUT_NUM_COL 12 /* Fill you code here */



void decimate( unsigned char * pixels,unsigned char * dest ) {


    int index=0 ;
    unsigned char* temp;
    unsigned char * ddest;
    unsigned char temp2;

    ddest = dest;
    temp = pixels;

    float x_ratio = ((float)(INPUT_NUM_COL-1))/OUTPUT_NUM_COL ;
    float y_ratio = 0 ;
    int i = 0;
    int j = 0;
    for (i=0;i<OUTPUT_NUM_ROW;i++) {

        for (j=0;j<OUTPUT_NUM_COL;j++) {
            index = (int) (y_ratio*INPUT_NUM_COL + x_ratio);
            temp += index;
            temp2 =*temp;
            *ddest = temp2;
            ddest ++;
            y_ratio = 0;
        }
        y_ratio = ((float)(INPUT_NUM_ROW-1))/OUTPUT_NUM_ROW;
    }
}


int main() {
	// Allocate memory for input and output arrays
	unsigned char* input = calloc( INPUT_NUM_COL*INPUT_NUM_ROW, sizeof(unsigned char));
    unsigned char * dest = calloc( OUTPUT_NUM_COL*OUTPUT_NUM_ROW, sizeof(unsigned char));
    // Intialize variables
    unsigned char min= 150;
    unsigned char max= 250;
    unsigned char r;
    int i = 0, j = 0;
    unsigned char * ini;
    ini = input;
    //Fill in the array with random ascii
    for(i=0; i<INPUT_NUM_COL*INPUT_NUM_ROW; i++) {
        int randm = rand();
    	r= randm % max + min;
        *ini = r;
        ini++;
    }
    
    decimate(input,dest);// function call for decimation

    // Printout arrays on the standard output device
    unsigned char * temp;
    temp = input;
    setvbuf (stdout, NULL, _IONBF, 0);
    printf("\n\n INPUT ARRARY \n");

    for(i=0; i<INPUT_NUM_ROW; i++) { //loop over row
    	for(j=0; j<INPUT_NUM_COL;j++){ //loop over cols
            printf("%c", temp[i+j*OUTPUT_NUM_COL]);
            temp++;
        }
    	printf("\n");
    }


    printf("\n\n OUTPUT ARRARY \n");

    temp = dest;

    for(i=0; i<OUTPUT_NUM_ROW; i++) {//loop over row
    	for(j=0; j<OUTPUT_NUM_COL;j++){//loop over cols
         printf("%c", temp[i+j*OUTPUT_NUM_COL]);
         temp++;
        }
    	printf("\n");
    }

    free(dest); // free the allocated memory for input
    free(input);// free the allocated memory for output

    return 0;
}
