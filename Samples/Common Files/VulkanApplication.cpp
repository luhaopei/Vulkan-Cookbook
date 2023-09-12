//
// Created by luhaopei on 23-9-7.
//

#include "VulkanApplication.h"
#include "CookbookSampleFramework.h"

#define APP_SHORT_NAME "demo"
namespace VulkanCookbook{
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    static void pointer_handle_enter(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface, wl_fixed_t sx,
                                     wl_fixed_t sy) {}

    static void pointer_handle_leave(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface) {}

    static void pointer_handle_motion(void *data, struct wl_pointer *pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy) {}

    static void pointer_handle_button(void *data, struct wl_pointer *wl_pointer, uint32_t serial, uint32_t time, uint32_t button,
                                      uint32_t state) {
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED) {
            xdg_toplevel_move(demo.window_toplevel, demo.seat, serial);
        }
    }

    static void pointer_handle_axis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value) {}

    static const struct wl_pointer_listener pointer_listener = {
            pointer_handle_enter, pointer_handle_leave, pointer_handle_motion, pointer_handle_button, pointer_handle_axis,
    };

    static void keyboard_handle_keymap(void *data, struct wl_keyboard *keyboard, uint32_t format, int fd, uint32_t size) {}

    static void keyboard_handle_enter(void *data, struct wl_keyboard *keyboard, uint32_t serial, struct wl_surface *surface,
                                      struct wl_array *keys) {}

    static void keyboard_handle_leave(void *data, struct wl_keyboard *keyboard, uint32_t serial, struct wl_surface *surface) {}

    static void keyboard_handle_key(void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t time, uint32_t key,
                                    uint32_t state) {
        if (state != WL_KEYBOARD_KEY_STATE_RELEASED) return;
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        switch (key) {
            case KEY_ESC:  // Escape
                demo.quit = true;
                break;
            case KEY_LEFT:  // left arrow key
                break;
            case KEY_RIGHT:  // right arrow key
                break;
            case KEY_SPACE:  // space bar
                break;
        }
    }

    static void keyboard_handle_modifiers(void *data, wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed,
                                          uint32_t mods_latched, uint32_t mods_locked, uint32_t group) {}

    static const struct wl_keyboard_listener keyboard_listener = {
            keyboard_handle_keymap, keyboard_handle_enter, keyboard_handle_leave, keyboard_handle_key, keyboard_handle_modifiers,
    };

    static void seat_handle_capabilities(void *data, wl_seat *seat, uint32_t caps) {
        // Subscribe to pointer events
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        if ((caps & WL_SEAT_CAPABILITY_POINTER) && !demo.pointer) {
            demo.pointer = wl_seat_get_pointer(seat);
            wl_pointer_add_listener(demo.pointer, &pointer_listener, &demo);
        } else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && demo.pointer) {
            wl_pointer_destroy(demo.pointer);
            demo.pointer = nullptr;
        }
        // Subscribe to keyboard events
        if (caps & WL_SEAT_CAPABILITY_KEYBOARD) {
            demo.keyboard = wl_seat_get_keyboard(seat);
            wl_keyboard_add_listener(demo.keyboard, &keyboard_listener, &demo);
        } else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD) && demo.keyboard) {
            wl_keyboard_destroy(demo.keyboard);
            demo.keyboard = nullptr;
        }
    }

    static const wl_seat_listener seat_listener = {
            seat_handle_capabilities,
    };

    static void wm_base_ping(void *data, xdg_wm_base *xdg_wm_base, uint32_t serial) { xdg_wm_base_pong(xdg_wm_base, serial); }

    static const struct xdg_wm_base_listener wm_base_listener = {wm_base_ping};

    static void registry_handle_global(void *data, wl_registry *registry, uint32_t id, const char *interface, uint32_t version) {
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        // pickup wayland objects when they appear
        if (strcmp(interface, wl_compositor_interface.name) == 0) {
            demo.compositor = (wl_compositor *)wl_registry_bind(registry, id, &wl_compositor_interface, 1);
        } else if (strcmp(interface, xdg_wm_base_interface.name) == 0) {
            demo.wm_base = (xdg_wm_base *)wl_registry_bind(registry, id, &xdg_wm_base_interface, 1);
            xdg_wm_base_add_listener(demo.wm_base, &wm_base_listener, nullptr);
        } else if (strcmp(interface, wl_seat_interface.name) == 0) {
            demo.seat = (wl_seat *)wl_registry_bind(registry, id, &wl_seat_interface, 1);
            wl_seat_add_listener(demo.seat, &seat_listener, &demo);
        } else if (strcmp(interface, zxdg_decoration_manager_v1_interface.name) == 0) {
            demo.xdg_decoration_mgr =
                    (zxdg_decoration_manager_v1 *)wl_registry_bind(registry, id, &zxdg_decoration_manager_v1_interface, 1);
        }
    }

    static void registry_handle_global_remove(void *data, wl_registry *registry, uint32_t name) {}

    static const wl_registry_listener registry_listener = {registry_handle_global, registry_handle_global_remove};

    static void handle_surface_configure(void *data, xdg_surface *xdg_surface, uint32_t serial) {
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        xdg_surface_ack_configure(xdg_surface, serial);
        if (demo.xdg_surface_has_been_configured) {
            //demo.resize();
        }
        demo.xdg_surface_has_been_configured = true;
    }

    static const xdg_surface_listener surface_listener = {handle_surface_configure};

    static void handle_toplevel_configure(void *data, xdg_toplevel *xdg_toplevel, int32_t width, int32_t height,
                                          struct wl_array *states) {
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        /* zero values imply the program may choose its own size, so in that case
         * stay with the existing value (which on startup is the default) */
        if (width > 0) {
            demo.width_ = static_cast<int>(width);
        }
        if (height > 0) {
            demo.height_ = static_cast<int>(height);
        }
        // This will be followed by a surface configure
    }

    static void handle_toplevel_close(void *data, xdg_toplevel *xdg_toplevel) {
        VulkanApplication &demo = *static_cast<VulkanApplication *>(data);
        demo.quit = true;
    }

    static const xdg_toplevel_listener toplevel_listener = {handle_toplevel_configure, handle_toplevel_close};

#endif
    VulkanApplication::VulkanApplication(const char * title, int x, int y, int width, int height, VulkanCookbookSampleBase &sample):
    title_(title),
        x_(x),
        y_(y),
        width_(width),
        height_(height),
        sample_(sample){

    }

    void VulkanApplication::init()
    {
        init_connection();
    }
    void VulkanApplication::init_connection() {
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        display = wl_display_connect(nullptr);

        if (display == nullptr) {
            printf("Cannot connect to wayland.\nExiting ...\n");
            fflush(stdout);
            exit(1);
        }

        registry = wl_display_get_registry(display);
        wl_registry_add_listener(registry, &registry_listener, this);
        wl_display_dispatch(display);
#endif
    }

    void VulkanApplication::create_window()
    {
        if (!wm_base) {
            printf("Compositor did not provide the standard protocol xdg-wm-base\n");
            fflush(stdout);
            exit(1);
        }

        window = wl_compositor_create_surface(compositor);
        if (!window) {
            printf("Can not create wayland_surface from compositor!\n");
            fflush(stdout);
            exit(1);
        }

        window_surface = xdg_wm_base_get_xdg_surface(wm_base, window);
        if (!window_surface) {
            printf("Can not get xdg_surface from wayland_surface!\n");
            fflush(stdout);
            exit(1);
        }
        window_toplevel = xdg_surface_get_toplevel(window_surface);
        if (!window_toplevel) {
            printf("Can not allocate xdg_toplevel for xdg_surface!\n");
            fflush(stdout);
            exit(1);
        }
        xdg_surface_add_listener(window_surface, &surface_listener, this);
        xdg_toplevel_add_listener(window_toplevel, &toplevel_listener, this);
        xdg_toplevel_set_title(window_toplevel, APP_SHORT_NAME);
        if (xdg_decoration_mgr) {
            // if supported, let the compositor render titlebars for us
            toplevel_decoration = zxdg_decoration_manager_v1_get_toplevel_decoration(xdg_decoration_mgr, window_toplevel);
            zxdg_toplevel_decoration_v1_set_mode(toplevel_decoration, ZXDG_TOPLEVEL_DECORATION_V1_MODE_SERVER_SIDE);
        }

        wl_surface_commit(window);

    }
    void VulkanApplication::run(){
        if( create_ &&
            sample_.Initialize( parameters ) ) {
            while(!quit){
                if( sample_.IsReady() ) {
                    sample_.UpdateTime();
                    sample_.Draw();
                    sample_.MouseReset();
                    wl_display_dispatch_pending(display);
                }
            }

        }
    }

    void VulkanApplication::init_vk()
    {

        parameters.display = display;
        parameters.surface = window;
        create_ = true;
    }


} // namespace VulkanCookbook