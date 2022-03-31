#include<gtk/gtk.h>

static void myprint1(GtkWidget *widget, gpointer data)
{
    g_print("Hello There!!\n");
}

static void myprint2(GtkWidget *wid, gpointer data)
{
    g_print("This is Pratyush\n\n");
}

static void myfunc( GtkApplication *app,gpointer data)
{
    GtkWidget *window;
    GtkWidget *gridbox;
    GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title((GtkWindow*)window, "window");
    gtk_container_set_border_width(GTK_CONTAINER (window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gridbox = gtk_grid_new();

    button = gtk_button_new_with_label("button 1");
    g_signal_connect(button, "clicked", G_CALLBACK(myprint1), NULL);

    gtk_grid_attach(GTK_GRID (gridbox), button, 0, 0, 1, 1);


    button = gtk_button_new_with_label("button 2");
    g_signal_connect(button, "clicked", G_CALLBACK(myprint2), NULL);
    gtk_grid_attach(GTK_GRID (gridbox ), button, 1, 0, 1, 1);


    button = gtk_button_new_with_label("close");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID (gridbox), button, 0, 1, 2, 4);
    gtk_container_add(GTK_CONTAINER (window), gridbox);

    gtk_widget_show_all(window);


    
}

int main(int argc, char** argv)
{
    GtkApplication *app = gtk_application_new("my.grid", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(myfunc), NULL);

    int status  = g_application_run( G_APPLICATION (app), argc, argv);

    g_object_unref(app);
    return status;
}