#include "monty.h"


/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_toks(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}


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

/**
 * monty_runner -  A function that exucutes a Monty file
 * 
 * @monty_f: monty file
 * 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
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
        line_number++;

        /* op_toks global variable - holds a arr of opcodes*/

        op_toks = strtow(line, DELIMS); /* strtow string to words - split the line into words */
        op_func = get_op_func(op_toks[0]); /* get operation function - compares the command to a map of command and functions. Returns the matching func */
        op_func(&stack, line_number); /* execute function */
        free_toks(); /* free memory */
    }

    free_stack(&stack); /* free memory */

}