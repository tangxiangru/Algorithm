#include<iostream>
using namespace std;
void GetNext(char T[ ], int next[ ]){
  int i, j, len;
  next[0] = -1;
  for (j = 1; T[j]!='\0'; j++){
    for (len = j - 1; len >= 1; len--){
      for (i = 0; i < len; i++)
      if (T[i] != T[j-len+i])
      break;
    if (i == len){
        next[j] = len; break;
      }
    }
    if (len < 1)
    next[j] = 0;
  }
}

int KMP(char S[ ], char T[ ]) {
  int i = 0, j = 0;int next[80];
  GetNext(T, next);
  while (S[i] != '\0' && T[j] != '\0'){
    if (S[i] == T[j]){
      i++; j++;}
      else{j = next[j];
        if (j == -1) {
          i++; j++;}
        }
      }
      if (T[j] == '\0')
      return (i - strlen(T) +1);
      else
      return 0;
    }

int main(){
  char s[40];
  char t[10];
  int location;
  cout<<"enter s:\n";
  cin.getline(s,39);
  cout<<"enter t:\n";
  cin.getline(t,9);
  location=KMP(s,t);
  if (location!=-1)
  cout<<"t is in"<<location<<"of s.\n";
  else
  cout<<"can not match t from s.\n";
  return 0;


}
