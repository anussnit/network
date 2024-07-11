#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
int main()
{
int clientsocket,port;
struct sockaddr_in serveraddr;
socklen_t len;
char message[50],sedi[50];
clientsocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf(" enter the port \n");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
do
{
printf("\n client : ");
scanf("%s",sedi);
send(clientsocket,sedi,sizeof(sedi),0);
if(strcmp(sedi,"end")==0)
break;
recv(clientsocket,message,sizeof(message),0);
printf("\n server: %s \n",message);
}
while((strcmp(message,"end")!=0));
close(clientsocket);
}

