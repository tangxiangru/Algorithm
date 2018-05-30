
#include<iostream> 

#include<string.h> 

using namespace std; 

//一个字符8位 最大256种 

#define MAX_CHAR_SIZE 256 

  

/*设定每个字符最右移动步长，保存每个字符的移动步长 

如果大串中匹配字符的右侧一个字符没在子串中，大串移动步长= 整个串的距离 +1 

   如果大串中匹配范围内的右侧一个字符在子串中，大串移动距离= 子串长度 - 这个字符在子串中的位置 

*/ 

int *setCharStep(char *subStr) 

{ 

     int *charStep=new int[MAX_CHAR_SIZE]; 

     int subStrLen=strlen(subStr); 

     for(int i=0;i<MAX_CHAR_SIZE;i++) 
             charStep[i]=subStrLen+1; 
     //从左向右扫描一遍 保存子串中每个字符所需移动步长 

     for(int i=0;i<subStrLen;i++) 

     { 
            charStep[(unsigned char)subStr[i] ]=subStrLen-i;          
     } 

     return charStep; 

} 

/* 

   算法核心思想，从左向右匹配，遇到不匹配的看大串中匹配范围之外的右侧第一个字符在小串中的最右位置 

   根据事先计算好的移动步长移动大串指针，直到匹配 

*/ 

int sundaySearch(char *mainStr,char *subStr,int *charStep) 

{ 

     int mainStrLen=strlen(mainStr); 
     int subStrLen=strlen(subStr); 
     int main_i=0; 
     int sub_j=0; 
     while(main_i<mainStrLen) 
     {                   
            //保存大串每次开始匹配的起始位置，便于移动指针 
             int tem=main_i; 
             while(sub_j<subStrLen) 
             { 
                    if(mainStr[main_i] ==   subStr[sub_j]) 
                    { 
                            main_i++; 
                            sub_j++; 
                            continue;                    
                    }                 
                    else{ 
                        //如果匹配范围外已经找不到右侧第一个字符，则匹配失败 
                         if(tem+subStrLen > mainStrLen) 
                                     return -1; 
                         //否则 移动步长 重新匹配 
                         char firstRightChar=mainStr[tem+subStrLen]; 
                         main_i =tem + charStep[(unsigned char)firstRightChar]; 
                         sub_j=0;    
                         break;//退出本次失败匹配 重新一轮匹配 
                    }   
             } 
             if(sub_j == subStrLen) 
                       return main_i-subStrLen; 
     } 
     return -1; 
} 

int main() 
{ 
         char *mainStr="absaddsasfasdfasdf"; 
         char *subStr="dd"; 
         int *charStep=setCharStep(subStr); 
         cout<<"位置： "<<sundaySearch(mainStr,subStr,charStep)<<endl; 
         system("pause"); 
         return 0;
} 

