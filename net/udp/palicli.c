#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
int main()
{
int clientsocket,port;
struct sockaddr_in serveraddr;
socklen_t len;
struct hostnet *server;
char message[50],str[50];
clientsocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf(" enter the port number ");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
printf("\n enter the string ");
scanf("%s",str);
sendto(clientsocket,str,sizeof(str),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
printf(" %s ",message);
close(clientsocket);
}

