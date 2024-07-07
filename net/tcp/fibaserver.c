#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
void finfFibanocci(int numrecieved,char fib[]);
int main()
{
int serversocket,clientsocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50];
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
len=sizeof(clientaddr);
listen(serversocket,5);
printf(" waiting for client connection\n");
printf(" hai");
clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
printf("\n client connectivity received \n");
write(clientsocket,"enter an integer",sizeof("enter an integer"));
read(clientsocket,&numrecieved,sizeof(numrecieved));
printf("\n number send from server %d",numrecieved);
finfFibanocci(numrecieved,fib);
write(clientsocket,fib,sizeof(fib));
close(serversocket);
close(clientsocket);
return 0;
}
void finfFibanocci(int numrecieved, char fib[])
{
int i;
int first=0;
int second=1;
int next=0;
for(i=0;i<numrecieved;i++)
{
if(i<=1)
{
next=i;
}
else
{
next=first+second;
first=second;
second=next;
}
char str[10];
sprintf(str,"%d",next);
strcat(fib,str);
strcat(fib,"");
}
}

