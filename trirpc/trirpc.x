/** This is the RPC specification file for my program used to classify user-defined triangles on client computers

**/

struct triangle {  
	int x;		/* values of triangle edges */
	int y;
	int z;
};



struct tri_type {
	int type;	/* returns result to client */
	float area;
};



/* Server_side Program Implementation */

program CLASSIFY {
	version	TRI_SERVER_1
	{
		tri_type CLASS_TRI(triangle)=1; 		/* function prototypes */

	} =1; /* Version Number */

} =0x20141308;
