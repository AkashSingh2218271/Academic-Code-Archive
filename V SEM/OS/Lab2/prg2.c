 #include <stdio.h>
int main() {
    DIR *d;
    d = opendir(".");
    if (d) {
        printf("Contents of directory:\n");
        while ((dir = readdir(d)) != NULL) {
            printf("listfiles");
        }
    } else {
        perror("opendir");
    }
    return 0;}
