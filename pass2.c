#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

void hex2binary(char*, FILE*);
void binary(char*, FILE*);


void binary(char* s , FILE *f4)
{

	int arr[16] ={0},i=15,k; k =atoi(s); ;
	while(k !=0)
	{
		arr[i]= k%2;
		k=k/2;
		i--;
	}
	int j;
	for(j=0;j<16;j++)
		fprintf(f4,"%d",arr[j]);
	fprintf(f4,"\n");
}

void hex2binary(char* arr, FILE *f4)
{

	int length = strlen(arr);

	if(arr[length -1] == 'H')
	{
		char arr1[4] ="0000"; int j,k;
		for(j=3,k=length -2;k>=0;j--,k--)
		{
			arr1[j]= arr[k];
		}
		int i=0;
		fprintf(f4,"\n");
		for(i=0;arr1[i] != '\0';i++)
		{

			switch(arr1[i])
			{

				case '0': fprintf(f4,"0000");
					break;
				case '1': fprintf(f4,"0001");
					break;
				case '2': fprintf(f4,"0010");
					break;
				case '3': fprintf(f4,"0011");
					break;
				case '4': fprintf(f4,"0100");
					break;
				case '5': fprintf(f4,"0101");
					break;
				case '6': fprintf(f4,"0110");
					break;
				case '7': fprintf(f4,"0111");
					break;
				case '8': fprintf(f4,"1000");
					break;
				case '9': fprintf(f4,"1001");
					break;
				case 'a':
				case 'A': fprintf(f4,"1010");
					break;
				case 'b':
				case 'B':fprintf(f4,"1011");
					break;
				case 'c':
				case 'C':fprintf(f4,"1100");
					break;
				case 'd':
				case 'D':fprintf(f4,"1101");
					break;
				case 'e':
				case 'E': fprintf(f4,"1110");
					break;
				case 'f':
				case 'F': fprintf(f4,"1111");
					break;
			}}
		}
	}
main()
{
        char inp[size],des[size],sym[size];
        printf("Enter the source file Name:");
        scanf("%s",inp);
        printf("Enter the symbol file Name:");
        scanf("%s",sym);
        printf("Enter the designation file Name:");
        scanf("%s",des);
        
	FILE *f1 ,*f2, *f3 , *f4;
	f1 = fopen(inp , "r");
	f2 = fopen(sym, "r");
	f3 = fopen("opcode.txt", "r");
	f4 = fopen(des, "w");


	char ch , sh , c , c1;
	char arr[17] , arr1[17] , arr2[17] ,arr3[17] ,line1[17],temp[17];
	int i=0, j=0 , k=0; int flag =0 , flag1 =0 ;
       
	while(! feof(f1))
	{
		fscanf(f1 , "%s", arr);


		while(! feof(f3))
		{
			flag = 0;
			fscanf(f3 , "%s %s", arr1,temp);

			if(strcmp(arr , arr1) == 0)
			{

				flag =1;
				fprintf(f4 , "%s", temp);
				break;
			}
		}

		rewind(f3);
		if( !strcmp(arr, ";") || !strcmp(arr , ":")){fprintf(f4,"\n");}
		if(flag == 0)
		{

		while(! feof(f2))
			{
				flag1=0;

				fscanf(f2,"%s %s",arr2,line1);

				if(strcmp(arr2 , arr) == 0)
				{

					flag1 =1;

					fprintf(f4,"\n");

					binary(line1 ,f4); break;
				}
			}
			rewind(f2);

			if(flag1 ==0)
			{
				hex2binary(arr , f4);
			}
		}
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);

}


