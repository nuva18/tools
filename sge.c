#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    char *new_argv[argc + 1];
    int i;

    if ((argc == 2 && argv[1][0] == '?')) {
        fprintf(stderr, "usage: sgeany [file-names ...]\n");
        fprintf(stderr, "       Runs geany in the background, so it doesn't hog the terminal.\n");
        exit(1);
    }
    
    /* If you run geany with multiple files it doesn't hog the terminal. Don't ask me why.
       Anyway, we don't need to do anything special if there's multiple files to open.
       ... except sometimes it does. I don't know why, don't ask, I can't even get it to replicate 
       most of the time. */
    
    if (fork() == 0) {
        new_argv[0] = "geany";
        for (i = 1; i < argc; i++) new_argv[i] = argv[i];
        new_argv[argc] = NULL;
        
        execvp("geany", new_argv);
        perror("execvp failed -- geany");
        exit(1);
    }
    
    /* Otherwise, we've got shit to do. Fork a child, and run geany in that child. 
    
    if (fork() == 0) {
        if (argc == 2) execlp("geany", "geany", argv[1], NULL);
        else execlp("geany", "geany", NULL);
        
        perror("execlp failed -- geany");
        exit(1);
    } */
    
    return 0; 
}
