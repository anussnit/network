
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
int perfect(int k);
int main()
{
int serversocket,clientsocket,port,s;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50];
struct serveraddr;
char fib[500]="";
int numrecieved,tr;
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
clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
printf("\n client connectivity received \n");
//write(clientsocket,"enter an integer",sizeof("enter an integer"));
read(clientsocket,&s,sizeof(s));
printf("\n number send from server %d",s);
tr=perfect(s);
printf("%d",tr);
if(tr==0)
{write(clientsocket," the number not perfect number",sizeof(" the number not perfect number"));
}
else
{
write(clientsocket," the number is perfect number",sizeof(" the number is perfect number"));
}
close(serversocket);
close(clientsocket);
return 0;
}
int perfect(int k)
{
int sum=0;
for(int i=1;i<k;i++)
{

  if (k%i==0) {
  sum+=i;
}
}
if (sum==k)
{
 return 1;
}
else 
{
return 0;
}
}



