#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void  *err_check_malloc(unsigned int size);
int main(int argc,char *argv[]){
    int _input;
    int *int_ptr;
    char *char_ptr;
    if(argc>3){
        _input = atoi(argv[1]);
    }else{
        _input=50;
        printf("[*]allocating a memory of byte on heap (default size of Memory[%d])\n",_input);
    }
    char_ptr = (char*)err_check_malloc(_input*sizeof(char));
    // if(char_ptr ==NULL){
    //     fprintf(stderr,"{*}error cannot allocated the memory \n");
    //     exit(-1);
    // }
    strcpy(char_ptr,"this is on heap memory address");
    printf("[*]char_ptr{address of %p} value of {%s}\n",char_ptr,char_ptr);
    int_ptr = (int*)err_check_malloc(_input*sizeof(int));
    // if(int_ptr==NULL){
    //     fprintf(stderr,"{*}error cannot allocated the memory \n");
    //     exit(-1);
    // }
    *int_ptr = 12345; 
    printf("[*]int_ptr addrss of{%p} value of {%d}\n",int_ptr,*int_ptr);
    free(char_ptr);
    char_ptr= NULL;
    printf("[*]freeing... the char_ptr\n");
    printf("if i set a memory size of char_ptr in {30}\n");
    char_ptr = (char*)err_check_malloc(30*sizeof(char));
    strcpy(char_ptr,"New memory allocation");
    // if(char_ptr == NULL){
    //     fprintf(stderr,"{*}error cannot allocated the memory\n");
    //     exit(-1);
    // }
    printf("[*]char_ptr address of {%p} value of {%s}\n",char_ptr,char_ptr);
    free(int_ptr);
    int_ptr=NULL;
    printf("{*}freeing...the inr_ptr\n");
    free(char_ptr);
    char_ptr=NULL;
    printf("{*}freeing...the char_ptr\n");
}
void  *err_check_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr==NULL){
        fprintf(stderr,"Memory is cannot be allocated \n");
        exit(-1);
    }
    return ptr;
}