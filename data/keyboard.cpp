#include <iostream>  //for cout and general IO
#include <fstream>   //for using Files
#include <math.h>    //for mathematical functions
#include <stdlib.h>  //for random variable generator
#define IP 52.8		 // Performance Index
#define max_size 6   // Size of Keyboard Space
using namespace std;
int iterator_1 = 60000;   //No. of iterations for optimization.
char dnt[27];			//Array for keys, which have not to be touched.
int dnt_counter = 0;	
char keyboard[max_size][max_size];		//Keyboard space for Optimization
char lowest[max_size][max_size];		//Optimized KeyBoard Layout
double lowest_energy = 0.00;			//Lowest Energy Level
double energy = 0.00;					//Current Energy Level
double prev_energy = 0.00;				//Previous Energy Level
char keyset[27] = {'.','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};		//Given Keyset
int prob[27][27] = {4009,21745,9578,9269,7650,3973,6532,6755,10090,17781,2193,2323,5576,9862,5798,10647,6528,473,4274,12637,28897,2468,1107,14233,116,6056,75,
		                7498,465,1809,2574,2828,95,402,1543,1653,2545,100,1584,7926,2721,17032,71,1150,7,8083,6395,12701,1425,2409,539,87,2854,399,
		                245,1810,290,34,115,5033,8,9,10,1338,145,4,1831,7,30,2337,6,0,895,257,99,1994,71,24,0,696,10,
		                777,4074,15,446,46,3020,2,9,5429,1316,3,2494,829,8,12,3576,13,6,1083,481,1771,688,3,0,0,186,26,
		                14705,1610,34,108,305,4356,48,213,51,2814,14,3,228,130,520,4263,6,5,749,1038,27,758,50,27,1,582,15,
		                34370,6619,426,2027,5349,3716,990,620,1038,1683,49,342,5488,2220,7562,1049,958,96,13449,8729,3606,181,2544,1036,1313,2232,106,
		                5784,1597,0,6,20,1523,1122,89,2,1546,3,15,405,15,9,2872,1,0,1444,64,375,1046,0,2,9,70,0,
		                5761,1275,12,5,60,2665,13,294,1875,2153,4,4,546,59,292,3949,0,1,1184,567,43,1108,4,8,0,181,1,
		                4624,12788,52,33,37,21947,22,9,414,7138,6,26,57,234,342,4669,12,3,1041,117,1359,1137,13,48,8,775,0,
		                6295,1759,687,4239,2615,3136,2381,2018,35,410,16,1141,3110,2719,16266,3034,633,93,2734,9766,9615,86,1543,27,106,42,203,
		                51,486,3,11,2,1098,0,5,7,38,16,8,0,0,5,596,3,0,18,9,11,1072,169,18,0,0,0,
		                2491,701,17,6,11,3063,15,14,381,2009,169,21,86,13,1171,300,10,0,80,944,63,72,5,50,0,203,0,
		                5774,3227,230,165,2253,6082,542,144,17,5395,1,543,7169,143,27,4721,214,0,150,1510,429,726,182,175,0,3350,92,
		                4209,4265,412,74,60,7113,28,13,16,1812,1,10,61,1022,219,2506,876,0,31,1145,54,1037,0,8,1,1208,1,
		                12907,3055,77,1760,7938,5569,265,7641,43,2349,97,1359,616,75,1453,6352,551,19,108,2360,5478,448,180,37,28,2539,21,
		                10884,282,794,1164,3161,863,4755,630,983,974,95,1122,3200,4208,11489,4163,1896,0,8040,2002,4866,11567,1130,3698,115,327,80,
		                1205,1441,12,20,6,3161,12,8,708,1724,2,13,2029,46,2,1902,935,0,1911,567,598,581,1,0,1,153,0,
		                10,8,2,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,768,1,2,0,0,0,
		                8898,3884,310,750,1500,13277,210,727,100,4628,11,646,1229,51,909,4490,234,1,901,2702,1991,1387,267,133,10,1947,0,
		                22762,3168,111,934,57,6075,58,647,2816,2744,11,354,595,634,616,3901,1177,30,52,2298,8368,2183,17,312,5,357,10,
		                23464,3453,60,457,45,6273,48,61,25793,6133,13,12,677,107,92,8430,87,2,2334,2391,1605,1493,49,326,7,12638,38,
		                4320,686,391,1247,713,1016,411,1001,174,591,19,197,2667,946,2631,137,1182,2,3885,5087,4058,98,11,10,32,492,69,
		                310,474,6,7,2,7300,1,5,5,1583,0,0,8,3,9,489,0,0,7,16,8,7,2,0,0,10,0,
		                2298,4759,94,3,21,3235,18,7,4332,3350,5,9,138,7,570,2410,5,0,382,365,34,73,1,242,0,19,1,
		                251,234,0,114,6,125,1,2,5,330,0,1,6,0,0,17,250,0,2,7,197,42,0,3,88,91,0,
		                11413,514,272,68,25,1784,101,118,35,406,1,82,66,147,61,6542,127,1,82,935,401,182,2,130,1,131,19,
		                191,94,0,0,3,227,0,1,2,124,0,34,6,2,5,55,0,0,1,2,3,27,0,1,0,96,132};			//Probability Table
double search(char a, char b)																		//Function to find Distance between Keys
{
	//cout<<"FINDING DISTANCE"<<'\n';
	int a_x,a_y,b_x,b_y;
	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; ++j)								//2D linear Search
		{
			if(keyboard[i][j] == a)
			{
				a_x = i;
				a_y = j;
			}
			else if(keyboard[i][j] == b)
			{
				b_x = i;
				b_y = j;
			}
		}
	}
	double distance = pow(b_x-a_x,2) + pow(b_y-a_y,2);
	distance = sqrt(distance);
	//cout<<"DISTANCE FOUND"<<'\n';
	return distance;
}
char shifter()		//Randomly changing layout for optimization
{
		//cout<<"SHIFTING LETTERS"<<'\n';
		if (dnt_counter == 27)
		{
			return '1';
		}
		retake:
		int a  = rand()%27;
		char change = keyset[a];
		for (int i = 0; i < 27; i++)
		{
			if(change == dnt[i])
			{
				goto retake;
			}
		}
		int change_x,change_y;
		for (int i = 0; i < max_size; i++)
		{
			for (int j = 0; j < max_size; ++j)
			{
				if(keyboard[i][j] == change)
				{
					change_x = i;
					change_y = j;
				}
			}
		}
		shiftnow:
		int shift_x;
		int shift_y;
		shift_x = rand()%3 + change_x - 1;
		shift_y = rand()%3 + change_y - 1;        //Kernel Initialization
		if (shift_x>=0 && shift_y>=0 && shift_x<=(max_size-1) && shift_y<= (max_size-1))  //Shiftimg in Action
		{
			if (keyboard[shift_x][shift_y]!='0')
			{
				char a = keyboard[shift_x][shift_y];
				keyboard[shift_x][shift_y] = keyboard[change_x][change_y];
				keyboard[change_x][change_y] = a;

			}

			else
			{
				keyboard[shift_x][shift_y] = keyset[a];
				keyboard[change_x][change_y] = '0';
			}
		}
		else
		{
			goto shiftnow;
		}
		//cout<<"LETTERS CHANGED"<<'\n';
		return change;
}
void save()			//function to save keyboard Layout
{
	//cout<<"SAVING KEYBOARD LAYOUT"<<'\n';
	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
		{
			lowest[i][j] = keyboard[i][j];
			//f1<<lowest[i][j]<<"  ";
		} 
		//cout<<'\n';
	}
}
double calc_energy()		//function to calculate Energy Level
{
	//cout<<" CALCULATING ENEGRY"<<'\n';
	double energy = 0.00;
	for (int i = 0; i < 27; ++i)
	{
		char first = keyset[i];
		for (int j = 0; j < 27; ++j)
		{
			char second = keyset[j];
			float dist = search(first,second);
			energy += (prob[i][j]/IP)*(log2(1+(dist/0.5))); //Using Fitts Function
		}
	}
	return energy;	
	//cout<<" ENERGY CALCULATED"<<'\n';
}
void branch(char dnt[],double ene)     //Branching in case of Local Minima
{

	if (dnt_counter >= 27)
	{
		return;
	}								//Break COndition
	prev_energy = ene;
	for (int i = 0; i <= iterator_1; ++i)
	{
		//shifting randomly
		char letter = shifter();
		energy = calc_energy();	
		if (energy - prev_energy <= 0)			//If moving towards Minima
		{
			//cout<<"COMPUTING IN BRANCH MAIN"<<'\n';
			if ( lowest_energy>energy)
			{
				lowest_energy = energy;
				save();	
			}
			else
			{

			}
			
		}
		else if (energy - prev_energy > 0)		//If moving Away from Minima
		{
			//cout<<"COMPUTING IN BRANCH BRANCH"<<'\n';
			dnt[dnt_counter] = letter;
			dnt_counter++; 
			branch(dnt,energy);
			for (int i = 0; i < 27; ++i)
			{
 				dnt[i] = '1';
			}
		}
		prev_energy  = energy;
	}
	return;
}
int main()
{
	
	srand(time(NULL));		//Seeding Random Generator
	fstream f, f1;			//Files for I/O
	f1.open("Original.txt",ios::out);
	f.open("ANSWER.txt",ios::out);
	for (int i = 0; i<max_size; i++)
		for (int j = 0; j<max_size; j++)
		{
			keyboard[i][j] = '0';
			lowest[i][j] = '0';
		}
	for (int i = 0; i < 27; ++i)		// Randomly Selecting Layout
	{
		regenerate:
		int l = rand()%max_size;
		int m = rand()%max_size;
		if (keyboard[l][m]!='0')
		{
			goto regenerate;
		}
		keyboard[l][m] = keyset[i];
		cout<<keyset[i]<<"     @   ("<<l<<"    ,    "<<m<<")"<<'\n';
	}
	for (int i = 0; i < max_size; i++)			//Saving Unoptimized Keyboard
	{
		for (int j = 0; j< 6; j++)
		{
			f1<<keyboard[i][j]<<"   ";
		}
		f1<<'\n';
	}
	prev_energy = calc_energy();
	for (int i = 0; i <= iterator_1; ++i) 		//Optimization Loop
	{
		//shifting randomly
		char letter = shifter();
		energy = calc_energy();	
		if (energy - prev_energy <= 0)			//Moving Towards Minima
		{
			if (energy<= lowest_energy)
			{
				lowest_energy = energy;
				save();
			}
			else
			{

			}
			//cout<<"COMPUTING IN MAIN"<<'\n';
			//continue;
		}
		else if (energy - prev_energy > 0)		//Moving Away from Minima
		{
			//cout<<"GOING IN BRANCH"<<'\n';
			dnt[dnt_counter] = letter;
			dnt_counter++; 
			branch(dnt,energy);
			for (int i = 0; i < 27; ++i)
			{
 				dnt[i] = '1';
			}
			//cout<<"OUT OF BRANCH"<<'\n';
		}
		prev_energy  = energy;
	}
	for (int i = 0; i < max_size; i++)   // Saving Output loop
	{
		for (int j = 0; j< max_size; j++)
		{
			if (lowest[i][j] == '0')
			{
				f<<" ";
			}
			else
				f<<lowest[i][j]<<" ";
		}
		f<<'\n';
	}
	cout<<" THE OPTIMIZED(PARTIALLY) KeyBoard has been stored in \"Answer.txt\". Please open to see output"<<'\n';
	f.close();
	f1.close(); //Closing Files
} //EOP
