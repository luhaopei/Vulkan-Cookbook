//
// Created by luhaopei on 23-9-7.
//

#include "GtkVulkanApplication.h"

namespace VulkanCookbook{

    GtkVulkanApplication::GtkVulkanApplication(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample):
    title_(title),
        x_(x),
        y_(y),
        width_(width),
        height_(height),
        sample_(sample),
        Gtk::Application("org.gtkmm.examples.applicaion", Gio::Application::Flags::HANDLES_OPEN) {
        Glib::set_application_name(title);
    }

    Glib::RefPtr<VulkanCookbook::GtkVulkanApplication> GtkVulkanApplication::create(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample){
        return Glib::make_refptr_for_instance<VulkanCookbook::GtkVulkanApplication>(new VulkanCookbook::GtkVulkanApplication(title, x, y, width, height, sample));
    }
    GtkAppWindow * GtkVulkanApplication::create_window() {
        auto window = new GtkAppWindow(x_, y_, width_, height_, sample_);
        add_window(*window);
        // todo
       window->signal_hide().connect(sigc::bind(
               sigc::mem_fun(*this, &GtkVulkanApplication::on_window_hide), window));

       return window;
    }

    void GtkVulkanApplication::on_window_hide(Gtk::Window* window)
    {
        delete window;
    }
    void GtkVulkanApplication::on_activate() {
        create_window();

    }

} // namespace VulkanCookbook