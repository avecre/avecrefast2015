// arbitrary sort;
// the revised version uses formatted i/o;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

double * sorting(double * ar)
{
    int i,j;
    int size = (int)ar[0];
    double temp;
    for (i=1; i<size; i++)
    {
        for (j=i+1; j<=size; j++)
        {
            if (ar[j]<ar[i])
            {
                temp =ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }

    return ar;
}
int main(void)
{
    int i;
    int namelen = 50;
    char * msg1 = "File name:\n";
    char * errmsg = "File open error\n";
    char * sucmsg = "File open succeed\n";
    char * logmsg1= "Data loading...\n";
    char * logmsg = "Data loaded success\n";
    char * dir = "";

    char * ftemp = malloc(sizeof(char)*namelen);
    char * fname = malloc(sizeof(char)*namelen);
    char * find;
    //------------
    int strsize = 20;
    int nummax = 100;
    int count = 0;
    char * strbuf = malloc(sizeof(double)*strsize*nummax);
    char * ptrtemp;
    double * dtemp = malloc(sizeof(double));
    FILE * fp;
//---------------------------file open part;
    fputs(msg1, stdout);// prompt for file name;
    fgets(ftemp, namelen, stdin); find = strchr(ftemp, '\n'); if (find != NULL){*find = '\0';}
    strncpy(fname, dir, namelen); strncat(fname, ftemp, namelen); free(ftemp);

    if ((fp = fopen(fname, "r")) == NULL){fputs(errmsg, stderr); exit(1);} free(fname);
    fputs(sucmsg, stdout);// File open succeed;
//---------------------------data loading part;
    fputs(logmsg1, stdout);// loading...

    while (fscanf(fp, "%lf", dtemp)!=EOF)
    {
        count++;
    }

    double * arr = malloc(sizeof(double)*(count+1));
    arr[0] = (double)count; ptrtemp = strbuf;
    fseek(fp, 0, SEEK_SET);
    for (i=1; i<=count; i++)
    {
        fscanf(fp, "%lf", arr+i);
        printf("%lf\n", arr[i]);
        ptrtemp += (strlen(ptrtemp)+2);
    }
    free(strbuf);
    fputs(logmsg, stdout);// loading succeed;
//--------------------------
    double * sortted = malloc(sizeof(double)*(int)arr[0]);
    FILE * fp2;
    sortted = sorting(arr);
    if ((fp2 = fopen("sort_output.txt", "w+")) != NULL)
    {
        for (i=1; i<=(int)arr[0]; i++)
        {
            fprintf(fp2, "%lf\n", sortted[i]);
            printf("%lf\n", sortted[i]);
        }
        fclose(fp2);
    }
    printf("sorting result in sort_output.txt\n");
    free(arr);
    free(sortted);

    return 0;
}
// end of code;
