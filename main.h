#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
char *mi_getenv(const char *name);
char *wand_path(const char *input);
char **spellarray(char *input);
int power_fwe(char *phatname, char *argv[], char *envp[]);
#endif
