#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows, compile these functions */
#ifdef _WIN32
#include <string.h>

/* Declare a buffer for user input of size 2048 */
static char buffer[2048];

/* Fake readline function */
char *readline(char *prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char *cpy = malloc(strlen(buffer) + 1);
  strcpy_s(cpy, sizeof(cpy), buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char *unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/history.h>
#include <editline/readine.h>
#endif

int main(int argc, char **argv) {
  /* Print Version and Exit info */
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    char *input = readline("lispy > ");

    /* Save input to history */
    add_history(input);

    /* Echo input back to user */
    printf("No you're a %s\n", input);

    /* Free retrieved input */
    free(input);
  }

  return 0;
}
