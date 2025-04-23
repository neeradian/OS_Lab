#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include<sys/wait.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    int status;
    int file_descriptor;
    char buffer[10];

    // Fork a new process
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        
        // Open a file 
        file_descriptor= open("example.txt", O_RDONLY);
        if(file_descriptor ==-1)
        {
            perror("Open");
            exit(EXIT_FAILURE);
        }

        // Read from file 
        ssize_t bytes_read = read(file_descriptor,buffer,sizeof(buffer)-1);
        if(bytes_read == -1)
        {
            perror("Read");
            close(file_descriptor);
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0'; //Null-terminate the string
        printf("Read from file: %s\n",buffer);
        close(file_descriptor);
        exit(0);
    }
    else{

        //Parent process
        printf("Parent Process ID: %d\n", getpid());
        wait(&status);
        printf("Child Complete\n");

    }
    return 0;
}

