#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if(argc != 2)
    {
        printf ("Usage : %s <a c file name>\n", argv[0]);
        exit(1);
    }
    fp = fopen (argv[1], "r");
    if (fp == NULL)
    {
        perror("Connot open input file");
        exit(1);
    }
    while ((ch = fgetc (fp)) != EOF)
    {
        printf ("%c",ch);
    }
    putchar ('\n');
    fclose (fp);
    return 0;
}
