//
// Created by gx178 on 4/7/2023.
//


#define INTERFACE_FONCTIONS_H
//
// Created by gx178 on 3/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "structures.h"
#ifndef GROUPE_FONCTIONS_H
#define GROUPE_FONCTIONS_H

/************Les Fonctions initialisation et son allocation************************/
///---------------fonction initialiser l'image
/* Entrees: le path de l'image
 Sorties: pointeur de type image
  But: inialisation du path de l'image
  */
image *initialiser_image_fenetre(gchar* fil)
{
    image *f; //declaration du pointeur
    f=(image*)g_malloc(sizeof (image)); //allocation de la memoire
    f->path=(gchar*)g_malloc(sizeof (gchar)); //alloctaion de la memoire pour extension path du type gchar
    if(!f->path) //erreur d'allocation
    {
        printf("erreur d'allocation \n");
        exit(-1);
    }
    strcpy(f->path,fil); //inialiser le path
    return ((image*)f);
}
///---------------fonction initialiser scroll window
/* Entrees:  pointeur adopte pour window
 Sorties: pointeur de type window
  But: inialisation du scroll window
  */
window *initialiser_scrol_window(window* s)
{
    s=(window*)g_malloc(sizeof(window)); //allocation de la memoire
    if(!s) //erreur d'allocation
    {
        printf("erreur d'allocation \n");
        exit(0);
    }
    return ((window*) s);//retourner pointeur window inialise
}
///--------------creation de scroll window
/*
 Entrees: pointeur de type window
 Sorties: type void
  But: creation du scrolled window
  */
void cree_scroll_window(window* s)
{
    s->fenetre= gtk_scrolled_window_new(NULL,NULL);//macro gtk pour creation du new window
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(s->fenetre),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);//macro gtk pour faire apparaitre les 2 viewports du  window
}
///----initialisation de la fenetre
/*
 Entrees: les parametres initiaux pour la fenetre : indiqueé dans les arguments du fonction
 Sorties: pointeur de type window
  But: inialisation de la fenetre
  */
window *initialiser_fenetre(gchar*titre,int posx,int posy,gboolean fixe,gboolean resize,int longueur,int largeur,int type,gchar *image)
{
    window*Fenetre;
    Fenetre=(window*) g_malloc(sizeof(window));//allocation de la memoire pour pinteur  de type window
    if(!Fenetre) //erreur d'allocation
    {
        printf("erreur d'allaction");
        exit(-1);
    }
    //sinon initialisation des valeurs de cet entite
    Fenetre->titre=(gchar*)g_malloc(sizeof (gchar)); //allocation de la memoire  pour le titre de la fenetre
    if(!Fenetre->titre)
    {
        printf("erreur d'allaction");
        exit(-1);
    }
    strcpy(Fenetre->titre,titre);//inialiser sa valeur
    Fenetre->icon=(gchar*)g_malloc(sizeof (gchar));//allocation de la memoire pour l'icone utilise
    strcpy(Fenetre->icon,image);//inialiser sa valeur
    if(!Fenetre->icon)//erreur d'allocation
    {
        printf("erreur d'allocation \n");
        exit(0);
    }

    Fenetre->longueur=longueur;//inialiser parametre longueur
    Fenetre->largeur=largeur;//inialiser parametre largeur
    Fenetre->fixe=fixe;//inialiser parametre fixe pour indique si la fenetre se fixe dans une seul position ou peut la changer par la souris
    Fenetre->posy=posy;//inialiser parametre position y
    Fenetre->posx=posx;//inialiser parametre position x
    Fenetre->resize=resize;//inialiser parametre pour modifier la taille du fenetre
    Fenetre->type=type;//inialiser parametre pour indique type de fenetre
    return ((window*)Fenetre);

}
///----creation de la fenetre selon le type
/*
 Entrees: pointeur de type window
 Sorties: type void
  But: creation d'une fenetre
  */
void cree_fenetre(window *fenetre)
{
    switch(fenetre->type) //selon le type indique dans le parametre du window on cree notre interface
    {
        case 1: fenetre->fenetre= gtk_window_new(GTK_WINDOW_TOPLEVEL); //fenetre normal
            gtk_window_move(GTK_WINDOW(fenetre->fenetre),fenetre->posx,fenetre->posy);//inserer dans la position indiquée
            break;
        case 2:   fenetre->fenetre= gtk_window_new(GTK_WINDOW_POPUP);//fenetre de type pop up
            gtk_window_move(GTK_WINDOW(fenetre->fenetre),fenetre->posx,fenetre->posy);//inserer dans la position indiquée
            break;
        case 3:
            fenetre->fenetre= gtk_window_new(GTK_WINDOW_TOPLEVEL);//fenetre normal
            gtk_window_set_position(GTK_WINDOW(fenetre->fenetre),GTK_WIN_POS_MOUSE);//inserer dans la position de la souris
            break;

    }
    //affecter les parametres du pointeur window a chaque element du window
    gtk_window_set_title(GTK_WINDOW(fenetre->fenetre),fenetre->titre);
    gtk_window_set_resizable(GTK_WINDOW(fenetre->fenetre),fenetre->resize);
    gtk_window_set_icon_from_file(GTK_WINDOW(fenetre->fenetre),fenetre->icon,NULL);
    gtk_window_set_default_size(GTK_WINDOW(fenetre->fenetre),fenetre->longueur,fenetre->largeur);

}
///------initialiser du bouton
/*
 Entrees: label du bouton de type gchar
 Sorties: poiteur de type bouton inialisée
  But: inialiser la structure du bouton
  */
bouton *initialiser_bouton(gchar *label )
{   bouton*b; //declarer le pointeur bouton
    b=(bouton*) g_malloc(sizeof(bouton));//alloctaion de la memoire pour le bouton
    if(!b)//gerer l'erreur d'allocation
    {
        printf("erreur d'allocation");
        exit(0);
    }
    b->label=(gchar*)g_malloc(sizeof(gchar*)); //allocation de la memoire pour le titre
    if(!b->label)//erreur d'allocation
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(b->label,label);//inialiser le titre

    return ((bouton*)b);

}

///****creation du bouton simple ********/
/*
 Entrees: pointeur de type bouton
 Sorties: type void
  But: creation d'un bouton simple
  */
void creer_bouton_simple(bouton*simple)
{
    simple->botton= gtk_button_new_with_label(simple->label); //creer un bouton simple
}

///-----creation du bouton radio------///
/*
 Entrees: pointeur de type bouton ainsi un pointeur pour indiquer son groupe de bouton
 Sorties: type void
  But: creation de bouton radio
  */
void cree_bouton_radio( bouton*groupe,bouton*radio)
{
    radio->botton= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(groupe->botton),radio->label);//creation du bouton radion tout en indiquant son groupe

}
///---------------fonction initialiser la grille
/*
 Entrees: les parametres utilises pour inialiser la grille
 Sorties: elment de type grid
 But: inialisation de la grille
  */
grid *initialiser_grid(int posx,int posy,int colonne,int lignes){
    grid *grille; //declarer pointeur de type grid
    grille=(grid*)g_malloc(sizeof(grid)); //allocation de la memoire
    if(!grille)//gestion d'erreur
    {
        printf("erreure d'allocation ");
        exit(0);
    }
    return ((grid*)grille); //retourner le pointeur de type grille
}
///---------------fonction creer la grille
/*
 Entrees: pointeur de type grille
 Sorties: type void
 But: creation de la grille
  */
void creer_grid(grid* grille)
{
    grille->nest=gtk_grid_new();//creer la grille attribue par la suite a la fenetre pour organiser les elements
}
///---------------fonction initialiser le fixed
/*
 Entrees: Aucun parametre
 Sorties: elment de type fixed
 But: inialisation de le fixed qui va permet de fixer les elements à des positions determinées
  */
fixed * initialiser_fixed()
{
    fixed *f;//delarer pointeur fixed
    f=(fixed*)g_malloc(sizeof(fixed));//allocation de la memeoire
    if(!f)
    {
        printf("erreur d'allocation ");
        exit(0);
    }
    return ((fixed*)f);
}
///---------------fonction creer la grille
/*
 Entrees: pointeur de type fixed
 Sorties: type void
 But: creation  du fixed
  */
void cree_fixed(fixed* fixe)
{
    fixe->fixe=gtk_fixed_new();//creation du fixed pour l'attribué  à la grille par la suite
}
///---------------fonction initialiser le box
/*
 Entrees: les parametres utilises pour inialiser le box
 Sorties: elment de type box
 But: inialisation du box
  */
box  *initialiser_box(gboolean horizontal,gboolean vertical)
{
    box *conteneur;// declarer le pointeur de type box
    conteneur=(box*)malloc(sizeof(box));//allocation de la memoire
    if(!conteneur)//gestion d'erreur d'allocation
    {
        printf("erreur d'allocation");
        exit(0);
    }
    //inialisation des parametres
    conteneur->Horizontal=horizontal;
    conteneur->Vertical=vertical;

    return ((box*)conteneur);

}
///---------------fonction creation du check bouton
/*
 Entrees: pointeur de type bouton
 Sorties: type void
 But: creation d'un check bouton
  */
void *cree_check_bouton(bouton*b)
{
    b->botton= gtk_check_button_new_with_label(b->label);//creation du check bouton par fonction du gtk

}
///---------------fonction creation de  box
/*
 Entrees: pointeur de type box
 Sorties: type void
 But: creation du box
  */
void creer_box(box* box)
{
    box->conteneur= gtk_box_new(box->Horizontal,5);//creation du box tout en definissant son espace à 5 "En Xml l'utilisateur definit la valeur qu'il veut"
}
///---------------fonction initialiser l'entry
/*
 Entrees: les parametres utilises pour inialiser l'entry
 Sorties: elment de typ entry
 But: inialisation de l'element entry
  */
entry *initialiser_entry(gchar*titre,gchar*placeholder,int posx,int posy)
{
    entry *entr; // declarer la variable de type pointeur entry
    entr=(entry*)g_malloc(sizeof(entry));//allocation de la memoire
    if(!entr)//gestion des erreurs
    {
        printf("erreur d'allocation");
        exit(0);
    }
    entr->titre=(gchar*)g_malloc(sizeof(gchar));//allocation de la memoire pour le titre
    if(!entr->titre)//gestion de l'erreur
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(entr->titre,titre);//inialiser le parametre titre
    entr->placeholder=(gchar*)g_malloc(sizeof(gchar));//allocation de la memoire pour le placeholder
    if(!entr->placeholder)//gestion des erreurs
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(entr->placeholder,placeholder);//inialiser le parametre du placeholder
    //inialiser des valeurs des positions pour cet element
    entr->posx=posx;
    entr->posy=posy;
    return ((entry*)entr);
}
///---------------fonction initialiser le spinner
/*
 Entrees: les parametres utilises pour inialiser le spinner
 Sorties: elment de type spin
 But: inialisation le spin
  */
spin *initialiser_spin(int pas,int min,int max,int posx,int posy)
{
    spin *spine;//declaraion du variable de type pointeur spin
    spine=(spin*)g_malloc(sizeof(spin));//allocation de la memoire
    if(!spine)//gestion d'erreur d'allocation
    {
        printf("erreur d'allocation \n");
        exit(0);
    }
    //inialiser le reste des parametres
    spine->pas=pas;
    spine->posx=posx;
    spine->posy=posy;
    spine->min=min;
    spine->max=max;
    //ajustement pour incrementer ou decrementer la valeur du spinner
    spine->ad= gtk_adjustment_new(0,min,max,pas,0,0);
    return((spin*)spine);
}
///---------------fonction creer le spinner
/*
 Entrees: pointeur de type spin
 Sorties: type void
 But: creation de la spinner
  */
void cree_spin(spin* spin)
{
    spin->spin= gtk_spin_button_new(GTK_ADJUSTMENT(spin->ad),spin->pas,1);//fonction pour creer le spinner en gtk

}
///---------------fonction la cretion de entry
/*
 Entrees: pointeur de type entry
 Sorties: type void
 But: creation du l'entry
  */
void creer_entry(entry *entre)
{
    entre->input=gtk_entry_new();//creation de l'entry
    gtk_entry_set_placeholder_text(GTK_ENTRY(entre->input),entre->placeholder);//creation du place holder qui est definit dans cet entry

}
///--------fonction initialisation du barre du fenetre
/*
 Entrees: la position x et y de la barre de la fenetre
 Sorties: elment de type menu
 But: inialisation de la barre de la fenetre
  */
menu* inialiser_barre_fenetre(int posx,int posy)
{
    menu*barre;//declaration du variable de type menu
    barre=(menu*)g_malloc(sizeof(menu));//allocation de la memoire pour la barre
    if(!barre)//gerer l'erreur de l'allocation dans la memoire
    {
        printf("erreur d'allocation");
        exit(0);
    }
    //inialiser les parametres de x et y
    barre->posx=posx;
    barre->posy=posy;
    return ((menu*)barre); //retourner poiteur inialiser du barrer de menu
}
///--------fonction creation du barre du fenetre
/*
 Entrees: pointeur  pour  la barre et un fixed
 Sorties: type void
 But: creation de la barre
  */
void creer_barre(menu*barre,fixed*fixe)
{
    barre->barre=gtk_menu_bar_new();//creer la barre associe au menu par la suite
    //GtkWidget*b= gtk_hbox_new(TRUE,1);
    //gtk_container_add(GTK_CONTAINER(b),barre->barre)
    gtk_fixed_put(GTK_FIXED(fixe->fixe),barre->barre,barre->posx,barre->posy); //positioner le box dans le fixed
}
///--------fonction creation du cellule menu de la barre de la fenetre
/*
 Entrees: le label du menu
 Sorties: pointeur de type menu
 But: inialisation du element menu qui va contenir  les sous menus
  */
menu *inialisercelluleparent(gchar*label)
{
    menu*tool; //declarer la variable de type menu
    tool=(menu*)g_malloc(sizeof(menu));//allocation de la memoire
    if(!tool)//erreur d'allocation
    {
        printf("erreur d'alloaction \n");
        exit(0);
    }
    tool->label=(gchar*)g_malloc(sizeof(gchar));//allocation de la memoire pour le label
    if(!tool->label)//gestion d'erreur d'alloaction
    {
        printf("erreur d'alloaction");
        exit(0);
    }
    strcpy(tool->label,label);//inialiser le label
    return ((menu*)tool);
}

///-------------creation du tool barre "elements de la barre ,ses items"
/*
 Entrees: la barre du type menu ainsi que item qui est aussi de type menu
 Sorties: type void
 But: creer cellule parent qui va etre associe a la barre et qui va contenir les sous menus
  */
void creercelluleparent(menu*item,menu*barre)
{
    //creer l'element menu du barre
    item->item= gtk_menu_item_new_with_label(item->label);
}
///------initailiser listes des itemes d'un element parent
/*
 Entrees: les parametres pour creer les items d'un menu "declarée dans les arguments de la fonction"
 Sorties: liste inialiser pour un menu
 But: initailiser  la liste des cellules ("sous elemnts") d'un element parent qui est le menu
  */
listemenus * inialiser_liste(listemenus *liste,gchar *label,gboolean frere)
{
    liste=(listemenus*) g_malloc(sizeof(listemenus));//allocation de la memoire
    if(!liste)//gestion d'erreur
    {
        printf("erreur d'allocation");
        exit(0);
    }
    liste->element=(menu*) g_malloc(sizeof(menu));//allocation de la memoire pour element menu
    liste->element->label=(gchar*) g_malloc(sizeof(gchar));//allocation de la memoire pour le label
    if(!liste->element->label)//erreur d'allocation
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(liste->element->label,label);//inialiser le label
    liste->element->right_attach=frere;//inialiser les attachements de la cellule par le frere
    return ((listemenus *)liste);
}
///initialialiser item a introduire dans la liste
/*
 Entrees: le label d'un item de type gchar
 Sorties: cellule de type menu inialiser
 But: initailiser  les sous cellules de  la liste
  */
menu* initialiser_sub_cel_parent(gchar*label)
{
    menu *nouveau; //declarer le nouveau element a inserer de type menu
    nouveau=(menu*)g_malloc(sizeof(menu));//allocation de la memoire
    if(!nouveau)//gestion d'erreur
    {
        printf("erreur d'allocation");
        exit(0);
    }
    nouveau->label=(gchar*) g_malloc(sizeof(gchar));//allocation de la memoire pour le label
    if(!nouveau->label)//gestion d'erreur
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(nouveau->label,label);//inialiser le label
    return ((menu*)nouveau);
}
/// creation de une liste horizontal  associe a un element parent
/*
/*
 Entrees: les parametres pour creer les items d'un element parent "declarée dans les arguments de la fonction"
 Sorties: creer liste horizontal
 But: creer la liste des cellules ("sous elemnts") d'un element parent

listemenus *creation_liste_horizontal(listemenus*liste,menu*nouveau,menu*parent)
{

    GtkWidget*r = gtk_menu_new();
    if (liste == NULL) {
        liste = inialiser_liste(liste, nouveau->label,FALSE);
        liste->element->item = gtk_menu_item_new_with_label(liste->element->label);
        //gtk_menu_attach_to_widget(GTK_MENU(parent->item),nouveau->item,NULL);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(parent->item), r);
        gtk_menu_shell_append(GTK_MENU_SHELL(r), liste->element->item);
        liste->suivant = NULL;
        return((listemenus*)liste);
    }
    listemenus *tmp;
    tmp=liste;
    while(!tmp->suivant==NULL)
    {
        tmp=tmp->suivant;
    }
    // GtkWidget *sep = gtk_separator_menu_item_new();
    tmp->suivant=inialiser_liste(liste, nouveau->label,FALSE);
    tmp->suivant->element->item = gtk_menu_item_new_with_label(nouveau->label);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(liste->element->item), r);
    gtk_menu_shell_append(GTK_MENU_SHELL(r), tmp->suivant->element->item);
    tmp->suivant->suivant = NULL;
    return ((listemenus*)liste);
}
*/
///creation de la liste  vertical d'un element pour un item menu de tollbar avec ses liens
/*
 Entrees: les parametres pour creer les items d'un menu "declarée dans les arguments de la fonction"
 Sorties: liste  pour un menu
 But: initailiser  la liste des cellules ("sous elemnts") d'un element parent qui est le menu
  */
listemenus *creation_liste_vertical(listemenus*liste,menu*nouveau,menu*parent,GtkWidget*s,gboolean frere,GtkWidget *f)
{
    if (liste == NULL) {
        //si liste est vide on inialise la liste par cet element puis on l'insere dans la liste
        liste = inialiser_liste(liste, nouveau->label,frere);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(parent->item), s);//associer ce nouveau element à inserer au menu
        liste->element->item = gtk_menu_item_new_with_label(liste->element->label);//creer la cellule de type menu par GTk
        gtk_menu_shell_append(GTK_MENU_SHELL(s), liste->element->item);//faire lien entre cellule de la liste
        if(frere==TRUE) //si la cellule a un frere on le donne un sous menu
        {
            GtkWidget*t;
            t=gtk_menu_new();//creer un menu
            f = gtk_menu_item_new_with_label("Choix 221");//
            gtk_menu_item_set_submenu(GTK_MENU_ITEM(liste->element->item), t);//traite la cellule ciourante de la liste en submenu
            gtk_menu_shell_append(GTK_MENU_SHELL(t), f);//faire le lien entre le  submenu et l'element a insere
        }

        liste->suivant = NULL;//inialiser le suivant par NULL
        return((listemenus*)liste);//retourner la liste
    }
    //insertion ailleurs
    listemenus *tmp;
    GtkWidget *sep = gtk_separator_menu_item_new();//mettre un trait entre les cellules "Juste une Decoration Pour Les cellules du menu"
    tmp=inialiser_liste(tmp, nouveau->label,frere);//inialiser la cellule à inserer
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(parent->item), s);//liee le sous menu au item principal
    tmp->element->item = gtk_menu_item_new_with_label(nouveau->label);//creation de la cellule
    gtk_menu_shell_append(GTK_MENU_SHELL(s), tmp->element->item);//lier la nouvelle cellule aux cellules precedent
    tmp->suivant = liste;
    if(frere==TRUE)//si il a un frere
    {
        GtkWidget*t,*h,*r;
        t=gtk_menu_new();// creer un menu pour les sous menus qui sont des freres
        h=gtk_menu_new();
        r=gtk_menu_new();
        GtkWidget *ss;
        GtkWidget *m;

        f = gtk_menu_item_new_with_label("choix 221");//inialser le titre de la cellule
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(tmp->element->item), t);//crrer une cellule de type submenu et l'attribué au cellule courante
        gtk_menu_shell_append(GTK_MENU_SHELL(t), f);//attribue la nouvelle cellule a la cellule courante qui va etre la cellule parent
        ss= gtk_menu_item_new_with_label("choix 222");
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(f),h);
        gtk_menu_shell_append(GTK_MENU_SHELL(h),ss);
        m= gtk_menu_item_new_with_label("choix 223");
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(ss),r);
        gtk_menu_shell_append(GTK_MENU_SHELL(r),m);

    }

    return((listemenus*)liste);//retourner la liste
}
///*************************Fonction pour attribuer les couleurs *********///
/*
 Entrees: pointeur de type window
 Sorties: type void
 But: liée le fichier CSS qui va contenir le style de l'interface  avec le widget principal qui est window
  */
void loadCSS(GtkWidget *window)
{
    GFile *css_gFile = g_file_new_for_path("style.css");//attribuer le path du fichier CSS
    GtkCssProvider *cssProvider = gtk_css_provider_new();//fonction responsable de lire le  CSS

    gtk_css_provider_load_from_file(cssProvider, css_gFile, 0);//attribuer le path CSS à la fonction responsable de lire CSS

    //Pour affecter les styles aux differentes widgets selon leur classe
    gtk_style_context_add_provider_for_screen(gtk_widget_get_screen(window),
                                              GTK_STYLE_PROVIDER(cssProvider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);
}
///********inialisation du boite de dialogue *******///
/*
 Entrees: les parametres pour creer une boite de dialogue
 Sorties: variable de type dialogue bien inialiser
 But: initialiser les composants du boite de dialogue
  */
dialogue *initialisation_boite_dialogue(int posx,int posy,gchar*label,gboolean ok,gboolean cancel)
{
    dialogue* boite=(dialogue*)g_malloc(sizeof(dialogue));//allocation de la memoire
    boite->titre=(gchar*)g_malloc((sizeof(gchar)));//allocation de la memoire pour le titre
    if(!boite->titre)//gestion d'erreur d'allocation
    {
        printf("erreur d'allocation ");
        exit(0);
    }
    strcpy(boite->titre,label);//inialiser le titre
    //inialiser le reste des parametres
    boite->posx=posx;
    boite->posy=posy;
    boite->hasOk=ok;//ok est de type gboolean c'est a dire True or False ,indiquer si la boite de dialogue a ce bouton ou non
    boite->hasCancel=cancel;//du meme pour le bouton cancel
    return((dialogue*)boite);//retourner la variable bien inialiser
}
///***creation du boite de dialogue ****/
/*
 Entrees: les parametres pour creer une boite de dialogue
 Sorties:type void
 But: creation de la boite de dialogue
  */

void creation_boite_dialogue(dialogue*dialogue)
{
    dialogue->contain=gtk_dialog_new();//creer une boite de dialogue
    gtk_window_set_title(dialogue->contain,"");//affecter le titre


    if(dialogue->hasOk)// si true ,il possede un  bouton ok
    {
        //gtk_dialog_add_buttons(GTK_DIALOG(boite->dialog), ("Oui"), NULL);
        //g_signal_connect(boite->dialog, "clicked", G_CALLBACK(gtk_main_quit), GTK_RESPONSE_DELETE_EVENT);
        //creer un bouton ok dans la boite de dialogue
        gtk_dialog_add_buttons(GTK_DIALOG(dialogue->contain),"OUI", NULL);
      //  g_signal_connect(dialogue->contain, "clicked",G_CALLBACK(aff),NULL);
    }
    if(dialogue->hasNo)//si true, il possede un bouton cancel
    {//creer un bouton annuler dans la boite de dialogue
        gtk_dialog_add_buttons(GTK_DIALOG(dialogue->contain), ("Non"), GTK_RESPONSE_DELETE_EVENT);
    }
    if(dialogue->hasCancel)//si true, il possede un bouton cancel
    {//creer un bouton annuler dans la boite de dialogue
        gtk_dialog_add_buttons(GTK_DIALOG(dialogue->contain), ("Annuler"), GTK_RESPONSE_DELETE_EVENT);
    }
    //affecter l'icone au boite de dialogue
    gtk_window_set_icon_from_file(dialogue->contain,"bl.png",NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialogue->contain));
    GtkWidget *lab= gtk_label_new("Voulez vous affichez une image?");
    GtkWidget *grid=gtk_grid_new();
    gtk_container_add (GTK_CONTAINER (content_area),lab);
    gtk_container_add(GTK_CONTAINER (content_area),grid);
   GtkWidget *im;
    im= gtk_image_new_from_file("al.png");
    gtk_grid_attach(GTK_GRID(grid),im,0,0,6,3);
    gtk_grid_attach_next_to(GTK_GRID(grid),lab,im,GTK_POS_RIGHT,30,80);


    g_signal_connect_swapped (dialogue->contain,
                              "response",
                              G_CALLBACK (gtk_widget_destroy),
                              NULL);


}
///***Dialogue fenetre  a interpelle ***///
/*
 Entrees: les parametres pour creer une boite de dialogue
 Sorties: variable de type dialogue bien inialiser
 But: initialiser les composants du boite de dialogue
  */
void dialogue_fenetre( dialogue* boite)
{
    //fonction qui fait l'apppel au boite du dialogue avec son affichage
    boite= initialisation_boite_dialogue(500,500,"",TRUE,TRUE);
    creation_boite_dialogue(boite);
    gtk_widget_show_all(boite->contain);
}
///**************INITIALISATION DU LISTE DEROULANTE
/*
 Entrees: le titre de attribue au cellule
 Sorties: variable de type listederoulante
 But: initialiser de la liste deroulante
  */
listederoulante* inialiser_liste_deroulante(gchar *titr)
{
    listederoulante* m=(listederoulante*) g_malloc(sizeof(listederoulante));//allocation de la memoire pour la liste deroulante
    m->titre=(gchar*)g_malloc(sizeof(gchar));//allocation de la memoire pour le titre
    if(!m->titre)//gestion d'erreur d'allocation
    {
        printf("erreur d'allocation");
        exit(0);
    }
    strcpy(m->titre,titr);//affecter le titre
    return ((listederoulante*)m);//retourner la listederoulante inialiser
}
window * navbar(fixed*fixet,window*fenetre)
{
    image*icon;
    icon= initialiser_image_fenetre("logo.jpg");
    fenetre=initialiser_fenetre("Test Macros GTK-2022-2023",700,200,TRUE,TRUE,1000,880,1,icon->path);
    cree_fenetre(fenetre);
    /****creation du style*****/
    loadCSS(fenetre->fenetre);
    gtk_style_context_add_class(gtk_widget_get_style_context(fenetre->fenetre),"col");
    GtkWidget *bar=gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(bar),"Test Macros GTK-2022-2023");
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(bar), TRUE);

    GtkWidget*button=gtk_button_new();
    GtkWidget *image= gtk_image_new_from_file("icon.png");
    gtk_button_set_image(GTK_BUTTON(button),image);
    gtk_widget_set_size_request(button,1,3);
    fixet=initialiser_fixed();
    cree_fixed(fixet);
    gtk_fixed_put(GTK_FIXED(fixet->fixe),button,0,0);
    gtk_container_add(GTK_CONTAINER(bar),fixet->fixe);
    gtk_window_set_titlebar(GTK_WINDOW(fenetre->fenetre), bar);

    return ((window*)fenetre);

}
/*
 Entrees: les parametres pour creer une boite de dialogue
 Sorties: variable de type dialogue bien inialiser
 But: initialiser les composants du boite de dialogue
  */
void liste_deroulante(listederoulante*tt, GtkComboBox *bt)
{
    //creer des cellules de type liste deroulante
    // la fonction fait de lien automatique , chaque fois on veut inserer une nouvelle cellule ,puisque ils vont  appartenir au meme groupe du combobox
    gtk_combo_box_text_append_text(bt,tt->titre);

}
///--------------------------la fonction principal
void principal()
{
    ///declaration des variables
    window *f,*source;// f :fenetre principal et source pour scroll element
    image*icon; // image attribue a l'icone
    grid*grid;//grid utilise
    fixed*fixe;//fixed utilise
    bouton *radio,*radio2,*radio3,*check;
    spin*spin;//boutons
    entry*entry;//entry
    GtkWidget*cel;
    box *box;//box
    menu*barre;
    menu*cellule;
    ///declaration du style utilisée pour la fenetre
    icon= initialiser_image_fenetre("logo.jpg");//initialisation du path de l'image
    f= initialiser_fenetre("groupe",700,200,TRUE,TRUE,800,500,1,icon->path);//initialisation de la fenetre

    ///scroll fenetre directement :Main objet a travaille sur lui
    cree_fenetre(f);//creer fenetre principal
    source = initialiser_scrol_window(source);//appel au scroll element
    cree_scroll_window(source);
    ///style de la fenetre scoll
    loadCSS(source->fenetre);
    gtk_style_context_add_class(gtk_widget_get_style_context(source->fenetre),"interface");
    /// fonctions  des conteneurs
    ///----grille----------------------------
    grid= initialiser_grid(NULL,NULL,NULL,NULL);//inialisation du grille
    creer_grid(grid);//creation de la grille

    ///--------fixed--------------------------
    fixe= initialiser_fixed();//initialisation du fixed
    cree_fixed(fixe);//cree le fixed
    ///--------box-----------------------------
    box= initialiser_box(TRUE,FALSE);//initialisation du box
    creer_box(box);//creation du box
    /// -----------------fonctions utilises-------------------///
    ///*******boutons radio*************///
    GtkWidget *frame= gtk_frame_new("RADIOS");
    gtk_style_context_add_class(gtk_widget_get_style_context(frame),"label");
    gtk_style_context_add_class(gtk_widget_get_style_context(box->conteneur),"frae");
    gtk_container_add(GTK_FRAME(frame),box->conteneur);
    radio=initialiser_bouton("radio1");
    radio->botton=gtk_radio_button_new_with_label(NULL,radio->label);
    radio2=initialiser_bouton("radio2");
    cree_bouton_radio(radio,radio2);
    radio3=initialiser_bouton("radio3");
    cree_bouton_radio(radio,radio3);
    gtk_box_pack_start(GTK_BOX(box->conteneur),radio->botton,FALSE,FALSE,1);
    gtk_box_pack_start(GTK_BOX(box->conteneur),radio2->botton,FALSE,FALSE,1);
    gtk_box_pack_start(GTK_BOX(box->conteneur),radio3->botton,FALSE,FALSE,1);
    gtk_frame_set_shadow_type(GTK_FRAME(frame),GTK_SHADOW_ETCHED_IN);
    gtk_fixed_put(GTK_FIXED(fixe->fixe),frame,90,60);
    ///*******boutons check*************///
    GtkWidget *fra;
    bouton*check1,*check2;
    fra= gtk_frame_new("CHECK_BOUTON");
    gtk_style_context_add_class(gtk_widget_get_style_context(fra),"label");

    GtkWidget *boxi= gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
    gtk_style_context_add_class(gtk_widget_get_style_context(boxi),"frae");
    gtk_container_add(GTK_FRAME(fra),boxi);
    check=initialiser_bouton("check1");
    cree_check_bouton(check);
    check2=initialiser_bouton("check2");
    cree_check_bouton(check2);
    check1=initialiser_bouton("check3");
    cree_check_bouton(check1);
    gtk_box_pack_start(GTK_BOX(boxi),check->botton,FALSE,FALSE,1);
    gtk_box_pack_start(GTK_BOX(boxi),check2->botton,FALSE,FALSE,1);
    gtk_box_pack_start(GTK_BOX(boxi),check1->botton,FALSE,FALSE,1);
    gtk_fixed_put(GTK_FIXED(fixe->fixe),fra,600,400);
    ///*******entry**************///
    GtkWidget*bo,*fr;
    bo= gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
    fr= gtk_frame_new("ENTRY");
    gtk_style_context_add_class(gtk_widget_get_style_context(fr),"label");

    gtk_container_add(GTK_FRAME(fr),bo);

    entry=initialiser_entry("nom","saisir nom",100,300);
    creer_entry(entry);
    gtk_style_context_add_class(gtk_widget_get_style_context(entry->input),"label");

    gtk_container_add(GTK_CONTAINER(bo),entry->input);
    gtk_fixed_put(GTK_FIXED(fixe->fixe),fr,entry->posx,entry->posy);
    ///***spin bouton***//
    GtkWidget *new;
    new= gtk_frame_new("Spin");
    gtk_style_context_add_class(gtk_widget_get_style_context(new),"label");
    spin= initialiser_spin(1,0,30,50,400);
    cree_spin(spin);
    GtkWidget *boxii;
    boxii= gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
    gtk_container_add(GTK_FRAME(new),boxii);
    gtk_container_add(GTK_CONTAINER(boxii),spin->spin);
    gtk_fixed_put(GTK_FIXED(fixe->fixe),new,spin->posx,spin->posy);

    ///menu avec vertical liste

    barre= inialiser_barre_fenetre(300,0);
    creer_barre(barre,fixe);
    //inialiser le menu
    cellule= inialisercelluleparent("MENU1");
    creercelluleparent(cellule,barre);
    gtk_style_context_add_class(gtk_widget_get_style_context(cellule->item),"frame");

    menu*cellule2;
    cellule2= inialisercelluleparent("MENU2");
    creercelluleparent(cellule2,barre);
    gtk_style_context_add_class(gtk_widget_get_style_context(cellule2->item),"frame");

    ///inialiser la barre
    listemenus *liste,*liste2;
    menu*nouveau,*nouveaux;
    //***DEMO en VERTICAL

    //horizontal
    GtkWidget *h,*s;
    s=gtk_menu_new();
    h=gtk_menu_new();
    gtk_style_context_add_class(gtk_widget_get_style_context(s),"frame");
    gtk_style_context_add_class(gtk_widget_get_style_context(h),"frame");
    menu*nouveaut,*nouveaute,*p;
    nouveaute= initialiser_sub_cel_parent("vert1");
    p= initialiser_sub_cel_parent("vert2");
    liste=creation_liste_vertical(liste,nouveaute,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,p,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,p,cellule,s,FALSE,h);

    nouveaute= initialiser_sub_cel_parent("vert1");
    p= initialiser_sub_cel_parent("vert2");
    liste2=creation_liste_vertical(liste2,nouveaute,cellule2,h,TRUE,h);
    liste2=creation_liste_vertical(liste2,p,cellule2,h,TRUE,h);
    liste2=creation_liste_vertical(liste2,p,cellule2,h,FALSE,h);
    //generation  fonctionnede menu horizontal
    // liste2= creation_liste_horizontal(liste2,p,cellule);
    //  liste2= creation_liste_horizontal(liste2,p,cellule);

    /*Fire apparaitre le menu voulu dans la barre)*/
    gtk_menu_shell_append(GTK_MENU_SHELL(barre->barre),cellule->item);
    gtk_menu_shell_append(GTK_MENU_SHELL(barre->barre),cellule2->item);

///******liste deroulante*********/
    listederoulante *t,*m,*n;
    GtkComboBox *b;
    GtkWidget *framee= gtk_frame_new("liste deroulante");
    b=gtk_combo_box_text_new();
    gtk_container_add(GTK_FRAME(framee),b);

    t= inialiser_liste_deroulante("liste1");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste2");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste");
    liste_deroulante(t,b);
    gtk_combo_box_set_active(GTK_COMBO_BOX(b),0);
    gtk_frame_set_shadow_type(GTK_FRAME(framee),GTK_SHADOW_OUT);
    gtk_style_context_add_class(gtk_widget_get_style_context(framee),"box");
    gtk_fixed_put(GTK_FIXED(fixe->fixe),framee,200,400);


    ///---------creation du bouton simple----------///
    bouton*simple;
    simple= initialiser_bouton("OK");
    image*im;
    im=initialiser_image_fenetre("2.png");
    GtkWidget *image=gtk_image_new_from_file(im->path);
    creer_bouton_simple(simple);
    gtk_button_set_image(GTK_BUTTON(simple->botton),image);
    gtk_button_set_always_show_image(GTK_BUTTON(simple->botton),1);
    g_signal_connect(simple->botton,"clicked",G_CALLBACK(dialogue_fenetre),NULL);
    gtk_fixed_put(GTK_FIXED(fixe->fixe),simple->botton,500,500);

    ///***Boite de dialogue*********///



    ///************AFFICHAGE***************************///
    gtk_container_add(GTK_CONTAINER(grid->nest),fixe->fixe);
    gtk_container_add(GTK_CONTAINER(source->fenetre),grid->nest);
    gtk_container_add(GTK_CONTAINER(f->fenetre),source->fenetre);
    gtk_widget_show_all(f->fenetre);
}



#endif //INTERFACE_FONCTIONS_H
