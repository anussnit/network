#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_MSG_SIZE 500
char message[MAX_MSG_SIZE];
void error(const char *msg) {
perror(msg);
exit(EXIT_FAILURE);
}
int main() {
int serverSocket, port, number;
struct sockaddr_in serverAddr, clientAddr;
socklen_t len;
//char message[MAX_MSG_SIZE];
// Create UDP socket
serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
if (serverSocket < 0)
error("ERROR opening socket");
// Clear server address structure
bzero((char *) &serverAddr, sizeof(serverAddr));
// Initialize server address structure
port = 8888; // Choose any available port
serverAddr.sin_family = AF_INET;
serverAddr.sin_addr.s_addr = INADDR_ANY;
serverAddr.sin_port = htons(port);
// Bind socket to address
if (bind(serverSocket, (struct sockaddr *) &serverAddr,
sizeof(serverAddr)) < 0)
error("ERROR on binding");
printf("Server is listening on port %d...\n", port);

while (1) {
len = sizeof(clientAddr);
// Receive message from client
int bytesReceived = recvfrom(serverSocket, message,
MAX_MSG_SIZE, 0, (struct sockaddr *) &clientAddr, &len);
if (bytesReceived < 0)
error("ERROR in recvfrom");
printf("Message received from client: %s\n", message);
// Convert received message to integer
sscanf(message, "%d", &number);
// Calculate Fibonacci series
int next=number;
char fib[MAX_MSG_SIZE] = "";
if (number == 0)
next=1;
else
for (int i = 1; i < number; i++)
{
next*=i;
printf(" ss %d ", next);
}
//sprintf(message, "%d", next);
sprintf(fib,"%d",next);
//strcat(fib, message);
//strcat(fib, " ");
// Send Fibonacci series back to client
if (sendto(serverSocket, fib, strlen(fib), 0, (struct sockaddr *)
&clientAddr, len) < 0)

error("ERROR in sendto");
}
// Close socket

close(serverSocket);
return 0;
}
