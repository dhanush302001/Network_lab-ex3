#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int i,j,k,n,p,n1,c,m,input_data[20],temp,originalData[20];
 int carry;
 char *str;
 int binary[30][10],data[30],position[10],count;
 str=(char*)malloc(40*sizeof(char));
 printf("Enter the data : ");
 scanf("%s",str);
 n=strlen(str);
 for(i=0;i<n;i++)
  input_data[i]=(int)str[i]-48;
 p=1;
 while(pow(2,p)<(n+p+1))
  p+=1;
 m=n+p;
 n1=1;
 while(pow(2,n1)<m) 
  n1+=1;
 for(i=0;i<=m;i++)
  data[i]=0;
 for(i=0;i<p;i++)
  position[i]=0;
 for(i=0;i<=m;i++)
 { 
  for(j=0;j<n1;j++)
   binary[i][j]=0;
 }
 for(i=1;i<=m;i++)
 {
  carry=1;
  for(j=0;j<n1;j++)
  {
   temp=binary[i-1][j];
   binary[i][j]=binary[i-1][j]^carry;
   carry=temp&carry;
  }
 }
 j=0;k=n-1;
 for(i=1;i<=m;i++)
 {
  if(i<pow(2,j))
  {
   data[i]=input_data[k];
   k--;
  }
  if(i==pow(2,j))
  {
   data[i]=0;
   j+=1;
  }
 }
 for(i=0;i<n1;i++)
 {
  temp=pow(2,i);
  count=0;
  for(j=temp+1;j<=m;j++)
  {
   if(binary[j][i]==1)
   {
    if(data[j]==1)
     count+=1;
   }
  }
  if(count%2==0)
   data[temp]=0;
  else
   data[temp]=1;
 }
 printf("Send data : ");
 for(i=m;i>0;i--)
  printf("%d ",data[i]);
 int changeBit;
 printf("\nEnter the bit index to change :");
 scanf("%d",&changeBit);
 if(changeBit!=-1)
 {
  if(data[changeBit]==0)
   data[changeBit]=1;
  else
   data[changeBit]=0;
 }
 printf("\nReceived data : ");
 for(i=m;i>0;i--)
  printf("%d ",data[i]);
 for(i=0;i<n1;i++)
 {
  temp=pow(2,i);
  count=0;
  for(j=temp;j<=m;j++)
  {
   if(binary[j][i]==1)
   {
    if(data[j]==1)
     count+=1;
   }
  }
  if(count%2==0)
   position[i]=0;
  else
   position[i]=1;
 }
 int errorPosition=0;
 for(i=0;i<n1;i++)
  errorPosition+=(position[i]*((int)pow(2,i)));
 if(errorPosition==0)
  printf("\nThere is no error");
 else
 {
  printf("\nThe error position: %d",errorPosition);
  if(data[errorPosition]==1)
   data[errorPosition]=0;
  else
   data[errorPosition]=1;
  printf("\nThe Corrected Receive data: ");
  for(i=m;i>0;i--)
   printf("%d ",data[i]);
 }
 k=0;j=0;
 for(i=1;i<m+1;i++)
 {
  temp=pow(2,k);
  if(i==temp)
   k++;
  else
  {
   originalData[j]=data[i];
   j++;
  }
 }
 printf("\nThe Original Data is : ");
 for(i=n-1;i>=0;i--)
    printf("%d",originalData[i]);
 printf("\n");
 return 0;
}


