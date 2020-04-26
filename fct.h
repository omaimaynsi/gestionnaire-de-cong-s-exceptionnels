#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED
#include <bits/stdc++.h>
#define nomFichier "C:/Users/LENOVO/Desktop/test.txt"

using namespace std;

vector<string> split(const string & src, char delim)
{
    vector<string> v;
    int pos=0;
    string m;
    int l=src.size();
    for(int i=0; i<l; i++)
    {
        if (src[i]==delim)
        {
            m=src.substr(pos,i-pos);
            v.push_back(m);
            pos=i+1;
        }
    }
    return v;
}

vector<vector<string> >* upload(void)
{
    vector<vector<string> > *v=new vector<vector<string> >;
    vector<string> c;
    string ligne;
    ifstream BD;
    BD.open(nomFichier); //ouverture d'un fichier en lecture
    if(BD)
    {
        while(getline(BD,ligne))
        {
            c=split(ligne,' ');
            v->push_back(c);
        }
    }
}

void affiche(congebase C)
{
    for(int i=0; i<C.base->size(); i++)
    {
        for(int j=0; j<6; j++)
        {
            cout<<(*(C.base))[i][j]<<" ";
        }
        cout<<endl ;
    }
}

congebase* traitement(congebase C)
{
    for(int i=0; i<C.base->size(); i++)
    {
        if ((*(C.base))[i][4]=="mort")
            (*(C.base))[i][5]="accepte" ;
        else
             (*(C.base))[i][5]="refuse" ;
    }

}

void download(congebase C)
{
    ofstream monFlux(nomFichier);

    if(monFlux)
    {

        for(int i=0; i<C.base->size(); i++)
        {
            for(int j=0; j<6; j++)
            {
                monFlux<<(*(C.base))[i][j]<<" ";
            }
            monFlux<<endl ;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

#endif // FCT_H_INCLUDED
