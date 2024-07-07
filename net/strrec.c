#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int main()
{
int number,nu;
int clientsocket,port,num[100];
struct sockaddr_in serveraddr;
socklen_t len;
struct hostent *server;
char message[50],str[100];
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
//printf(" enter a string to be sent to the server");
//scanf("%s",str);
printf(" enter the 1 numbers");
scanf(" %d",&num[0]);
printf(" enter the 2 numbers");
scanf(" %d",&num[1]);
sendto(clientsocket,num,sizeof(num),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
//recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
//printf("\n %s",message);
recvfrom(clientsocket,num,sizeof(num),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf(" the sum is %d ",num[2]);
close(clientsocket);
}
