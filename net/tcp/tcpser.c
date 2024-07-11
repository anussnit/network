#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
int main()
{
FILE *f1;
int serversocket,clientsocket,port,sin;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
struct serveraddr;
char message[50],rec[50];
f1=fopen("log.txt","w");
serversocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf("enter the port \n");
scanf("%d",&port);
fprintf(f1," waiting for connection \n port address : %d \n connection established \n",port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char*)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
listen(serversocket,5);
clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
do
{
read(clientsocket,rec,sizeof(rec));
printf("\n client : %s \n",rec);
if(strcmp(rec,"end")==0)
{
fprintf(f1,"\n client : connection stopped \n");
break;
}
fprintf(f1,"\n client : %s \n",rec);
printf("\n server : ");
scanf("%s",message);
fprintf(f1,"\n server : %s \n",message);
write(clientsocket,message,sizeof(message));
}
while((strcmp(message,"end")!=0));
close(clientsocket);
close(serversocket);
fclose(f1);
}
