#include<stdio.h>  
int main()  
{  
    char expression[50];   
    int x=0,y=0,z=0,i=0,l=0;
    printf("\nEnter an expression");  
    scanf("%s", expression);  
    for (l = 0; expression[l] != '\0'; l++);
		l=l-1;
	
if(l<0){
	return 0;
}
	
if((l+1)%2==0){

 while(expression[i]!= '\0')  
    {  
     if(expression[i]=='(')  
        { if(expression[l-i]==')') {
		}         
			else{
				x++; break;
			}   
        }  
     
    else if(expression[i]=='[')  
        { if(expression[l-i]==']') {
			} 
        	else{
				y++; break;
			}
			  
        }  
        
    else if(expression[i]=='{')  
        {  if(expression[l-i]=='}'){
		}         	
			else{
				z++; break;
			}   
        }  
  
    i++;       
    }  
}
else{
	printf("Expression is unbalanced");	
	return 0;
}
    if(x==0&&y==0&&z==0)  
    {  
        printf("Expression is balanced");  
    }  
      
    else  
    {  
        printf("Expression is unbalanced");  
    }  
    return 0;  
}  
