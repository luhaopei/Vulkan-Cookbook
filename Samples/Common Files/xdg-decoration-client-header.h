/* Generated by wayland-scanner 1.22.90 */

#ifndef XDG_DECORATION_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define XDG_DECORATION_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_xdg_decoration_unstable_v1 The xdg_decoration_unstable_v1 protocol
 * @section page_ifaces_xdg_decoration_unstable_v1 Interfaces
 * - @subpage page_iface_zxdg_decoration_manager_v1 - window decoration manager
 * - @subpage page_iface_zxdg_toplevel_decoration_v1 - decoration object for a toplevel surface
 * @section page_copyright_xdg_decoration_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2018 Simon Ser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct xdg_toplevel;
struct zxdg_decoration_manager_v1;
struct zxdg_toplevel_decoration_v1;

#ifndef ZXDG_DECORATION_MANAGER_V1_INTERFACE
#define ZXDG_DECORATION_MANAGER_V1_INTERFACE
/**
 * @page page_iface_zxdg_decoration_manager_v1 zxdg_decoration_manager_v1
 * @section page_iface_zxdg_decoration_manager_v1_desc Description
 *
 * This interface allows a compositor to announce support for server-side
 * decorations.
 *
 * A window decoration is a set of window controls as deemed appropriate by
 * the party managing them, such as user interface components used to move,
 * resize and change a window's state.
 *
 * A client can use this protocol to request being decorated by a supporting
 * compositor.
 *
 * If compositor and client do not negotiate the use of a server-side
 * decoration using this protocol, clients continue to self-decorate as they
 * see fit.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding interface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and interface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 * @section page_iface_zxdg_decoration_manager_v1_api API
 * See @ref iface_zxdg_decoration_manager_v1.
 */
/**
 * @defgroup iface_zxdg_decoration_manager_v1 The zxdg_decoration_manager_v1 interface
 *
 * This interface allows a compositor to announce support for server-side
 * decorations.
 *
 * A window decoration is a set of window controls as deemed appropriate by
 * the party managing them, such as user interface components used to move,
 * resize and change a window's state.
 *
 * A client can use this protocol to request being decorated by a supporting
 * compositor.
 *
 * If compositor and client do not negotiate the use of a server-side
 * decoration using this protocol, clients continue to self-decorate as they
 * see fit.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding interface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and interface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 */
extern const struct wl_interface zxdg_decoration_manager_v1_interface;
#endif
#ifndef ZXDG_TOPLEVEL_DECORATION_V1_INTERFACE
#define ZXDG_TOPLEVEL_DECORATION_V1_INTERFACE
/**
 * @page page_iface_zxdg_toplevel_decoration_v1 zxdg_toplevel_decoration_v1
 * @section page_iface_zxdg_toplevel_decoration_v1_desc Description
 *
 * The decoration object allows the compositor to toggle server-side window
 * decorations for a toplevel surface. The client can request to switch to
 * another mode.
 *
 * The xdg_toplevel_decoration object must be destroyed before its
 * xdg_toplevel.
 * @section page_iface_zxdg_toplevel_decoration_v1_api API
 * See @ref iface_zxdg_toplevel_decoration_v1.
 */
/**
 * @defgroup iface_zxdg_toplevel_decoration_v1 The zxdg_toplevel_decoration_v1 interface
 *
 * The decoration object allows the compositor to toggle server-side window
 * decorations for a toplevel surface. The client can request to switch to
 * another mode.
 *
 * The xdg_toplevel_decoration object must be destroyed before its
 * xdg_toplevel.
 */
extern const struct wl_interface zxdg_toplevel_decoration_v1_interface;
#endif

#define ZXDG_DECORATION_MANAGER_V1_DESTROY 0
#define ZXDG_DECORATION_MANAGER_V1_GET_TOPLEVEL_DECORATION 1


/**
 * @ingroup iface_zxdg_decoration_manager_v1
 */
#define ZXDG_DECORATION_MANAGER_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zxdg_decoration_manager_v1
 */
#define ZXDG_DECORATION_MANAGER_V1_GET_TOPLEVEL_DECORATION_SINCE_VERSION 1

/** @ingroup iface_zxdg_decoration_manager_v1 */
static inline void
zxdg_decoration_manager_v1_set_user_data(struct zxdg_decoration_manager_v1 *zxdg_decoration_manager_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zxdg_decoration_manager_v1, user_data);
}

/** @ingroup iface_zxdg_decoration_manager_v1 */
static inline void *
zxdg_decoration_manager_v1_get_user_data(struct zxdg_decoration_manager_v1 *zxdg_decoration_manager_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zxdg_decoration_manager_v1);
}

static inline uint32_t
zxdg_decoration_manager_v1_get_version(struct zxdg_decoration_manager_v1 *zxdg_decoration_manager_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zxdg_decoration_manager_v1);
}

/**
 * @ingroup iface_zxdg_decoration_manager_v1
 *
 * Destroy the decoration manager. This doesn't destroy objects created
 * with the manager.
 */
static inline void
zxdg_decoration_manager_v1_destroy(struct zxdg_decoration_manager_v1 *zxdg_decoration_manager_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zxdg_decoration_manager_v1,
			 ZXDG_DECORATION_MANAGER_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zxdg_decoration_manager_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zxdg_decoration_manager_v1
 *
 * Create a new decoration object associated with the given toplevel.
 *
 * Creating an xdg_toplevel_decoration from an xdg_toplevel which has a
 * buffer attached or committed is a client error, and any attempts by a
 * client to attach or manipulate a buffer prior to the first
 * xdg_toplevel_decoration.configure event must also be treated as
 * errors.
 */
static inline struct zxdg_toplevel_decoration_v1 *
zxdg_decoration_manager_v1_get_toplevel_decoration(struct zxdg_decoration_manager_v1 *zxdg_decoration_manager_v1, struct xdg_toplevel *toplevel)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_flags((struct wl_proxy *) zxdg_decoration_manager_v1,
			 ZXDG_DECORATION_MANAGER_V1_GET_TOPLEVEL_DECORATION, &zxdg_toplevel_decoration_v1_interface, wl_proxy_get_version((struct wl_proxy *) zxdg_decoration_manager_v1), 0, NULL, toplevel);

	return (struct zxdg_toplevel_decoration_v1 *) id;
}

#ifndef ZXDG_TOPLEVEL_DECORATION_V1_ERROR_ENUM
#define ZXDG_TOPLEVEL_DECORATION_V1_ERROR_ENUM
enum zxdg_toplevel_decoration_v1_error {
	/**
	 * xdg_toplevel has a buffer attached before configure
	 */
	ZXDG_TOPLEVEL_DECORATION_V1_ERROR_UNCONFIGURED_BUFFER = 0,
	/**
	 * xdg_toplevel already has a decoration object
	 */
	ZXDG_TOPLEVEL_DECORATION_V1_ERROR_ALREADY_CONSTRUCTED = 1,
	/**
	 * xdg_toplevel destroyed before the decoration object
	 */
	ZXDG_TOPLEVEL_DECORATION_V1_ERROR_ORPHANED = 2,
};
#endif /* ZXDG_TOPLEVEL_DECORATION_V1_ERROR_ENUM */

#ifndef ZXDG_TOPLEVEL_DECORATION_V1_MODE_ENUM
#define ZXDG_TOPLEVEL_DECORATION_V1_MODE_ENUM
/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 * window decoration modes
 *
 * These values describe window decoration modes.
 */
enum zxdg_toplevel_decoration_v1_mode {
	/**
	 * no server-side window decoration
	 */
	ZXDG_TOPLEVEL_DECORATION_V1_MODE_CLIENT_SIDE = 1,
	/**
	 * server-side window decoration
	 */
	ZXDG_TOPLEVEL_DECORATION_V1_MODE_SERVER_SIDE = 2,
};
#endif /* ZXDG_TOPLEVEL_DECORATION_V1_MODE_ENUM */

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 * @struct zxdg_toplevel_decoration_v1_listener
 */
struct zxdg_toplevel_decoration_v1_listener {
	/**
	 * suggest a surface change
	 *
	 * The configure event asks the client to change its decoration
	 * mode. The configured state should not be applied immediately.
	 * Clients must send an ack_configure in response to this event.
	 * See xdg_surface.configure and xdg_surface.ack_configure for
	 * details.
	 *
	 * A configure event can be sent at any time. The specified mode
	 * must be obeyed by the client.
	 * @param mode the decoration mode
	 */
	void (*configure)(void *data,
			  struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1,
			  uint32_t mode);
};

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 */
static inline int
zxdg_toplevel_decoration_v1_add_listener(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1,
					 const struct zxdg_toplevel_decoration_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zxdg_toplevel_decoration_v1,
				     (void (**)(void)) listener, data);
}

#define ZXDG_TOPLEVEL_DECORATION_V1_DESTROY 0
#define ZXDG_TOPLEVEL_DECORATION_V1_SET_MODE 1
#define ZXDG_TOPLEVEL_DECORATION_V1_UNSET_MODE 2

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 */
#define ZXDG_TOPLEVEL_DECORATION_V1_CONFIGURE_SINCE_VERSION 1

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 */
#define ZXDG_TOPLEVEL_DECORATION_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 */
#define ZXDG_TOPLEVEL_DECORATION_V1_SET_MODE_SINCE_VERSION 1
/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 */
#define ZXDG_TOPLEVEL_DECORATION_V1_UNSET_MODE_SINCE_VERSION 1

/** @ingroup iface_zxdg_toplevel_decoration_v1 */
static inline void
zxdg_toplevel_decoration_v1_set_user_data(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zxdg_toplevel_decoration_v1, user_data);
}

/** @ingroup iface_zxdg_toplevel_decoration_v1 */
static inline void *
zxdg_toplevel_decoration_v1_get_user_data(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zxdg_toplevel_decoration_v1);
}

static inline uint32_t
zxdg_toplevel_decoration_v1_get_version(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zxdg_toplevel_decoration_v1);
}

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 *
 * Switch back to a mode without any server-side decorations at the next
 * commit.
 */
static inline void
zxdg_toplevel_decoration_v1_destroy(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zxdg_toplevel_decoration_v1,
			 ZXDG_TOPLEVEL_DECORATION_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zxdg_toplevel_decoration_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 *
 * Set the toplevel surface decoration mode. This informs the compositor
 * that the client prefers the provided decoration mode.
 *
 * After requesting a decoration mode, the compositor will respond by
 * emitting an xdg_surface.configure event. The client should then update
 * its content, drawing it without decorations if the received mode is
 * server-side decorations. The client must also acknowledge the configure
 * when committing the new content (see xdg_surface.ack_configure).
 *
 * The compositor can decide not to use the client's mode and enforce a
 * different mode instead.
 *
 * Clients whose decoration mode depend on the xdg_toplevel state may send
 * a set_mode request in response to an xdg_surface.configure event and wait
 * for the next xdg_surface.configure event to prevent unwanted state.
 * Such clients are responsible for preventing configure loops and must
 * make sure not to send multiple successive set_mode requests with the
 * same decoration mode.
 */
static inline void
zxdg_toplevel_decoration_v1_set_mode(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1, uint32_t mode)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zxdg_toplevel_decoration_v1,
			 ZXDG_TOPLEVEL_DECORATION_V1_SET_MODE, NULL, wl_proxy_get_version((struct wl_proxy *) zxdg_toplevel_decoration_v1), 0, mode);
}

/**
 * @ingroup iface_zxdg_toplevel_decoration_v1
 *
 * Unset the toplevel surface decoration mode. This informs the compositor
 * that the client doesn't prefer a particular decoration mode.
 *
 * This request has the same semantics as set_mode.
 */
static inline void
zxdg_toplevel_decoration_v1_unset_mode(struct zxdg_toplevel_decoration_v1 *zxdg_toplevel_decoration_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zxdg_toplevel_decoration_v1,
			 ZXDG_TOPLEVEL_DECORATION_V1_UNSET_MODE, NULL, wl_proxy_get_version((struct wl_proxy *) zxdg_toplevel_decoration_v1), 0);
}

#ifdef  __cplusplus
}
#endif

#endif
