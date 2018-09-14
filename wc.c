#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int CharCount(char *file)//字符统计函数 
{
	FILE *fp;
	int i;
	int c=0;
	
	fp=fopen(file,"r");
	i=fgetc(fp);
	
	if (fp==NULL)
	{
	printf("文件不存在，请重新输入");
	exit(1); 
	}
	
    while(i!= EOF) 
	{
    	if( i >= 33 && i <= 126 )
            c++;
        i=fgetc(fp);
    }      
    
    fclose(fp);
    return c;
}


int WordCount(char *file)//单词统计函数 
{
	FILE *fp;
	int i;
	int w=0;
	
	fp=fopen(file,"r");
    i=fgetc(fp);
	
	if (fp==NULL)
	{
	printf("文件不存在，请重新输入");
	exit(1); 
	}
	
	while(i!=EOF)
	{
		if( (i >= 'a' && i <= 'z') || (i >= 'A' && i<= 'Z') || (i >= '0' && i <= '9') ) 
		{
    		
    		while( (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')  || i == '_' ) {
	    		i = fgetc(fp);
	    	}
	    		w++;
	    	
		}
	
         i=fgetc(fp);          
	}
	fclose(fp);
	return w;	 
}


int LineCount(char *file)//行数统计函数 
{
	FILE *fp;
	int i;
	int l=0;
	
	fp=fopen(file,"r");
    i=fgetc(fp);
    
    if (fp==NULL)
	{
	printf("文件不存在，请重新输入");
	exit(1);
	}
	
    while(i!= EOF) 
	{
    	if( i=='\n' )
            l++;
        i=fgetc(fp);
    }      
    
    fclose(fp);
    return l;
}


int main(int argc, char *argv[]) //主函数，选择功能            
{
	FILE *fp;
	int c;
	int w;
	int l;
    

	    
    if( !strcmp (argv[1], "-c") ) 
	{                     
    	c = CharCount(argv[2]);
        printf("文件:%s     字符数:%d\n", argv[2], c );
	}
	
	
    else if( !strcmp (argv[1], "-w") )  
	{  
		w = WordCount(argv[2]);	            
        printf("文件:%s     词数:%d\n", argv[2], w );
    }
	
			    
	else if( !strcmp (argv[1], "-l") )  
	{  
		l = LineCount(argv[2]);     
        printf("文件:%s     行数:%d\n", argv[2], l );
	}
	
	else  printf("您的输入有误，请重新输入。");
    return 0;
}











