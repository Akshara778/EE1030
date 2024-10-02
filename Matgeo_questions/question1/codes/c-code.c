#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "libs/matfun.h"
#include "libs/geofun.h"

void points(FILE *fptr, double **a, double **b, int num_points) {
	for (int i = 0; i <= num_points; i++) {
		double temp = (double)i/(double)num_points;
        	double **output = Matadd(Matscale(a,2,1,1-temp),Matscale(b,2,1,temp),2,1);
		printf("%lf,%lf\n",output[0][0],output[1][0]);
		fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        	freeMat(output,2);
	}
}
int main() {
    	double x1,y1,x2,y2,x3,y3;
    	x1 = 1; 
    	y1 = 3;
    	x2 = 4; 
    	y2 = 5;
	x3 = -3.5;
	y3 = 0;
    	int m = 2, n = 1;
    	double **A = createMat(m,n);
    	double **B = createMat(m,n);
	double **P = createMat(m,n);
    	A[0][0] = x1;
    	A[1][0] = y1;
    	B[0][0] = x2;
    	B[1][0] = y2;
	P[0][0] = x3;
	P[1][0] = y3;
    	FILE *fptr;
    	fptr = fopen("points.txt", "w");
    	if (fptr == NULL) {
        	printf("Error opening file!\n");
        	return 1;
    	}
	points(fptr, A,B ,20);
	points(fptr,P,A,20);
    	fclose(fptr);
    	return 0;
}
