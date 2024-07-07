#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_MSG_SIZE 500
void error(const char *msg) {
perror(msg);
exit(EXIT_FAILURE);
}
int main() {
int clientSocket, port, number;
struct sockaddr_in serverAddr;
socklen_t len;
char message[MAX_MSG_SIZE], fib[MAX_MSG_SIZE];
// Create UDP socket
clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
if (clientSocket < 0)
error("ERROR opening socket");
// Clear server address structure
bzero((char *) &serverAddr, sizeof(serverAddr));
// Initialize server address structure
port = 8888; // Assuming server is running on port 8888
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(port);
serverAddr.sin_addr.s_addr = INADDR_ANY;

while (1) {
// Prompt user for input
printf("Enter an integer: ");
scanf("%d", &number);
// Send input to server
sprintf(message, "%d", number);
if (sendto(clientSocket, message, strlen(message), 0, (struct
sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)

error("ERROR in sendto");
// Receive Fibonacci series from server
len = sizeof(serverAddr);
int bytesReceived = recvfrom(clientSocket, fib,
MAX_MSG_SIZE, 0, (struct sockaddr *) &serverAddr, &len);
if (bytesReceived < 0)
error("ERROR in recvfrom");
fib[bytesReceived] = '\0'; // Null terminate the received message
printf("Fibonacci series received from server: %s\n", fib);
}
// Close socket
close(clientSocket);
return 0;
}