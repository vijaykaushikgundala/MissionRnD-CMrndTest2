/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>


char * find_common_route(char * hacklist, char *codelist, int *cost)
{
	int a[26];
	static char ch[26];
	int i, j, l = 0, k = 0, i1, j1, maxl = 0, c = 0, com1, com2;
	a[0] = 0;
	if (hacklist == NULL || codelist == NULL)
	{
		return NULL;
	}
	for (i = 0; hacklist[i] != '\0'; i++)
	{
		for (j = 0; codelist[j] != '\0'; j++)
		{
			if (hacklist[i] == codelist[j])
			{
				i1 = i;
				j1 = j;
				l = 0;
				while (hacklist[i1] == codelist[j1])
				{
					i1++;
					j1++;
					l++;
				}
				if (l >= maxl)
				{
					maxl = l;
					if (a[0] != 0)
					{
						com1 = hacklist[a[0]] - 'A' + 1;
						com2 = hacklist[i] - 'A' + 1;
						if (com1 > com2)
						{
							a[0] = i;
						}
					}
					else
					{
						a[0] = i;
					}
			    }
			}
		}
	}
	for (i = a[0]; i<a[0]+maxl; i++)
	{
		ch[i - a[0]] = hacklist[i];
		c = c + hacklist[i] - 'A'+1;
	}
	ch[i-a[0]] = '\0';
	*cost = c;
	return ch;
}

