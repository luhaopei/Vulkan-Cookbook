//
// Created by luhaopei on 23-9-6.
//

#ifndef VULKANCOOKBOOK_GTKAPPWINDOW_H
#define VULKANCOOKBOOK_GTKAPPWINDOW_H

#include <gtkmm.h>
#include "Common.h"

namespace VulkanCookbook {

    class VulkanCookbookSampleBase;

    class GtkAppWindow : public Gtk::Window {
    public:
        GtkAppWindow(int x, int y, int width, int height, VulkanCookbookSampleBase &sample);

        virtual ~GtkAppWindow();

    protected:
        void on_button_clicked();
        void on_drawing_area_realized();
        void on_drawing_erea_draw(const Cairo::RefPtr<Cairo::Context>&, int, int);
        void on_resize_erea(int width, int height);
        bool on_rendering(const Glib::RefPtr<Gdk::GLContext>&);
    private:
        int width_;
        int height_;
        int x_;
        int y_;

        VulkanCookbookSampleBase &sample_;
        WindowParameters windowParameters_;
        bool create_ = false;
        bool isDoSomething_ = false;
        bool initial_ = false;
        Glib::RefPtr<Gtk::GestureClick> m_refGestUreClick;

        guint add_tick_id;

        //Gtk::DrawingArea m_DrawingArea;
        //Gtk::GLArea m_GLArea;
        //Gtk::Widget m_Widget;

    private:
        bool on_window_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);

        void on_window_mouse_pressed(int n_press, double x, double y);

        bool on_tick(const Glib::RefPtr<Gdk::FrameClock>& frame_clock);

    };

} //namespace VulkanCookbook

#endif //VULKANCOOKBOOK_GTKAPPWINDOW_H
