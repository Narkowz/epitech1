/*
** EPITECH PROJECT, 2023
** star.c
** File description:
** star
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

void star( unsigned int size)
{
    int i = 0;
    int n = 2;
    
    for (; i < size; i++) {
        my_putchar('*');
        for (;n < (2*i)-3;n++) {
            my_putchar(' ');
        }
        
        }
        my_putchar('\n');
}

void top(int size, int *i)
{
    for (; i < size; (*i)++) {
        my_putchar('*');
        //my_putchar('\n');
        }
}

void main()
{
    star(5);
}
//<3 <3 bbou <3 <3
