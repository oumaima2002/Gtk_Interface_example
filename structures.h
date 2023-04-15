//
// Created by gx178 on 4/7/2023.
//

#ifndef INTERFACE_STRUCTURES_H
#define INTERFACE_STRUCTURES_H
//
// Created by gx178 on 3/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>



///*******************les structures utilises*****************///
typedef struct
{
    gchar* tooltip;// information de l'element qui  apparaisse l'orsque on pose la souris sur une image
    gchar* path;//le lien de l'image
    int posx;//position d'abcisse pour l'image
    int posy;//position d'ordonne pour l'image
    GtkWidget *icone;// entite image attribueé par la suite a un element
}image;//structure utilise pour  l'habillage d'un element par une image

typedef struct
{
    gboolean vertical;//l'orientation vertical du box
    gboolean horizontal;//l'orientation horizontal du box
    gint espace;// espace entre les objet dans le conteneur
    gint pack ;  //  haut ou bas
    gboolean homogen;// les objet occupe meme taille
    GtkWidget* conteneur;// l'objet conteneur
}Box;
typedef struct
{
    gchar* titre;//titre associe au fenetre
    gchar* icon;
    int posx;//position de  la fenetre en abcisse
    int posy;//position de la fenetre en ordonne
    int type;//type de fenetre
    int longueur;//longueur de la fenetre
    int largeur;//largeur de la fenetre
    gboolean  fixe; // propriete de la fenetre pour savoir si il a position fixe ou on peut la glisser par la souris
    gboolean  resize;//savoir si la fenetre peut modifie sa taille ou il reste  constante
    GtkWidget *fenetre;//l'entite principal  qui va contenir par la suite tous les elements
}window;//structure de la fenetre
typedef struct
{
    GtkWidget* spin; //entite de spinner
    GtkAdjustment *ad;//ajustement des pas de spinner
    int posx;//position de cet entite en abcisse
    int posy;//position de cet entite en ordonne
    int pas;//le pas d'avancement
    int min;//la valeur minimal de spinner
    int max;//la valeur maximal de spinner
}spin;//entite representant le spinner
typedef  struct {
    gchar *label;//titre associe à un bouton
    image *cover;//habillage d'un bouton par une image
    int posx;// position en terme d'abcisse du bouton dans la fenetre
    int posy;// position en terme d'ordonne du bouton dans la fenetre
    GtkWidget *botton;// prite associe a un bouton de type spin qui s'agit d'un pas d'incrementation de la valeur du bouton
}bouton;//structure  representant les proprités possible d'un bouton

typedef  struct
{
    int posx;// la position  en terme d'abcisse du box dans la fenetre
    int posy;//la position en terme d'ordonne au box dans la fenetre
    gboolean Horizontal; // determination du direction horizontalement du conteneur dans la fenetre
    gboolean Vertical;// determination du direction verticalement du conteneur dans la fenetre
    GtkWidget *conteneur;// l'entite conteneur qui va regrouper des sous elements par la suite
}box; // structure representant le conteneur qui va contient un element
typedef struct {
    int posx;//position de la gride en abcisse
    int posy;//position de la gride en ordonne
    int colonne;// nombre de collonne de la grille
    int lignes;// nombre de ligne  de la grille
    GtkWidget *nest; // entite representant la grille
}grid; //structure principal de la grille d'un conteneur
typedef struct
{
    gchar* label;// le titre associe au grid
    int posx;//le positionement du frame en abcisse
    int posy;//le positionement du frame en ordonne
    GtkWidget *cadre;//entite representant  le cadre d'un element
}frame; //entite representant le  frame d'un element
typedef struct
{
    int posx; // la position en abcisse de la grille
    int posy; //la position en ordonne de la grille
    GtkWidget *fixe;// entite utilise pour representer la grille d'un conteneur
}fixed; //structure utilise pour initialiser la grille d'un conteneur
typedef struct
{
    int posx;
    int posy;
    GtkWidget *barre;//entite principal de la fenetre qui va supporter le menu et ses elements
    GtkWidget *menu;//entite attache a la barre pour supporter les sous items
    GtkWidget *item;// entite lie au menu qui represente les sous elements du menu
    GtkWidget *sousitem;// les sous elements d'un  item principal du menu
    image* icon;//icon associe a un element du menu
    gboolean Horizontal;// direction de l'entite du menu en horizontal
    gboolean Vertical;// direction de l'entite du menu en vertical
    gchar*label;//le label de l'item
    gboolean left_attach;//attachement a gauche
    gboolean right_attach;//attachement a droite
    gboolean top_attach;//attachement en haut
    gboolean bottom_attach;//attachement en bas
    gboolean hasmenu;//item considere comme menu
}menu;// structure representant le menu d'un conteneur
///liste de tous les items d'un menu
typedef struct cel
{
    menu *element; //item de menu
    struct cel *suivant; //l'element suivant de liste des items en dessus
    struct cel*frere;//si il a des frere
}listemenus;
typedef struct
{
    gchar *titre;//titre associe à un entry
    gchar *placeholder;// le titre déja saisi dans l'entite entry qui sert a informer l'utilisateur
    int posx;//position de l'entite en abcisse
    int posy;//position de l'entite en ordonne
    GtkWidget *input;//l'entite representant  l'element entry
}entry;// entite dediéé à saisi un input dans la fenetre
typedef  struct
{    gchar* titre;
    GtkWidget *contain;
    gboolean *hasOk;//Boite de dialogue contenant le bouton ok
    gboolean *hasCancel;//Boite de dialogue contenant le bouton cancel
    gboolean *hasQuit;//Boite de dialogue contenant le bouton quitter
    gboolean *hasYes;//Boite de dialogue contenant le bouton yes
    gboolean *hasNo;//Boite de dialogue contenant le bouton non
    int posx;//la position du boite de dialogue en abcisse
    int posy;//la position du boite de dialogue en ordonne
    gboolean fixe;//la possibilite de fixer la fenetre du boite de dialogue
    gboolean modifiable;//la possibilite de modifier la fenetre du boite de dialogue
}dialogue;//la boite du dialogue d'une fenetre
typedef struct cell
{
    gchar *titre;
    GtkWidget *cellule;
    struct cell*suivant;
}listederoulante;




#endif //INTERFACE_STRUCTURES_H
