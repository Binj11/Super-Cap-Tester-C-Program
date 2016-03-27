#include <stdio.h>
#include <math.h>
#define Tao 0.368
int main(){
	printf("\nIf this is the only line you see it is because there is no capacitor discharge data in the file\n\n");
	FILE *fpointer; 
	fpointer=fopen("capture.asc", "r"); /*Using this method because I am using a program called CoolTerm
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
				printf("The value of p on this line is: %f\n",p);
				break;}
					if (inputfloat<=p*Tao){
		printf("\nThe voltage droped one discharge time constanct on this line: %d\n\n",line);
		printf("Where each line represents 0.125 Seconds\n\n");
	    float stopper=inputfloat;
		float timeinSeconds=line*0.125;
		int loadresistanceOhms=150;
		printf("The time period for the voltage to drop one Tao is:%3.3f Seconds\n\n",timeinSeconds);
	    printf("Load Resistance: %d Ohms\n\n",loadresistanceOhms);
		printf("Capacitance = %3.3f Seconds / %d Ohms\n\n",timeinSeconds,loadresistanceOhms);
		float cValueinFarad=timeinSeconds/loadresistanceOhms;
       	printf("The capacitance is: %f Farad\n\n",cValueinFarad);
       	float cValueinuF=cValueinFarad*1000000;
       	printf("The value of the tested cap in microFarad is: %8.2f uF\n\n",cValueinuF);
       	if (inputfloat<=stopper){break;
		   }
		           }}   
	fopen("capture.asc","w");/*Clears data from file*/
    return (0);
	}
