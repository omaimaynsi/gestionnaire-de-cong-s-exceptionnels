#include <istream>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{

	char choix;
	const string ID="1234";
	const string MDP="admin";
	string mdp="",id,tap;
	int lim=3;



do
{
	system("color f0");
	system("cls");
	cout<<"\t\t\tGestionnaire de conges exeptionnels \n";
	cout<<"\n\t\t\t\tMENU\n";
	cout<<"\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"administrateur  ==> taper 1\n";
	cout<<"employe         ==> taper 2\n";
	cout<<"A propos        ==> taper 3\n";
	cout<<"Quitter         ==> taper Q\n\n";
	cout<<"Votre Choix:\t";
	cin>>choix;
	switch(choix)
		{
//*************************************************************************************************
        case'1': system("cls");
            cout<<"veuillez saisir votre ID \n";
            cin>>id;
            if(id!=ID){
                cout<<"votre ID n'est pas valide \n";
            }
            else{
                cout<<"saisir votre mot de passe\n";
                cin>>mdp;
            if(mdp!=MDP){
                while(lim!=0 && mdp!=MDP)
                cout<<"resaisir votre mot de passe nbre d'esssai est" <<lim<<"\n";
                cin>>mdp;
                lim--;
            }
            else{
                cout<<"informations valides"<<endl;
                //affichage de la liste des cong�s
            }
            }
            break;
//*************************************************************************************************
        case '2':system("cls");
        system("color 74");
        cout<<"saisir votre ID"<<endl;
        cin>>id;
        if(true/* fct verif de id*/){
            system("cls");
            cout<<"Bienvenue sur l'espace employes et conges veuillez saisir votre chois"<<endl;

            cout<<"\n\t\t\t\tMENU\n";
	        cout<<"\t\t*************************\n";
	        cout<<"demande de conge         ==> taper 1\n";
            cout<<"modification de conge    ==> taper 2\n";
            cout<<"suppression de conge      ==> taper 3\n";
            cout<<"Retour au menu principal ==> taper R\n\n";
            cout<<"Votre Choix:\t";
            cin>>choix;
            switch (choix) {

            case'1':// instructions de saisie d'un nouveau conge
                break;
            case'2'://instructions de modification d'un conge
                break;
            case'3'://instruction de supression d'un conge
                break;

            }
                    }
            break;
//*************************************************************************************************
        case '3': system("cls");
        system("color 70");
        cout<<"\t\t\t\*travail fait par le groupe num 9 de II1F*"<<endl;
        cout<<"\n les membres sont:\n";
        cout<<"\t\tWissem Ayat\n\t\tRym Oualha\n\t\tJawhar Mallek\n\t\tOmaima Younsi\n";
        cout<<"\n\n\n\n pour retouner au menu taper sur le clavier \n";
        cin>>tap;

		}
        }while ((choix!='q') && (choix!='Q'));
printf("\n\n\t\t\t\tFin du programme\n\n");
return 0;
}
