#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int main()
{
int number;
int clientsocket,port;
struct sockaddr_in serveraddr;
socklen_t len;
struct hostent *server;
char message[50];
clientsocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf(" enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
fgets(message,2,stdin);
if(connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof (serveraddr))<0)
{
printf("\n connection failed\n");
exit(0);
}
else
{
printf("\n connection successful\n");
}
printf(" enter a number to be sent to the server");
scanf("%d",&number);
sendto(clientsocket,&number,sizeof(number),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
printf("\n %s",message);
close(clientsocket);
}
