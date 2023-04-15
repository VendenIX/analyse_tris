/*#include "../../include/view/GUI.hpp"

my_gdata create_gdata() {
    my_gdata data = (my_gdata)malloc(sizeof(struct My_GData));
    data->tri = NULL;
    data->melange = NULL;
    data->visu = 0;
    data->taille = 0;
    return data;
}

void destroy_gdata(my_gdata data) {
    free(data);
}

void print_gdata(my_gdata data) {
    std::cout << "Print gdata" << std::endl;
    std::cout << "Tri : " << data->tri << std::endl;
    std::cout << "Melange : " << data->melange << std::endl;
    std::cout << "Visu : " << data->visu << std::endl;
    std::cout << "Taille : " << data->taille << std::endl;
}

Sorting<int>* selectSorting(std::string argv, int* liste, size_t size) {
    if (argv == "BingoSort") {
        return new BingoSort<int>(liste, size);
    } else if (argv == "BitonicSort") {
        return new BitonicSort<int>(liste, size);
    } else if (argv == "BubbleSort") {
        return new BubbleSort<int>(liste, size);
    } else if (argv == "BucketSort") {
        return new BucketSort<int>(liste, size);
    } else if (argv == "CocktailSort") {
        return new CocktailSort<int>(liste, size);
    } else if (argv == "CombSort") {
        return new CombSort<int>(liste, size);
    } else if (argv == "CycleSort") {
        return new CycleSort<int>(liste, size);
    } else if (argv == "GnomeSort") {
        return new GnomeSort<int>(liste, size);
    } else if (argv == "HeapSort") {
        return new HeapSort<int>(liste, size);
    } else if (argv == "InsertionSort") {
        return new InsertionSort<int>(liste, size);
    } else if (argv == "MergeSort") {
        return new MergeSort<int>(liste, size);
    } else if (argv == "PancakeSort") {
        return new PancakeSort<int>(liste, size);
    } else if (argv == "PigeonholeSort") {
        return new PigeonholeSort<int>(liste, size);
    } else if (argv == "QuickSort") {
        return new QuickSort<int>(liste, size);
    } else if (argv == "RadixSort") {
        return new RadixSort<int>(liste, size);
    } else if (argv == "SelectionSort") {
        return new SelectionSort<int>(liste, size);
    } else if (argv == "ShellSort") {
        return new ShellSort<int>(liste, size);
    } else if (argv == "SleepSort") {
        return new SleepSort<int>(liste, size);
    } else if (argv == "StrandSort") {
        return new StrandSort<int>(liste, size);
    } 
    exit(EXIT_FAILURE);
}

// Fonction de rappel pour le message de fermeture de la fenêtre
static void on_window_closed(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

// Fonction de rappel pour la sélection de l'élément dans la liste déroulante
static void on_combo_changed(GtkComboBox *widget, gpointer data)
{
    my_gdata gdata = (my_gdata)data;
    gdata->tri = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    g_print("Vous avez sélectionné : %s\n", text);
    g_free(text);
}

static void on_melange_changed(GtkComboBox *widget, gpointer data)
{
    my_gdata gdata = (my_gdata)data;
    gdata->melange = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    g_print("Vous avez sélectionné : %s\n", text);
    g_free(text);
}

// Fonction de rappel pour le clic sur la case à cocher
static void on_check_toggled(GtkToggleButton *toggle_button, gpointer data)
{
    my_gdata gdata = (my_gdata)data;
    gdata->visu = gtk_toggle_button_get_active(toggle_button);
    gboolean active = gtk_toggle_button_get_active(toggle_button);
    if (active)
        g_print("La case est cochée.\n");
    else
        g_print("La case n'est pas cochée.\n");
}

// Fonction de rappel pour la validation de la saisie de nombre
static void on_entry_activate(GtkEntry *entry, gpointer data)
{
    my_gdata gdata = (my_gdata)data;
    gdata->taille = atoi(gtk_entry_get_text(entry));
    const gchar *text = gtk_entry_get_text(entry);
    gint value = atoi(text);
    g_print("Vous avez entré : %d\n", value);
}

// Submit the form
static void execution(gchar *gmelange, gchar *gtri, int taille, bool visualisation) {
    std::string melange = gmelange;
    std::string tri = gtri;

    std::cout << "Melange : " << melange << std::endl;
    std::cout << "Tri : " << tri << std::endl;
    std::cout << "Taille : " << taille << std::endl;
    std::cout << "Visualisation : " << visualisation << std::endl;

    #pragma region Visualisation
    size_t size = taille;

    int liste[size];
    for (size_t i = 0; i < size; i++) {
        liste[i] = i;
    }

    Sorting<int>* s = selectSorting(gtri, liste, size);
    Window<int>* w = nullptr;
    if (visualisation) {
        Window<int>* w = new Window<int>(1200, 720, s, 60);
    }
    // initialize random seed:
    srand(time(NULL));
    int seed = 140;//rand();
    s->schuffle(seed, seed % 100);
    if (visualisation) {
        std::cout << s->get() << std::endl;
        std::cout << "Seed = " << seed << std::endl;
        w->schuffled(s);
        std::cout << "Seed2 = " << seed << std::endl;
        while (w->isOpen() && !s->isSorted()) {
        std::cout << "Seed3 = " << seed << std::endl;
            w->pollEvent();
            if (w->isStart()) {
                s->sort();
                std::cout << "Nombre de comparaisons = " << s->getComparisons() << std::endl;
                std::cout << "Nombre de déplacements = " << s->getCount() << std::endl;
                w->update(s->getSwitches());
            } else {
                w->update();
            }
        }
    } else {
        // get time before
        auto start = std::chrono::high_resolution_clock::now();
        s->sort();
        // get time after
        auto end = std::chrono::high_resolution_clock::now();
        // calculate time difference
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;
    }
    //std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    #pragma endregion
}

static void on_button_clicked(GtkButton *button, gpointer data)
{
    g_print("Button clicked\n");
    my_gdata gdata = (my_gdata)data;
    print_gdata(gdata);
    execution(gdata->melange, gdata->tri, gdata->taille, gdata->visu);
    on_window_closed(NULL, NULL);
}

void run_gtk(int argc, char *argv[]) {
    my_gdata data = create_gdata();

    // Initialiser GTK+
    std::cout << "Initialisation de GTK+" << std::endl;
    gtk_init(&argc, &argv);

    // Créer une fenêtre principale
    std::cout << "Création de la fenêtre" << std::endl;
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Algortihmes de tri");
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    // Créer une boîte verticale pour les éléments de l'interface
    std::cout << "Création de la boîte verticale" << std::endl;
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Créer une liste déroulante
    std::cout << "Création de la liste déroulante" << std::endl;
    GtkWidget *melanges = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(melanges), "Choisir un algorithme de mélange");
    std::vector<std::string> melange = std::vector<std::string>{"", ""};
    for (int i = 0; i < melange.size(); i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(melanges), melange[i].c_str());
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(melanges), 0);
    g_signal_connect(melanges, "changed", G_CALLBACK(on_combo_changed), &data);
    gtk_box_pack_start(GTK_BOX(vbox), melanges, FALSE, FALSE, 0);

    // Créer une liste déroulante
    std::cout << "Création de la liste déroulante" << std::endl;
    GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Choisir un algorithme de tri");
    std::vector<std::string> names = readSortNames();
    for (int i = 0; i < names.size(); i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), names[i].c_str());
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);
    g_signal_connect(combo, "changed", G_CALLBACK(on_combo_changed), &data);
    gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);

    // Ajout de texte
    std::cout << "Ajout de texte" << std::endl;
    GtkWidget *label = gtk_label_new("Nombre d'éléments à trier");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // Créer une zone de saisie de nombre
    std::cout << "Création de la zone de saisie de nombre" << std::endl;
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
    g_signal_connect(entry, "activate", G_CALLBACK(on_entry_activate), &data);
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    // Créer une case à cocher
    std::cout << "Création de la case à cocher" << std::endl;
    GtkWidget *check = gtk_check_button_new_with_label("Avec visualisation");
    gpointer *gcheck = NULL;
    g_signal_connect(check, "toggled", G_CALLBACK(on_check_toggled), &data);
    gtk_box_pack_start(GTK_BOX(vbox), check, FALSE, FALSE, 0);

    // Créer un bouton pour soumettre le formulaire avec les données saisies
    std::cout << "Création du bouton" << std::endl;
    GtkWidget *button = gtk_button_new_with_label("Soumettre");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), &data);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Afficher tous les éléments de l'interface
    std::cout << "Affichage de l'interface" << std::endl;
    gtk_widget_show_all(window);

    // Lancer la boucle d'événnements
    std::cout << "Lancement de la boucle d'événements" << std::endl;
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), &data);
    gtk_main();
}*/