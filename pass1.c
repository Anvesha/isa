#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
main()
{
        char inp[size],sym[size];
        printf("Enter the source file Name:");
        scanf("%s",inp);
        printf("Enter the symbol file Name:");
        scanf("%s",sym);
	FILE *f1, *f2;
	char three[3][5]={"lrpi","gonz","goz"};
	char two[1][4]={"cpi"};
	char one[10][5] = {"mul","cprp","inrp","dcrp","strp","dcr","stp","sum","ges","inr"};
	f1 = fopen(inp,"r");
	f2 = fopen(sym,"w");
	char s[20];
	int i,j,k,ilc=0, flag1 =0, flag2 =0,flag3=0;
	char c , sh;

		while((c = fgetc(f1)) != EOF)
		{

		if(c == '\n')
		{
			fscanf(f1,"%s",s);

	    for(k=0;k<3;k++)
			{
				flag3 =0;
				if((strcmp( s,three[k])) == 0)
				{
					ilc+=3; flag3 = 1;
					break;
				}
			}
			if (flag3==0)
            {

			for(i=0;i<1;i++)
			{
				flag2 =0;
				if((strcmp( s,two[i])) == 0)
				{
					ilc+=2; flag2 = 1;
					break;
				}
			}


			if(flag2 == 0)
			{


				for(j=0;j<10;j++)
				{flag1=0;
					if((strcmp( s,one[j])) == 0)
					{
						ilc++; flag1 =1;break;
					}
				}
				if(flag1 != 1)
				{
					fprintf(f2,"%s\t",s);
					fprintf(f2,"%d\n",++ilc);
				}
			}
		}
    }
}
		fclose(f1);
		fclose(f2);
}



