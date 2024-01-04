#include "monty.h"

/**
 * monty_runner -  A function that exucutes a Monty file
 * 
 * @monty_f: monty file
 * 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
    /* List of opcode match with a opfunction */
    instruction_t op_funcs[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    int i;

    for (i = 0; op_funcs[i].opcode; i++)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
            return (op_funcs[i].f);        
    }
}
int monty_runner(FILE *monty_f)
{

    /* Declare variabales */
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    /* loop */
    while (getline(&line, &len, monty_f) != -1)
    {
        
    }

        /* get current_op from line */
        /* get operation match with a list of string and functions then save function in a variable*/
        /* run operation */
        /* NEXT Line*/

}