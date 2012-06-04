#ifndef PILE_H
#define PILE_H
#include <QStack> /*!< Pour pouvoir utiliser Qstack*/
#include <iostream>
#include "element.h"

/**
 * \class Pile
 * \brief Classe permetant de g�rer une pile d'�l�ment.
 * Impl�mentation avec le design patern singleton
 */

class Pile{

    private:

        QStack<Element*>* pile; /*!< Impl�mentation de Qstack pour la pile, pile de pointeur de valeur*/
        static Pile* instanceUnique;/*!< Pointeur unique sur instance */
        Pile();
        Pile(const Pile&);
        ~Pile();

    public:

        static Pile& donneInstance();
        static void libereInstance();
        QStack<Element*> getPile()const;
        void empilerElement(Element * e);
        Element* depilerElement();
        void swap(const unsigned int x,const unsigned int y);
        void dup();
        void drop();
        void clear();
        Constante& addition();
        Constante& multiplication();
        Constante& soustraction();
        Constante& division();
        Constante& pow();
        Constante& cos();
        Constante& sin();
        Constante& tan();
        Constante& cosh();
        Constante& sinh();
        Constante& tanh();
        Constante& ln();
        Constante& log();
        Constante& inv();
        Constante& sqrt();
        Constante& sqr();
        Constante& operator!();
};

#endif // PILE_H

