#include<gtk/gtk.h>

static void myfunc(GtkWidget *widget, gpointer data) 
{
    g_print("Hello World\n");
}

static void myprint(GtkWidget *wid, gpointer anydata)
{
    g_print("Printing something on terminal\n");
}
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button_box;
    GtkWidget *button_box2;
    GtkWidget *button1;
    GtkWidget *button2;

    window = gtk_application_window_new(app);

    gtk_window_set_title ((GtkWindow*) (window), "Window");

    gtk_window_set_default_size((GtkWindow*)window, 400, 400);


    // button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    // gtk_container_add((GtkContainer*)window, button_box);

    button_box2 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add((GtkContainer*)window, button_box2);



    // button1 = gtk_button_new_with_label("Hello World");
    button2 = gtk_button_new_with_label("Print something");
    // g_signal_connect (button1, "clicked", G_CALLBACK(myfunc), NULL);
    g_signal_connect (button2, "clicked", G_CALLBACK(myprint), NULL);
    // g_signal_connect (button2, "clicked", G_CALLBACK(gtk_widget_destroy), window);      // will destroy button itself
    // g_signal_connect_swapped(button1, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    g_signal_connect_swapped(button2, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    // gtk_container_add((GtkContainer*)button_box, button1);
    gtk_container_add((GtkContainer*)button_box2, button2);
    
    gtk_widget_show_all(window);


    // g_object_unref(button);
}

int main(int argc, char** argv)
{
    GtkApplication *app;
    
    app = gtk_application_new("hello.world", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION (app), argc, argv );

    g_object_unref(app);

    return status;

}