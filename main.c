
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonctions.h"

void style_entite(GtkWidget*g,char label[20])
{
    gtk_style_context_add_class(gtk_widget_get_style_context(g),label);
}
GtkWidget *menu_type(GtkWidget*s)
{
    s=gtk_menu_new();
    return s;
}
void associer_bar_menu(GtkWidget*barre,GtkWidget*elem)
{
    gtk_menu_shell_append(GTK_MENU_SHELL(barre),elem);
}
GtkWidget * creer_frame(GtkWidget * frame,char label[20])
{

    frame= gtk_frame_new(label);
    gtk_frame_set_shadow_type(GTK_FRAME(frame),GTK_SHADOW_ETCHED_IN);
    return frame;
}
 void conteneur( box*box,GtkWidget *frame)
{
    gtk_container_add(GTK_FRAME(frame),box->conteneur);

}
GtkWidget *bouton_source(bouton*radio)
{
    radio->botton=gtk_radio_button_new_with_label(NULL,radio->label);
}
void package_bouton(GtkWidget*box,GtkWidget*radio,gboolean h,gboolean k,int g)
{
    gtk_box_pack_start(GTK_BOX(box),radio,h,k,g);

}
void position_fixe(GtkWidget*fix,frame*f,int x,int y)
{
    gtk_fixed_put(GTK_FIXED(fix),f,x,y);
}
GtkComboBox *combo_box(GtkComboBox*b,GtkWidget*framee)
{
    b=gtk_combo_box_text_new();
    gtk_container_add(GTK_CONTAINER(framee),b);
    return b;
}
void activer(GtkComboBox*b,int x)
{
    gtk_combo_box_set_active(GTK_COMBO_BOX(b),x);
}
void propriete_bouton(bouton*simple,int x,int y,fixed*fix,image*im,int width,int height)
{
    GtkWidget *image=gtk_image_new_from_file(im->path);
    gtk_widget_set_size_request(GTK_WIDGET(simple->botton),width,height);
    gtk_button_set_image(GTK_BUTTON(simple->botton),image);
    gtk_button_set_always_show_image(GTK_BUTTON(simple->botton),1);
    g_signal_connect(simple->botton,"clicked",G_CALLBACK(dialogue_fenetre),NULL);
    gtk_fixed_put(GTK_FIXED(fix->fixe),simple->botton,x,y);
}
void affichage(grid*grid,fixed*fix,window*source,window*fenetre)
{

    gtk_container_add(GTK_CONTAINER(grid->nest),fix->fixe);
    gtk_container_add(GTK_CONTAINER(source->fenetre),grid->nest);
    gtk_container_add(GTK_CONTAINER(fenetre->fenetre),source->fenetre);
    gtk_widget_show_all(fenetre->fenetre);
    gtk_main();
}


///*************MAIN*******************///
int main(int argc, char const *argv[]) {
    gtk_init(&argc, &argv);
    //Declaration  Des Variables

    window *fenetre,*source;
    fixed*fixe;
    fixed*fix;
    menu*barre;
    menu*cellule;
    listemenus *liste,*liste2;
    grid*grid;//grid utilise
    menu*cellule2;
    GtkWidget *h,*s;
    menu*nouveaut,*nouveaute,*p;
    menu*nouveau,*nouveaux;
    box *box,*boxi,*boxt,*boxp,*boxT;
    GtkWidget *frame;
    GtkWidget *fra;
    bouton*check1,*check2,*check,*check3,*check4,*check5;
    listederoulante *t,*m,*n,*o;
    GtkComboBox *b,*b1,*b2,*b3,*b4;
    GtkWidget *framee;
    entry *e;
    image*im;
    bouton*simple,*imple;
    bouton *radio,*radio2,*radio3;


    /****creation de la fenetre **********/
    fenetre=navbar(fixe,fenetre);

    /**creation du fixed pour la fenetre**/
    fix=initialiser_fixed();
    cree_fixed(fix);
    /*****Scroll Windwo*****/
    source = initialiser_scrol_window(source);//appel au scroll element
    cree_scroll_window(source);
    /***Inialisation et creation de la grille***/
    grid= initialiser_grid(NULL,NULL,NULL,NULL);//inialisation du grille
    creer_grid(grid);//creation de la grille
    /****La barre de la fenetre*****/
    barre= inialiser_barre_fenetre(300,90);
    creer_barre(barre,fix);
    /****inialiser les cellule de menus**/
    cellule= inialisercelluleparent("MENU1");
    creercelluleparent(cellule,barre);
    cellule2= inialisercelluleparent("MENU2");
    creercelluleparent(cellule2,barre);
    style_entite(barre->barre,"barre");
   /*****Listes associéés au menu *****/
    s=menu_type(s);
    h=menu_type(h);
    style_entite(s,"couleur");
    style_entite(h,"couleur");
    /** Composantes du Premier Menu ***/
    nouveaute= initialiser_sub_cel_parent(" 📚Menu 1");
    p= initialiser_sub_cel_parent("📚Menu 2");
    nouveaut= initialiser_sub_cel_parent("📚Menu 3");
    liste=creation_liste_vertical(liste,nouveaute,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,p,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,nouveaut,cellule,s,FALSE,h);
    /** Composantes du Deuxieme Menu ***/
    liste2=creation_liste_vertical(liste2,nouveaute,cellule2,h,TRUE,h);
    liste2=creation_liste_vertical(liste2,p,cellule2,h,TRUE,h);
    liste2=creation_liste_vertical(liste2,nouveaut,cellule2,h,FALSE,h);

    /****Associéé  les menu voulu dans la barre ******/
    associer_bar_menu(barre->barre,cellule->item);
    associer_bar_menu(barre->barre,cellule2->item);

    /***Radios Bouttons****/
    box= initialiser_box(FALSE,TRUE);//initialisation du box
    creer_box(box);//creation du box
    frame=creer_frame(frame,"Genre");
   conteneur(box, frame);
    radio=initialiser_bouton("H");
    radio->botton=bouton_source(radio);
    radio2=initialiser_bouton("F");
    cree_bouton_radio(radio,radio2);
    radio3=initialiser_bouton("A");
    cree_bouton_radio(radio,radio3);
    package_bouton(box->conteneur,radio->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio2->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio3->botton,FALSE,FALSE,1);
    position_fixe(fix->fixe,frame,10,100);


    /*********Check buttons *********/


    fra=creer_frame(frame,"🧑‍💻Vos Choix:🧑‍💻");
    //gtk_style_context_add_class(gtk_widget_get_style_context(fra),"label");
    boxi=initialiser_box(TRUE,FALSE);
    creer_box(boxi);

    //gtk_style_context_add_class(gtk_widget_get_style_context(boxi),"frae");
    conteneur(boxi,fra);
    check=initialiser_bouton("dessiner");
    cree_check_bouton(check);
    check2=initialiser_bouton("lecture");
    cree_check_bouton(check2);
    check1=initialiser_bouton("voyager");
    cree_check_bouton(check1);
    check3=initialiser_bouton("culture");
    cree_check_bouton(check3);
    check4=initialiser_bouton("travaux manuels");
    cree_check_bouton(check4);
    check5=initialiser_bouton("ne rien faire");
    cree_check_bouton(check5);
    package_bouton(boxi->conteneur,check->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check2->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check1->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check3->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check4->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check5->botton,FALSE,FALSE,1);
    position_fixe(fix->fixe,fra,500,60);
    /**********liste deroulante************/
    framee= creer_frame(framee,"Depart");
    b=combo_box(b,framee);
    conteneur(box,framee);
    t= inialiser_liste_deroulante("liste1");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste2");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste3");
    liste_deroulante(t,b);
    activer(b,0);
    style_entite(framee,"couleur");
    position_fixe(fix->fixe,framee,90,250);
    /**********liste deroulante************/
    framee= creer_frame(framee,"Arrive");
    b=combo_box(b,framee);
    conteneur(box,framee);
    t= inialiser_liste_deroulante("liste1");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste2");
    liste_deroulante(t,b);
    t= inialiser_liste_deroulante("liste3");
    liste_deroulante(t,b);
    activer(b,0);
    style_entite(framee,"couleur");
    position_fixe(fix->fixe,framee,250,250);

    /**********liste deroulante Calendrier ************/
    frame= creer_frame(frame,"Calendrier");
    boxT= initialiser_box(FALSE,TRUE);//initialisation du box
    creer_box(boxT);//creation du box

    b2=combo_box(b2,boxT->conteneur);
    t= inialiser_liste_deroulante("1");
    liste_deroulante(t,b2);
    t= inialiser_liste_deroulante("2");
    liste_deroulante(t,b2);
    t= inialiser_liste_deroulante("3");
    liste_deroulante(t,b2);
    activer(b2,0);

    conteneur(boxT,frame);

    /***Mois***/


    b3=combo_box(b3,boxT->conteneur);
    o= inialiser_liste_deroulante("1");
    liste_deroulante(o,b3);
    o= inialiser_liste_deroulante("2");
    liste_deroulante(o,b3);
    o= inialiser_liste_deroulante("3");
    liste_deroulante(o,b3);
    activer(b3,0);

    conteneur(boxT,frame);


 /**Annee*/

    b4=combo_box(b4,boxT->conteneur);
    t= inialiser_liste_deroulante("1");
    liste_deroulante(t,b4);
    t= inialiser_liste_deroulante("2");
    liste_deroulante(t,b4);
    t= inialiser_liste_deroulante("3");
    liste_deroulante(t,b4);
    activer(b4,0);

    conteneur(boxT,frame);
    style_entite(framee,"couleur");
    position_fixe(fix->fixe,frame,250,400);


    //-------------entry--------------//

    e= initialiser_entry("ENTRY","LOGIN",0,350);
    creer_entry(e);
    position_fixe(fix->fixe,e->input,e->posx,e->posy);
    e= initialiser_entry("ENTRY","MOT DE PASSE",0,450);
    creer_entry(e);
    position_fixe(fix->fixe,e->input,e->posx,e->posy);

    ///---------creation du bouton simple----------///

    simple= initialiser_bouton("✅OK✅");
    im=initialiser_image_fenetre("icon.png");

    creer_bouton_simple(simple);

    propriete_bouton(simple,350,300,fix,im,20,20);

    imple= initialiser_bouton("❌Quitter❌");
    im=initialiser_image_fenetre("icon.png");

    creer_bouton_simple(imple);

    propriete_bouton(imple,500,300,fix,im,20,20);


    ///************AFFICHAGE***************************///
    affichage(grid,fix,source,fenetre);
}
