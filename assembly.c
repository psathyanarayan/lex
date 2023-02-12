#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char op[5],arg1[10],arg2[10],result[10];
int main()
{
    FILE *fin,*fout;
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");
    while(!feof(fin))
    {
        fscanf(fin,"%s%s%s%s",op,arg1,arg2,result);
        if(strcmp(op,"+")==0)
        {
            fprintf(fout,"\nMOV R0 %s",arg1);
            fprintf(fout,"\nADD R0 %s",arg2);
            fprintf(fout,"\nMOV %s R0",result);
        }
        if(strcmp(op,"-")==0)
        {
            fprintf(fout,"\nMOV R0 %s",arg1);
            fprintf(fout,"\nSUB R0 %s",arg2);
            fprintf(fout,"\nMOV %s R0",result);
        }
        if(strcmp(op,"*")==0)
        {
            fprintf(fout,"\nMOV R0 %s",arg1);
            fprintf(fout,"\nMUL R0 %s",arg2);
            fprintf(fout,"\nMOV %s R0",result);
        }
        if(strcmp(op,"/")==0)
        {
            fprintf(fout,"\nMOV R0 %s",arg1);
            fprintf(fout,"\nDIV R0 %s",arg2);
            fprintf(fout,"\nMOV %s R0",result);
        }
        if(strcmp(op,"=")==0)
        {
            fprintf(fout,"\nMOV R0 %s",arg1);
            fprintf(fout,"\nMOV %s R0",result);
        }
    }
    fclose(fin);
    fclose(fout);
}
