#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int isPali(char str[])
{
int len;
len=strlen(str);
printf(" len %d ",len);
int i;
for(i=0;i<=len/2;i++)
{
if(str[i]==str[len-1-i])
return 1;
else
{
return 0;
break;
}
}
}
int main()
{
int numrecieved,num[100];
int serversocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50],str[100],rev[100];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf(" enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\n waiting for the client connection\n");
bzero((char*)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
recvfrom(serversocket,num,sizeof(num),0,(struct sockaddr*)&clientaddr,&len);
printf("\n the client sent number:\t %d %d\n",num[0],num[1]);
//if(isPali(str))
//{
//int l;
//l=strlen(str);
//for(int i=0;i<l;i++)
//rev[i]=str[l-1-i];
//printf(" rev %s ",rev);
num[2]=num[0]+num[1];
sendto(serversocket,num,sizeof(num),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
//}
//else
//{
//sendto(serversocket,"the string is not palindrome",sizeof("the string is not palindrome"),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
//}
close(serversocket);
}
