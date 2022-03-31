#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdio.h>

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "MyWindow");
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 400);
    gtk_widget_show_all(window);
}

int main(int args, char **argv)
{
    GtkApplication *app;
    // app = gtk_application_new("myfirstgui", G_APPLICATION_FLAGS_NONE);
    app = gtk_application_new("my.firstgui", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION (app), args, argv);

    g_object_unref(app);

    return status;

}