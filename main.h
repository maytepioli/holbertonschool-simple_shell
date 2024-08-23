#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int ac, char **av, char **env);
char *mi_getenv(const char *name);
char *wand_path(const char *input);
char **spellarray(char *input);
int power_fwe(char *phatname, char *argv[], char *envp[]);
char *_perror(char *s, int count, char *in);
void free_array(char **array);
char **print_arr(char **arr);
extern char **environ;

#endif
