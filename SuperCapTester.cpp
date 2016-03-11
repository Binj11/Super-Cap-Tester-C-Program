#include <stdio.h>
#include <math.h>
#define Tao 0.632
int main(){
	printf("\nThis is how far I have got on the C-Program for the Super-Cap Tester Project\n\n");
	FILE *fpointer; 
	fpointer=fopen("four20.txt", "r"); /*Using this method because I am using a program called CoolTerm
	                                    to export the arduino serial printout directly into a text file*/
	int line=0;
	char input[10];
    float inputfloat;
    float d=1023;
	float t=5;
	float p;
	
    while (fgets(input, 8, fpointer)){
	line++;
	int assigned =sscanf(input, "%f",&inputfloat);
	printf("Line# %d Sensor Values: %4.0f\n",line,inputfloat);
	switch (line){
			    case 1:					
				float x=inputfloat;
				float v;
			    printf("x=%4.0f and the initial voltage is x / 1024 * 5V\n",x);
			    v=x/d*t;
			    p=x;
				printf("The initial voltage accross the cap: %4.3fV\n",v);
				break;
				}
	if (inputfloat<=p*Tao){printf("This is the line that the V drops 1 Tao\n\n");
	}
		}	
    printf("Where each line is represents 125mS\n");
    printf("We have successfully converted char string to integer!\n");
    printf("It is slow progress but I am gradually getting better at C Programing\n\n");
    printf("Peace\n");
    return (0);
	}
