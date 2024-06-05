#include<stdio.h>

struct Grade {
	int number;
	char name[30];
	int q1;
	int q2;
	int q3;
	int mt;
	int final;
	double avg;
};

int main(void){
	struct Grade student;

	FILE *rPtr;
	
	if((rPtr=fopen("students.dat","r"))==NULL)
		printf("file could not be opened\n");
	else{
		fscanf(rPtr,"%d%s%d%d%d%d%d%lf",&student.number,&student.name,&student.q1,&student.q2,&student.q3,&student.mt,&student.final,&student.avg);
		while(!feof(rPtr)){
			printf("%d %s %d %d %d %d %d %lf\n",student.number,student.name,student.q1,student.q2,student.q3,student.mt,student.final,student.avg);
			fscanf(rPtr,"%d%s%d%d%d%d%d%lf",&student.number,&student.name,&student.q1,&student.q2,&student.q3,&student.mt,&student.final,&student.avg);
		
		}
		fclose(rPtr);
	}
	return 0;
}
