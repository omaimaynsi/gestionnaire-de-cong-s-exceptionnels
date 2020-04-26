#include <iostream>
#include <bits/stdc++.h>
#include "congebase.h"
#include "fct.h"



using namespace std;



int main()
{
    vector<vector<string> >* T=new vector<vector<string> >;
    T=upload();
    congebase C=congebase(T);
    affiche(C);
    traitement(C);
    cout<<endl ;
    affiche(C);
    // download(C); //si activé transforme le fichier texte

    return 0 ;
}
