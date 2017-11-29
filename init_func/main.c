/* main.c -- 初始化函数 */ 

#include <ncurses.h>

int main ()
{
    int ch;

    initscr ();
    raw (); // 禁用行缓冲  把字符送给程序 而不是终端
    keypad (stdscr, TRUE);  //开启功能键响应模式
    noecho (); // 关闭键盘回显
    printw ("Type any character to see it in bold\n");
    ch = getch();

    if (ch == KEY_F (2))  //前面没有执行keypad（）函数 这条语句不会执行
        printw ("F2 key pressed");
    else
    {
        printw ("The pressed key is ");
        attron (A_BOLD);  // 开启字符修饰效果    加粗
        printw ("%c", ch);
        attroff (A_BOLD); // 关闭字符修饰效果    
    }
    refresh ();
    getch ();
    endwin ();
    return 0;
}

