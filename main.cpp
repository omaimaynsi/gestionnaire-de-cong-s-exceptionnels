#include <istream>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{

	char choix;
	const string ID="1234";
	const string MDP="admin";
	string mdp="",id;
	int lim=3;



do
{
	system("color f4");
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
        case'1': system("cls");
            cout<<"veuillez saisir votre ID \n";
            cin>>ID;
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
                //affichage de la liste des congés
            }
            }
            break;
        case '2':
        case '3': system("cls");
        cout<<"\t\t\t\travail fait par le groupe n°9 de II1F"<<endl;
        cout<<"\n les membres sont:\n";
        cout<<"\t\tWissem Ayat\n\t\tRym Oualha\n\t\tJawhar Mallek\n\t\tOmaima Younsi\n";

        case'h':

		}
        }while ((choix!='q') && (choix!='Q'));
printf("\n\nFermeture\n\n");
return 0;
}
