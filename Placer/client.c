#include "../grille/Socket.h"
SOCKET sock;
void client(void){
 #if defined (WIN32)
        WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #else
        int erreur = 0;
    #endif
 

    SOCKADDR_IN sin;
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr("localhost"); // localhost, 127.0.0.1
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
        /* Si le client arrive à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
            printw("Connexion à %s sur le port %d \n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
        else
            printw("Impossible de se connecter\n");
 
        /* On ferme la socket précédemment ouverte */
        closesocket(sock);
 
        #if defined (WIN32)
            WSACleanup();
        #endif
    }
}
