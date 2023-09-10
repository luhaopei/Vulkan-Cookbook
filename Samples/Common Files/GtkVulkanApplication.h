//
// Created by luhaopei on 23-9-7.
//

#ifndef VULKANCOOKBOOK_GTKVULKANAPPLICATION_H
#define VULKANCOOKBOOK_GTKVULKANAPPLICATION_H
#include "Common.h"
#include <gtkmm.h>
#include "GtkAppWindow.h"

namespace VulkanCookbook {

    class VulkanCookbookSampleBase;

    class GtkVulkanApplication :public Gtk::Application {
    protected:
        GtkVulkanApplication(const char * title_, int x, int y, int width, int height, VulkanCookbookSampleBase &sample);
    public:
        static Glib::RefPtr<GtkVulkanApplication> create(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample);
    protected:
        void on_activate() override;
        //void on_startup() override;
    private:
        GtkAppWindow *create_window();
        void on_window_hide(Gtk::Window* window);
    private:
        const char * title_;
        int x_;
        int y_;
        int width_;
        int height_;
        VulkanCookbookSampleBase &sample_;
    };

} // namespace VulkanCookbook
#endif //VULKANCOOKBOOK_GTKVULKANAPPLICATION_H
