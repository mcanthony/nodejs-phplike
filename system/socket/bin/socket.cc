#include <iostream>
#include <stdlib.h>
#include "stdio.h"
#include "../src/socket.h"
using namespace std;

int main() {
    int sockfd;
    char sysHost[255] = "localhost"; 
    sockfd = phplikeSocketConnect(sysHost, 3306);
    if (sockfd < 0) {
        close(sockfd);
        return 1;
    }

    //send message
    //char msg[20] = "aaaaaab";
    //phplikeSocketSend(sockfd, msg);


    char *buf;
    unsigned int resLength;
    buf = phplikeSocketReceive(sockfd, 12, &resLength);
    cout << "res length = " << resLength <<endl;
    for(int j=0; j< resLength;j++)   {
        printf("%2X ", buf[j]);
    }
    phplikeSocketClose(sockfd);
    free(buf);

  //  //receive messagie
  //  char *buf;
  //  buf = phplikeSocketReceive(sockfd, 2000);
  //  cout << "response = " << buf <<endl;
  //  phplikeSocketClose(sockfd);
  //  free(buf);


    return 1;
}
