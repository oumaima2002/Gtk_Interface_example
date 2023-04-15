//
// Created by gx178 on 4/13/2023.
//


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
void propriete_bouton2(bouton*simple,int x,int y,fixed*fix,image*im,int width,int height)
{
    GtkWidget *image=gtk_image_new_from_file(im->path);
    gtk_widget_set_size_request(GTK_WIDGET(simple->botton),width,height);
    gtk_button_set_image(GTK_BUTTON(simple->botton),image);
    gtk_button_set_always_show_image(GTK_BUTTON(simple->botton),1);
    g_signal_connect(simple->botton,"clicked",G_CALLBACK(gtk_main_quit),NULL);
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
    listemenus *liste,*liste2,*liste3;
    grid*grid;//grid utilise
    menu*cellule2,*cellule3;
    GtkWidget *h,*s,*v,*oi;
    menu*nouveaut,*nouveaute,*p,*l,*k;
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
    bouton *radio,*radio2,*radio3,*radio4;


    /****creation de la fenetre **********/
    fenetre=navbar(fixe,fenetre);

    /**creation du fixed pour la fenetre**/
    fix=initialiser_fixed();
    cree_fixed(fix);
    /*****Scroll Windwo*****/
    source = initialiser_scrol_window(source);//appel  au scroll element
    cree_scroll_window(source);
    /***Inialisation et creation de la grille***/
    grid= initialiser_grid(NULL,NULL,NULL,NULL);//inialisation du grille
    creer_grid(grid);//creation de la grille
    /****La barre de la fenetre*****/
    barre= inialiser_barre_fenetre(0,0);
    creer_barre(barre,fix);
    /****inialiser les cellule de menus**/
    cellule= inialisercelluleparent("Fichier");
    creercelluleparent(cellule,barre);
    cellule2= inialisercelluleparent("Acceuil");
    creercelluleparent(cellule2,barre);
    cellule3= inialisercelluleparent("Insertion");
    creercelluleparent(cellule3,barre);
    style_entite(barre->barre,"barre");
    /*****Listes associéés au menu *****/
    s=menu_type(s);
    h=menu_type(h);
    v=menu_type(v);
    style_entite(s,"couleur");
    style_entite(h,"couleur");
    /** Composantes du Premier Menu ***/
    nouveaute= initialiser_sub_cel_parent(" 📚Enregistrer ");
    p= initialiser_sub_cel_parent("📥Enregistrer sous ");
    nouveaut= initialiser_sub_cel_parent("📚Enregistrer format pdf");
    l= initialiser_sub_cel_parent("📧Ouvrir");
   k= initialiser_sub_cel_parent("📚Fermer");
    liste=creation_liste_vertical(liste,nouveaute,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,p,cellule,s,TRUE,h);
    liste=creation_liste_vertical(liste,nouveaut,cellule,s,FALSE,h);
    liste=creation_liste_vertical(liste,l,cellule,s,FALSE,h);
    liste=creation_liste_vertical(liste,k,cellule,s,FALSE,h);
    /** Composantes du Deuxieme Menu ***/
    liste2=creation_liste_vertical(liste2,nouveaute,cellule2,h,FALSE,h);
    liste2=creation_liste_vertical(liste2,p,cellule2,h,TRUE,h);
    liste2=creation_liste_vertical(liste2,nouveaut,cellule2,h,FALSE,h);

    /** Composantes du Troisieme Menu ***/
    liste3=creation_liste_vertical(liste3,nouveaute,cellule3,v,FALSE,oi);
    liste3=creation_liste_vertical(liste3,p,cellule3,v,FALSE,oi);
    liste3=creation_liste_vertical(liste3,nouveaut,cellule3,v,FALSE,oi);

    /****Associéé  les menu voulu dans la barre ******/
    associer_bar_menu(barre->barre,cellule->item);
    associer_bar_menu(barre->barre,cellule2->item);
    associer_bar_menu(barre->barre,cellule3->item);

    /***Radios Bouttons****/
    box= initialiser_box(TRUE,TRUE);//initialisation du box
    creer_box(box);//creation du box
    frame=creer_frame(frame,"Buttons Rdaios Vertical:");
    conteneur(box, frame);
    radio=initialiser_bouton("Faible");
    radio->botton=bouton_source(radio);
    radio2=initialiser_bouton("Moyen");
    cree_bouton_radio(radio,radio2);
    radio3=initialiser_bouton("Bien");
    cree_bouton_radio(radio,radio3);
    radio4=initialiser_bouton("T. Bien");
    cree_bouton_radio(radio,radio4);
    package_bouton(box->conteneur,radio->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio2->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio3->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio4->botton,FALSE,FALSE,1);
    position_fixe(fix->fixe,frame,0,400);


    /***Radios Bouttons****/
    box= initialiser_box(FALSE,TRUE);//initialisation du box
    creer_box(box);//creation du box
    frame=creer_frame(frame,"Buttons Rdaios Horizontal:");
    conteneur(box, frame);
    radio=initialiser_bouton("Premier");
    radio->botton=bouton_source(radio);
    radio2=initialiser_bouton("Deuxieme");
    cree_bouton_radio(radio,radio2);
    radio3=initialiser_bouton("Troisieme");
    cree_bouton_radio(radio,radio3);

    package_bouton(box->conteneur,radio->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio2->botton,FALSE,FALSE,1);
    package_bouton(box->conteneur,radio3->botton,FALSE,FALSE,1);

    position_fixe(fix->fixe,frame,550,200);
    /*********Check buttons *********/


    fra=creer_frame(frame,"🧑‍💻Liste Choix Multiples:🧑‍💻");
    //gtk_style_context_add_class(gtk_widget_get_style_context(fra),"label");
    boxi=initialiser_box (TRUE,FALSE);
    creer_box(boxi);

    //gtk_style_context_add_class(gtk_widget_get_style_context(boxi),"frae");
    conteneur(boxi,fra);
    check=initialiser_bouton("Mon 1er choix");
    cree_check_bouton(check);
    check2=initialiser_bouton("Mon 2e choix");
    cree_check_bouton(check2);
    check1=initialiser_bouton("Mon 3e choix");
    cree_check_bouton(check1);
    check3=initialiser_bouton("Mon dernier Choix");
    cree_check_bouton(check3);

    package_bouton(boxi->conteneur,check->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check2->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check1->botton,FALSE,FALSE,1);
    package_bouton(boxi->conteneur,check3->botton,FALSE,FALSE,1);

    position_fixe(fix->fixe,fra,550,10  );


    /**********liste deroulante choix ************/
    frame= creer_frame(frame,"Liste Deroulante:Multi choix");
    boxT= initialiser_box(TRUE,TRUE);//initialisation du box
    GtkWidget *lab= gtk_label_new("Choix parmis 5::");
    creer_box(boxT);//creation du box



    position_fixe(fix->fixe,frame,0,100);
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

    GtkWidget *labe= gtk_label_new("Choix parmis 7::");
    gtk_container_add(GTK_BOX(boxT->conteneur),labe);
    b3=combo_box(b3,boxT->conteneur);
    o= inialiser_liste_deroulante("1");
    liste_deroulante(o,b3);
    o= inialiser_liste_deroulante("2");
    liste_deroulante(o,b3);
    o= inialiser_liste_deroulante("3");
    liste_deroulante(o,b3);
    activer(b3,0);

    conteneur(boxT,frame);



   // conteneur(boxT,frame);
    style_entite(framee,"couleur");
    position_fixe(fix->fixe,frame,0,100);


   //-------------entry--------------//
    frame= creer_frame(frame,"Saisir du login et de mot de passe:Zone de texte");
    boxT= initialiser_box(TRUE,TRUE);//initialisation du box
    creer_box(boxT);//creation du box
    conteneur(box, frame);
    e= initialiser_entry("ENTRY","LOGIN",600,350);
    creer_entry(e);
    position_fixe(fix->fixe,e->input,e->posx,e->posy);
    //gtk_container_add(GTK_FRAME(frame),fix->fixe);
    e= initialiser_entry("ENTRY","MOT DE PASSE",600,400);
    creer_entry(e);
    position_fixe(fix->fixe,e->input,e->posx,e->posy);
    GtkWidget *g= gtk_check_button_new_with_label("Maintenir la connexion");
    position_fixe(fix->fixe,g,600,440);
    simple= initialiser_bouton("🌐Se Connecter🌐");
    im=initialiser_image_fenetre("icon.png");

    creer_bouton_simple(simple);

    propriete_bouton(simple,600,480,fix,im,30,20);
    conteneur(box, frame);
     style_entite(framee,"couleur");
    position_fixe(fix->fixe,frame,600,330);


    ///---------creation du bouton simple----------///

    simple= initialiser_bouton("✅OK✅");
    im=initialiser_image_fenetre("icon.png");

    creer_bouton_simple(simple);

    propriete_bouton(simple,0,300,fix,im,30,20);

    imple= initialiser_bouton("❌Quitter❌");
    im=initialiser_image_fenetre("icon.png");

    creer_bouton_simple(imple);

    propriete_bouton2(imple,150,300,fix,im,30,20);


    ///************AFFICHAGE***************************///
    affichage(grid,fix,source,fenetre);
}
