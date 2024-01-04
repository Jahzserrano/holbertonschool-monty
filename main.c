#include "monty.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
/**
 * main - Entry Point
 * 
 * @argc - argument counter
 * @argv - pointer of char pointer of arguments
 * 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char **argv)
{
    FILE *monty_f;
    int exit_code = EXIT_SUCCESS;

    /* if argc is */
    if (argc != 1)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    monty_f = fopen(argv[1], "r");

    if (monty_f == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    exit_code = monty_runner(monty_f);
    fclose(monty_f);
    return (exit_code);
}