//
// Created by luhaopei on 23-9-6.
//


#include "GtkAppWindow.h"
#include <iostream>
#include <gtkmm/application.h>
#include <gdk/wayland/gdkwayland.h>
#include "CookbookSampleFramework.h"
#include <gtk/gtk.h>
namespace VulkanCookbook {


    GtkAppWindow::GtkAppWindow(int x, int y, int width, int height, VulkanCookbookSampleBase &sample) : //m_button("hello world") ,
    x_(x),
    y_(y),
    width_(width),
    height_(height),
    sample_(sample),
    windowParameters_()
    {
        //m_DrawingArea.set_content_width(width_);
        //m_DrawingArea.set_content_height(height_);
        //set_child(m_DrawingArea);
        //m_DrawingArea.signal_realize().connect(
        //        sigc::mem_fun(*this, &GtkAppWindow::on_drawing_area_realized));
        //m_DrawingArea.set_draw_func(
        //        sigc::mem_fun(*this, &GtkAppWindow::on_drawing_erea_draw)
        //        );

        //set_default_widget(m_GLArea);
//        m_GLArea.signal_resize().connect(sigc::mem_fun(*this, &GtkAppWindow::on_resize_erea));
//        m_GLArea.signal_realize().connect(sigc::mem_fun(*this, &GtkAppWindow::on_drawing_area_realized));
//        m_GLArea.set_visible();
//        m_GLArea.signal_render().connect(sigc::mem_fun(*this, &GtkAppWindow::on_rendering);
//        set_child(m_GLArea);

        this->signal_realize().connect(sigc::mem_fun(*this, &GtkAppWindow::on_drawing_area_realized));

        set_default_size(width_, height_);

//        auto windows = list_toplevels();
//        for(auto & window : windows){
////            auto display = window->get_display();
////            GdkDisplay * gdkDisplay = display->gobj();
////            windowParameters_.display = gdk_wayland_display_get_wl_display(gdkDisplay);
////            GdkSurface * surface =  gtk_native_get_surface(GTK_NATIVE(window));
////            windowParameters_.surface = gdk_wayland_surface_get_wl_surface(surface);
////            int widths = gdk_surface_get_width(surface);
////            int heights = gdk_surface_get_height(surface);
////
////            widths;
////            heights;
//        }
        // keyboard event
        auto controller = Gtk::EventControllerKey::create();
        controller->signal_key_pressed().connect(
           sigc::mem_fun(*this, &GtkAppWindow::on_window_key_pressed), false);
        add_controller(controller);

        // mouse click
        m_refGestUreClick = Gtk::GestureClick::create();
        m_refGestUreClick->set_button(GDK_BUTTON_PRIMARY);
        m_refGestUreClick->signal_pressed().connect(
                sigc::mem_fun(*this, &GtkAppWindow::on_window_mouse_pressed));
        add_controller(m_refGestUreClick);

        add_tick_id = Gtk::Widget::add_tick_callback(sigc::mem_fun(*this, &GtkAppWindow::on_tick));

        create_ = true;


        auto display = get_display();
        GdkDisplay * gdkDisplay = display->gobj();
        windowParameters_.display = gdk_wayland_display_get_wl_display(gdkDisplay);
        GdkSurface *gdkSurface = gdk_surface_new_toplevel(gdkDisplay);
        windowParameters_.surface = gdk_wayland_surface_get_wl_surface(gdkSurface);

        create_ = sample_.Initialize(windowParameters_);
        if (create_)
            present();

    }

    GtkAppWindow::~GtkAppWindow() noexcept {
        sample_.Deinitialize();
        Gtk::Widget::remove_tick_callback(add_tick_id);
    }

    void GtkAppWindow::on_resize_erea(int width, int height)
    {

    }
    bool GtkAppWindow::on_rendering(const Glib::RefPtr<Gdk::GLContext>&content){

    }

    void GtkAppWindow::on_drawing_erea_draw(const Cairo::RefPtr<Cairo::Context>&, int, int){
        std::cout << "on_drawing_erea_draw" << std::endl;
    }

    void GtkAppWindow::on_drawing_area_realized() {
        std::cout << "on_drawing_area_realized" << std::endl;
        auto gtk_native = this->get_native();
//        if(gtk_native) {
//            auto gdk_surface = gtk_native->get_surface();
//            if (gdk_surface) {
//
//                windowParameters_.display = gdk_wayland_display_get_wl_display(gdk_surface->get_display()->gobj());
//                windowParameters_.surface = gdk_wayland_surface_get_wl_surface(gdk_surface->gobj());
//                create_ = true;
//
//            }
//        }
    }

    void GtkAppWindow::on_button_clicked() {
        std::cout << "Hello world" << std::endl;
    }
    bool GtkAppWindow::on_window_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state)  {
        return false;
    }
    void GtkAppWindow::on_window_mouse_pressed(int n_press, double x, double y){
        isDoSomething_ = true;
        std::cout << "x:" << x <<  " y:" << y << std::endl;
        isDoSomething_ = false;
    }

    bool GtkAppWindow::on_tick(const Glib::RefPtr<Gdk::FrameClock>& frame_clock){
        if(isDoSomething_ || !create_)
            return false;
        if(sample_.IsReady())
        {
            sample_.UpdateTime();
            sample_.Draw();
            sample_.MouseReset();
        }
    }

}