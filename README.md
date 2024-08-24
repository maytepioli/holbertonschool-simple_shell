# _Simplified Shell Project_ 🐚
This project implements a simplified version of a C command interpreter. The program allows you to execute commands, manage environment variables, and handle basic errors. It is designed to provide a fundamental understanding of how a shell works in an operating system.
## _Descripción_
The program simulates the basic behavior of a shell, allowing the user to input commands and see the results. The shell runs in an infinite loop, reading user input and executing commands. Additionally, the program provides the capability to display environment variables and handle errors in a customized way.

## 🛠️ _Features_

- **Command Execution**: Executes system commands entered at the command line.
- **Show Environment Variables**: With the environment command, the program prints the current environment variables.
- **Custom Error Handling**: Displays detailed error messages in case of command execution failures.
- **Executable Search**: Searches for the executable command in the directories defined in the system's PATH variable.

Available Commands
ls: Lists files and directories in the current directory.

Usage Example:
```
$ ls
file1.txt  file2.txt  directory1  directory2
```
```
 ls -l
-rw-r--r-- 1 user user  1234 Aug 24 14:30 file1.txt
-rw-r--r-- 1 user user  5678 Aug 24 14:31 file2.txt
drwxr-xr-x 2 user user  4096 Aug 24 14:32 directory1
drwxr-xr-x 2 user user  4096 Aug 24 14:33 directory2
```
pwd: Shows the current working directory.

Usage Example:
```
$ pwd
/home/user/project
```

env: Displays the current environment variables.

Usage Example:
```
$ env
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
USER=user
```
exit: Exits the shell.
```
$ exit
```

## ❌ _Example Error Messages_

- **Command Not Found**:

    ```
    $ nonexistent_command
    nonexistent_command: 1: nonexistent_command: No such file or directory
    ```
## ✨ _Compilation_
To compile the project, use the following command:
 ```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
 ```
This compiles all .c files in the current directory and creates an executable named hsh.
## _Running_
Once compiled, run the shell with:

 ```
./hsh
 ```
 ## 📊 _Flow Diagrams_
  
  ### 🔮  `Main Flow Diagram` _(SHELMAIONI)_
 ![imagen](https://github.com/user-attachments/assets/4c01c501-fec2-4168-b845-4a10a5116340)

### ⚡ `wand_path` Flow Diagram
![imagen](https://github.com/user-attachments/assets/499187ae-a990-406c-ac7d-00dab612ea5d)

### ✨  `spellarray`Flow Diagram
![contar](https://github.com/user-attachments/assets/4f3a0c88-ec61-4a99-8892-e19e92efa57e)
![dibujo de hechizos](https://github.com/user-attachments/assets/738ee4f6-3890-4d0f-94b2-bc3d58a7ae10)

### 🧚 `power_fwe Flow` Diagram
![imagen](https://github.com/user-attachments/assets/bb55fda4-e184-403b-8456-175b3bce1989)

### `main`

The entry point of the program. Handles user input and executes commands. Prints a prompt ($ ) if run in an interactive terminal.
```
int main(__attribute__((unused))int ac,
         __attribute__((unused))char **av,
         char **envp)
```
__perror_
Prints a custom error message that includes the command name, command number, and specific error message.
```
char *_perror(char *s, int count, char *in);
```
_free_array_
Frees a dynamically allocated array of strings.
```
void free_array(char **array);
```
_print_arr_
Prints each element of an array of strings.
```
char **print_arr(char **arr);
```
_wand_path_
Searches for an executable file in the directories defined in the PATH environment variable.
```
char *wand_path(const char *input);
```
_spellarray_
Splits a string into a series of words using predefined delimiters.
```
char **spellarray(char *input);
```
_power_fwe_
Executes a command in a child process. Uses execve to execute the command and fork to create a new process.
```
int power_fwe(char *phatname, char *argv[], char *envp[]);
```
* 🧙‍♂️  _AUTHOR_
  * _Mayte Pioli_
