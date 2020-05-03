#include <iostream>

using namespace std;

int main ()
{
    int n, k, mdp, p, id ;

    do
    {

        do
        {
            printf(" \n \n ************************************** GESTIONNAIRE DE CONGE *************************************** \n \n");
            printf(" * 1 * ESPACE ADMINISTRATEUR \n");
            printf(" * 2 * ESPACE EMPLOYE \n");
            printf(" * 3 * QUITTER LE PROGRAMME \n \n");
            printf("  SAISISSEZ VOTRE CHOIX : ");
            cin>>n;
        }
        while(n<0 || n>3);
        cout<<endl ;
        switch(n)
        {
        case 1 :

            cout<< " BIENVENUE DANS L'ESPACE ADMINISTRATEUR"<<endl;
            do
            {
                cout<<" *1* SAISIR VOTRE MOT DE PASSE  "<<endl;
                cout<<" *2* RETOURNER AU MENU PRINCIPAL "<<endl;
                cin>>k ;
            }
            while(k<0 || k>2) ;

            switch(k)
            {
            case 1 :
                cout<<" TAPER VOTRE MOT DE PASSE :"<<endl ;
                cin>> mdp ;
                // chnouwa yssir lena ???
                break ;

            case 2 :
                break;
            }

            break;

        case 2 :
            cout<<" BIENVENUE DANS L'ESPACE EMPLOYE :"<<endl;
            do
            {
                cout<<" *1* DEPOSER UNE DEMANDE DE CONGE "<<endl;
                cout<<" *2* SUPPRIMER UNE DEMANDE DE CONGE "<<endl;
                cout<<" *3* VERIFIER UNE DEMANDE DE CONGE "<<endl;
                cout<<" *4* RETOURNER AU MENU PRINCIPAL "<<endl;
                cin>>p ;
            }
            while(p<0 || p>4) ;
            switch(p)
            {
            case 1 :
                cout<<" TAPER VOTRE ID :"<<endl ;
                cin>> id ;
                //verification de l'identite avec le numero de l'id
                // demande
                break ;

            case 2 :
                cout<<" suppression"<<endl ;
                //suppresion
                break;
            case 3 :
                cout<<" verification"<<endl ;
                //verification
                break;
            case 4 :
                break;
            }
            break;


        case 3 :
            break;

        }

    }
    while (n!=3);



    return 0;

}
