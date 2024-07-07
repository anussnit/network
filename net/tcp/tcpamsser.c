#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int isArmstrong(int num)
{
int num, originalNum, remainder, n = 0;;
for (originalNum = num; originalNum != 0; ++n) {
       originalNum /= 10;
   }

   for (originalNum = num; originalNum != 0; originalNum /= 10) {
       remainder = originalNum % 10;

      // store the sum of the power of individual digits in result
      result += pow(remainder, n);
   }

   // if num is equal to result, the number is an Armstrong number
   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
    return 1;
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}
int main()
{
int numrecieved;
int serversocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
char message[50];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf(" enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\n waiting for the client connection\n");
bzero((char*)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
recvfrom(serversocket,&numrecieved,sizeof(numrecieved),0,(struct sockaddr*)&clientaddr,&len);
printf("\n the client sent number:\t %d\n",numrecieved);
if(isArmstrong(numrecieved))
{
sendto(serversocket,"the number is Armstrong",sizeof("the number is Armstrong"),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
}
close(serversocket);
}
