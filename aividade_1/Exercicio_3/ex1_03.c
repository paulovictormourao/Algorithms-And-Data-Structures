/*

	Name: Paulo Victor Mourao
	Mat:  2215310043
	
	exercise 1.03
*/ 

#include <stdio.h>

int main(int argc, char** argv)
{
	int i;
	double grade, total = 0;
	
	
	for(i = 0; i < 4; i++)
	{
		
		scanf("%lf", &grade);
		total += grade;
		
	}
	printf("%.1f\n", total/4);

}
