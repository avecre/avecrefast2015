// quick sort;
// this is an error version;
// The use of character functions is not mature;
// the revised version uses standard i/o;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
double * sorting(int size, double * ar);
double* data(void);

int main(void)
{
    int i;
    double * returndata;
    double * sortted;
    FILE * fp;

    returndata = data();
    sortted = sorting((int)returndata[0], returndata+1);
    if ((fp = fopen("sort_output.txt", "w+")) != NULL)
    {
        for (i=0; i<(int)returndata[0]; i++)
        {
            fprintf(fp, "%lf\n", sortted[i]);
        }
        fclose(fp);
    }
    printf("sorting result in sort_output.txt\n");
    free(returndata);
    free(sortted);

    return 0;
}
double * sorting(int size, double * ar)
{
    double * f = malloc(sizeof(double)*size);
    f = ar-1;

    return f;
}
double* data(void)
{
    int i;
    int namelen = 50;
    char * msg1 = "File name:\n";
    char * errmsg = "File open error\n";
    char * sucmsg = "File open succeed\n";
    char * logmsg1= "Data loading...\r";
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
    FILE * fp;
//---------------------------file open part;
    fputs(msg1, stdout);// prompt for file name;
    fgets(ftemp, namelen, stdin); find = strchr(ftemp, '\n'); if (find != NULL){*find = '\0';}
    strncpy(fname, dir, namelen); strncat(fname, ftemp, namelen); free(ftemp);

    if ((fp = fopen(fname, "r")) == NULL){fputs(errmsg, stderr); exit(1);} free(fname);
    fputs(sucmsg, stdout);// File open succeed;
//---------------------------data loading part;
    fputs(logmsg1, stdout);// loading...
    fgets(strbuf, strsize*nummax, fp);
    ptrtemp = strbuf; while (count<nummax && strchr(ptrtemp, '\n') != NULL && strlen(ptrtemp) != 0){count++;ptrtemp+=(strlen(ptrtemp)+2);}count++;

    double * arr = malloc(sizeof(double)*(count+1)); arr[0] = (double)count; ptrtemp = strbuf;
    for (i=1; i<=count; i++)
    {
        arr[i] = atof(ptrtemp);
        printf("%lf\n", arr[i]);
        ptrtemp += (strlen(ptrtemp)+2);
    }
    free(strbuf);
    fputs(logmsg, stdout);// loading succeed;
//--------------------------
    return arr;
}
// end of code;
