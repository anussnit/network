#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
#include<unistd.h>
int main()
{
int clientsocket,port;
struct sockaddr_in serveraddr;
socklen_t len;
char message[500],str[100];
int number;
clientsocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf(" enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
printf("\n trying to connect to the server\n");
connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\n connected to the server.\n");
printf("Enter a string: ");
  scanf("%s", str);
send(clientsocket,str,sizeof(str),0);
recv(clientsocket,message,sizeof(message),0);
printf("\n %s",message);
close(clientsocket);
}

