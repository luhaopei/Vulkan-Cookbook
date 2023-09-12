//
// Created by luhaopei on 23-9-7.
//

#ifndef VULKANCOOKBOOK_VULKANAPPLICATION_H
#define VULKANCOOKBOOK_VULKANAPPLICATION_H
#include "Common.h"
#include <linux/input.h>
#include "xdg-shell-client-header.h"
#include "xdg-decoration-client-header.h"

namespace VulkanCookbook {

    class VulkanCookbookSampleBase;

    class VulkanApplication  {
    public:
        VulkanApplication(const char * title_, int x, int y, int width, int height, VulkanCookbookSampleBase &sample);
        //virtual ~VulkanApplication();
    public:
        void init();
        void init_connection();
        void create_window();
        void run();
        void init_vk();
    protected:

    public:
        wl_display *display = nullptr;
        wl_registry *registry = nullptr;
        wl_compositor *compositor = nullptr;
        wl_surface *window = nullptr;
        xdg_wm_base *wm_base = nullptr;
        zxdg_decoration_manager_v1 *xdg_decoration_mgr = nullptr;
        zxdg_toplevel_decoration_v1 *toplevel_decoration = nullptr;
        xdg_surface *window_surface = nullptr;
        bool xdg_surface_has_been_configured = false;
        xdg_toplevel *window_toplevel = nullptr;
        wl_seat *seat = nullptr;
        wl_pointer *pointer = nullptr;
        wl_keyboard *keyboard = nullptr;
        const char * title_;
        int x_;
        int y_;
        uint32_t width_;
        uint32_t height_;
        VulkanCookbookSampleBase &sample_;
        bool quit = false;
        WindowParameters parameters;
        bool create_ = false;
    };

} // namespace VulkanCookbook
#endif //VULKANCOOKBOOK_VULKANAPPLICATION_H
