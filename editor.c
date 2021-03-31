#include<stdio.h>
#include <fcntl.h>
#include<sys/file.h>
#include<unistd.h>
#define DATA_SIZE 1000
int main()
{
    char name[500];char text[500]; int option;
  
    printf("\nChoose the respective option:\n1.Create a new textfile \n2.Edit an exisiting file \n" );
    scanf("%d %s",&option,name);
    if(option==1) 
    {
        char data[DATA_SIZE];
        FILE * fPtr;
        fPtr = fopen(name, "w");
        if(fPtr == NULL)
        {
            perror("");
            printf("Unable to create file.\n");
            return 1;
        }
    printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);
    fgets(data, DATA_SIZE, stdin);
    fputs(data, fPtr);
    fclose(fPtr);
    printf("File created and saved successfully. :) \n");
    return 0;
    }
    

    
    else
    {
    int fd=open(name,O_RDWR);
    if(fd==-1){perror(""); return -1;}
    if (flock(fd, LOCK_EX|LOCK_NB) == -1) 
     {  
        printf("Warning: file already open for writing,do you still want to proceed?[Y/N]");
        char choice;
        scanf("%c*[\n]",&choice);
        scanf("%c*[\n]",&choice);
       
        if(choice=='N')
        {
            return 1;
        }
        
        else 
        {
         FILE *fp2 = fopen(name, "r");
        ssize_t len=500;
        char *line=NULL; int read;
         while ((read = getline(&line, &len, fp2)) != -1) 
         {   
            printf("%s", line);
    }
    
    fclose(fp2);
        FILE *fp1 = fopen(name, "a+");
        printf("Enter more content to append to the file:");
        fflush( stdout );
        //flock(fd,LOCK_UN);
        //flock(fd,LOCK_NB);
        
        fgets(text, DATA_SIZE, stdin);
        fgets(text, DATA_SIZE, stdin);
        fprintf(fp1,"%s",text);

        printf("done writing");
        fclose(fp1);
        }
      }
    else 
    { 
        FILE *fp2 = fopen(name, "r");
        ssize_t len=500;
        char *line=NULL; int read;
         while ((read = getline(&line, &len, fp2)) != -1) 
         {   
            printf("%s", line);
         }
    fclose(fp2);
        FILE *fp1 = fopen(name, "a+");
        if(fp1==NULL) {perror(""); return -1;}
        printf("Enter more content to append to the file:");
        fflush( stdout );
        //flock(fd,LOCK_UN);
        //flock(fd,LOCK_NB);
        
        fgets(text, DATA_SIZE, stdin);
        fgets(text, DATA_SIZE, stdin);
        fprintf(fp1,"%s",text);

        printf("done writing");
        fclose(fp1);

    } 
    close(fd);  
    }        

}