#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct File
{
    void *data;
    char *c;
};


struct Directory
{
    struct File *file[10];
    char *c;
};


struct Root
{
    struct Directory *dir[10];
};

void touch(struct Root *start, char *dir_name, char *file_name, char *contents)
{
    struct File *file = (struct File *)malloc(sizeof(struct File));
    for(int i=0;i<10;i++)
    {
        if(start->dir[i]->c==dir_name)
        {
            for(int j=0;j<10;j++)
            {
                if(start->dir[i]->file[j]!=NULL)
                {
                    continue;
                }
                else
                {
                    start->dir[i]->file[j]->data=contents;
                    start->dir[i]->file[j]->c=file_name;
                    break;
                }
            }
        }
    }
}
void mkdir(struct Root *start, char *name)
{
    struct Directory *dir = (struct Directory *)malloc(sizeof(struct Directory));
    memset(dir,0,sizeof *dir);
    for(int i=0;i<10;i++)
    {
        if(start->dir[i]!=NULL)
        {
            continue;
        }
        else
        {
            start->dir[i]=dir;
            start->dir[i]->c=name;
            break;
        }
    }
}
void printDir(struct Root *start)
{
    for(int i=0;i<10;i++)
    {
        if(start->dir[i]!=NULL)
            printf("%s\n",start->dir[i]->c);
        else
        {
            break;
        }
    }
}
void cat(struct Root *start,char *dir_name, char *file_name)
{
    for(int i=0;i<10;i++)
    {
        if(start->dir[i]->c!=dir_name)
        {
            continue;
        }
        else
        {
            for(int j=0;j<10;j++)
            {
                if(start->dir[i]->file[j]->c!=file_name)
                {
                    continue;
                }
                else
                {
                    char *con = (char *)start->dir[i]->file[j]->data;
                    printf("%s",con);
                    break;
                }
            }
            break;
        }
    }
}
int main()
{
    struct Root *start=(struct Root *)malloc(sizeof(struct Root));
    memset(start,0,sizeof *start);
    char *dir_name = "first";
    char *file_name = "file1";
    char *data = "This is my first simple file system using C";
    mkdir(start,dir_name);
    touch(start,dir_name,file_name,data);
    cat(start,dir_name,file_name);
    printDir(start);
    return 0;
    
}
