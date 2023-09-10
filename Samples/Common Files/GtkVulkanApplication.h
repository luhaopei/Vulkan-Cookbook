//
// Created by luhaopei on 23-9-7.
//

#ifndef VULKANCOOKBOOK_GTKAPPLICATION_H
#define VULKANCOOKBOOK_GTKAPPLICATION_H
#include <gtkmm.h>

namespace VulkanCookbook {
    class VulkanCookbookSampleBase;
    class GtkApplication : Gtk::Application {
    private:
        GtkApplication(const char * title_, int x, int y, int width, int height, VulkanCookbookSampleBase &sample);
    public:
        static Glib::RefPtr<GtkApplication> create(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample);
    protected:
        void on_activate() override;
        void on_open(const Gio::Application::type_vec_files& file,
                     const Glib::ustring&hint ) override;
    private:
        void create_window(const Glib::RefPtr<Gio::File>& file = Glib::RefPtr<Gio::File>());

    private:
        const char * title_;
        int x_;
        int y_;
        int width_;
        int height_;
        VulkanCookbookSampleBase &sample_;
    };

} // namespace VulkanCookbook
#endif //VULKANCOOKBOOK_GTKAPPLICATION_H
