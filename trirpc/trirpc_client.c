/*
 * This is a client program to classify triangles
 * It implements RPC.
 * Server runs on localhost
 */

#include "trirpc.h"
#include <stdio.h>
#include <rpc/rpc.h>

void
classify_1(char *host)
{
/* Client */
	CLIENT *clnt;
/* Variable Definitions */

	tri_type *result_1;
	triangle newTriangle;
	int a,b,c;
	int toexit =0;

/* Start Client */

#ifndef	DEBUG
	clnt = clnt_create (host, CLASSIFY, TRI_SERVER_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

/* User Input */
	printf("\n\n******************************************************************************\n\nWelcome! This Program Classifies Triangles and Calculates their area...\n");

	while (toexit !=1)
{
	printf("Please Enter the values of the sides of a triangle: \n");
	scanf("%d %d %d", &a, &b, &c);


/* Initialise user-defined triangle */

	newTriangle.x =a;
	newTriangle.y =b;
	newTriangle.z =c;

/* Call remote proceedure */

	result_1=class_tri_1(newTriangle, clnt);

/* Server returns result for output on client-side */

 if ( result_1->type ==1) 
{

			printf("Your triangle is an Equilateral Triangle. \n");
			printf("Area of your Equilateral Triangle is: %f\n\n", result_1->area);

			printf("Do you wish to exit? Reply with 1 for YES and 0 for NO\n");
			scanf("%d", &toexit);

			}


else if ( result_1->type ==2) 
{

			printf("You triangle is an Isoceles Triangle. \n");
			printf("Area of your Isoceles Triangle is: %f\n\n", result_1->area);

			printf("Do you wish to exit? Reply with 1 for YES and 0 for NO\n");
			scanf("%d", &toexit);

		}

else if ( result_1->type ==3)
{

			printf("Your triangle is a Scalene Triangle. \n");
			printf("Area of your Scalene Triangle is: %f\n\n", result_1->area);

			printf("Do you wish to exit? Reply with 1 for YES and 0 for NO\n");
			scanf("%d", &toexit);

	}
else 
{

			printf("ERROR! Input not a valid Triangle. \n");

			printf("Do you wish to exit? Reply with 1 for YES and 0 for NO\n");
			scanf("%d", &toexit);

			
		}
			
} /* End While */

	printf("\n\nEND OF PROGRAM.\n ******************GOODBYE****************\n\n");



#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	classify_1(host);
exit (0);
}
