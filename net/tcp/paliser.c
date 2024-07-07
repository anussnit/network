#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
int pali(char str[]);
int main()
{
int serversocket,clientsocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50],str[200];
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
printf(" hai");
clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
printf("\n client connectivity received \n");
//write(clientsocket,"enter an integer",sizeof("enter an integer"));
read(clientsocket,str,sizeof(str));
printf("\n number send from server %s",str);
tr=pali(str);
printf("%d",tr);
if(tr==0)
{write(clientsocket," the string is notpalindrome",sizeof("the string is notpalindrome"));
}
else
{
write(clientsocket," the string is palindrome",sizeof("the string is palindrome"));
}
close(serversocket);
close(clientsocket);
return 0;
}
int pali(char str[])
{
int len=strlen(str);
for(int i=0;i<len/2;i++)
{

  if (str[i] == str[len-i-1]) {
    return 1;
}else
break;
}
  return 0;
}


