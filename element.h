#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <iostream>

class Reel;
class Entier;
class Rationnel;
class Constante;
class Complexe;

class Element
{
    public:
        Element();
        virtual ~Element();
        /**
        * Les classes filles de Element doivent pouvoir
        * �tre transformer en toutes autres classe filles
        * en fonction du mode de la calculette
        */

        /**
        * \fn virtual Qstring toQstring()
        * \brief transforme l'�l�ment en Qstring pour l'afficher sur la calculatrice
        * Fonction virtual pure qui doit �tre impl�menter par toutes les classes filles
        */
        virtual QString toQString() const = 0;

        /**
        * \fn  virtual QString toReel() = 0;
        * \brief transforme l'�l�ment en r�el pour pouvoir l'utiliser
        * Fonction virtual pure qui doit �tre impl�menter par toutes les classes filles
        */

        virtual Reel& toReel() = 0;
        virtual Rationnel& toRationnel() = 0;
        virtual Entier& toEntier() = 0;
        virtual Complexe& toComplexe() = 0;
};

class Constante : public Element
{
    public:
        Constante();
        virtual ~Constante();
        virtual QString toQString() const = 0;
        virtual Reel& toReel() = 0;/*!< /todo quelle retour mettre reel? */
        virtual Rationnel& toRationnel() = 0; /*! idem */
        virtual Entier& toEntier() = 0; /*! idem */
        virtual Complexe& toComplexe() = 0; /*! idem */
        virtual void afficher(std::ostream& f=std::cout) const = 0;
        virtual Constante& operator+(Constante& c) = 0;
        virtual Constante& operator-(Constante& c) = 0;
        virtual Constante& operator/(Constante& c) = 0;
        virtual Constante& operator*(Constante& c) = 0;
    };


class Reel : public Constante
{
    private:
        float x;

    public:
        Reel(float r);
        Reel(const Reel& c);
        ~Reel();
        float getX () const;
        void setX(float value);
        QString toQString() const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Reel& operator+(Constante& c);
        Reel& operator-(Constante& c);
        Reel& operator/(Constante& c);
        Reel& operator*(Constante& c);

};


class Rationnel : public Constante
{

    private:
        int x;
        int y;
    public:
        Rationnel(int x, int y = 1);
        ~Rationnel(){}
        QString toQString () const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Rationnel& operator+(Constante& c);
        Rationnel& operator-(Constante& c);
        Rationnel& operator/(Constante& c);
        Rationnel& operator*(Constante& c);


};



class Entier : public Constante
{
    private :
        int x;
    public:
        Entier(int r);
        ~Entier(){}
        QString toQString() const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Entier& operator+(Constante& c);
        Entier& operator-(Constante& c);
        Entier& operator/(Constante& c);
        Entier& operator*(Constante& c);

};

class Complexe : public Element
{
    private:
       Constante* re;
       Constante* im;
    public:
        Complexe(Constante* x, Constante* y = 0);
        ~Complexe(){}
        QString toQString() const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Complexe& operator+(Constante& c);
        Complexe& operator-(Constante& c);
        Complexe& operator/(Constante& c);
        Complexe& operator*(Constante& c);
};



#endif // ELEMENT_H
