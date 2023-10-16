#include "main.h"

/**
 * print_rot13 - prints in rot13
 * @ptarg: string
 * @prm: parameters
 * Return: number bytes printed
 */
int print_rot13(va_list ptarg, prm_t *prm)
{
    int j, index;
    int tally = 0;  
    char rot_array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm"; 
    char *input_string = va_arg(ptarg, char *);  
    (void)prm;

    j = 0;
    index = 0;
    while (input_string[j])
    {
        if ((input_string[j] >= 'A' && input_string[j] <= 'Z') || (input_string[j] >= 'a' && input_string[j] <= 'z'))
        {
            index = input_string[j] - 65;
            tally += _putchar(rot_array[index]);
        }
        else
            tally += _putchar(input_string[j]);
        j++;
    }
    return (tally);
}

/**
 * print_rev - string in reverse
 * @ptarg: string
 * @prm: parameters
 * Return: number bytes printed
 */
int print_rev(va_list ptarg, prm_t *prm)
{
    int length, sum = 0;  
    char *reversed_str = va_arg(ptarg, char *);  
    (void)prm;

    if (reversed_str)
    {
        for (length = 0; *reversed_str; reversed_str++)
            length++;
        reversed_str--;
        for (; length > 0; length--, reversed_str--)
            sum += _putchar(*reversed_str);
    }
    return (sum);
}

/**
 * print_from_to - prints a range of char
 * @start: start
 * @stop: stop
 * @except: except
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
    int sum = 0;
    while (start <= stop)
    {
        if (start != except)
            sum += _putchar(*start);
        start++;
    }
    return (sum);
}

