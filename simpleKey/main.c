#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;
char * choices[] = {
    "Choices 1",
    "Choices 2",
    "Choices 3",
    "Choices 4",
    "Exit",
};
int n_choices = sizeof(choices) / sizeof (char*);
void print_menu (WINDOW *menu_win, int hightlight);

#include <ncurses.h>

int main (int agrc, char *argv)
{
    WINDOW * menu_win;
    int hightlight = 1;
    int choice = 0;
    int c;

    initscr ();
    clear ();
    noecho ();
    cbreak ();
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu_win = newwin (HEIGHT, WIDTH, starty, startx);
    keypad (menu_win, TRUE);
    mvprintw (0, 0, "Use arrow keys to go up and down , Press enter to select a choice");
    refresh ();
    print_menu (menu_win, hightlight);
    while (1)
    {
        c = wgetch (menu_win);
        switch (c)
        {
        case KEY_UP:
            if (hightlight == 1)
                hightlight = n_choices;
            else
                --hightlight;
            break;

        case KEY_DOWN:
            if (hightlight == n_choices)
                hightlight = 1;
            else
                ++hightlight;
            break;
        case 10:
            choice = hightlight;
            break;
        default:
            mvprintw (24, 0, "charcter pressed is = %3d Hopfully it can be printed as '%c'", c, c);
            refresh ();
            break;
        }
        print_menu (menu_win, hightlight);
        if(choice != 0)
            break;
    }
    mvprintw (23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol ();

    refresh ();
    endwin ();
    return 0;
}


void print_menu (WINDOW *menu_win, int hightlight)
{
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i)
    {
        if (hightlight == i + 1)
        {
            wattron (menu_win, A_REVERSE);
            mvwprintw (menu_win, y, x, "%s", choices[i]);
            wattroff (menu_win, A_REVERSE);
        }
        else
            mvwprintw (menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh (menu_win);
}


