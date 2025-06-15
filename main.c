#include <stdio.h>
#include <string.h>
#include "interpret.h"

static void repl()
{
  char line[1024];
  for (;;)
  {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");
      break;
    }

    line[strcspn(line, "\n")] = '\0';

    if (strcmp(line, "exit") == 0)
    {
      printf("Encerrando o interpretador...\n");
      break;
    }

    interpret(line);
  }
}

int main()
{

  repl();
  return 0;
}