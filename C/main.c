#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>


typedef struct {
    int magic;
    int length;
    char* data;
} Header;

#define LEN (1024)

int main(int argc, char** argv) {
    FILE* file = fopen("data.txt", "wb");
    Header* h = malloc(sizeof(Header)+sizeof(char)*LEN-sizeof(char*));
    h->magic = 0x44414548;
    h->length=1024;
    h->data=h+sizeof(Header)-sizeof(char*);
    int i;
    for(i=0;i<h->length;i++){
        h->data[i] = i%255;
    }
    fwrite(h, sizeof(Header)+sizeof(char)*LEN-sizeof(char*), 1, file);
    fflush(file);
    fclose(file);
    Header * rh = malloc(sizeof(Header));
    file = fopen("data.txt", "rb");
    fread(rh, sizeof(Header)-sizeof(char*), 1, file);
    rh->data = malloc(sizeof(char)*rh->length);
    fread(rh->data, sizeof(char)*rh->length, 1, file);
    printf("0x%X,%d\n",rh->magic,rh->length);
    fclose(file);
    return 0;
}

