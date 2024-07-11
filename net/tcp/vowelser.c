#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<ctype.h>
int main()
{
int serversocket,clientsocket,port,lens,count[6];
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char str[200],vowel[200]="aeiou";
struct serveraddr;
char fib[500]="";
int numrecieved;
serversocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf(" enter the port number ");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char*)&clientaddr,sizeof(clientaddr));
lens=sizeof(clientaddr);
listen(serversocket,5);
printf(" waiting for client connection\n");
printf(" hai");
clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
printf("\n client connectivity received \n");
//write(clientsocket,"enter an integer",sizeof("enter an integer"));
read(clientsocket,str,sizeof(str));
printf("\n number send from server %s",str);
//printf("%s",str);
lens=strlen(str);
for(int i=0;i<len;i++)
{
str[i]=tolower((unsigned char)str[i]);
}
//printf("y %s ",str);
count[5]=0;
for(int i=0;i<5;i++)
{
count[i]=0;
for(int j=0;j<lens;j++)
{
if(vowel[i]==str[j])
{
count[i]+=1;
}
}
//printf("\n %d ",count[i]);
count[5]+=count[i];
}
//printf(" %d ", count[5]);
write(clientsocket,count,sizeof(count));
close(serversocket);
close(clientsocket);
return 0;
}

