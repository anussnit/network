#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
int main()
{
int serversocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf(" enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char *)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
recvfrom(serversocket,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&len);
printf("\n %s \n",message);
int n;
printf(" enter the number");
scanf("%d",&n);
sendto(serversocket,&n,sizeof(n),0,(struct sockaddr*)&clientaddr,len);
close(serversocket);
}
