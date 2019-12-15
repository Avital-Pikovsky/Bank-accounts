#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#define LINE 256
#define WORD 30


int getLine(char s[]){
    int count = 0;
    char ch = getchar();
    s[0]=ch;
    while(ch!='\n' && ch!='\0'){
        count++;
        ch = getchar();
        s[count] = ch;
    }
    s[count] = '\0';
    if(ch == '\0') return -1;
    else return count;
}

int getWord(char w[]){
    int count = 0;
    char ch = getchar();
    w[0]=ch;
    while(ch!=' ' && ch!='\t' && ch!='\n' && ch!='\0'){
        count++;
        ch = getchar();
        w[count] = ch;
    }
    w[count] = '\0';
    if(ch == '\0') return -1;
    //printf("There are %d letters in the word '%s'. \n\n" ,count,w);
    return count;
}

int subString(char *str1, char *str2){
//    int i=0;
//
//    printf("Enter first string: ");
//    char ch1 = getchar();
//    str1[i] = ch1;
//    while(ch1!='\n' && ch1!='\0'){
//        i++;
//        ch1 = getchar();
//        str1[i] = ch1;
//    }
//    int j=0;
//
//    printf("Enter second string: ");
//    char ch2 = getchar();
//    str2[j] = ch2;
//    while(ch2!='\n' && ch2!='\0'){
//        j++;
//        ch2 = getchar();
//        str2[j] = ch2;
//    }
//
    int counter = 0;
    int i=0,j=0;
    while(str1[i] != '\0' && str2[j] != '\0'){

        if(str1[i] == str2[j]){
            j++;
            i++;
            counter++;
        }
        else{
            i++;
            j=0;
            counter=0;
        }
    }
    if(counter == 0) return 0;

    else return 1;     
}

int similar(char *s, char *t, int n){


//    int i=0;
//
//    printf("Enter first string: ");
//    char ch1 = getchar();
//    s[i] = ch1;
//    while(ch1!='\n' && ch1!='\0'){
//        i++;
//        ch1 = getchar();
//        s[i] = ch1;
//    }
//
//    int j=0;
//
//    printf("Enter second string: ");
//    char ch2 = getchar();
//    t[j] = ch2;
//    while(ch2!='\n' && ch2!='\0'){
//        j++;
//        ch2 = getchar();
//        t[j] = ch2;
//    }

    //printf("Enter num of letters: ");
    //scanf(" %d", &n);

    int i=0,j=0;
    while(s[i] != '\0' && t[j] != '\0'){

        if(s[i] == t[j]){
            j++;
            i++;
        }
        else{
            i++;
            n--;
        }
    }
    if(n == 0) return 1;
    
    else return 0;
}

void print_lines(char *str){

    char line [LINE];
    int length=0;
    while(length!=-1){
        length = getLine(line);
 
        if(subString(line,str)){
        printf("%s \n",line);
        }
    }
}
void print_similar_words(char *str){
    char word [LINE];
    int length=0;

    while(length!=-1){
        length = getWord(word);
 
        if(similar(word,str,1))
        printf("%s \n", word);

        if(similar(word,str,0))
        printf("%s \n", word);
        
    }
    
}


