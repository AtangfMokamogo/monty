#ifndef _monty_h_
#define _monty_h_

/* macros global */

#define _GNU_SOURCE
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>




/* operation tokenised keywords */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* MONTY OPERATION FUNCTIONS */

/* errors.c */
int err_use(void);
int err_malloc(void);
int err_file_open(char *filename);
int err_op_unknown(char *opcode, unsigned int line_number);
int err_no_data(unsigned int line_number);


/* more_errors.c */
int err_short_stack(unsigned int line_no, char *op);
int err_pop(unsigned int line_no);
int err_div(unsigned int line_no);
int err_pchar(unsigned int line_no, char *msg);
int err_pint(unsigned int line_no);

/* op_funcs1.c */
void my_push(stack_t **stack, unsigned int line_no);
void my_pall(stack_t **stack, unsigned int line_no);
void my_pint(stack_t **stack, unsigned int line_no);
void my_pop(stack_t **stack, unsigned int line_no);
void my_swap(stack_t **stack, unsigned int line_no);


/* op_funcs2.c */
void my_add(stack_t **stack, unsigned int line_no);
void my_sub(stack_t **stack, unsigned int line_no);
void my_div(stack_t **stack, unsigned int line_no);
void my_mul(stack_t **stack, unsigned int line_no);
void my_mod(stack_t **stack, unsigned int line_no);


/* op_funcs3.c */
void my_nop(stack_t **stack, unsigned int line_no);
void my_pchar(stack_t **stack, unsigned int line_no);
void my_pstring(stack_t **stack, unsigned int line_no);
void set_error(int error);


/* advanced_funcs.c */
void my_rotl(stack_t **stack, unsigned int line_no);
void my_rotr(stack_t **stack, unsigned int line_no);
void my_stack(stack_t **stack, unsigned int line_no);
void my_queue(stack_t **stack, unsigned int line_no);


/* stack_funcs.c */
int stack_init(stack_t **stack);
void stack_free(stack_t **stack);
int stack_mode(stack_t *stack);


/* execute_script.c */
void free_tokens(void);
unsigned int token_arr_len(void);
int empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int execute_file(FILE *file_doc);


/* monty_tokeniser.c */
char **my_tow(char *str, char *delims);
int delim(char ch, char *delims);
int word_length(char *str, char *delims);
int word_count(char *str, char *delims);
char *next_word(char *str, char *delims);


/* int_str_ops.c */

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

#endif
