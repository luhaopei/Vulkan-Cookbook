//
// Created by luhaopei on 23-9-7.
//

#include "GtkApplication.h"
#include "GtkAppWindow.h"
#include "CookbookSampleFramework.h"

namespace VulkanCookbook{
    class VulkanCookbookSampleBase;

    GtkApplication::GtkApplication(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample):
    title_(title),
    x_(x),
        y_(y),
        width_(width),
        height_(height),
        sample_(sample),
        Gtk::Application("org.gtkmm.examples.applicaion", Gio::Application::Flags::HANDLES_OPEN) {
        Glib::set_application_name("VulkanCookbook demo");
    }

    Glib::RefPtr<GtkApplication> GtkApplication::create(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample){

        return Glib::make_refptr_for_instance<GtkApplication>(new GtkApplication(title, x,  y, width, height, sample));
    }
    void GtkApplication::create_window(const Glib::RefPtr<Gio::File> &file) {
        auto window = new GtkAppWindow(x_, y_, width_, height_, sample_);
        add_window(*window);
        // todo
        window->signal_hide().connect([window](){delete window;});
        window->set_visible(true);

        if(!file){
            return;
        }
        const bool loaded = window->load_file(file);
        if(!loaded)
            std::cerr << "This file could not be loaded:" << file->get_path() << std::endl;

    }

    void GtkApplication::on_activate() {
        create_window();
    }

    void GtkApplication::on_open(const Gio::Application::type_vec_files &files, const Glib::ustring &hint) {
        for(guint i = 0; i < files.size(); i++){
            auto file = files[i];
            if(!file){
                std::cerr << G_STRFUNC << ": file is null." << std::endl;

            } else{
                create_window(file);
            }
        }
        Gtk::Application::on_open(files, hint);
    }

} // namespace VulkanCookbook