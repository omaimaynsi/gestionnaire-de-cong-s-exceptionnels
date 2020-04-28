#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <bits/stdc++.h>
#define nomFichier "C:/Users/ASUS/Downloads/test.txt"

using namespace std;
typedef struct
{
    int jour, mois, annee;
} Date;

vector<string> split(const string &src, char delim)
{
    vector<string> v;
    int pos = 0;
    string m;
    int l = src.size();
    for (int i = 0; i < l; i++)
    {
        if (src[i] == delim)
        {
            m = src.substr(pos, i - pos);
            v.push_back(m);
            pos = i + 1;
        }
    }

    return v;
}

Liste_Conge *deposer(void)
{
    Liste_Conge *v;
    vector<string> *c, *b;
    string ligne;
    ifstream BD;
    BD.open(nomFichier); //ouverture d'un fichier en lecture
    if (BD)
    {
        while (getline(BD, ligne))
        {
            *c = split(ligne, ' ');
            *b = split((*c)[2], '/');
            Date d = {stoi((*b)[0]), stoi((*b)[1]), stoi((*b)[2])};
            Conge *con = new Conge(stoi((*c)[0]), (*c)[1], d, stoi((*c)[2]), stoi((*c)[3]));

            (*v).ajouter(con);
        }
        return v;
    }
}

class Post
{
private:
    string Nom;
    static map<string, int> Effectif;
    static map<string, int> Min_Effectif;

public:
    Post(string nom, int min_eff)
    {
        Nom = nom;

        if (Effectif.find(Nom) == Effectif.end())
        {
            Effectif[Nom] = 1;
            Min_Effectif[Nom] = min_eff;
        }
    }
    ~Post()
    {
        Effectif[Nom]--;
    }
    static bool verif(string name)
    {
        if (Effectif.find(name) != Effectif.end())
        {
            return true;
        }
        if (Effectif.find(name) == Effectif.end())
        {
            return false;
        }
    }
    static void increment(string Nom)
    {
        if (Effectif.find(Nom) != Effectif.end())
        {
            Effectif[Nom]++;
        }
    }
    static void decrement(string Nom)
    {
        if (Effectif.find(Nom) != Effectif.end())
        {
            Effectif[Nom]++;
        }
    }
};
map<string, int> Post::Effectif = {};
map<string, int> Post::Min_Effectif = {};

class Personne
{
private:
    int ID;
    string Nom;
    string Prenom;

public:
    int GetID() const
    {
        return ID;
    }

    void SetID(int ID)
    {
        ID = ID;
    }

    string GetNom() const
    {
        return Nom;
    }

    void SetNom(string Nom)
    {
        Nom = Nom;
    }

    string GetPrenom() const
    {
        return Prenom;
    }

    void SetPrenom(string Prenom)
    {
        Prenom = Prenom;
    }

    Personne(int n, string nom, string prenom)
    {
        ID = n;
        Nom = nom;
        Prenom = prenom;
    }
};
class Employe : public Personne
{
private:
    int MDP;
    int Filiale;
    int Status;
    string Poste;

public:
    void affichage()
    {
        cout << GetID() << "  " << GetNom() << "  " << GetPrenom() << "  " << GetMDP() << "  " << GetFiliale() << "  " << GetStatus() << "  " << GetPoste() << endl;
    }
    int GetMDP() const
    {
        return MDP;
    }

    void SetMDP(int MDP)
    {
        MDP = MDP;
    }

    int GetFiliale() const
    {
        return Filiale;
    }

    void SetFiliale(int Filiale)
    {
        Filiale = Filiale;
    }

    int GetStatus() const
    {
        return Status;
    }

    void SetStatus(int Status)
    {
        Status = Status;
    }

    string GetPoste() const
    {
        return Poste;
    }

    void SetPoste(string Poste)
    {
        Poste = Poste;
    }

    Employe(int n, string nom, string prenom, int mdp, int fil, int stat, string pos) : Personne(n, nom, prenom)
    {
        MDP = mdp;
        Filiale = fil;
        Status = stat;
        Poste = pos;
        if (Post::verif(pos))
        {
            Post::increment(pos);
        }
        else
        {
            cout << "donner l'eefectif minimal de cette poste" << endl;
            int x;
            cin >> x;
            Post Postex = Post(Poste, x);
        }
    }
    ~Employe()
    {
        Post::decrement(Poste);
    }
};
class Liste_employe
{
    vector<Employe *> vect;
    int taille;

public:
    Liste_employe() { taille = 0; };
    ~Liste_employe()
    {
        vector<Employe *>::iterator pos;
        vector<Employe *>::iterator pos1;
        for (pos = vect.begin(); pos != vect.end(); pos++)
            delete *pos;
    }
    vector<Employe *> get_vect()
    {
        return vect;
    }
    void ajouter(Employe *p)
    {
        vect.push_back(p);
        taille++;
    }
    bool existe(Employe *p)
    {
        vector<Employe *>::iterator pos;
        vector<Employe *>::iterator pos1;
        bool test = false;
        for (pos = vect.begin(); pos != vect.end() && test == false; pos++)
        {
            if ((*pos)->GetID() == p->GetID())
                return true;
        }
        return test;
    }
    void supprimer(Employe *p)
    {
        vector<Employe *>::iterator pos;
        vector<Employe *>::iterator pos1;
        bool test = false;
        if (existe(p))
        {
            for (pos = vect.begin(); pos != vect.end() && test == false; pos++)
            {
                if ((*pos)->GetID() == p->GetID())
                    test = true;
            }
            if (test)
            {
                for (pos1 = pos; pos1 != (vect.end() - 1); pos1++)
                {
                    *pos1 = *pos;
                }
            }
            taille--;
        }
        else
            cout << "n'existe pas!!!" << endl;
    }
    void afficher()
    {

        vector<Employe *>::iterator pos;
        vector<Employe *>::iterator pos1;
        for (pos = get_vect().begin(); pos != get_vect().end(); pos++)
        {
            (*pos)->affichage();
        }
    }
};
class Conge
{
private:
    int ID;
    string Name;

    Date debut;
    int duree;
    int cause;

public:
    Conge(int id, string s, Date d, int dur, int caus)
    {
        ID = id;
        debut = d;
        duree = dur;
        cause = caus;
        Name = s;
    }
    ~Conge() {}
    string GetName() const
    {
        return Name;
    }

    void SetName(string Name)
    {
        Name = Name;
    }
    int GetCause() const
    {
        return cause;
    }

    void SetCause(int cause)
    {
        cause = cause;
    }
    int GetID() const
    {
        return ID;
    }

    void SetID(int ID)
    {
        ID = ID;
    }

    Date GetDebut() const
    {
        return debut;
    }

    void SetDebut(Date debut)
    {
        debut = debut;
    }

    int GetDuree() const
    {
        return duree;
    }

    void SetDuree(int duree)
    {
        duree = duree;
    }
    void affichage()
    {
        cout << GetID() << "  " << GetDebut().annee << "//" << GetDebut().mois << "//" << GetDebut().jour << "  " << GetDuree() << endl;
    }
};
class Liste_Conge
{
    vector<Conge *> vect;
    int taille;

public:
    Liste_Conge() { taille = 0; };
    ~Liste_Conge()
    {
        vector<Conge *>::iterator pos;
        vector<Conge *>::iterator pos1;
        for (pos = vect.begin(); pos != vect.end(); pos++)
            delete *pos;
    }
    vector<Conge *> get_vect()
    {
        return vect;
    }
    void ajouter(Conge *p)
    {
        vect.push_back(p);
        taille++;
    }
    bool existe(Conge *p)
    {
        vector<Conge *>::iterator pos;
        vector<Conge *>::iterator pos1;
        bool test = false;
        for (pos = vect.begin(); pos != vect.end() && test == false; pos++)
        {
            if ((*pos)->GetID() == p->GetID())
                return true;
        }
        return test;
    }
    void supprimer(Conge *p)
    {
        vector<Conge *>::iterator pos;
        vector<Conge *>::iterator pos1;
        bool test = false;
        if (existe(p))
        {
            for (pos = vect.begin(); pos != vect.end() && test == false; pos++)
            {
                if ((*pos)->GetID() == p->GetID())
                    test = true;
            }
            if (test)
            {
                for (pos1 = pos; pos1 != (vect.end() - 1); pos1++)
                {
                    *pos1 = *pos;
                }
            }
            taille--;
        }
        else
            cout << "n'existe pas!!!" << endl;
    }
    void analyse()
    {
        vector<Conge *>::iterator pos;
        vector<Conge *>::iterator pos1;

        for (pos = vect.begin(); pos != vect.end(); pos++)
        {
            if ((*pos)->GetCause() == 1)
            {
                cout << "la demande de " << (*pos)->GetName() << "est acceptee";
            }
            else
            {
                cout << "la demande de " << (*pos)->GetName() << "n'est pas acceptee";
            }
        }
    }
    void afficher()
    {

        vector<Conge *>::iterator pos;
        vector<Conge *>::iterator pos1;
        for (pos = get_vect().begin(); pos != get_vect().end(); pos++)
        {
            (*pos)->affichage();
        }
    }
};
int main(int argc, const char **argv)
{
    /*Personne e(14, "fa", "fg");
    Post p("fg", {});
    Employe(5, "gt", "az", 4, 7, 1, "inf");

    cout << e.GetID();

    cout << "hello chabbe";*/
    Liste_Conge L;

    return 0;
}
