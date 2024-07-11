#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
int main()
{
int clientsocket,port,n;
struct sockaddr_in serveraddr;
socklen_t len;
struct hostnet *server;
char message[50];
clientsocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf(" enter tbe port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
sendto(clientsocket,"Hi",sizeof("Hi"),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
recvfrom(clientsocket,&n,sizeof(n),0,(struct sockaddr*)&serveraddr,&len);
printf("%d",n);
close(clientsocket);
}

