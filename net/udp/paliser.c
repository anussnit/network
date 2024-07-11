#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
#include<string.h>
int ispali(char str[]);
int main()
{
int serversocket,port,tr;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50],str[50];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf(" enter the port number ");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char *)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
recvfrom(serversocket,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&len);
printf(" \n string %s ",message);
tr=ispali(message);
if(tr==1)
sendto(serversocket,"palindrome",sizeof("palindrome"),0,(struct sockaddr*)&clientaddr,len);
else
sendto(serversocket,"not palindrome",sizeof("not palindrome"),0,(struct sockaddr*)&clientaddr,len);
close(serversocket);
}
int ispali(char str[])
{
int len=strlen(str);
printf("%d",len);
for(int i=0;i<len/2;i++)
{
if(str[i]==str[len-i-1])
return 1;
else
return 0;
}
}

