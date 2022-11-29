#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;
int CreateServer(int PORT)
{
    int sfd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    const int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

    cout << "Created socket.." << endl;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(sfd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    cout << "Binded socket to address.." << endl;
    if (listen(sfd, SOMAXCONN) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    cout << "Socket listening on port " << PORT << endl;
    return sfd;
}
int ConnectToServer(int PORT)
{
    int sfd, valread;
    struct sockaddr_in address;
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    cout << "Socket created" << endl;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    cout << "Connecting to the server ..." << endl;
    while (connect(sfd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("connect");
        cout << "Connection failed, retrying in 5 seconds" << endl;
        sleep(5);
    }
    cout << "Connection established...\n";
    return sfd;
}

string ReadFD(int fd)
{
    string s = "";
    char ch;
    while (true)
    {
        int n = read(fd, &ch, 1);
        if (n <= 0 || ch == '\0')
        {
            break;
        }
        s.push_back(ch);
    }
    return s;
}
int WriteFD(int fd, string s)
{
    s.push_back('\0');
    return write(fd, s.c_str(), s.size());
}
int StringToInt(string s)
{
    return stoi(s);
}
string IntToString(int n)
{
    return to_string(n);
}
