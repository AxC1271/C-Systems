#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char** parse(char* buf);
void execute(char** args);
void execute_pipe(char* buf);

int main() {
    char buf[1024];

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(buf, 1024, stdin) == NULL) {
        break;
        }

        buf[strcspn(buf, "\n")] = '\0';

        if (strchr(buf, '|') != NULL) {
            execute_pipe(buf);
        } else {
            char** args = parse(buf);
            if (strcmp(args[0], "exit") == 0) {
                free(args);
                break;
            }
            else if (strcmp(args[0], "cd") == 0) {
                chdir(args[1]);
            }
            else {
                execute(args);
                free(args);
            }
        }
    }
    return 0;
}

char** parse(char* buffer) {
    char* args[64];
    int count = 0;

    char* token = strtok(buffer, " ");

    while (token != NULL) {
        args[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    args[count] = NULL;  // sentinel

    char **result = malloc(sizeof(char*) * (count + 1));
    for (int i = 0; i <= count; i++) {
        result[i] = args[i];
    }

    return result;
}

void execute(char** args) {
    pid_t pid = fork();

    if (pid == 0) {
        // we are the child
        execvp(args[0], args);
        // if execvp returns, it failed
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // we are the parent — wait for child
        waitpid(pid, NULL, 0);
    } else {
        // fork failed
        perror("fork");
    }
}

void execute_pipe(char* buf) {
    // split into left and right
    char* left = strtok(buf, "|");
    char* right = strtok(NULL, "|");

    char** args_left = parse(left);
    char** args_right = parse(right);

    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        execvp(args_left[0], args_left);
        perror("execvp");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        execvp(args_right[0], args_right);
        perror("execvp");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    free(args_left);
    free(args_right);
}
