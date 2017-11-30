/* main.c -- 输入->打开文件->美化修饰内容 */
#include <ncurses.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
    int ch, prev;
    FILE *fp;
    int goto_prev = FALSE, y, x, row, col;
    if(argc != 2)
    {
        printf ("usage: %s <a c file name>\n", argv[0]);
        exit(1);
    }
    if((fp = fopen (argv[1], "r")) == NULL)
    {
        perror ("Cannot open input file");
        exit(1);
    }
    initscr ();
    getmaxyx (stdscr, row, col);
    prev = EOF;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (prev == '/' && ch == '*')
        {
            attron (A_BOLD);
            getyx (stdscr, y, x);
            move (y, x - 1);
            printw ("%c%c", '/', ch);
        }
        else
            printw ("%c", ch);
        if (prev == '*' && ch == '/')
            attroff (A_BOLD);
        prev = ch;
    }
        refresh ();
    getch ();
    endwin ();
    fclose (fp);
    return 0;
}

