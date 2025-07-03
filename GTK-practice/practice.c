#include <gtk/gtk.h>

void button1(GtkWidget *widget, gpointer data1){
    g_print("You pressed button 1\n");
}

void button2(GtkWidget *widget, gpointer data2){
    g_print("You pressed button 2\n");
}

int main(int argc, char *argv[]){

    GtkBuilder *builder;
    GObject *window;
    GObject *button;
    GError *error = NULL;

    gtk_init (&argc, &argv);
    builder = gtk_builder_new();

    if(gtk_builder_add_from_file(builder, "builder.ui", &error)==0){
        g_printerr("Cannot find the builder file %s\n", error->message);
        g_clear_error(&error);
        return 1;
    }

    window = gtk_builder_get_object(builder, "window");
    button = gtk_builder_get_object(builder, "button1");
    button = gtk_builder_get_object(builder, "button2");
    button = gtk_builder_get_object(builder, "quit");

    gtk_builder_connect_signals(builder,NULL);

    gtk_main();
    return 0;

}