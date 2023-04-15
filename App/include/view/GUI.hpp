#include <gtk/gtk.h>
#include <vector>
#include "../Model.hpp"
#include "Window.hpp"
#include <iostream>
#include <random>

typedef struct My_GData {
    gchar *tri;
    gchar *melange;
    bool visu;
    int taille;
} * my_gdata;

my_gdata create_gdata();

void print_gdata(my_gdata data);

void destroy_gdata(my_gdata data);

// Fonction de rappel pour le message de fermeture de la fenêtre
static void on_window_closed(GtkWidget *widget, gpointer data);

// Fonction de rappel pour la sélection de l'élément dans la liste déroulante
static void on_combo_changed(GtkComboBox *widget, gpointer data);
// Fonction de rappel pour le clic sur la case à cocher
static void on_check_toggled(GtkToggleButton *toggle_button, gpointer data);

// Fonction de rappel pour la validation de la saisie de nombre
static void on_entry_activate(GtkEntry *entry, gpointer data);

static void on_submit_clicked(GtkButton *button, gpointer data);

void run_gtk(int argc, char *argv[]);