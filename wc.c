#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int CharCount(char *file)//�ַ�ͳ�ƺ��� 
{
	FILE *fp;
	int i;
	int c=0;
	
	fp=fopen(file,"r");
	i=fgetc(fp);
	
	if (fp==NULL)
	{
	printf("�ļ������ڣ�����������");
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


int WordCount(char *file)//����ͳ�ƺ��� 
{
	FILE *fp;
	int i;
	int w=0;
	
	fp=fopen(file,"r");
    i=fgetc(fp);
	
	if (fp==NULL)
	{
	printf("�ļ������ڣ�����������");
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


int LineCount(char *file)//����ͳ�ƺ��� 
{
	FILE *fp;
	int i;
	int l=0;
	
	fp=fopen(file,"r");
    i=fgetc(fp);
    
    if (fp==NULL)
	{
	printf("�ļ������ڣ�����������");
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


int main(int argc, char *argv[]) //��������ѡ����            
{
	FILE *fp;
	int c;
	int w;
	int l;
    

	    
    if( !strcmp (argv[1], "-c") ) 
	{                     
    	c = CharCount(argv[2]);
        printf("�ļ�:%s     �ַ���:%d\n", argv[2], c );
	}
	
	
    else if( !strcmp (argv[1], "-w") )  
	{  
		w = WordCount(argv[2]);	            
        printf("�ļ�:%s     ����:%d\n", argv[2], w );
    }
	
			    
	else if( !strcmp (argv[1], "-l") )  
	{  
		l = LineCount(argv[2]);     
        printf("�ļ�:%s     ����:%d\n", argv[2], l );
	}
	
	else  printf("���������������������롣");
    return 0;
}











