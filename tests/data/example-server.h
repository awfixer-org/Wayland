/* SCANNER TEST */

#ifndef WAYLAND_SERVER_PROTOCOL_H
#define WAYLAND_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_wayland The wayland protocol
 * @section page_ifaces_wayland Interfaces
 * - @subpage page_iface_wl_display - core global object
 * - @subpage page_iface_wl_registry - global registry object
 * - @subpage page_iface_wl_callback - callback object
 * - @subpage page_iface_wl_compositor - the compositor singleton
 * - @subpage page_iface_wl_shm_pool - a shared memory pool
 * - @subpage page_iface_wl_shm - shared memory support
 * - @subpage page_iface_wl_buffer - content for a wl_surface
 * - @subpage page_iface_wl_data_offer - offer to transfer data
 * - @subpage page_iface_wl_data_source - offer to transfer data
 * - @subpage page_iface_wl_data_device - data transfer device
 * - @subpage page_iface_wl_data_device_manager - data transfer interface
 * - @subpage page_iface_wl_shell - create desktop-style surfaces
 * - @subpage page_iface_wl_shell_surface - desktop-style metadata interface
 * - @subpage page_iface_wl_surface - an onscreen surface
 * - @subpage page_iface_wl_seat - group of input devices
 * - @subpage page_iface_wl_pointer - pointer input device
 * - @subpage page_iface_wl_keyboard - keyboard input device
 * - @subpage page_iface_wl_touch - touchscreen input device
 * - @subpage page_iface_wl_output - compositor output region
 * - @subpage page_iface_wl_region - region interface
 * - @subpage page_iface_wl_subcompositor - sub-surface compositing
 * - @subpage page_iface_wl_subsurface - sub-surface interface to a wl_surface
 * @section page_copyright_wayland Copyright
 * <pre>
 *
 * Copyright © 2008-2011 Kristian Høgsberg
 * Copyright © 2010-2011 Intel Corporation
 * Copyright © 2012-2013 Collabora, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * </pre>
 */
struct wl_buffer;
struct wl_callback;
struct wl_compositor;
struct wl_data_device;
struct wl_data_device_manager;
struct wl_data_offer;
struct wl_data_source;
struct wl_display;
struct wl_keyboard;
struct wl_output;
struct wl_pointer;
struct wl_region;
struct wl_registry;
struct wl_seat;
struct wl_shell;
struct wl_shell_surface;
struct wl_shm;
struct wl_shm_pool;
struct wl_subcompositor;
struct wl_subsurface;
struct wl_surface;
struct wl_touch;

#ifndef WL_DISPLAY_INTERFACE
#define WL_DISPLAY_INTERFACE
/**
 * @page page_iface_wl_display wl_display
 * @section page_iface_wl_display_desc Description
 *
 * The core global object.  This is a special singleton object.  It
 * is used for internal Wayland protocol features.
 * @section page_iface_wl_display_api API
 * See @ref iface_wl_display.
 */
/**
 * @defgroup iface_wl_display The wl_display interface
 *
 * The core global object.  This is a special singleton object.  It
 * is used for internal Wayland protocol features.
 */
extern const struct wl_interface wl_display_interface;
#endif
#ifndef WL_REGISTRY_INTERFACE
#define WL_REGISTRY_INTERFACE
/**
 * @page page_iface_wl_registry wl_registry
 * @section page_iface_wl_registry_desc Description
 *
 * The singleton global registry object.  The server has a number of
 * global objects that are available to all clients.  These objects
 * typically represent an actual object in the server (for example,
 * an input device) or they are singleton objects that provide
 * extension functionality.
 *
 * When a client creates a registry object, the registry object
 * will emit a global event for each global currently in the
 * registry.  Globals come and go as a result of device or
 * monitor hotplugs, reconfiguration or other events, and the
 * registry will send out global and global_remove events to
 * keep the client up to date with the changes.  To mark the end
 * of the initial burst of events, the client can use the
 * wl_display.sync request immediately after calling
 * wl_display.get_registry.
 *
 * A client can bind to a global object by using the bind
 * request.  This creates a client-side handle that lets the object
 * emit events to the client and lets the client invoke requests on
 * the object.
 * @section page_iface_wl_registry_api API
 * See @ref iface_wl_registry.
 */
/**
 * @defgroup iface_wl_registry The wl_registry interface
 *
 * The singleton global registry object.  The server has a number of
 * global objects that are available to all clients.  These objects
 * typically represent an actual object in the server (for example,
 * an input device) or they are singleton objects that provide
 * extension functionality.
 *
 * When a client creates a registry object, the registry object
 * will emit a global event for each global currently in the
 * registry.  Globals come and go as a result of device or
 * monitor hotplugs, reconfiguration or other events, and the
 * registry will send out global and global_remove events to
 * keep the client up to date with the changes.  To mark the end
 * of the initial burst of events, the client can use the
 * wl_display.sync request immediately after calling
 * wl_display.get_registry.
 *
 * A client can bind to a global object by using the bind
 * request.  This creates a client-side handle that lets the object
 * emit events to the client and lets the client invoke requests on
 * the object.
 */
extern const struct wl_interface wl_registry_interface;
#endif
#ifndef WL_CALLBACK_INTERFACE
#define WL_CALLBACK_INTERFACE
/**
 * @page page_iface_wl_callback wl_callback
 * @section page_iface_wl_callback_desc Description
 *
 * Clients can handle the 'done' event to get notified when
 * the related request is done.
 * @section page_iface_wl_callback_api API
 * See @ref iface_wl_callback.
 */
/**
 * @defgroup iface_wl_callback The wl_callback interface
 *
 * Clients can handle the 'done' event to get notified when
 * the related request is done.
 */
extern const struct wl_interface wl_callback_interface;
#endif
#ifndef WL_COMPOSITOR_INTERFACE
#define WL_COMPOSITOR_INTERFACE
/**
 * @page page_iface_wl_compositor wl_compositor
 * @section page_iface_wl_compositor_desc Description
 *
 * A compositor.  This object is a singleton global.  The
 * compositor is in charge of combining the contents of multiple
 * surfaces into one displayable output.
 * @section page_iface_wl_compositor_api API
 * See @ref iface_wl_compositor.
 */
/**
 * @defgroup iface_wl_compositor The wl_compositor interface
 *
 * A compositor.  This object is a singleton global.  The
 * compositor is in charge of combining the contents of multiple
 * surfaces into one displayable output.
 */
extern const struct wl_interface wl_compositor_interface;
#endif
#ifndef WL_SHM_POOL_INTERFACE
#define WL_SHM_POOL_INTERFACE
/**
 * @page page_iface_wl_shm_pool wl_shm_pool
 * @section page_iface_wl_shm_pool_desc Description
 *
 * The wl_shm_pool object encapsulates a piece of memory shared
 * between the compositor and client.  Through the wl_shm_pool
 * object, the client can allocate shared memory wl_buffer objects.
 * All objects created through the same pool share the same
 * underlying mapped memory. Reusing the mapped memory avoids the
 * setup/teardown overhead and is useful when interactively resizing
 * a surface or for many small buffers.
 * @section page_iface_wl_shm_pool_api API
 * See @ref iface_wl_shm_pool.
 */
/**
 * @defgroup iface_wl_shm_pool The wl_shm_pool interface
 *
 * The wl_shm_pool object encapsulates a piece of memory shared
 * between the compositor and client.  Through the wl_shm_pool
 * object, the client can allocate shared memory wl_buffer objects.
 * All objects created through the same pool share the same
 * underlying mapped memory. Reusing the mapped memory avoids the
 * setup/teardown overhead and is useful when interactively resizing
 * a surface or for many small buffers.
 */
extern const struct wl_interface wl_shm_pool_interface;
#endif
#ifndef WL_SHM_INTERFACE
#define WL_SHM_INTERFACE
/**
 * @page page_iface_wl_shm wl_shm
 * @section page_iface_wl_shm_desc Description
 *
 * A singleton global object that provides support for shared
 * memory.
 *
 * Clients can create wl_shm_pool objects using the create_pool
 * request.
 *
 * At connection setup time, the wl_shm object emits one or more
 * format events to inform clients about the valid pixel formats
 * that can be used for buffers.
 * @section page_iface_wl_shm_api API
 * See @ref iface_wl_shm.
 */
/**
 * @defgroup iface_wl_shm The wl_shm interface
 *
 * A singleton global object that provides support for shared
 * memory.
 *
 * Clients can create wl_shm_pool objects using the create_pool
 * request.
 *
 * At connection setup time, the wl_shm object emits one or more
 * format events to inform clients about the valid pixel formats
 * that can be used for buffers.
 */
extern const struct wl_interface wl_shm_interface;
#endif
#ifndef WL_BUFFER_INTERFACE
#define WL_BUFFER_INTERFACE
/**
 * @page page_iface_wl_buffer wl_buffer
 * @section page_iface_wl_buffer_desc Description
 *
 * A buffer provides the content for a wl_surface. Buffers are
 * created through factory interfaces such as wl_drm, wl_shm or
 * similar. It has a width and a height and can be attached to a
 * wl_surface, but the mechanism by which a client provides and
 * updates the contents is defined by the buffer factory interface.
 * @section page_iface_wl_buffer_api API
 * See @ref iface_wl_buffer.
 */
/**
 * @defgroup iface_wl_buffer The wl_buffer interface
 *
 * A buffer provides the content for a wl_surface. Buffers are
 * created through factory interfaces such as wl_drm, wl_shm or
 * similar. It has a width and a height and can be attached to a
 * wl_surface, but the mechanism by which a client provides and
 * updates the contents is defined by the buffer factory interface.
 */
extern const struct wl_interface wl_buffer_interface;
#endif
#ifndef WL_DATA_OFFER_INTERFACE
#define WL_DATA_OFFER_INTERFACE
/**
 * @page page_iface_wl_data_offer wl_data_offer
 * @section page_iface_wl_data_offer_desc Description
 *
 * A wl_data_offer represents a piece of data offered for transfer
 * by another client (the source client).  It is used by the
 * copy-and-paste and drag-and-drop mechanisms.  The offer
 * describes the different mime types that the data can be
 * converted to and provides the mechanism for transferring the
 * data directly from the source client.
 * @section page_iface_wl_data_offer_api API
 * See @ref iface_wl_data_offer.
 */
/**
 * @defgroup iface_wl_data_offer The wl_data_offer interface
 *
 * A wl_data_offer represents a piece of data offered for transfer
 * by another client (the source client).  It is used by the
 * copy-and-paste and drag-and-drop mechanisms.  The offer
 * describes the different mime types that the data can be
 * converted to and provides the mechanism for transferring the
 * data directly from the source client.
 */
extern const struct wl_interface wl_data_offer_interface;
#endif
#ifndef WL_DATA_SOURCE_INTERFACE
#define WL_DATA_SOURCE_INTERFACE
/**
 * @page page_iface_wl_data_source wl_data_source
 * @section page_iface_wl_data_source_desc Description
 *
 * The wl_data_source object is the source side of a wl_data_offer.
 * It is created by the source client in a data transfer and
 * provides a way to describe the offered data and a way to respond
 * to requests to transfer the data.
 * @section page_iface_wl_data_source_api API
 * See @ref iface_wl_data_source.
 */
/**
 * @defgroup iface_wl_data_source The wl_data_source interface
 *
 * The wl_data_source object is the source side of a wl_data_offer.
 * It is created by the source client in a data transfer and
 * provides a way to describe the offered data and a way to respond
 * to requests to transfer the data.
 */
extern const struct wl_interface wl_data_source_interface;
#endif
#ifndef WL_DATA_DEVICE_INTERFACE
#define WL_DATA_DEVICE_INTERFACE
/**
 * @page page_iface_wl_data_device wl_data_device
 * @section page_iface_wl_data_device_desc Description
 *
 * There is one wl_data_device per seat which can be obtained
 * from the global wl_data_device_manager singleton.
 *
 * A wl_data_device provides access to inter-client data transfer
 * mechanisms such as copy-and-paste and drag-and-drop.
 * @section page_iface_wl_data_device_api API
 * See @ref iface_wl_data_device.
 */
/**
 * @defgroup iface_wl_data_device The wl_data_device interface
 *
 * There is one wl_data_device per seat which can be obtained
 * from the global wl_data_device_manager singleton.
 *
 * A wl_data_device provides access to inter-client data transfer
 * mechanisms such as copy-and-paste and drag-and-drop.
 */
extern const struct wl_interface wl_data_device_interface;
#endif
#ifndef WL_DATA_DEVICE_MANAGER_INTERFACE
#define WL_DATA_DEVICE_MANAGER_INTERFACE
/**
 * @page page_iface_wl_data_device_manager wl_data_device_manager
 * @section page_iface_wl_data_device_manager_desc Description
 *
 * The wl_data_device_manager is a singleton global object that
 * provides access to inter-client data transfer mechanisms such as
 * copy-and-paste and drag-and-drop.  These mechanisms are tied to
 * a wl_seat and this interface lets a client get a wl_data_device
 * corresponding to a wl_seat.
 *
 * Depending on the version bound, the objects created from the bound
 * wl_data_device_manager object will have different requirements for
 * functioning properly. See wl_data_source.set_actions,
 * wl_data_offer.accept and wl_data_offer.finish for details.
 * @section page_iface_wl_data_device_manager_api API
 * See @ref iface_wl_data_device_manager.
 */
/**
 * @defgroup iface_wl_data_device_manager The wl_data_device_manager interface
 *
 * The wl_data_device_manager is a singleton global object that
 * provides access to inter-client data transfer mechanisms such as
 * copy-and-paste and drag-and-drop.  These mechanisms are tied to
 * a wl_seat and this interface lets a client get a wl_data_device
 * corresponding to a wl_seat.
 *
 * Depending on the version bound, the objects created from the bound
 * wl_data_device_manager object will have different requirements for
 * functioning properly. See wl_data_source.set_actions,
 * wl_data_offer.accept and wl_data_offer.finish for details.
 */
extern const struct wl_interface wl_data_device_manager_interface;
#endif
#ifndef WL_SHELL_INTERFACE
#define WL_SHELL_INTERFACE
/**
 * @page page_iface_wl_shell wl_shell
 * @section page_iface_wl_shell_desc Description
 *
 * This interface is implemented by servers that provide
 * desktop-style user interfaces.
 *
 * It allows clients to associate a wl_shell_surface with
 * a basic surface.
 * @section page_iface_wl_shell_api API
 * See @ref iface_wl_shell.
 */
/**
 * @defgroup iface_wl_shell The wl_shell interface
 *
 * This interface is implemented by servers that provide
 * desktop-style user interfaces.
 *
 * It allows clients to associate a wl_shell_surface with
 * a basic surface.
 */
extern const struct wl_interface wl_shell_interface;
#endif
#ifndef WL_SHELL_SURFACE_INTERFACE
#define WL_SHELL_SURFACE_INTERFACE
/**
 * @page page_iface_wl_shell_surface wl_shell_surface
 * @section page_iface_wl_shell_surface_desc Description
 *
 * An interface that may be implemented by a wl_surface, for
 * implementations that provide a desktop-style user interface.
 *
 * It provides requests to treat surfaces like toplevel, fullscreen
 * or popup windows, move, resize or maximize them, associate
 * metadata like title and class, etc.
 *
 * On the server side the object is automatically destroyed when
 * the related wl_surface is destroyed. On the client side,
 * wl_shell_surface_destroy() must be called before destroying
 * the wl_surface object.
 * @section page_iface_wl_shell_surface_api API
 * See @ref iface_wl_shell_surface.
 */
/**
 * @defgroup iface_wl_shell_surface The wl_shell_surface interface
 *
 * An interface that may be implemented by a wl_surface, for
 * implementations that provide a desktop-style user interface.
 *
 * It provides requests to treat surfaces like toplevel, fullscreen
 * or popup windows, move, resize or maximize them, associate
 * metadata like title and class, etc.
 *
 * On the server side the object is automatically destroyed when
 * the related wl_surface is destroyed. On the client side,
 * wl_shell_surface_destroy() must be called before destroying
 * the wl_surface object.
 */
extern const struct wl_interface wl_shell_surface_interface;
#endif
#ifndef WL_SURFACE_INTERFACE
#define WL_SURFACE_INTERFACE
/**
 * @page page_iface_wl_surface wl_surface
 * @section page_iface_wl_surface_desc Description
 *
 * A surface is a rectangular area that is displayed on the screen.
 * It has a location, size and pixel contents.
 *
 * The size of a surface (and relative positions on it) is described
 * in surface-local coordinates, which may differ from the buffer
 * coordinates of the pixel content, in case a buffer_transform
 * or a buffer_scale is used.
 *
 * A surface without a "role" is fairly useless: a compositor does
 * not know where, when or how to present it. The role is the
 * purpose of a wl_surface. Examples of roles are a cursor for a
 * pointer (as set by wl_pointer.set_cursor), a drag icon
 * (wl_data_device.start_drag), a sub-surface
 * (wl_subcompositor.get_subsurface), and a window as defined by a
 * shell protocol (e.g. wl_shell.get_shell_surface).
 *
 * A surface can have only one role at a time. Initially a
 * wl_surface does not have a role. Once a wl_surface is given a
 * role, it is set permanently for the whole lifetime of the
 * wl_surface object. Giving the current role again is allowed,
 * unless explicitly forbidden by the relevant interface
 * specification.
 *
 * Surface roles are given by requests in other interfaces such as
 * wl_pointer.set_cursor. The request should explicitly mention
 * that this request gives a role to a wl_surface. Often, this
 * request also creates a new protocol object that represents the
 * role and adds additional functionality to wl_surface. When a
 * client wants to destroy a wl_surface, they must destroy this 'role
 * object' before the wl_surface.
 *
 * Destroying the role object does not remove the role from the
 * wl_surface, but it may stop the wl_surface from "playing the role".
 * For instance, if a wl_subsurface object is destroyed, the wl_surface
 * it was created for will be unmapped and forget its position and
 * z-order. It is allowed to create a wl_subsurface for the same
 * wl_surface again, but it is not allowed to use the wl_surface as
 * a cursor (cursor is a different role than sub-surface, and role
 * switching is not allowed).
 * @section page_iface_wl_surface_api API
 * See @ref iface_wl_surface.
 */
/**
 * @defgroup iface_wl_surface The wl_surface interface
 *
 * A surface is a rectangular area that is displayed on the screen.
 * It has a location, size and pixel contents.
 *
 * The size of a surface (and relative positions on it) is described
 * in surface-local coordinates, which may differ from the buffer
 * coordinates of the pixel content, in case a buffer_transform
 * or a buffer_scale is used.
 *
 * A surface without a "role" is fairly useless: a compositor does
 * not know where, when or how to present it. The role is the
 * purpose of a wl_surface. Examples of roles are a cursor for a
 * pointer (as set by wl_pointer.set_cursor), a drag icon
 * (wl_data_device.start_drag), a sub-surface
 * (wl_subcompositor.get_subsurface), and a window as defined by a
 * shell protocol (e.g. wl_shell.get_shell_surface).
 *
 * A surface can have only one role at a time. Initially a
 * wl_surface does not have a role. Once a wl_surface is given a
 * role, it is set permanently for the whole lifetime of the
 * wl_surface object. Giving the current role again is allowed,
 * unless explicitly forbidden by the relevant interface
 * specification.
 *
 * Surface roles are given by requests in other interfaces such as
 * wl_pointer.set_cursor. The request should explicitly mention
 * that this request gives a role to a wl_surface. Often, this
 * request also creates a new protocol object that represents the
 * role and adds additional functionality to wl_surface. When a
 * client wants to destroy a wl_surface, they must destroy this 'role
 * object' before the wl_surface.
 *
 * Destroying the role object does not remove the role from the
 * wl_surface, but it may stop the wl_surface from "playing the role".
 * For instance, if a wl_subsurface object is destroyed, the wl_surface
 * it was created for will be unmapped and forget its position and
 * z-order. It is allowed to create a wl_subsurface for the same
 * wl_surface again, but it is not allowed to use the wl_surface as
 * a cursor (cursor is a different role than sub-surface, and role
 * switching is not allowed).
 */
extern const struct wl_interface wl_surface_interface;
#endif
#ifndef WL_SEAT_INTERFACE
#define WL_SEAT_INTERFACE
/**
 * @page page_iface_wl_seat wl_seat
 * @section page_iface_wl_seat_desc Description
 *
 * A seat is a group of keyboards, pointer and touch devices. This
 * object is published as a global during start up, or when such a
 * device is hot plugged.  A seat typically has a pointer and
 * maintains a keyboard focus and a pointer focus.
 * @section page_iface_wl_seat_api API
 * See @ref iface_wl_seat.
 */
/**
 * @defgroup iface_wl_seat The wl_seat interface
 *
 * A seat is a group of keyboards, pointer and touch devices. This
 * object is published as a global during start up, or when such a
 * device is hot plugged.  A seat typically has a pointer and
 * maintains a keyboard focus and a pointer focus.
 */
extern const struct wl_interface wl_seat_interface;
#endif
#ifndef WL_POINTER_INTERFACE
#define WL_POINTER_INTERFACE
/**
 * @page page_iface_wl_pointer wl_pointer
 * @section page_iface_wl_pointer_desc Description
 *
 * The wl_pointer interface represents one or more input devices,
 * such as mice, which control the pointer location and pointer_focus
 * of a seat.
 *
 * The wl_pointer interface generates motion, enter and leave
 * events for the surfaces that the pointer is located over,
 * and button and axis events for button presses, button releases
 * and scrolling.
 * @section page_iface_wl_pointer_api API
 * See @ref iface_wl_pointer.
 */
/**
 * @defgroup iface_wl_pointer The wl_pointer interface
 *
 * The wl_pointer interface represents one or more input devices,
 * such as mice, which control the pointer location and pointer_focus
 * of a seat.
 *
 * The wl_pointer interface generates motion, enter and leave
 * events for the surfaces that the pointer is located over,
 * and button and axis events for button presses, button releases
 * and scrolling.
 */
extern const struct wl_interface wl_pointer_interface;
#endif
#ifndef WL_KEYBOARD_INTERFACE
#define WL_KEYBOARD_INTERFACE
/**
 * @page page_iface_wl_keyboard wl_keyboard
 * @section page_iface_wl_keyboard_desc Description
 *
 * The wl_keyboard interface represents one or more keyboards
 * associated with a seat.
 * @section page_iface_wl_keyboard_api API
 * See @ref iface_wl_keyboard.
 */
/**
 * @defgroup iface_wl_keyboard The wl_keyboard interface
 *
 * The wl_keyboard interface represents one or more keyboards
 * associated with a seat.
 */
extern const struct wl_interface wl_keyboard_interface;
#endif
#ifndef WL_TOUCH_INTERFACE
#define WL_TOUCH_INTERFACE
/**
 * @page page_iface_wl_touch wl_touch
 * @section page_iface_wl_touch_desc Description
 *
 * The wl_touch interface represents a touchscreen
 * associated with a seat.
 *
 * Touch interactions can consist of one or more contacts.
 * For each contact, a series of events is generated, starting
 * with a down event, followed by zero or more motion events,
 * and ending with an up event. Events relating to the same
 * contact point can be identified by the ID of the sequence.
 * @section page_iface_wl_touch_api API
 * See @ref iface_wl_touch.
 */
/**
 * @defgroup iface_wl_touch The wl_touch interface
 *
 * The wl_touch interface represents a touchscreen
 * associated with a seat.
 *
 * Touch interactions can consist of one or more contacts.
 * For each contact, a series of events is generated, starting
 * with a down event, followed by zero or more motion events,
 * and ending with an up event. Events relating to the same
 * contact point can be identified by the ID of the sequence.
 */
extern const struct wl_interface wl_touch_interface;
#endif
#ifndef WL_OUTPUT_INTERFACE
#define WL_OUTPUT_INTERFACE
/**
 * @page page_iface_wl_output wl_output
 * @section page_iface_wl_output_desc Description
 *
 * An output describes part of the compositor geometry.  The
 * compositor works in the 'compositor coordinate system' and an
 * output corresponds to a rectangular area in that space that is
 * actually visible.  This typically corresponds to a monitor that
 * displays part of the compositor space.  This object is published
 * as global during start up, or when a monitor is hotplugged.
 * @section page_iface_wl_output_api API
 * See @ref iface_wl_output.
 */
/**
 * @defgroup iface_wl_output The wl_output interface
 *
 * An output describes part of the compositor geometry.  The
 * compositor works in the 'compositor coordinate system' and an
 * output corresponds to a rectangular area in that space that is
 * actually visible.  This typically corresponds to a monitor that
 * displays part of the compositor space.  This object is published
 * as global during start up, or when a monitor is hotplugged.
 */
extern const struct wl_interface wl_output_interface;
#endif
#ifndef WL_REGION_INTERFACE
#define WL_REGION_INTERFACE
/**
 * @page page_iface_wl_region wl_region
 * @section page_iface_wl_region_desc Description
 *
 * A region object describes an area.
 *
 * Region objects are used to describe the opaque and input
 * regions of a surface.
 * @section page_iface_wl_region_api API
 * See @ref iface_wl_region.
 */
/**
 * @defgroup iface_wl_region The wl_region interface
 *
 * A region object describes an area.
 *
 * Region objects are used to describe the opaque and input
 * regions of a surface.
 */
extern const struct wl_interface wl_region_interface;
#endif
#ifndef WL_SUBCOMPOSITOR_INTERFACE
#define WL_SUBCOMPOSITOR_INTERFACE
/**
 * @page page_iface_wl_subcompositor wl_subcompositor
 * @section page_iface_wl_subcompositor_desc Description
 *
 * The global interface exposing sub-surface compositing capabilities.
 * A wl_surface, that has sub-surfaces associated, is called the
 * parent surface. Sub-surfaces can be arbitrarily nested and create
 * a tree of sub-surfaces.
 *
 * The root surface in a tree of sub-surfaces is the main
 * surface. The main surface cannot be a sub-surface, because
 * sub-surfaces must always have a parent.
 *
 * A main surface with its sub-surfaces forms a (compound) window.
 * For window management purposes, this set of wl_surface objects is
 * to be considered as a single window, and it should also behave as
 * such.
 *
 * The aim of sub-surfaces is to offload some of the compositing work
 * within a window from clients to the compositor. A prime example is
 * a video player with decorations and video in separate wl_surface
 * objects. This should allow the compositor to pass YUV video buffer
 * processing to dedicated overlay hardware when possible.
 * @section page_iface_wl_subcompositor_api API
 * See @ref iface_wl_subcompositor.
 */
/**
 * @defgroup iface_wl_subcompositor The wl_subcompositor interface
 *
 * The global interface exposing sub-surface compositing capabilities.
 * A wl_surface, that has sub-surfaces associated, is called the
 * parent surface. Sub-surfaces can be arbitrarily nested and create
 * a tree of sub-surfaces.
 *
 * The root surface in a tree of sub-surfaces is the main
 * surface. The main surface cannot be a sub-surface, because
 * sub-surfaces must always have a parent.
 *
 * A main surface with its sub-surfaces forms a (compound) window.
 * For window management purposes, this set of wl_surface objects is
 * to be considered as a single window, and it should also behave as
 * such.
 *
 * The aim of sub-surfaces is to offload some of the compositing work
 * within a window from clients to the compositor. A prime example is
 * a video player with decorations and video in separate wl_surface
 * objects. This should allow the compositor to pass YUV video buffer
 * processing to dedicated overlay hardware when possible.
 */
extern const struct wl_interface wl_subcompositor_interface;
#endif
#ifndef WL_SUBSURFACE_INTERFACE
#define WL_SUBSURFACE_INTERFACE
/**
 * @page page_iface_wl_subsurface wl_subsurface
 * @section page_iface_wl_subsurface_desc Description
 *
 * An additional interface to a wl_surface object, which has been
 * made a sub-surface. A sub-surface has one parent surface. A
 * sub-surface's size and position are not limited to that of the parent.
 * Particularly, a sub-surface is not automatically clipped to its
 * parent's area.
 *
 * A sub-surface becomes mapped, when a non-NULL wl_buffer is applied
 * and the parent surface is mapped. The order of which one happens
 * first is irrelevant. A sub-surface is hidden if the parent becomes
 * hidden, or if a NULL wl_buffer is applied. These rules apply
 * recursively through the tree of surfaces.
 *
 * The behaviour of a wl_surface.commit request on a sub-surface
 * depends on the sub-surface's mode. The possible modes are
 * synchronized and desynchronized, see methods
 * wl_subsurface.set_sync and wl_subsurface.set_desync. Synchronized
 * mode caches the wl_surface state to be applied when the parent's
 * state gets applied, and desynchronized mode applies the pending
 * wl_surface state directly. A sub-surface is initially in the
 * synchronized mode.
 *
 * Sub-surfaces have also other kind of state, which is managed by
 * wl_subsurface requests, as opposed to wl_surface requests. This
 * state includes the sub-surface position relative to the parent
 * surface (wl_subsurface.set_position), and the stacking order of
 * the parent and its sub-surfaces (wl_subsurface.place_above and
 * .place_below). This state is applied when the parent surface's
 * wl_surface state is applied, regardless of the sub-surface's mode.
 * As the exception, set_sync and set_desync are effective immediately.
 *
 * The main surface can be thought to be always in desynchronized mode,
 * since it does not have a parent in the sub-surfaces sense.
 *
 * Even if a sub-surface is in desynchronized mode, it will behave as
 * in synchronized mode, if its parent surface behaves as in
 * synchronized mode. This rule is applied recursively throughout the
 * tree of surfaces. This means, that one can set a sub-surface into
 * synchronized mode, and then assume that all its child and grand-child
 * sub-surfaces are synchronized, too, without explicitly setting them.
 *
 * If the wl_surface associated with the wl_subsurface is destroyed, the
 * wl_subsurface object becomes inert. Note, that destroying either object
 * takes effect immediately. If you need to synchronize the removal
 * of a sub-surface to the parent surface update, unmap the sub-surface
 * first by attaching a NULL wl_buffer, update parent, and then destroy
 * the sub-surface.
 *
 * If the parent wl_surface object is destroyed, the sub-surface is
 * unmapped.
 * @section page_iface_wl_subsurface_api API
 * See @ref iface_wl_subsurface.
 */
/**
 * @defgroup iface_wl_subsurface The wl_subsurface interface
 *
 * An additional interface to a wl_surface object, which has been
 * made a sub-surface. A sub-surface has one parent surface. A
 * sub-surface's size and position are not limited to that of the parent.
 * Particularly, a sub-surface is not automatically clipped to its
 * parent's area.
 *
 * A sub-surface becomes mapped, when a non-NULL wl_buffer is applied
 * and the parent surface is mapped. The order of which one happens
 * first is irrelevant. A sub-surface is hidden if the parent becomes
 * hidden, or if a NULL wl_buffer is applied. These rules apply
 * recursively through the tree of surfaces.
 *
 * The behaviour of a wl_surface.commit request on a sub-surface
 * depends on the sub-surface's mode. The possible modes are
 * synchronized and desynchronized, see methods
 * wl_subsurface.set_sync and wl_subsurface.set_desync. Synchronized
 * mode caches the wl_surface state to be applied when the parent's
 * state gets applied, and desynchronized mode applies the pending
 * wl_surface state directly. A sub-surface is initially in the
 * synchronized mode.
 *
 * Sub-surfaces have also other kind of state, which is managed by
 * wl_subsurface requests, as opposed to wl_surface requests. This
 * state includes the sub-surface position relative to the parent
 * surface (wl_subsurface.set_position), and the stacking order of
 * the parent and its sub-surfaces (wl_subsurface.place_above and
 * .place_below). This state is applied when the parent surface's
 * wl_surface state is applied, regardless of the sub-surface's mode.
 * As the exception, set_sync and set_desync are effective immediately.
 *
 * The main surface can be thought to be always in desynchronized mode,
 * since it does not have a parent in the sub-surfaces sense.
 *
 * Even if a sub-surface is in desynchronized mode, it will behave as
 * in synchronized mode, if its parent surface behaves as in
 * synchronized mode. This rule is applied recursively throughout the
 * tree of surfaces. This means, that one can set a sub-surface into
 * synchronized mode, and then assume that all its child and grand-child
 * sub-surfaces are synchronized, too, without explicitly setting them.
 *
 * If the wl_surface associated with the wl_subsurface is destroyed, the
 * wl_subsurface object becomes inert. Note, that destroying either object
 * takes effect immediately. If you need to synchronize the removal
 * of a sub-surface to the parent surface update, unmap the sub-surface
 * first by attaching a NULL wl_buffer, update parent, and then destroy
 * the sub-surface.
 *
 * If the parent wl_surface object is destroyed, the sub-surface is
 * unmapped.
 */
extern const struct wl_interface wl_subsurface_interface;
#endif

#ifndef WL_DISPLAY_ERROR_ENUM
#define WL_DISPLAY_ERROR_ENUM
/**
 * @ingroup iface_wl_display
 * global error values
 *
 * These errors are global and can be emitted in response to any
 * server request.
 */
enum wl_display_error {
	/**
	 * server couldn't find object
	 */
	WL_DISPLAY_ERROR_INVALID_OBJECT = 0,
	/**
	 * method doesn't exist on the specified interface
	 */
	WL_DISPLAY_ERROR_INVALID_METHOD = 1,
	/**
	 * server is out of memory
	 */
	WL_DISPLAY_ERROR_NO_MEMORY = 2,
};
/**
 * @ingroup iface_wl_display
 * Validate a wl_display error value.
 *
 * @return true on success, false on error.
 * @ref wl_display_error
 */
static inline bool
wl_display_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_DISPLAY_ERROR_INVALID_OBJECT:
		return version >= 1;
	case WL_DISPLAY_ERROR_INVALID_METHOD:
		return version >= 1;
	case WL_DISPLAY_ERROR_NO_MEMORY:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_DISPLAY_ERROR_ENUM */

/**
 * @ingroup iface_wl_display
 * @struct wl_display_interface
 */
struct wl_display_interface {
	/**
	 * asynchronous roundtrip
	 *
	 * The sync request asks the server to emit the 'done' event on
	 * the returned wl_callback object. Since requests are handled
	 * in-order and events are delivered in-order, this can be used as
	 * a barrier to ensure all previous requests and the resulting
	 * events have been handled.
	 *
	 * The object returned by this request will be destroyed by the
	 * compositor after the callback is fired and as such the client
	 * must not attempt to use it after that point.
	 *
	 * The callback_data passed in the callback is the event serial.
	 * @param callback callback object for the sync request
	 */
	void (*sync)(struct wl_client *client,
		     struct wl_resource *resource,
		     uint32_t callback);
	/**
	 * get global registry object
	 *
	 * This request creates a registry object that allows the client
	 * to list and bind the global objects available from the
	 * compositor.
	 * @param registry global registry object
	 */
	void (*get_registry)(struct wl_client *client,
			     struct wl_resource *resource,
			     uint32_t registry);
};

#define WL_DISPLAY_MAX_VERSION 1

#define WL_DISPLAY_ERROR 0
#define WL_DISPLAY_DELETE_ID 1

/**
 * @ingroup iface_wl_display
 */
#define WL_DISPLAY_ERROR_SINCE_VERSION 1
/**
 * @ingroup iface_wl_display
 */
#define WL_DISPLAY_DELETE_ID_SINCE_VERSION 1

/**
 * @ingroup iface_wl_display
 */
#define WL_DISPLAY_SYNC_SINCE_VERSION 1
/**
 * @ingroup iface_wl_display
 */
#define WL_DISPLAY_GET_REGISTRY_SINCE_VERSION 1

/**
 * @ingroup iface_wl_registry
 * @struct wl_registry_interface
 */
struct wl_registry_interface {
	/**
	 * bind an object to the display
	 *
	 * Binds a new, client-created object to the server using the
	 * specified name as the identifier.
	 * @param name unique numeric name of the object
	 * @param interface name of the objects interface
	 * @param version version of the objects interface
	 * @param id bounded object
	 */
	void (*bind)(struct wl_client *client,
		     struct wl_resource *resource,
		     uint32_t name,
		     const char *interface, uint32_t version, uint32_t id);
};

#define WL_REGISTRY_MAX_VERSION 1

#define WL_REGISTRY_GLOBAL 0
#define WL_REGISTRY_GLOBAL_REMOVE 1

/**
 * @ingroup iface_wl_registry
 */
#define WL_REGISTRY_GLOBAL_SINCE_VERSION 1
/**
 * @ingroup iface_wl_registry
 */
#define WL_REGISTRY_GLOBAL_REMOVE_SINCE_VERSION 1

/**
 * @ingroup iface_wl_registry
 */
#define WL_REGISTRY_BIND_SINCE_VERSION 1

/**
 * @ingroup iface_wl_registry
 * Sends an global event to the client owning the resource.
 * @param resource_ The client's resource
 * @param name numeric name of the global object
 * @param interface interface implemented by the object
 * @param version interface version
 */
static inline void
wl_registry_send_global(struct wl_resource *resource_, uint32_t name, const char *interface, uint32_t version)
{
	wl_resource_post_event(resource_, WL_REGISTRY_GLOBAL, name, interface, version);
}

/**
 * @ingroup iface_wl_registry
 * Sends an global_remove event to the client owning the resource.
 * @param resource_ The client's resource
 * @param name numeric name of the global object
 */
static inline void
wl_registry_send_global_remove(struct wl_resource *resource_, uint32_t name)
{
	wl_resource_post_event(resource_, WL_REGISTRY_GLOBAL_REMOVE, name);
}

#define WL_CALLBACK_MAX_VERSION 1

#define WL_CALLBACK_DONE 0

/**
 * @ingroup iface_wl_callback
 */
#define WL_CALLBACK_DONE_SINCE_VERSION 1


/**
 * @ingroup iface_wl_callback
 * Sends an done event to the client owning the resource.
 * @param resource_ The client's resource
 * @param callback_data request-specific data for the callback
 */
static inline void
wl_callback_send_done(struct wl_resource *resource_, uint32_t callback_data)
{
	wl_resource_post_event(resource_, WL_CALLBACK_DONE, callback_data);
}

/**
 * @ingroup iface_wl_compositor
 * @struct wl_compositor_interface
 */
struct wl_compositor_interface {
	/**
	 * create new surface
	 *
	 * Ask the compositor to create a new surface.
	 * @param id the new surface
	 */
	void (*create_surface)(struct wl_client *client,
			       struct wl_resource *resource,
			       uint32_t id);
	/**
	 * create new region
	 *
	 * Ask the compositor to create a new region.
	 * @param id the new region
	 */
	void (*create_region)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t id);
};

#define WL_COMPOSITOR_MAX_VERSION 4


/**
 * @ingroup iface_wl_compositor
 */
#define WL_COMPOSITOR_CREATE_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_compositor
 */
#define WL_COMPOSITOR_CREATE_REGION_SINCE_VERSION 1

/**
 * @ingroup iface_wl_shm_pool
 * @struct wl_shm_pool_interface
 */
struct wl_shm_pool_interface {
	/**
	 * create a buffer from the pool
	 *
	 * Create a wl_buffer object from the pool.
	 *
	 * The buffer is created offset bytes into the pool and has width
	 * and height as specified. The stride argument specifies the
	 * number of bytes from the beginning of one row to the beginning
	 * of the next. The format is the pixel format of the buffer and
	 * must be one of those advertised through the wl_shm.format event.
	 *
	 * A buffer will keep a reference to the pool it was created from
	 * so it is valid to destroy the pool immediately after creating a
	 * buffer from it.
	 * @param id buffer to create
	 * @param offset buffer byte offset within the pool
	 * @param width buffer width, in pixels
	 * @param height buffer height, in pixels
	 * @param stride number of bytes from the beginning of one row to the beginning of the next row
	 * @param format buffer pixel format
	 */
	void (*create_buffer)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t id,
			      int32_t offset,
			      int32_t width,
			      int32_t height,
			      int32_t stride,
			      uint32_t format);
	/**
	 * destroy the pool
	 *
	 * Destroy the shared memory pool.
	 *
	 * The mmapped memory will be released when all buffers that have
	 * been created from this pool are gone.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * change the size of the pool mapping
	 *
	 * This request will cause the server to remap the backing memory
	 * for the pool from the file descriptor passed when the pool was
	 * created, but using the new size. This request can only be used
	 * to make the pool bigger.
	 * @param size new size of the pool, in bytes
	 */
	void (*resize)(struct wl_client *client,
		       struct wl_resource *resource,
		       int32_t size);
};

#define WL_SHM_POOL_MAX_VERSION 1


/**
 * @ingroup iface_wl_shm_pool
 */
#define WL_SHM_POOL_CREATE_BUFFER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shm_pool
 */
#define WL_SHM_POOL_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shm_pool
 */
#define WL_SHM_POOL_RESIZE_SINCE_VERSION 1

#ifndef WL_SHM_ERROR_ENUM
#define WL_SHM_ERROR_ENUM
/**
 * @ingroup iface_wl_shm
 * wl_shm error values
 *
 * These errors can be emitted in response to wl_shm requests.
 */
enum wl_shm_error {
	/**
	 * buffer format is not known
	 */
	WL_SHM_ERROR_INVALID_FORMAT = 0,
	/**
	 * invalid size or stride during pool or buffer creation
	 */
	WL_SHM_ERROR_INVALID_STRIDE = 1,
	/**
	 * mmapping the file descriptor failed
	 */
	WL_SHM_ERROR_INVALID_FD = 2,
};
/**
 * @ingroup iface_wl_shm
 * Validate a wl_shm error value.
 *
 * @return true on success, false on error.
 * @ref wl_shm_error
 */
static inline bool
wl_shm_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SHM_ERROR_INVALID_FORMAT:
		return version >= 1;
	case WL_SHM_ERROR_INVALID_STRIDE:
		return version >= 1;
	case WL_SHM_ERROR_INVALID_FD:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SHM_ERROR_ENUM */

#ifndef WL_SHM_FORMAT_ENUM
#define WL_SHM_FORMAT_ENUM
/**
 * @ingroup iface_wl_shm
 * pixel formats
 *
 * This describes the memory layout of an individual pixel.
 *
 * All renderers should support argb8888 and xrgb8888 but any other
 * formats are optional and may not be supported by the particular
 * renderer in use.
 *
 * The drm format codes match the macros defined in drm_fourcc.h.
 * The formats actually supported by the compositor will be
 * reported by the format event.
 */
enum wl_shm_format {
	/**
	 * 32-bit ARGB format, [31:0] A:R:G:B 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_ARGB8888 = 0,
	/**
	 * 32-bit RGB format, [31:0] x:R:G:B 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_XRGB8888 = 1,
	/**
	 * 8-bit color index format, [7:0] C
	 */
	WL_SHM_FORMAT_C8 = 0x20203843,
	/**
	 * 8-bit RGB format, [7:0] R:G:B 3:3:2
	 */
	WL_SHM_FORMAT_RGB332 = 0x38424752,
	/**
	 * 8-bit BGR format, [7:0] B:G:R 2:3:3
	 */
	WL_SHM_FORMAT_BGR233 = 0x38524742,
	/**
	 * 16-bit xRGB format, [15:0] x:R:G:B 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_XRGB4444 = 0x32315258,
	/**
	 * 16-bit xBGR format, [15:0] x:B:G:R 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_XBGR4444 = 0x32314258,
	/**
	 * 16-bit RGBx format, [15:0] R:G:B:x 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_RGBX4444 = 0x32315852,
	/**
	 * 16-bit BGRx format, [15:0] B:G:R:x 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_BGRX4444 = 0x32315842,
	/**
	 * 16-bit ARGB format, [15:0] A:R:G:B 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_ARGB4444 = 0x32315241,
	/**
	 * 16-bit ABGR format, [15:0] A:B:G:R 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_ABGR4444 = 0x32314241,
	/**
	 * 16-bit RBGA format, [15:0] R:G:B:A 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_RGBA4444 = 0x32314152,
	/**
	 * 16-bit BGRA format, [15:0] B:G:R:A 4:4:4:4 little endian
	 */
	WL_SHM_FORMAT_BGRA4444 = 0x32314142,
	/**
	 * 16-bit xRGB format, [15:0] x:R:G:B 1:5:5:5 little endian
	 */
	WL_SHM_FORMAT_XRGB1555 = 0x35315258,
	/**
	 * 16-bit xBGR 1555 format, [15:0] x:B:G:R 1:5:5:5 little endian
	 */
	WL_SHM_FORMAT_XBGR1555 = 0x35314258,
	/**
	 * 16-bit RGBx 5551 format, [15:0] R:G:B:x 5:5:5:1 little endian
	 */
	WL_SHM_FORMAT_RGBX5551 = 0x35315852,
	/**
	 * 16-bit BGRx 5551 format, [15:0] B:G:R:x 5:5:5:1 little endian
	 */
	WL_SHM_FORMAT_BGRX5551 = 0x35315842,
	/**
	 * 16-bit ARGB 1555 format, [15:0] A:R:G:B 1:5:5:5 little endian
	 */
	WL_SHM_FORMAT_ARGB1555 = 0x35315241,
	/**
	 * 16-bit ABGR 1555 format, [15:0] A:B:G:R 1:5:5:5 little endian
	 */
	WL_SHM_FORMAT_ABGR1555 = 0x35314241,
	/**
	 * 16-bit RGBA 5551 format, [15:0] R:G:B:A 5:5:5:1 little endian
	 */
	WL_SHM_FORMAT_RGBA5551 = 0x35314152,
	/**
	 * 16-bit BGRA 5551 format, [15:0] B:G:R:A 5:5:5:1 little endian
	 */
	WL_SHM_FORMAT_BGRA5551 = 0x35314142,
	/**
	 * 16-bit RGB 565 format, [15:0] R:G:B 5:6:5 little endian
	 */
	WL_SHM_FORMAT_RGB565 = 0x36314752,
	/**
	 * 16-bit BGR 565 format, [15:0] B:G:R 5:6:5 little endian
	 */
	WL_SHM_FORMAT_BGR565 = 0x36314742,
	/**
	 * 24-bit RGB format, [23:0] R:G:B little endian
	 */
	WL_SHM_FORMAT_RGB888 = 0x34324752,
	/**
	 * 24-bit BGR format, [23:0] B:G:R little endian
	 */
	WL_SHM_FORMAT_BGR888 = 0x34324742,
	/**
	 * 32-bit xBGR format, [31:0] x:B:G:R 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_XBGR8888 = 0x34324258,
	/**
	 * 32-bit RGBx format, [31:0] R:G:B:x 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_RGBX8888 = 0x34325852,
	/**
	 * 32-bit BGRx format, [31:0] B:G:R:x 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_BGRX8888 = 0x34325842,
	/**
	 * 32-bit ABGR format, [31:0] A:B:G:R 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_ABGR8888 = 0x34324241,
	/**
	 * 32-bit RGBA format, [31:0] R:G:B:A 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_RGBA8888 = 0x34324152,
	/**
	 * 32-bit BGRA format, [31:0] B:G:R:A 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_BGRA8888 = 0x34324142,
	/**
	 * 32-bit xRGB format, [31:0] x:R:G:B 2:10:10:10 little endian
	 */
	WL_SHM_FORMAT_XRGB2101010 = 0x30335258,
	/**
	 * 32-bit xBGR format, [31:0] x:B:G:R 2:10:10:10 little endian
	 */
	WL_SHM_FORMAT_XBGR2101010 = 0x30334258,
	/**
	 * 32-bit RGBx format, [31:0] R:G:B:x 10:10:10:2 little endian
	 */
	WL_SHM_FORMAT_RGBX1010102 = 0x30335852,
	/**
	 * 32-bit BGRx format, [31:0] B:G:R:x 10:10:10:2 little endian
	 */
	WL_SHM_FORMAT_BGRX1010102 = 0x30335842,
	/**
	 * 32-bit ARGB format, [31:0] A:R:G:B 2:10:10:10 little endian
	 */
	WL_SHM_FORMAT_ARGB2101010 = 0x30335241,
	/**
	 * 32-bit ABGR format, [31:0] A:B:G:R 2:10:10:10 little endian
	 */
	WL_SHM_FORMAT_ABGR2101010 = 0x30334241,
	/**
	 * 32-bit RGBA format, [31:0] R:G:B:A 10:10:10:2 little endian
	 */
	WL_SHM_FORMAT_RGBA1010102 = 0x30334152,
	/**
	 * 32-bit BGRA format, [31:0] B:G:R:A 10:10:10:2 little endian
	 */
	WL_SHM_FORMAT_BGRA1010102 = 0x30334142,
	/**
	 * packed YCbCr format, [31:0] Cr0:Y1:Cb0:Y0 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_YUYV = 0x56595559,
	/**
	 * packed YCbCr format, [31:0] Cb0:Y1:Cr0:Y0 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_YVYU = 0x55595659,
	/**
	 * packed YCbCr format, [31:0] Y1:Cr0:Y0:Cb0 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_UYVY = 0x59565955,
	/**
	 * packed YCbCr format, [31:0] Y1:Cb0:Y0:Cr0 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_VYUY = 0x59555956,
	/**
	 * packed AYCbCr format, [31:0] A:Y:Cb:Cr 8:8:8:8 little endian
	 */
	WL_SHM_FORMAT_AYUV = 0x56555941,
	/**
	 * 2 plane YCbCr Cr:Cb format, 2x2 subsampled Cr:Cb plane
	 */
	WL_SHM_FORMAT_NV12 = 0x3231564e,
	/**
	 * 2 plane YCbCr Cb:Cr format, 2x2 subsampled Cb:Cr plane
	 */
	WL_SHM_FORMAT_NV21 = 0x3132564e,
	/**
	 * 2 plane YCbCr Cr:Cb format, 2x1 subsampled Cr:Cb plane
	 */
	WL_SHM_FORMAT_NV16 = 0x3631564e,
	/**
	 * 2 plane YCbCr Cb:Cr format, 2x1 subsampled Cb:Cr plane
	 */
	WL_SHM_FORMAT_NV61 = 0x3136564e,
	/**
	 * 3 plane YCbCr format, 4x4 subsampled Cb (1) and Cr (2) planes
	 */
	WL_SHM_FORMAT_YUV410 = 0x39565559,
	/**
	 * 3 plane YCbCr format, 4x4 subsampled Cr (1) and Cb (2) planes
	 */
	WL_SHM_FORMAT_YVU410 = 0x39555659,
	/**
	 * 3 plane YCbCr format, 4x1 subsampled Cb (1) and Cr (2) planes
	 */
	WL_SHM_FORMAT_YUV411 = 0x31315559,
	/**
	 * 3 plane YCbCr format, 4x1 subsampled Cr (1) and Cb (2) planes
	 */
	WL_SHM_FORMAT_YVU411 = 0x31315659,
	/**
	 * 3 plane YCbCr format, 2x2 subsampled Cb (1) and Cr (2) planes
	 */
	WL_SHM_FORMAT_YUV420 = 0x32315559,
	/**
	 * 3 plane YCbCr format, 2x2 subsampled Cr (1) and Cb (2) planes
	 */
	WL_SHM_FORMAT_YVU420 = 0x32315659,
	/**
	 * 3 plane YCbCr format, 2x1 subsampled Cb (1) and Cr (2) planes
	 */
	WL_SHM_FORMAT_YUV422 = 0x36315559,
	/**
	 * 3 plane YCbCr format, 2x1 subsampled Cr (1) and Cb (2) planes
	 */
	WL_SHM_FORMAT_YVU422 = 0x36315659,
	/**
	 * 3 plane YCbCr format, non-subsampled Cb (1) and Cr (2) planes
	 */
	WL_SHM_FORMAT_YUV444 = 0x34325559,
	/**
	 * 3 plane YCbCr format, non-subsampled Cr (1) and Cb (2) planes
	 */
	WL_SHM_FORMAT_YVU444 = 0x34325659,
};
/**
 * @ingroup iface_wl_shm
 * Validate a wl_shm format value.
 *
 * @return true on success, false on error.
 * @ref wl_shm_format
 */
static inline bool
wl_shm_format_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SHM_FORMAT_ARGB8888:
		return version >= 1;
	case WL_SHM_FORMAT_XRGB8888:
		return version >= 1;
	case WL_SHM_FORMAT_C8:
		return version >= 1;
	case WL_SHM_FORMAT_RGB332:
		return version >= 1;
	case WL_SHM_FORMAT_BGR233:
		return version >= 1;
	case WL_SHM_FORMAT_XRGB4444:
		return version >= 1;
	case WL_SHM_FORMAT_XBGR4444:
		return version >= 1;
	case WL_SHM_FORMAT_RGBX4444:
		return version >= 1;
	case WL_SHM_FORMAT_BGRX4444:
		return version >= 1;
	case WL_SHM_FORMAT_ARGB4444:
		return version >= 1;
	case WL_SHM_FORMAT_ABGR4444:
		return version >= 1;
	case WL_SHM_FORMAT_RGBA4444:
		return version >= 1;
	case WL_SHM_FORMAT_BGRA4444:
		return version >= 1;
	case WL_SHM_FORMAT_XRGB1555:
		return version >= 1;
	case WL_SHM_FORMAT_XBGR1555:
		return version >= 1;
	case WL_SHM_FORMAT_RGBX5551:
		return version >= 1;
	case WL_SHM_FORMAT_BGRX5551:
		return version >= 1;
	case WL_SHM_FORMAT_ARGB1555:
		return version >= 1;
	case WL_SHM_FORMAT_ABGR1555:
		return version >= 1;
	case WL_SHM_FORMAT_RGBA5551:
		return version >= 1;
	case WL_SHM_FORMAT_BGRA5551:
		return version >= 1;
	case WL_SHM_FORMAT_RGB565:
		return version >= 1;
	case WL_SHM_FORMAT_BGR565:
		return version >= 1;
	case WL_SHM_FORMAT_RGB888:
		return version >= 1;
	case WL_SHM_FORMAT_BGR888:
		return version >= 1;
	case WL_SHM_FORMAT_XBGR8888:
		return version >= 1;
	case WL_SHM_FORMAT_RGBX8888:
		return version >= 1;
	case WL_SHM_FORMAT_BGRX8888:
		return version >= 1;
	case WL_SHM_FORMAT_ABGR8888:
		return version >= 1;
	case WL_SHM_FORMAT_RGBA8888:
		return version >= 1;
	case WL_SHM_FORMAT_BGRA8888:
		return version >= 1;
	case WL_SHM_FORMAT_XRGB2101010:
		return version >= 1;
	case WL_SHM_FORMAT_XBGR2101010:
		return version >= 1;
	case WL_SHM_FORMAT_RGBX1010102:
		return version >= 1;
	case WL_SHM_FORMAT_BGRX1010102:
		return version >= 1;
	case WL_SHM_FORMAT_ARGB2101010:
		return version >= 1;
	case WL_SHM_FORMAT_ABGR2101010:
		return version >= 1;
	case WL_SHM_FORMAT_RGBA1010102:
		return version >= 1;
	case WL_SHM_FORMAT_BGRA1010102:
		return version >= 1;
	case WL_SHM_FORMAT_YUYV:
		return version >= 1;
	case WL_SHM_FORMAT_YVYU:
		return version >= 1;
	case WL_SHM_FORMAT_UYVY:
		return version >= 1;
	case WL_SHM_FORMAT_VYUY:
		return version >= 1;
	case WL_SHM_FORMAT_AYUV:
		return version >= 1;
	case WL_SHM_FORMAT_NV12:
		return version >= 1;
	case WL_SHM_FORMAT_NV21:
		return version >= 1;
	case WL_SHM_FORMAT_NV16:
		return version >= 1;
	case WL_SHM_FORMAT_NV61:
		return version >= 1;
	case WL_SHM_FORMAT_YUV410:
		return version >= 1;
	case WL_SHM_FORMAT_YVU410:
		return version >= 1;
	case WL_SHM_FORMAT_YUV411:
		return version >= 1;
	case WL_SHM_FORMAT_YVU411:
		return version >= 1;
	case WL_SHM_FORMAT_YUV420:
		return version >= 1;
	case WL_SHM_FORMAT_YVU420:
		return version >= 1;
	case WL_SHM_FORMAT_YUV422:
		return version >= 1;
	case WL_SHM_FORMAT_YVU422:
		return version >= 1;
	case WL_SHM_FORMAT_YUV444:
		return version >= 1;
	case WL_SHM_FORMAT_YVU444:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SHM_FORMAT_ENUM */

/**
 * @ingroup iface_wl_shm
 * @struct wl_shm_interface
 */
struct wl_shm_interface {
	/**
	 * create a shm pool
	 *
	 * Create a new wl_shm_pool object.
	 *
	 * The pool can be used to create shared memory based buffer
	 * objects. The server will mmap size bytes of the passed file
	 * descriptor, to use as backing memory for the pool.
	 * @param id pool to create
	 * @param fd file descriptor for the pool
	 * @param size pool size, in bytes
	 */
	void (*create_pool)(struct wl_client *client,
			    struct wl_resource *resource,
			    uint32_t id,
			    int32_t fd,
			    int32_t size);
};

#define WL_SHM_MAX_VERSION 1

#define WL_SHM_FORMAT 0

/**
 * @ingroup iface_wl_shm
 */
#define WL_SHM_FORMAT_SINCE_VERSION 1

/**
 * @ingroup iface_wl_shm
 */
#define WL_SHM_CREATE_POOL_SINCE_VERSION 1

/**
 * @ingroup iface_wl_shm
 * Sends an format event to the client owning the resource.
 * @param resource_ The client's resource
 * @param format buffer pixel format
 */
static inline void
wl_shm_send_format(struct wl_resource *resource_, uint32_t format)
{
	wl_resource_post_event(resource_, WL_SHM_FORMAT, format);
}

/**
 * @ingroup iface_wl_buffer
 * @struct wl_buffer_interface
 */
struct wl_buffer_interface {
	/**
	 * destroy a buffer
	 *
	 * Destroy a buffer. If and how you need to release the backing
	 * storage is defined by the buffer factory interface.
	 *
	 * For possible side-effects to a surface, see wl_surface.attach.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_BUFFER_MAX_VERSION 1

#define WL_BUFFER_RELEASE 0

/**
 * @ingroup iface_wl_buffer
 */
#define WL_BUFFER_RELEASE_SINCE_VERSION 1

/**
 * @ingroup iface_wl_buffer
 */
#define WL_BUFFER_DESTROY_SINCE_VERSION 1

/**
 * @ingroup iface_wl_buffer
 * Sends an release event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_buffer_send_release(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_BUFFER_RELEASE);
}

#ifndef WL_DATA_OFFER_ERROR_ENUM
#define WL_DATA_OFFER_ERROR_ENUM
enum wl_data_offer_error {
	/**
	 * finish request was called untimely
	 */
	WL_DATA_OFFER_ERROR_INVALID_FINISH = 0,
	/**
	 * action mask contains invalid values
	 */
	WL_DATA_OFFER_ERROR_INVALID_ACTION_MASK = 1,
	/**
	 * action argument has an invalid value
	 */
	WL_DATA_OFFER_ERROR_INVALID_ACTION = 2,
	/**
	 * offer doesn't accept this request
	 */
	WL_DATA_OFFER_ERROR_INVALID_OFFER = 3,
};
/**
 * @ingroup iface_wl_data_offer
 * Validate a wl_data_offer error value.
 *
 * @return true on success, false on error.
 * @ref wl_data_offer_error
 */
static inline bool
wl_data_offer_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_DATA_OFFER_ERROR_INVALID_FINISH:
		return version >= 1;
	case WL_DATA_OFFER_ERROR_INVALID_ACTION_MASK:
		return version >= 1;
	case WL_DATA_OFFER_ERROR_INVALID_ACTION:
		return version >= 1;
	case WL_DATA_OFFER_ERROR_INVALID_OFFER:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_DATA_OFFER_ERROR_ENUM */

/**
 * @ingroup iface_wl_data_offer
 * @struct wl_data_offer_interface
 */
struct wl_data_offer_interface {
	/**
	 * accept one of the offered mime types
	 *
	 * Indicate that the client can accept the given mime type, or
	 * NULL for not accepted.
	 *
	 * For objects of version 2 or older, this request is used by the
	 * client to give feedback whether the client can receive the given
	 * mime type, or NULL if none is accepted; the feedback does not
	 * determine whether the drag-and-drop operation succeeds or not.
	 *
	 * For objects of version 3 or newer, this request determines the
	 * final result of the drag-and-drop operation. If the end result
	 * is that no mime types were accepted, the drag-and-drop operation
	 * will be cancelled and the corresponding drag source will receive
	 * wl_data_source.cancelled. Clients may still use this event in
	 * conjunction with wl_data_source.action for feedback.
	 * @param serial serial number of the accept request
	 * @param mime_type mime type accepted by the client
	 */
	void (*accept)(struct wl_client *client,
		       struct wl_resource *resource,
		       uint32_t serial,
		       const char *mime_type);
	/**
	 * request that the data is transferred
	 *
	 * To transfer the offered data, the client issues this request
	 * and indicates the mime type it wants to receive. The transfer
	 * happens through the passed file descriptor (typically created
	 * with the pipe system call). The source client writes the data in
	 * the mime type representation requested and then closes the file
	 * descriptor.
	 *
	 * The receiving client reads from the read end of the pipe until
	 * EOF and then closes its end, at which point the transfer is
	 * complete.
	 *
	 * This request may happen multiple times for different mime types,
	 * both before and after wl_data_device.drop. Drag-and-drop
	 * destination clients may preemptively fetch data or examine it
	 * more closely to determine acceptance.
	 * @param mime_type mime type desired by receiver
	 * @param fd file descriptor for data transfer
	 */
	void (*receive)(struct wl_client *client,
			struct wl_resource *resource,
			const char *mime_type,
			int32_t fd);
	/**
	 * destroy data offer
	 *
	 * Destroy the data offer.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * the offer will no longer be used
	 *
	 * Notifies the compositor that the drag destination successfully
	 * finished the drag-and-drop operation.
	 *
	 * Upon receiving this request, the compositor will emit
	 * wl_data_source.dnd_finished on the drag source client.
	 *
	 * It is a client error to perform other requests than
	 * wl_data_offer.destroy after this one. It is also an error to
	 * perform this request after a NULL mime type has been set in
	 * wl_data_offer.accept or no action was received through
	 * wl_data_offer.action.
	 * @since 3
	 */
	void (*finish)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * set the available/preferred drag-and-drop actions
	 *
	 * Sets the actions that the destination side client supports for
	 * this operation. This request may trigger the emission of
	 * wl_data_source.action and wl_data_offer.action events if the
	 * compositor needs to change the selected action.
	 *
	 * This request can be called multiple times throughout the
	 * drag-and-drop operation, typically in response to
	 * wl_data_device.enter or wl_data_device.motion events.
	 *
	 * This request determines the final result of the drag-and-drop
	 * operation. If the end result is that no action is accepted, the
	 * drag source will receive wl_drag_source.cancelled.
	 *
	 * The dnd_actions argument must contain only values expressed in
	 * the wl_data_device_manager.dnd_actions enum, and the
	 * preferred_action argument must only contain one of those values
	 * set, otherwise it will result in a protocol error.
	 *
	 * While managing an "ask" action, the destination drag-and-drop
	 * client may perform further wl_data_offer.receive requests, and
	 * is expected to perform one last wl_data_offer.set_actions
	 * request with a preferred action other than "ask" (and optionally
	 * wl_data_offer.accept) before requesting wl_data_offer.finish, in
	 * order to convey the action selected by the user. If the
	 * preferred action is not in the wl_data_offer.source_actions
	 * mask, an error will be raised.
	 *
	 * If the "ask" action is dismissed (e.g. user cancellation), the
	 * client is expected to perform wl_data_offer.destroy right away.
	 *
	 * This request can only be made on drag-and-drop offers, a
	 * protocol error will be raised otherwise.
	 * @param dnd_actions actions supported by the destination client
	 * @param preferred_action action preferred by the destination client
	 * @since 3
	 */
	void (*set_actions)(struct wl_client *client,
			    struct wl_resource *resource,
			    uint32_t dnd_actions,
			    uint32_t preferred_action);
};

#define WL_DATA_OFFER_MAX_VERSION 3

#define WL_DATA_OFFER_OFFER 0
#define WL_DATA_OFFER_SOURCE_ACTIONS 1
#define WL_DATA_OFFER_ACTION 2

/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_OFFER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_SOURCE_ACTIONS_SINCE_VERSION 3
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_ACTION_SINCE_VERSION 3

/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_ACCEPT_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_RECEIVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_FINISH_SINCE_VERSION 3
/**
 * @ingroup iface_wl_data_offer
 */
#define WL_DATA_OFFER_SET_ACTIONS_SINCE_VERSION 3

/**
 * @ingroup iface_wl_data_offer
 * Sends an offer event to the client owning the resource.
 * @param resource_ The client's resource
 * @param mime_type offered mime type
 */
static inline void
wl_data_offer_send_offer(struct wl_resource *resource_, const char *mime_type)
{
	wl_resource_post_event(resource_, WL_DATA_OFFER_OFFER, mime_type);
}

/**
 * @ingroup iface_wl_data_offer
 * Sends an source_actions event to the client owning the resource.
 * @param resource_ The client's resource
 * @param source_actions actions offered by the data source
 */
static inline void
wl_data_offer_send_source_actions(struct wl_resource *resource_, uint32_t source_actions)
{
	wl_resource_post_event(resource_, WL_DATA_OFFER_SOURCE_ACTIONS, source_actions);
}

/**
 * @ingroup iface_wl_data_offer
 * Sends an action event to the client owning the resource.
 * @param resource_ The client's resource
 * @param dnd_action action selected by the compositor
 */
static inline void
wl_data_offer_send_action(struct wl_resource *resource_, uint32_t dnd_action)
{
	wl_resource_post_event(resource_, WL_DATA_OFFER_ACTION, dnd_action);
}

#ifndef WL_DATA_SOURCE_ERROR_ENUM
#define WL_DATA_SOURCE_ERROR_ENUM
enum wl_data_source_error {
	/**
	 * action mask contains invalid values
	 */
	WL_DATA_SOURCE_ERROR_INVALID_ACTION_MASK = 0,
	/**
	 * source doesn't accept this request
	 */
	WL_DATA_SOURCE_ERROR_INVALID_SOURCE = 1,
};
/**
 * @ingroup iface_wl_data_source
 * Validate a wl_data_source error value.
 *
 * @return true on success, false on error.
 * @ref wl_data_source_error
 */
static inline bool
wl_data_source_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_DATA_SOURCE_ERROR_INVALID_ACTION_MASK:
		return version >= 1;
	case WL_DATA_SOURCE_ERROR_INVALID_SOURCE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_DATA_SOURCE_ERROR_ENUM */

/**
 * @ingroup iface_wl_data_source
 * @struct wl_data_source_interface
 */
struct wl_data_source_interface {
	/**
	 * add an offered mime type
	 *
	 * This request adds a mime type to the set of mime types
	 * advertised to targets. Can be called several times to offer
	 * multiple types.
	 * @param mime_type mime type offered by the data source
	 */
	void (*offer)(struct wl_client *client,
		      struct wl_resource *resource,
		      const char *mime_type);
	/**
	 * destroy the data source
	 *
	 * Destroy the data source.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * set the available drag-and-drop actions
	 *
	 * Sets the actions that the source side client supports for this
	 * operation. This request may trigger wl_data_source.action and
	 * wl_data_offer.action events if the compositor needs to change
	 * the selected action.
	 *
	 * The dnd_actions argument must contain only values expressed in
	 * the wl_data_device_manager.dnd_actions enum, otherwise it will
	 * result in a protocol error.
	 *
	 * This request must be made once only, and can only be made on
	 * sources used in drag-and-drop, so it must be performed before
	 * wl_data_device.start_drag. Attempting to use the source other
	 * than for drag-and-drop will raise a protocol error.
	 * @param dnd_actions actions supported by the data source
	 * @since 3
	 */
	void (*set_actions)(struct wl_client *client,
			    struct wl_resource *resource,
			    uint32_t dnd_actions);
};

#define WL_DATA_SOURCE_MAX_VERSION 3

#define WL_DATA_SOURCE_TARGET 0
#define WL_DATA_SOURCE_SEND 1
#define WL_DATA_SOURCE_CANCELLED 2
#define WL_DATA_SOURCE_DND_DROP_PERFORMED 3
#define WL_DATA_SOURCE_DND_FINISHED 4
#define WL_DATA_SOURCE_ACTION 5

/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_TARGET_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_SEND_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_CANCELLED_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_DND_DROP_PERFORMED_SINCE_VERSION 3
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_DND_FINISHED_SINCE_VERSION 3
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_ACTION_SINCE_VERSION 3

/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_OFFER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_source
 */
#define WL_DATA_SOURCE_SET_ACTIONS_SINCE_VERSION 3

/**
 * @ingroup iface_wl_data_source
 * Sends an target event to the client owning the resource.
 * @param resource_ The client's resource
 * @param mime_type mime type accepted by the target
 */
static inline void
wl_data_source_send_target(struct wl_resource *resource_, const char *mime_type)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_TARGET, mime_type);
}

/**
 * @ingroup iface_wl_data_source
 * Sends an send event to the client owning the resource.
 * @param resource_ The client's resource
 * @param mime_type mime type for the data
 * @param fd file descriptor for the data
 */
static inline void
wl_data_source_send_send(struct wl_resource *resource_, const char *mime_type, int32_t fd)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_SEND, mime_type, fd);
}

/**
 * @ingroup iface_wl_data_source
 * Sends an cancelled event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_data_source_send_cancelled(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_CANCELLED);
}

/**
 * @ingroup iface_wl_data_source
 * Sends an dnd_drop_performed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_data_source_send_dnd_drop_performed(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_DND_DROP_PERFORMED);
}

/**
 * @ingroup iface_wl_data_source
 * Sends an dnd_finished event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_data_source_send_dnd_finished(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_DND_FINISHED);
}

/**
 * @ingroup iface_wl_data_source
 * Sends an action event to the client owning the resource.
 * @param resource_ The client's resource
 * @param dnd_action action selected by the compositor
 */
static inline void
wl_data_source_send_action(struct wl_resource *resource_, uint32_t dnd_action)
{
	wl_resource_post_event(resource_, WL_DATA_SOURCE_ACTION, dnd_action);
}

#ifndef WL_DATA_DEVICE_ERROR_ENUM
#define WL_DATA_DEVICE_ERROR_ENUM
enum wl_data_device_error {
	/**
	 * given wl_surface has another role
	 */
	WL_DATA_DEVICE_ERROR_ROLE = 0,
};
/**
 * @ingroup iface_wl_data_device
 * Validate a wl_data_device error value.
 *
 * @return true on success, false on error.
 * @ref wl_data_device_error
 */
static inline bool
wl_data_device_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_DATA_DEVICE_ERROR_ROLE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_DATA_DEVICE_ERROR_ENUM */

/**
 * @ingroup iface_wl_data_device
 * @struct wl_data_device_interface
 */
struct wl_data_device_interface {
	/**
	 * start drag-and-drop operation
	 *
	 * This request asks the compositor to start a drag-and-drop
	 * operation on behalf of the client.
	 *
	 * The source argument is the data source that provides the data
	 * for the eventual data transfer. If source is NULL, enter, leave
	 * and motion events are sent only to the client that initiated the
	 * drag and the client is expected to handle the data passing
	 * internally.
	 *
	 * The origin surface is the surface where the drag originates and
	 * the client must have an active implicit grab that matches the
	 * serial.
	 *
	 * The icon surface is an optional (can be NULL) surface that
	 * provides an icon to be moved around with the cursor. Initially,
	 * the top-left corner of the icon surface is placed at the cursor
	 * hotspot, but subsequent wl_surface.attach request can move the
	 * relative position. Attach requests must be confirmed with
	 * wl_surface.commit as usual. The icon surface is given the role
	 * of a drag-and-drop icon. If the icon surface already has another
	 * role, it raises a protocol error.
	 *
	 * The current and pending input regions of the icon wl_surface are
	 * cleared, and wl_surface.set_input_region is ignored until the
	 * wl_surface is no longer used as the icon surface. When the use
	 * as an icon ends, the current and pending input regions become
	 * undefined, and the wl_surface is unmapped.
	 * @param source data source for the eventual transfer
	 * @param origin surface where the drag originates
	 * @param icon drag-and-drop icon surface
	 * @param serial serial number of the implicit grab on the origin
	 */
	void (*start_drag)(struct wl_client *client,
			   struct wl_resource *resource,
			   struct wl_resource *source,
			   struct wl_resource *origin,
			   struct wl_resource *icon,
			   uint32_t serial);
	/**
	 * copy data to the selection
	 *
	 * This request asks the compositor to set the selection to the
	 * data from the source on behalf of the client.
	 *
	 * To unset the selection, set the source to NULL.
	 * @param source data source for the selection
	 * @param serial serial number of the event that triggered this request
	 */
	void (*set_selection)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *source,
			      uint32_t serial);
	/**
	 * destroy data device
	 *
	 * This request destroys the data device.
	 * @since 2
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_DATA_DEVICE_MAX_VERSION 3

#define WL_DATA_DEVICE_DATA_OFFER 0
#define WL_DATA_DEVICE_ENTER 1
#define WL_DATA_DEVICE_LEAVE 2
#define WL_DATA_DEVICE_MOTION 3
#define WL_DATA_DEVICE_DROP 4
#define WL_DATA_DEVICE_SELECTION 5

/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_DATA_OFFER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_MOTION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_DROP_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_SELECTION_SINCE_VERSION 1

/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_START_DRAG_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_SET_SELECTION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device
 */
#define WL_DATA_DEVICE_RELEASE_SINCE_VERSION 2

/**
 * @ingroup iface_wl_data_device
 * Sends an data_offer event to the client owning the resource.
 * @param resource_ The client's resource
 * @param id the new data_offer object
 */
static inline void
wl_data_device_send_data_offer(struct wl_resource *resource_, struct wl_resource *id)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_DATA_OFFER, id);
}

/**
 * @ingroup iface_wl_data_device
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the enter event
 * @param surface client surface entered
 * @param x surface-local x coordinate
 * @param y surface-local y coordinate
 * @param id source data_offer object
 */
static inline void
wl_data_device_send_enter(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface, wl_fixed_t x, wl_fixed_t y, struct wl_resource *id)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_ENTER, serial, surface, x, y, id);
}

/**
 * @ingroup iface_wl_data_device
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_data_device_send_leave(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_LEAVE);
}

/**
 * @ingroup iface_wl_data_device
 * Sends an motion event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param x surface-local x coordinate
 * @param y surface-local y coordinate
 */
static inline void
wl_data_device_send_motion(struct wl_resource *resource_, uint32_t time, wl_fixed_t x, wl_fixed_t y)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_MOTION, time, x, y);
}

/**
 * @ingroup iface_wl_data_device
 * Sends an drop event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_data_device_send_drop(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_DROP);
}

/**
 * @ingroup iface_wl_data_device
 * Sends an selection event to the client owning the resource.
 * @param resource_ The client's resource
 * @param id selection data_offer object
 */
static inline void
wl_data_device_send_selection(struct wl_resource *resource_, struct wl_resource *id)
{
	wl_resource_post_event(resource_, WL_DATA_DEVICE_SELECTION, id);
}

#ifndef WL_DATA_DEVICE_MANAGER_DND_ACTION_ENUM
#define WL_DATA_DEVICE_MANAGER_DND_ACTION_ENUM
/**
 * @ingroup iface_wl_data_device_manager
 * drag and drop actions
 *
 * This is a bitmask of the available/preferred actions in a
 * drag-and-drop operation.
 *
 * In the compositor, the selected action is a result of matching the
 * actions offered by the source and destination sides.  "action" events
 * with a "none" action will be sent to both source and destination if
 * there is no match. All further checks will effectively happen on
 * (source actions ∩ destination actions).
 *
 * In addition, compositors may also pick different actions in
 * reaction to key modifiers being pressed. One common design that
 * is used in major toolkits (and the behavior recommended for
 * compositors) is:
 *
 * - If no modifiers are pressed, the first match (in bit order)
 * will be used.
 * - Pressing Shift selects "move", if enabled in the mask.
 * - Pressing Control selects "copy", if enabled in the mask.
 *
 * Behavior beyond that is considered implementation-dependent.
 * Compositors may for example bind other modifiers (like Alt/Meta)
 * or drags initiated with other buttons than BTN_LEFT to specific
 * actions (e.g. "ask").
 */
enum wl_data_device_manager_dnd_action {
	/**
	 * no action
	 */
	WL_DATA_DEVICE_MANAGER_DND_ACTION_NONE = 0,
	/**
	 * copy action
	 */
	WL_DATA_DEVICE_MANAGER_DND_ACTION_COPY = 1,
	/**
	 * move action
	 */
	WL_DATA_DEVICE_MANAGER_DND_ACTION_MOVE = 2,
	/**
	 * ask action
	 */
	WL_DATA_DEVICE_MANAGER_DND_ACTION_ASK = 4,
};
/**
 * @ingroup iface_wl_data_device_manager
 * Validate a wl_data_device_manager dnd_action value.
 *
 * @return true on success, false on error.
 * @ref wl_data_device_manager_dnd_action
 */
static inline bool
wl_data_device_manager_dnd_action_is_valid(uint32_t value, uint32_t version) {
	uint32_t valid = 0;
	if (version >= 1)
		valid |= WL_DATA_DEVICE_MANAGER_DND_ACTION_NONE;
	if (version >= 1)
		valid |= WL_DATA_DEVICE_MANAGER_DND_ACTION_COPY;
	if (version >= 1)
		valid |= WL_DATA_DEVICE_MANAGER_DND_ACTION_MOVE;
	if (version >= 1)
		valid |= WL_DATA_DEVICE_MANAGER_DND_ACTION_ASK;
	return (value & ~valid) == 0;
}
#endif /* WL_DATA_DEVICE_MANAGER_DND_ACTION_ENUM */

/**
 * @ingroup iface_wl_data_device_manager
 * @struct wl_data_device_manager_interface
 */
struct wl_data_device_manager_interface {
	/**
	 * create a new data source
	 *
	 * Create a new data source.
	 * @param id data source to create
	 */
	void (*create_data_source)(struct wl_client *client,
				   struct wl_resource *resource,
				   uint32_t id);
	/**
	 * create a new data device
	 *
	 * Create a new data device for a given seat.
	 * @param id data device to create
	 * @param seat seat associated with the data device
	 */
	void (*get_data_device)(struct wl_client *client,
				struct wl_resource *resource,
				uint32_t id,
				struct wl_resource *seat);
};

#define WL_DATA_DEVICE_MANAGER_MAX_VERSION 3


/**
 * @ingroup iface_wl_data_device_manager
 */
#define WL_DATA_DEVICE_MANAGER_CREATE_DATA_SOURCE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_data_device_manager
 */
#define WL_DATA_DEVICE_MANAGER_GET_DATA_DEVICE_SINCE_VERSION 1

#ifndef WL_SHELL_ERROR_ENUM
#define WL_SHELL_ERROR_ENUM
enum wl_shell_error {
	/**
	 * given wl_surface has another role
	 */
	WL_SHELL_ERROR_ROLE = 0,
};
/**
 * @ingroup iface_wl_shell
 * Validate a wl_shell error value.
 *
 * @return true on success, false on error.
 * @ref wl_shell_error
 */
static inline bool
wl_shell_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SHELL_ERROR_ROLE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SHELL_ERROR_ENUM */

/**
 * @ingroup iface_wl_shell
 * @struct wl_shell_interface
 */
struct wl_shell_interface {
	/**
	 * create a shell surface from a surface
	 *
	 * Create a shell surface for an existing surface. This gives the
	 * wl_surface the role of a shell surface. If the wl_surface
	 * already has another role, it raises a protocol error.
	 *
	 * Only one shell surface can be associated with a given surface.
	 * @param id shell surface to create
	 * @param surface surface to be given the shell surface role
	 */
	void (*get_shell_surface)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t id,
				  struct wl_resource *surface);
};

#define WL_SHELL_MAX_VERSION 1


/**
 * @ingroup iface_wl_shell
 */
#define WL_SHELL_GET_SHELL_SURFACE_SINCE_VERSION 1

#ifndef WL_SHELL_SURFACE_RESIZE_ENUM
#define WL_SHELL_SURFACE_RESIZE_ENUM
/**
 * @ingroup iface_wl_shell_surface
 * edge values for resizing
 *
 * These values are used to indicate which edge of a surface
 * is being dragged in a resize operation. The server may
 * use this information to adapt its behavior, e.g. choose
 * an appropriate cursor image.
 */
enum wl_shell_surface_resize {
	/**
	 * no edge
	 */
	WL_SHELL_SURFACE_RESIZE_NONE = 0,
	/**
	 * top edge
	 */
	WL_SHELL_SURFACE_RESIZE_TOP = 1,
	/**
	 * bottom edge
	 */
	WL_SHELL_SURFACE_RESIZE_BOTTOM = 2,
	/**
	 * left edge
	 */
	WL_SHELL_SURFACE_RESIZE_LEFT = 4,
	/**
	 * top and left edges
	 */
	WL_SHELL_SURFACE_RESIZE_TOP_LEFT = 5,
	/**
	 * bottom and left edges
	 */
	WL_SHELL_SURFACE_RESIZE_BOTTOM_LEFT = 6,
	/**
	 * right edge
	 */
	WL_SHELL_SURFACE_RESIZE_RIGHT = 8,
	/**
	 * top and right edges
	 */
	WL_SHELL_SURFACE_RESIZE_TOP_RIGHT = 9,
	/**
	 * bottom and right edges
	 */
	WL_SHELL_SURFACE_RESIZE_BOTTOM_RIGHT = 10,
};
/**
 * @ingroup iface_wl_shell_surface
 * Validate a wl_shell_surface resize value.
 *
 * @return true on success, false on error.
 * @ref wl_shell_surface_resize
 */
static inline bool
wl_shell_surface_resize_is_valid(uint32_t value, uint32_t version) {
	uint32_t valid = 0;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_NONE;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_TOP;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_BOTTOM;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_LEFT;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_TOP_LEFT;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_BOTTOM_LEFT;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_RIGHT;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_TOP_RIGHT;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_RESIZE_BOTTOM_RIGHT;
	return (value & ~valid) == 0;
}
#endif /* WL_SHELL_SURFACE_RESIZE_ENUM */

#ifndef WL_SHELL_SURFACE_TRANSIENT_ENUM
#define WL_SHELL_SURFACE_TRANSIENT_ENUM
/**
 * @ingroup iface_wl_shell_surface
 * details of transient behaviour
 *
 * These flags specify details of the expected behaviour
 * of transient surfaces. Used in the set_transient request.
 */
enum wl_shell_surface_transient {
	/**
	 * do not set keyboard focus
	 */
	WL_SHELL_SURFACE_TRANSIENT_INACTIVE = 0x1,
};
/**
 * @ingroup iface_wl_shell_surface
 * Validate a wl_shell_surface transient value.
 *
 * @return true on success, false on error.
 * @ref wl_shell_surface_transient
 */
static inline bool
wl_shell_surface_transient_is_valid(uint32_t value, uint32_t version) {
	uint32_t valid = 0;
	if (version >= 1)
		valid |= WL_SHELL_SURFACE_TRANSIENT_INACTIVE;
	return (value & ~valid) == 0;
}
#endif /* WL_SHELL_SURFACE_TRANSIENT_ENUM */

#ifndef WL_SHELL_SURFACE_FULLSCREEN_METHOD_ENUM
#define WL_SHELL_SURFACE_FULLSCREEN_METHOD_ENUM
/**
 * @ingroup iface_wl_shell_surface
 * different method to set the surface fullscreen
 *
 * Hints to indicate to the compositor how to deal with a conflict
 * between the dimensions of the surface and the dimensions of the
 * output. The compositor is free to ignore this parameter.
 */
enum wl_shell_surface_fullscreen_method {
	/**
	 * no preference, apply default policy
	 */
	WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT = 0,
	/**
	 * scale, preserve the surface's aspect ratio and center on output
	 */
	WL_SHELL_SURFACE_FULLSCREEN_METHOD_SCALE = 1,
	/**
	 * switch output mode to the smallest mode that can fit the surface, add black borders to compensate size mismatch
	 */
	WL_SHELL_SURFACE_FULLSCREEN_METHOD_DRIVER = 2,
	/**
	 * no upscaling, center on output and add black borders to compensate size mismatch
	 */
	WL_SHELL_SURFACE_FULLSCREEN_METHOD_FILL = 3,
};
/**
 * @ingroup iface_wl_shell_surface
 * Validate a wl_shell_surface fullscreen_method value.
 *
 * @return true on success, false on error.
 * @ref wl_shell_surface_fullscreen_method
 */
static inline bool
wl_shell_surface_fullscreen_method_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT:
		return version >= 1;
	case WL_SHELL_SURFACE_FULLSCREEN_METHOD_SCALE:
		return version >= 1;
	case WL_SHELL_SURFACE_FULLSCREEN_METHOD_DRIVER:
		return version >= 1;
	case WL_SHELL_SURFACE_FULLSCREEN_METHOD_FILL:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SHELL_SURFACE_FULLSCREEN_METHOD_ENUM */

/**
 * @ingroup iface_wl_shell_surface
 * @struct wl_shell_surface_interface
 */
struct wl_shell_surface_interface {
	/**
	 * respond to a ping event
	 *
	 * A client must respond to a ping event with a pong request or
	 * the client may be deemed unresponsive.
	 * @param serial serial number of the ping event
	 */
	void (*pong)(struct wl_client *client,
		     struct wl_resource *resource,
		     uint32_t serial);
	/**
	 * start an interactive move
	 *
	 * Start a pointer-driven move of the surface.
	 *
	 * This request must be used in response to a button press event.
	 * The server may ignore move requests depending on the state of
	 * the surface (e.g. fullscreen or maximized).
	 * @param seat seat whose pointer is used
	 * @param serial serial number of the implicit grab on the pointer
	 */
	void (*move)(struct wl_client *client,
		     struct wl_resource *resource,
		     struct wl_resource *seat,
		     uint32_t serial);
	/**
	 * start an interactive resize
	 *
	 * Start a pointer-driven resizing of the surface.
	 *
	 * This request must be used in response to a button press event.
	 * The server may ignore resize requests depending on the state of
	 * the surface (e.g. fullscreen or maximized).
	 * @param seat seat whose pointer is used
	 * @param serial serial number of the implicit grab on the pointer
	 * @param edges which edge or corner is being dragged
	 */
	void (*resize)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *seat,
		       uint32_t serial,
		       uint32_t edges);
	/**
	 * make the surface a toplevel surface
	 *
	 * Map the surface as a toplevel surface.
	 *
	 * A toplevel surface is not fullscreen, maximized or transient.
	 */
	void (*set_toplevel)(struct wl_client *client,
			     struct wl_resource *resource);
	/**
	 * make the surface a transient surface
	 *
	 * Map the surface relative to an existing surface.
	 *
	 * The x and y arguments specify the location of the upper left
	 * corner of the surface relative to the upper left corner of the
	 * parent surface, in surface-local coordinates.
	 *
	 * The flags argument controls details of the transient behaviour.
	 * @param parent parent surface
	 * @param x surface-local x coordinate
	 * @param y surface-local y coordinate
	 * @param flags transient surface behavior
	 */
	void (*set_transient)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *parent,
			      int32_t x,
			      int32_t y,
			      uint32_t flags);
	/**
	 * make the surface a fullscreen surface
	 *
	 * Map the surface as a fullscreen surface.
	 *
	 * If an output parameter is given then the surface will be made
	 * fullscreen on that output. If the client does not specify the
	 * output then the compositor will apply its policy - usually
	 * choosing the output on which the surface has the biggest surface
	 * area.
	 *
	 * The client may specify a method to resolve a size conflict
	 * between the output size and the surface size - this is provided
	 * through the method parameter.
	 *
	 * The framerate parameter is used only when the method is set to
	 * "driver", to indicate the preferred framerate. A value of 0
	 * indicates that the client does not care about framerate. The
	 * framerate is specified in mHz, that is framerate of 60000 is
	 * 60Hz.
	 *
	 * A method of "scale" or "driver" implies a scaling operation of
	 * the surface, either via a direct scaling operation or a change
	 * of the output mode. This will override any kind of output
	 * scaling, so that mapping a surface with a buffer size equal to
	 * the mode can fill the screen independent of buffer_scale.
	 *
	 * A method of "fill" means we don't scale up the buffer, however
	 * any output scale is applied. This means that you may run into an
	 * edge case where the application maps a buffer with the same size
	 * of the output mode but buffer_scale 1 (thus making a surface
	 * larger than the output). In this case it is allowed to downscale
	 * the results to fit the screen.
	 *
	 * The compositor must reply to this request with a configure event
	 * with the dimensions for the output on which the surface will be
	 * made fullscreen.
	 * @param method method for resolving size conflict
	 * @param framerate framerate in mHz
	 * @param output output on which the surface is to be fullscreen
	 */
	void (*set_fullscreen)(struct wl_client *client,
			       struct wl_resource *resource,
			       uint32_t method,
			       uint32_t framerate,
			       struct wl_resource *output);
	/**
	 * make the surface a popup surface
	 *
	 * Map the surface as a popup.
	 *
	 * A popup surface is a transient surface with an added pointer
	 * grab.
	 *
	 * An existing implicit grab will be changed to owner-events mode,
	 * and the popup grab will continue after the implicit grab ends
	 * (i.e. releasing the mouse button does not cause the popup to be
	 * unmapped).
	 *
	 * The popup grab continues until the window is destroyed or a
	 * mouse button is pressed in any other client's window. A click in
	 * any of the client's surfaces is reported as normal, however,
	 * clicks in other clients' surfaces will be discarded and trigger
	 * the callback.
	 *
	 * The x and y arguments specify the location of the upper left
	 * corner of the surface relative to the upper left corner of the
	 * parent surface, in surface-local coordinates.
	 * @param seat seat whose pointer is used
	 * @param serial serial number of the implicit grab on the pointer
	 * @param parent parent surface
	 * @param x surface-local x coordinate
	 * @param y surface-local y coordinate
	 * @param flags transient surface behavior
	 */
	void (*set_popup)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *seat,
			  uint32_t serial,
			  struct wl_resource *parent,
			  int32_t x,
			  int32_t y,
			  uint32_t flags);
	/**
	 * make the surface a maximized surface
	 *
	 * Map the surface as a maximized surface.
	 *
	 * If an output parameter is given then the surface will be
	 * maximized on that output. If the client does not specify the
	 * output then the compositor will apply its policy - usually
	 * choosing the output on which the surface has the biggest surface
	 * area.
	 *
	 * The compositor will reply with a configure event telling the
	 * expected new surface size. The operation is completed on the
	 * next buffer attach to this surface.
	 *
	 * A maximized surface typically fills the entire output it is
	 * bound to, except for desktop elements such as panels. This is
	 * the main difference between a maximized shell surface and a
	 * fullscreen shell surface.
	 *
	 * The details depend on the compositor implementation.
	 * @param output output on which the surface is to be maximized
	 */
	void (*set_maximized)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *output);
	/**
	 * set surface title
	 *
	 * Set a short title for the surface.
	 *
	 * This string may be used to identify the surface in a task bar,
	 * window list, or other user interface elements provided by the
	 * compositor.
	 *
	 * The string must be encoded in UTF-8.
	 * @param title surface title
	 */
	void (*set_title)(struct wl_client *client,
			  struct wl_resource *resource,
			  const char *title);
	/**
	 * set surface class
	 *
	 * Set a class for the surface.
	 *
	 * The surface class identifies the general class of applications
	 * to which the surface belongs. A common convention is to use the
	 * file name (or the full path if it is a non-standard location) of
	 * the application's .desktop file as the class.
	 * @param class_ surface class
	 */
	void (*set_class)(struct wl_client *client,
			  struct wl_resource *resource,
			  const char *class_);
};

#define WL_SHELL_SURFACE_MAX_VERSION 1

#define WL_SHELL_SURFACE_PING 0
#define WL_SHELL_SURFACE_CONFIGURE 1
#define WL_SHELL_SURFACE_POPUP_DONE 2

/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_PING_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_CONFIGURE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_POPUP_DONE_SINCE_VERSION 1

/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_PONG_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_MOVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_RESIZE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_TOPLEVEL_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_TRANSIENT_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_FULLSCREEN_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_POPUP_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_MAXIMIZED_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_TITLE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_shell_surface
 */
#define WL_SHELL_SURFACE_SET_CLASS_SINCE_VERSION 1

/**
 * @ingroup iface_wl_shell_surface
 * Sends an ping event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the ping
 */
static inline void
wl_shell_surface_send_ping(struct wl_resource *resource_, uint32_t serial)
{
	wl_resource_post_event(resource_, WL_SHELL_SURFACE_PING, serial);
}

/**
 * @ingroup iface_wl_shell_surface
 * Sends an configure event to the client owning the resource.
 * @param resource_ The client's resource
 * @param edges how the surface was resized
 * @param width new width of the surface
 * @param height new height of the surface
 */
static inline void
wl_shell_surface_send_configure(struct wl_resource *resource_, uint32_t edges, int32_t width, int32_t height)
{
	wl_resource_post_event(resource_, WL_SHELL_SURFACE_CONFIGURE, edges, width, height);
}

/**
 * @ingroup iface_wl_shell_surface
 * Sends an popup_done event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_shell_surface_send_popup_done(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_SHELL_SURFACE_POPUP_DONE);
}

#ifndef WL_SURFACE_ERROR_ENUM
#define WL_SURFACE_ERROR_ENUM
/**
 * @ingroup iface_wl_surface
 * wl_surface error values
 *
 * These errors can be emitted in response to wl_surface requests.
 */
enum wl_surface_error {
	/**
	 * buffer scale value is invalid
	 */
	WL_SURFACE_ERROR_INVALID_SCALE = 0,
	/**
	 * buffer transform value is invalid
	 */
	WL_SURFACE_ERROR_INVALID_TRANSFORM = 1,
};
/**
 * @ingroup iface_wl_surface
 * Validate a wl_surface error value.
 *
 * @return true on success, false on error.
 * @ref wl_surface_error
 */
static inline bool
wl_surface_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SURFACE_ERROR_INVALID_SCALE:
		return version >= 1;
	case WL_SURFACE_ERROR_INVALID_TRANSFORM:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SURFACE_ERROR_ENUM */

/**
 * @ingroup iface_wl_surface
 * @struct wl_surface_interface
 */
struct wl_surface_interface {
	/**
	 * delete surface
	 *
	 * Deletes the surface and invalidates its object ID.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * set the surface contents
	 *
	 * Set a buffer as the content of this surface.
	 *
	 * The new size of the surface is calculated based on the buffer
	 * size transformed by the inverse buffer_transform and the inverse
	 * buffer_scale. This means that the supplied buffer must be an
	 * integer multiple of the buffer_scale.
	 *
	 * The x and y arguments specify the location of the new pending
	 * buffer's upper left corner, relative to the current buffer's
	 * upper left corner, in surface-local coordinates. In other words,
	 * the x and y, combined with the new surface size define in which
	 * directions the surface's size changes.
	 *
	 * Surface contents are double-buffered state, see
	 * wl_surface.commit.
	 *
	 * The initial surface contents are void; there is no content.
	 * wl_surface.attach assigns the given wl_buffer as the pending
	 * wl_buffer. wl_surface.commit makes the pending wl_buffer the new
	 * surface contents, and the size of the surface becomes the size
	 * calculated from the wl_buffer, as described above. After commit,
	 * there is no pending buffer until the next attach.
	 *
	 * Committing a pending wl_buffer allows the compositor to read the
	 * pixels in the wl_buffer. The compositor may access the pixels at
	 * any time after the wl_surface.commit request. When the
	 * compositor will not access the pixels anymore, it will send the
	 * wl_buffer.release event. Only after receiving wl_buffer.release,
	 * the client may reuse the wl_buffer. A wl_buffer that has been
	 * attached and then replaced by another attach instead of
	 * committed will not receive a release event, and is not used by
	 * the compositor.
	 *
	 * Destroying the wl_buffer after wl_buffer.release does not change
	 * the surface contents. However, if the client destroys the
	 * wl_buffer before receiving the wl_buffer.release event, the
	 * surface contents become undefined immediately.
	 *
	 * If wl_surface.attach is sent with a NULL wl_buffer, the
	 * following wl_surface.commit will remove the surface content.
	 * @param buffer buffer of surface contents
	 * @param x surface-local x coordinate
	 * @param y surface-local y coordinate
	 */
	void (*attach)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *buffer,
		       int32_t x,
		       int32_t y);
	/**
	 * mark part of the surface damaged
	 *
	 * This request is used to describe the regions where the pending
	 * buffer is different from the current surface contents, and where
	 * the surface therefore needs to be repainted. The compositor
	 * ignores the parts of the damage that fall outside of the
	 * surface.
	 *
	 * Damage is double-buffered state, see wl_surface.commit.
	 *
	 * The damage rectangle is specified in surface-local coordinates,
	 * where x and y specify the upper left corner of the damage
	 * rectangle.
	 *
	 * The initial value for pending damage is empty: no damage.
	 * wl_surface.damage adds pending damage: the new pending damage is
	 * the union of old pending damage and the given rectangle.
	 *
	 * wl_surface.commit assigns pending damage as the current damage,
	 * and clears pending damage. The server will clear the current
	 * damage as it repaints the surface.
	 *
	 * Alternatively, damage can be posted with
	 * wl_surface.damage_buffer which uses buffer coordinates instead
	 * of surface coordinates, and is probably the preferred and
	 * intuitive way of doing this.
	 * @param x surface-local x coordinate
	 * @param y surface-local y coordinate
	 * @param width width of damage rectangle
	 * @param height height of damage rectangle
	 */
	void (*damage)(struct wl_client *client,
		       struct wl_resource *resource,
		       int32_t x,
		       int32_t y,
		       int32_t width,
		       int32_t height);
	/**
	 * request a frame throttling hint
	 *
	 * Request a notification when it is a good time to start drawing
	 * a new frame, by creating a frame callback. This is useful for
	 * throttling redrawing operations, and driving animations.
	 *
	 * When a client is animating on a wl_surface, it can use the
	 * 'frame' request to get notified when it is a good time to draw
	 * and commit the next frame of animation. If the client commits an
	 * update earlier than that, it is likely that some updates will
	 * not make it to the display, and the client is wasting resources
	 * by drawing too often.
	 *
	 * The frame request will take effect on the next
	 * wl_surface.commit. The notification will only be posted for one
	 * frame unless requested again. For a wl_surface, the
	 * notifications are posted in the order the frame requests were
	 * committed.
	 *
	 * The server must send the notifications so that a client will not
	 * send excessive updates, while still allowing the highest
	 * possible update rate for clients that wait for the reply before
	 * drawing again. The server should give some time for the client
	 * to draw and commit after sending the frame callback events to
	 * let it hit the next output refresh.
	 *
	 * A server should avoid signaling the frame callbacks if the
	 * surface is not visible in any way, e.g. the surface is
	 * off-screen, or completely obscured by other opaque surfaces.
	 *
	 * The object returned by this request will be destroyed by the
	 * compositor after the callback is fired and as such the client
	 * must not attempt to use it after that point.
	 *
	 * The callback_data passed in the callback is the current time, in
	 * milliseconds, with an undefined base.
	 * @param callback callback object for the frame request
	 */
	void (*frame)(struct wl_client *client,
		      struct wl_resource *resource,
		      uint32_t callback);
	/**
	 * set opaque region
	 *
	 * This request sets the region of the surface that contains
	 * opaque content.
	 *
	 * The opaque region is an optimization hint for the compositor
	 * that lets it optimize the redrawing of content behind opaque
	 * regions. Setting an opaque region is not required for correct
	 * behaviour, but marking transparent content as opaque will result
	 * in repaint artifacts.
	 *
	 * The opaque region is specified in surface-local coordinates.
	 *
	 * The compositor ignores the parts of the opaque region that fall
	 * outside of the surface.
	 *
	 * Opaque region is double-buffered state, see wl_surface.commit.
	 *
	 * wl_surface.set_opaque_region changes the pending opaque region.
	 * wl_surface.commit copies the pending region to the current
	 * region. Otherwise, the pending and current regions are never
	 * changed.
	 *
	 * The initial value for an opaque region is empty. Setting the
	 * pending opaque region has copy semantics, and the wl_region
	 * object can be destroyed immediately. A NULL wl_region causes the
	 * pending opaque region to be set to empty.
	 * @param region opaque region of the surface
	 */
	void (*set_opaque_region)(struct wl_client *client,
				  struct wl_resource *resource,
				  struct wl_resource *region);
	/**
	 * set input region
	 *
	 * This request sets the region of the surface that can receive
	 * pointer and touch events.
	 *
	 * Input events happening outside of this region will try the next
	 * surface in the server surface stack. The compositor ignores the
	 * parts of the input region that fall outside of the surface.
	 *
	 * The input region is specified in surface-local coordinates.
	 *
	 * Input region is double-buffered state, see wl_surface.commit.
	 *
	 * wl_surface.set_input_region changes the pending input region.
	 * wl_surface.commit copies the pending region to the current
	 * region. Otherwise the pending and current regions are never
	 * changed, except cursor and icon surfaces are special cases, see
	 * wl_pointer.set_cursor and wl_data_device.start_drag.
	 *
	 * The initial value for an input region is infinite. That means
	 * the whole surface will accept input. Setting the pending input
	 * region has copy semantics, and the wl_region object can be
	 * destroyed immediately. A NULL wl_region causes the input region
	 * to be set to infinite.
	 * @param region input region of the surface
	 */
	void (*set_input_region)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *region);
	/**
	 * commit pending surface state
	 *
	 * Surface state (input, opaque, and damage regions, attached
	 * buffers, etc.) is double-buffered. Protocol requests modify the
	 * pending state, as opposed to the current state in use by the
	 * compositor. A commit request atomically applies all pending
	 * state, replacing the current state. After commit, the new
	 * pending state is as documented for each related request.
	 *
	 * On commit, a pending wl_buffer is applied first, and all other
	 * state second. This means that all coordinates in double-buffered
	 * state are relative to the new wl_buffer coming into use, except
	 * for wl_surface.attach itself. If there is no pending wl_buffer,
	 * the coordinates are relative to the current surface contents.
	 *
	 * All requests that need a commit to become effective are
	 * documented to affect double-buffered state.
	 *
	 * Other interfaces may add further double-buffered surface state.
	 */
	void (*commit)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * sets the buffer transformation
	 *
	 * This request sets an optional transformation on how the
	 * compositor interprets the contents of the buffer attached to the
	 * surface. The accepted values for the transform parameter are the
	 * values for wl_output.transform.
	 *
	 * Buffer transform is double-buffered state, see
	 * wl_surface.commit.
	 *
	 * A newly created surface has its buffer transformation set to
	 * normal.
	 *
	 * wl_surface.set_buffer_transform changes the pending buffer
	 * transformation. wl_surface.commit copies the pending buffer
	 * transformation to the current one. Otherwise, the pending and
	 * current values are never changed.
	 *
	 * The purpose of this request is to allow clients to render
	 * content according to the output transform, thus permitting the
	 * compositor to use certain optimizations even if the display is
	 * rotated. Using hardware overlays and scanning out a client
	 * buffer for fullscreen surfaces are examples of such
	 * optimizations. Those optimizations are highly dependent on the
	 * compositor implementation, so the use of this request should be
	 * considered on a case-by-case basis.
	 *
	 * Note that if the transform value includes 90 or 270 degree
	 * rotation, the width of the buffer will become the surface height
	 * and the height of the buffer will become the surface width.
	 *
	 * If transform is not one of the values from the
	 * wl_output.transform enum the invalid_transform protocol error is
	 * raised.
	 * @param transform transform for interpreting buffer contents
	 * @since 2
	 */
	void (*set_buffer_transform)(struct wl_client *client,
				     struct wl_resource *resource,
				     int32_t transform);
	/**
	 * sets the buffer scaling factor
	 *
	 * This request sets an optional scaling factor on how the
	 * compositor interprets the contents of the buffer attached to the
	 * window.
	 *
	 * Buffer scale is double-buffered state, see wl_surface.commit.
	 *
	 * A newly created surface has its buffer scale set to 1.
	 *
	 * wl_surface.set_buffer_scale changes the pending buffer scale.
	 * wl_surface.commit copies the pending buffer scale to the current
	 * one. Otherwise, the pending and current values are never
	 * changed.
	 *
	 * The purpose of this request is to allow clients to supply higher
	 * resolution buffer data for use on high resolution outputs. It is
	 * intended that you pick the same buffer scale as the scale of the
	 * output that the surface is displayed on. This means the
	 * compositor can avoid scaling when rendering the surface on that
	 * output.
	 *
	 * Note that if the scale is larger than 1, then you have to attach
	 * a buffer that is larger (by a factor of scale in each dimension)
	 * than the desired surface size.
	 *
	 * If scale is not positive the invalid_scale protocol error is
	 * raised.
	 * @param scale positive scale for interpreting buffer contents
	 * @since 3
	 */
	void (*set_buffer_scale)(struct wl_client *client,
				 struct wl_resource *resource,
				 int32_t scale);
	/**
	 * mark part of the surface damaged using buffer coordinates
	 *
	 * This request is used to describe the regions where the pending
	 * buffer is different from the current surface contents, and where
	 * the surface therefore needs to be repainted. The compositor
	 * ignores the parts of the damage that fall outside of the
	 * surface.
	 *
	 * Damage is double-buffered state, see wl_surface.commit.
	 *
	 * The damage rectangle is specified in buffer coordinates, where x
	 * and y specify the upper left corner of the damage rectangle.
	 *
	 * The initial value for pending damage is empty: no damage.
	 * wl_surface.damage_buffer adds pending damage: the new pending
	 * damage is the union of old pending damage and the given
	 * rectangle.
	 *
	 * wl_surface.commit assigns pending damage as the current damage,
	 * and clears pending damage. The server will clear the current
	 * damage as it repaints the surface.
	 *
	 * This request differs from wl_surface.damage in only one way - it
	 * takes damage in buffer coordinates instead of surface-local
	 * coordinates. While this generally is more intuitive than surface
	 * coordinates, it is especially desirable when using wp_viewport
	 * or when a drawing library (like EGL) is unaware of buffer scale
	 * and buffer transform.
	 *
	 * Note: Because buffer transformation changes and damage requests
	 * may be interleaved in the protocol stream, it is impossible to
	 * determine the actual mapping between surface and buffer damage
	 * until wl_surface.commit time. Therefore, compositors wishing to
	 * take both kinds of damage into account will have to accumulate
	 * damage from the two requests separately and only transform from
	 * one to the other after receiving the wl_surface.commit.
	 * @param x buffer-local x coordinate
	 * @param y buffer-local y coordinate
	 * @param width width of damage rectangle
	 * @param height height of damage rectangle
	 * @since 4
	 */
	void (*damage_buffer)(struct wl_client *client,
			      struct wl_resource *resource,
			      int32_t x,
			      int32_t y,
			      int32_t width,
			      int32_t height);
};

#define WL_SURFACE_MAX_VERSION 4

#define WL_SURFACE_ENTER 0
#define WL_SURFACE_LEAVE 1

/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_LEAVE_SINCE_VERSION 1

/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_ATTACH_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_DAMAGE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_FRAME_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_SET_OPAQUE_REGION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_SET_INPUT_REGION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_COMMIT_SINCE_VERSION 1
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_SET_BUFFER_TRANSFORM_SINCE_VERSION 2
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_SET_BUFFER_SCALE_SINCE_VERSION 3
/**
 * @ingroup iface_wl_surface
 */
#define WL_SURFACE_DAMAGE_BUFFER_SINCE_VERSION 4

/**
 * @ingroup iface_wl_surface
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 * @param output output entered by the surface
 */
static inline void
wl_surface_send_enter(struct wl_resource *resource_, struct wl_resource *output)
{
	wl_resource_post_event(resource_, WL_SURFACE_ENTER, output);
}

/**
 * @ingroup iface_wl_surface
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 * @param output output left by the surface
 */
static inline void
wl_surface_send_leave(struct wl_resource *resource_, struct wl_resource *output)
{
	wl_resource_post_event(resource_, WL_SURFACE_LEAVE, output);
}

#ifndef WL_SEAT_CAPABILITY_ENUM
#define WL_SEAT_CAPABILITY_ENUM
/**
 * @ingroup iface_wl_seat
 * seat capability bitmask
 *
 * This is a bitmask of capabilities this seat has; if a member is
 * set, then it is present on the seat.
 */
enum wl_seat_capability {
	/**
	 * the seat has pointer devices
	 */
	WL_SEAT_CAPABILITY_POINTER = 1,
	/**
	 * the seat has one or more keyboards
	 */
	WL_SEAT_CAPABILITY_KEYBOARD = 2,
	/**
	 * the seat has touch devices
	 */
	WL_SEAT_CAPABILITY_TOUCH = 4,
};
/**
 * @ingroup iface_wl_seat
 * Validate a wl_seat capability value.
 *
 * @return true on success, false on error.
 * @ref wl_seat_capability
 */
static inline bool
wl_seat_capability_is_valid(uint32_t value, uint32_t version) {
	uint32_t valid = 0;
	if (version >= 1)
		valid |= WL_SEAT_CAPABILITY_POINTER;
	if (version >= 1)
		valid |= WL_SEAT_CAPABILITY_KEYBOARD;
	if (version >= 1)
		valid |= WL_SEAT_CAPABILITY_TOUCH;
	return (value & ~valid) == 0;
}
#endif /* WL_SEAT_CAPABILITY_ENUM */

/**
 * @ingroup iface_wl_seat
 * @struct wl_seat_interface
 */
struct wl_seat_interface {
	/**
	 * return pointer object
	 *
	 * The ID provided will be initialized to the wl_pointer
	 * interface for this seat.
	 *
	 * This request only takes effect if the seat has the pointer
	 * capability, or has had the pointer capability in the past. It is
	 * a protocol violation to issue this request on a seat that has
	 * never had the pointer capability.
	 * @param id seat pointer
	 */
	void (*get_pointer)(struct wl_client *client,
			    struct wl_resource *resource,
			    uint32_t id);
	/**
	 * return keyboard object
	 *
	 * The ID provided will be initialized to the wl_keyboard
	 * interface for this seat.
	 *
	 * This request only takes effect if the seat has the keyboard
	 * capability, or has had the keyboard capability in the past. It
	 * is a protocol violation to issue this request on a seat that has
	 * never had the keyboard capability.
	 * @param id seat keyboard
	 */
	void (*get_keyboard)(struct wl_client *client,
			     struct wl_resource *resource,
			     uint32_t id);
	/**
	 * return touch object
	 *
	 * The ID provided will be initialized to the wl_touch interface
	 * for this seat.
	 *
	 * This request only takes effect if the seat has the touch
	 * capability, or has had the touch capability in the past. It is a
	 * protocol violation to issue this request on a seat that has
	 * never had the touch capability.
	 * @param id seat touch interface
	 */
	void (*get_touch)(struct wl_client *client,
			  struct wl_resource *resource,
			  uint32_t id);
	/**
	 * release the seat object
	 *
	 * Using this request a client can tell the server that it is not
	 * going to use the seat object anymore.
	 * @since 5
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_SEAT_MAX_VERSION 6

#define WL_SEAT_CAPABILITIES 0
#define WL_SEAT_NAME 1

/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_CAPABILITIES_SINCE_VERSION 1
/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_NAME_SINCE_VERSION 2

/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_GET_POINTER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_GET_KEYBOARD_SINCE_VERSION 1
/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_GET_TOUCH_SINCE_VERSION 1
/**
 * @ingroup iface_wl_seat
 */
#define WL_SEAT_RELEASE_SINCE_VERSION 5

/**
 * @ingroup iface_wl_seat
 * Sends an capabilities event to the client owning the resource.
 * @param resource_ The client's resource
 * @param capabilities capabilities of the seat
 */
static inline void
wl_seat_send_capabilities(struct wl_resource *resource_, uint32_t capabilities)
{
	wl_resource_post_event(resource_, WL_SEAT_CAPABILITIES, capabilities);
}

/**
 * @ingroup iface_wl_seat
 * Sends an name event to the client owning the resource.
 * @param resource_ The client's resource
 * @param name seat identifier
 */
static inline void
wl_seat_send_name(struct wl_resource *resource_, const char *name)
{
	wl_resource_post_event(resource_, WL_SEAT_NAME, name);
}

#ifndef WL_POINTER_ERROR_ENUM
#define WL_POINTER_ERROR_ENUM
enum wl_pointer_error {
	/**
	 * given wl_surface has another role
	 */
	WL_POINTER_ERROR_ROLE = 0,
};
/**
 * @ingroup iface_wl_pointer
 * Validate a wl_pointer error value.
 *
 * @return true on success, false on error.
 * @ref wl_pointer_error
 */
static inline bool
wl_pointer_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_POINTER_ERROR_ROLE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_POINTER_ERROR_ENUM */

#ifndef WL_POINTER_BUTTON_STATE_ENUM
#define WL_POINTER_BUTTON_STATE_ENUM
/**
 * @ingroup iface_wl_pointer
 * physical button state
 *
 * Describes the physical state of a button that produced the button
 * event.
 */
enum wl_pointer_button_state {
	/**
	 * the button is not pressed
	 */
	WL_POINTER_BUTTON_STATE_RELEASED = 0,
	/**
	 * the button is pressed
	 */
	WL_POINTER_BUTTON_STATE_PRESSED = 1,
};
/**
 * @ingroup iface_wl_pointer
 * Validate a wl_pointer button_state value.
 *
 * @return true on success, false on error.
 * @ref wl_pointer_button_state
 */
static inline bool
wl_pointer_button_state_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_POINTER_BUTTON_STATE_RELEASED:
		return version >= 1;
	case WL_POINTER_BUTTON_STATE_PRESSED:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_POINTER_BUTTON_STATE_ENUM */

#ifndef WL_POINTER_AXIS_ENUM
#define WL_POINTER_AXIS_ENUM
/**
 * @ingroup iface_wl_pointer
 * axis types
 *
 * Describes the axis types of scroll events.
 */
enum wl_pointer_axis {
	/**
	 * vertical axis
	 */
	WL_POINTER_AXIS_VERTICAL_SCROLL = 0,
	/**
	 * horizontal axis
	 */
	WL_POINTER_AXIS_HORIZONTAL_SCROLL = 1,
};
/**
 * @ingroup iface_wl_pointer
 * Validate a wl_pointer axis value.
 *
 * @return true on success, false on error.
 * @ref wl_pointer_axis
 */
static inline bool
wl_pointer_axis_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_POINTER_AXIS_VERTICAL_SCROLL:
		return version >= 1;
	case WL_POINTER_AXIS_HORIZONTAL_SCROLL:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_POINTER_AXIS_ENUM */

#ifndef WL_POINTER_AXIS_SOURCE_ENUM
#define WL_POINTER_AXIS_SOURCE_ENUM
/**
 * @ingroup iface_wl_pointer
 * axis source types
 *
 * Describes the source types for axis events. This indicates to the
 * client how an axis event was physically generated; a client may
 * adjust the user interface accordingly. For example, scroll events
 * from a "finger" source may be in a smooth coordinate space with
 * kinetic scrolling whereas a "wheel" source may be in discrete steps
 * of a number of lines.
 */
enum wl_pointer_axis_source {
	/**
	 * a physical wheel rotation
	 */
	WL_POINTER_AXIS_SOURCE_WHEEL = 0,
	/**
	 * finger on a touch surface
	 */
	WL_POINTER_AXIS_SOURCE_FINGER = 1,
	/**
	 * continuous coordinate space
	 *
	 * A device generating events in a continuous coordinate space,
	 * but using something other than a finger. One example for this
	 * source is button-based scrolling where the vertical motion of a
	 * device is converted to scroll events while a button is held
	 * down.
	 */
	WL_POINTER_AXIS_SOURCE_CONTINUOUS = 2,
	/**
	 * a physical wheel tilt
	 *
	 * Indicates that the actual device is a wheel but the scroll
	 * event is not caused by a rotation but a (usually sideways) tilt
	 * of the wheel.
	 * @since 6
	 */
	WL_POINTER_AXIS_SOURCE_WHEEL_TILT = 3,
};
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_AXIS_SOURCE_WHEEL_TILT_SINCE_VERSION 6
/**
 * @ingroup iface_wl_pointer
 * Validate a wl_pointer axis_source value.
 *
 * @return true on success, false on error.
 * @ref wl_pointer_axis_source
 */
static inline bool
wl_pointer_axis_source_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_POINTER_AXIS_SOURCE_WHEEL:
		return version >= 1;
	case WL_POINTER_AXIS_SOURCE_FINGER:
		return version >= 1;
	case WL_POINTER_AXIS_SOURCE_CONTINUOUS:
		return version >= 1;
	case WL_POINTER_AXIS_SOURCE_WHEEL_TILT:
		return version >= 6;
	default:
		return false;
	}
}
#endif /* WL_POINTER_AXIS_SOURCE_ENUM */

/**
 * @ingroup iface_wl_pointer
 * @struct wl_pointer_interface
 */
struct wl_pointer_interface {
	/**
	 * set the pointer surface
	 *
	 * Set the pointer surface, i.e., the surface that contains the
	 * pointer image (cursor). This request gives the surface the role
	 * of a cursor. If the surface already has another role, it raises
	 * a protocol error.
	 *
	 * The cursor actually changes only if the pointer focus for this
	 * device is one of the requesting client's surfaces or the surface
	 * parameter is the current pointer surface. If there was a
	 * previous surface set with this request it is replaced. If
	 * surface is NULL, the pointer image is hidden.
	 *
	 * The parameters hotspot_x and hotspot_y define the position of
	 * the pointer surface relative to the pointer location. Its
	 * top-left corner is always at (x, y) - (hotspot_x, hotspot_y),
	 * where (x, y) are the coordinates of the pointer location, in
	 * surface-local coordinates.
	 *
	 * On surface.attach requests to the pointer surface, hotspot_x and
	 * hotspot_y are decremented by the x and y parameters passed to
	 * the request. Attach must be confirmed by wl_surface.commit as
	 * usual.
	 *
	 * The hotspot can also be updated by passing the currently set
	 * pointer surface to this request with new values for hotspot_x
	 * and hotspot_y.
	 *
	 * The current and pending input regions of the wl_surface are
	 * cleared, and wl_surface.set_input_region is ignored until the
	 * wl_surface is no longer used as the cursor. When the use as a
	 * cursor ends, the current and pending input regions become
	 * undefined, and the wl_surface is unmapped.
	 * @param serial serial number of the enter event
	 * @param surface pointer surface
	 * @param hotspot_x surface-local x coordinate
	 * @param hotspot_y surface-local y coordinate
	 */
	void (*set_cursor)(struct wl_client *client,
			   struct wl_resource *resource,
			   uint32_t serial,
			   struct wl_resource *surface,
			   int32_t hotspot_x,
			   int32_t hotspot_y);
	/**
	 * release the pointer object
	 *
	 * Using this request a client can tell the server that it is not
	 * going to use the pointer object anymore.
	 *
	 * This request destroys the pointer proxy object, so clients must
	 * not call wl_pointer_destroy() after using this request.
	 * @since 3
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_POINTER_MAX_VERSION 6

#define WL_POINTER_ENTER 0
#define WL_POINTER_LEAVE 1
#define WL_POINTER_MOTION 2
#define WL_POINTER_BUTTON 3
#define WL_POINTER_AXIS 4
#define WL_POINTER_FRAME 5
#define WL_POINTER_AXIS_SOURCE 6
#define WL_POINTER_AXIS_STOP 7
#define WL_POINTER_AXIS_DISCRETE 8

/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_MOTION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_BUTTON_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_AXIS_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_FRAME_SINCE_VERSION 5
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_AXIS_SOURCE_SINCE_VERSION 5
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_AXIS_STOP_SINCE_VERSION 5
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_AXIS_DISCRETE_SINCE_VERSION 5

/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_SET_CURSOR_SINCE_VERSION 1
/**
 * @ingroup iface_wl_pointer
 */
#define WL_POINTER_RELEASE_SINCE_VERSION 3

/**
 * @ingroup iface_wl_pointer
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the enter event
 * @param surface surface entered by the pointer
 * @param surface_x surface-local x coordinate
 * @param surface_y surface-local y coordinate
 */
static inline void
wl_pointer_send_enter(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface, wl_fixed_t surface_x, wl_fixed_t surface_y)
{
	wl_resource_post_event(resource_, WL_POINTER_ENTER, serial, surface, surface_x, surface_y);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the leave event
 * @param surface surface left by the pointer
 */
static inline void
wl_pointer_send_leave(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, WL_POINTER_LEAVE, serial, surface);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an motion event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param surface_x surface-local x coordinate
 * @param surface_y surface-local y coordinate
 */
static inline void
wl_pointer_send_motion(struct wl_resource *resource_, uint32_t time, wl_fixed_t surface_x, wl_fixed_t surface_y)
{
	wl_resource_post_event(resource_, WL_POINTER_MOTION, time, surface_x, surface_y);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an button event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the button event
 * @param time timestamp with millisecond granularity
 * @param button button that produced the event
 * @param state physical state of the button
 */
static inline void
wl_pointer_send_button(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t button, uint32_t state)
{
	wl_resource_post_event(resource_, WL_POINTER_BUTTON, serial, time, button, state);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an axis event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param axis axis type
 * @param value length of vector in surface-local coordinate space
 */
static inline void
wl_pointer_send_axis(struct wl_resource *resource_, uint32_t time, uint32_t axis, wl_fixed_t value)
{
	wl_resource_post_event(resource_, WL_POINTER_AXIS, time, axis, value);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an frame event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_pointer_send_frame(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_POINTER_FRAME);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an axis_source event to the client owning the resource.
 * @param resource_ The client's resource
 * @param axis_source source of the axis event
 */
static inline void
wl_pointer_send_axis_source(struct wl_resource *resource_, uint32_t axis_source)
{
	wl_resource_post_event(resource_, WL_POINTER_AXIS_SOURCE, axis_source);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an axis_stop event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param axis the axis stopped with this event
 */
static inline void
wl_pointer_send_axis_stop(struct wl_resource *resource_, uint32_t time, uint32_t axis)
{
	wl_resource_post_event(resource_, WL_POINTER_AXIS_STOP, time, axis);
}

/**
 * @ingroup iface_wl_pointer
 * Sends an axis_discrete event to the client owning the resource.
 * @param resource_ The client's resource
 * @param axis axis type
 * @param discrete number of steps
 */
static inline void
wl_pointer_send_axis_discrete(struct wl_resource *resource_, uint32_t axis, int32_t discrete)
{
	wl_resource_post_event(resource_, WL_POINTER_AXIS_DISCRETE, axis, discrete);
}

#ifndef WL_KEYBOARD_KEYMAP_FORMAT_ENUM
#define WL_KEYBOARD_KEYMAP_FORMAT_ENUM
/**
 * @ingroup iface_wl_keyboard
 * keyboard mapping format
 *
 * This specifies the format of the keymap provided to the
 * client with the wl_keyboard.keymap event.
 */
enum wl_keyboard_keymap_format {
	/**
	 * no keymap; client must understand how to interpret the raw keycode
	 */
	WL_KEYBOARD_KEYMAP_FORMAT_NO_KEYMAP = 0,
	/**
	 * libxkbcommon compatible; to determine the xkb keycode, clients must add 8 to the key event keycode
	 */
	WL_KEYBOARD_KEYMAP_FORMAT_XKB_V1 = 1,
};
/**
 * @ingroup iface_wl_keyboard
 * Validate a wl_keyboard keymap_format value.
 *
 * @return true on success, false on error.
 * @ref wl_keyboard_keymap_format
 */
static inline bool
wl_keyboard_keymap_format_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_KEYBOARD_KEYMAP_FORMAT_NO_KEYMAP:
		return version >= 1;
	case WL_KEYBOARD_KEYMAP_FORMAT_XKB_V1:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_KEYBOARD_KEYMAP_FORMAT_ENUM */

#ifndef WL_KEYBOARD_KEY_STATE_ENUM
#define WL_KEYBOARD_KEY_STATE_ENUM
/**
 * @ingroup iface_wl_keyboard
 * physical key state
 *
 * Describes the physical state of a key that produced the key event.
 */
enum wl_keyboard_key_state {
	/**
	 * key is not pressed
	 */
	WL_KEYBOARD_KEY_STATE_RELEASED = 0,
	/**
	 * key is pressed
	 */
	WL_KEYBOARD_KEY_STATE_PRESSED = 1,
};
/**
 * @ingroup iface_wl_keyboard
 * Validate a wl_keyboard key_state value.
 *
 * @return true on success, false on error.
 * @ref wl_keyboard_key_state
 */
static inline bool
wl_keyboard_key_state_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_KEYBOARD_KEY_STATE_RELEASED:
		return version >= 1;
	case WL_KEYBOARD_KEY_STATE_PRESSED:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_KEYBOARD_KEY_STATE_ENUM */

/**
 * @ingroup iface_wl_keyboard
 * @struct wl_keyboard_interface
 */
struct wl_keyboard_interface {
	/**
	 * release the keyboard object
	 *
	 * 
	 * @since 3
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_KEYBOARD_MAX_VERSION 6

#define WL_KEYBOARD_KEYMAP 0
#define WL_KEYBOARD_ENTER 1
#define WL_KEYBOARD_LEAVE 2
#define WL_KEYBOARD_KEY 3
#define WL_KEYBOARD_MODIFIERS 4
#define WL_KEYBOARD_REPEAT_INFO 5

/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_KEYMAP_SINCE_VERSION 1
/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_KEY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_MODIFIERS_SINCE_VERSION 1
/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_REPEAT_INFO_SINCE_VERSION 4

/**
 * @ingroup iface_wl_keyboard
 */
#define WL_KEYBOARD_RELEASE_SINCE_VERSION 3

/**
 * @ingroup iface_wl_keyboard
 * Sends an keymap event to the client owning the resource.
 * @param resource_ The client's resource
 * @param format keymap format
 * @param fd keymap file descriptor
 * @param size keymap size, in bytes
 */
static inline void
wl_keyboard_send_keymap(struct wl_resource *resource_, uint32_t format, int32_t fd, uint32_t size)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_KEYMAP, format, fd, size);
}

/**
 * @ingroup iface_wl_keyboard
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the enter event
 * @param surface surface gaining keyboard focus
 * @param keys the currently pressed keys
 */
static inline void
wl_keyboard_send_enter(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface, struct wl_array *keys)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_ENTER, serial, surface, keys);
}

/**
 * @ingroup iface_wl_keyboard
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the leave event
 * @param surface surface that lost keyboard focus
 */
static inline void
wl_keyboard_send_leave(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_LEAVE, serial, surface);
}

/**
 * @ingroup iface_wl_keyboard
 * Sends an key event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the key event
 * @param time timestamp with millisecond granularity
 * @param key key that produced the event
 * @param state physical state of the key
 */
static inline void
wl_keyboard_send_key(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t key, uint32_t state)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_KEY, serial, time, key, state);
}

/**
 * @ingroup iface_wl_keyboard
 * Sends an modifiers event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the modifiers event
 * @param mods_depressed depressed modifiers
 * @param mods_latched latched modifiers
 * @param mods_locked locked modifiers
 * @param group keyboard layout
 */
static inline void
wl_keyboard_send_modifiers(struct wl_resource *resource_, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_MODIFIERS, serial, mods_depressed, mods_latched, mods_locked, group);
}

/**
 * @ingroup iface_wl_keyboard
 * Sends an repeat_info event to the client owning the resource.
 * @param resource_ The client's resource
 * @param rate the rate of repeating keys in characters per second
 * @param delay delay in milliseconds since key down until repeating starts
 */
static inline void
wl_keyboard_send_repeat_info(struct wl_resource *resource_, int32_t rate, int32_t delay)
{
	wl_resource_post_event(resource_, WL_KEYBOARD_REPEAT_INFO, rate, delay);
}

/**
 * @ingroup iface_wl_touch
 * @struct wl_touch_interface
 */
struct wl_touch_interface {
	/**
	 * release the touch object
	 *
	 * 
	 * @since 3
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_TOUCH_MAX_VERSION 6

#define WL_TOUCH_DOWN 0
#define WL_TOUCH_UP 1
#define WL_TOUCH_MOTION 2
#define WL_TOUCH_FRAME 3
#define WL_TOUCH_CANCEL 4
#define WL_TOUCH_SHAPE 5
#define WL_TOUCH_ORIENTATION 6

/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_DOWN_SINCE_VERSION 1
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_UP_SINCE_VERSION 1
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_MOTION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_FRAME_SINCE_VERSION 1
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_CANCEL_SINCE_VERSION 1
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_SHAPE_SINCE_VERSION 6
/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_ORIENTATION_SINCE_VERSION 6

/**
 * @ingroup iface_wl_touch
 */
#define WL_TOUCH_RELEASE_SINCE_VERSION 3

/**
 * @ingroup iface_wl_touch
 * Sends an down event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the touch down event
 * @param time timestamp with millisecond granularity
 * @param surface surface touched
 * @param id the unique ID of this touch point
 * @param x surface-local x coordinate
 * @param y surface-local y coordinate
 */
static inline void
wl_touch_send_down(struct wl_resource *resource_, uint32_t serial, uint32_t time, struct wl_resource *surface, int32_t id, wl_fixed_t x, wl_fixed_t y)
{
	wl_resource_post_event(resource_, WL_TOUCH_DOWN, serial, time, surface, id, x, y);
}

/**
 * @ingroup iface_wl_touch
 * Sends an up event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial number of the touch up event
 * @param time timestamp with millisecond granularity
 * @param id the unique ID of this touch point
 */
static inline void
wl_touch_send_up(struct wl_resource *resource_, uint32_t serial, uint32_t time, int32_t id)
{
	wl_resource_post_event(resource_, WL_TOUCH_UP, serial, time, id);
}

/**
 * @ingroup iface_wl_touch
 * Sends an motion event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param id the unique ID of this touch point
 * @param x surface-local x coordinate
 * @param y surface-local y coordinate
 */
static inline void
wl_touch_send_motion(struct wl_resource *resource_, uint32_t time, int32_t id, wl_fixed_t x, wl_fixed_t y)
{
	wl_resource_post_event(resource_, WL_TOUCH_MOTION, time, id, x, y);
}

/**
 * @ingroup iface_wl_touch
 * Sends an frame event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_touch_send_frame(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_TOUCH_FRAME);
}

/**
 * @ingroup iface_wl_touch
 * Sends an cancel event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_touch_send_cancel(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_TOUCH_CANCEL);
}

/**
 * @ingroup iface_wl_touch
 * Sends an shape event to the client owning the resource.
 * @param resource_ The client's resource
 * @param id the unique ID of this touch point
 * @param major length of the major axis in surface-local coordinates
 * @param minor length of the minor axis in surface-local coordinates
 */
static inline void
wl_touch_send_shape(struct wl_resource *resource_, int32_t id, wl_fixed_t major, wl_fixed_t minor)
{
	wl_resource_post_event(resource_, WL_TOUCH_SHAPE, id, major, minor);
}

/**
 * @ingroup iface_wl_touch
 * Sends an orientation event to the client owning the resource.
 * @param resource_ The client's resource
 * @param id the unique ID of this touch point
 * @param orientation angle between major axis and positive surface y-axis in degrees
 */
static inline void
wl_touch_send_orientation(struct wl_resource *resource_, int32_t id, wl_fixed_t orientation)
{
	wl_resource_post_event(resource_, WL_TOUCH_ORIENTATION, id, orientation);
}

#ifndef WL_OUTPUT_SUBPIXEL_ENUM
#define WL_OUTPUT_SUBPIXEL_ENUM
/**
 * @ingroup iface_wl_output
 * subpixel geometry information
 *
 * This enumeration describes how the physical
 * pixels on an output are laid out.
 */
enum wl_output_subpixel {
	/**
	 * unknown geometry
	 */
	WL_OUTPUT_SUBPIXEL_UNKNOWN = 0,
	/**
	 * no geometry
	 */
	WL_OUTPUT_SUBPIXEL_NONE = 1,
	/**
	 * horizontal RGB
	 */
	WL_OUTPUT_SUBPIXEL_HORIZONTAL_RGB = 2,
	/**
	 * horizontal BGR
	 */
	WL_OUTPUT_SUBPIXEL_HORIZONTAL_BGR = 3,
	/**
	 * vertical RGB
	 */
	WL_OUTPUT_SUBPIXEL_VERTICAL_RGB = 4,
	/**
	 * vertical BGR
	 */
	WL_OUTPUT_SUBPIXEL_VERTICAL_BGR = 5,
};
/**
 * @ingroup iface_wl_output
 * Validate a wl_output subpixel value.
 *
 * @return true on success, false on error.
 * @ref wl_output_subpixel
 */
static inline bool
wl_output_subpixel_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_OUTPUT_SUBPIXEL_UNKNOWN:
		return version >= 1;
	case WL_OUTPUT_SUBPIXEL_NONE:
		return version >= 1;
	case WL_OUTPUT_SUBPIXEL_HORIZONTAL_RGB:
		return version >= 1;
	case WL_OUTPUT_SUBPIXEL_HORIZONTAL_BGR:
		return version >= 1;
	case WL_OUTPUT_SUBPIXEL_VERTICAL_RGB:
		return version >= 1;
	case WL_OUTPUT_SUBPIXEL_VERTICAL_BGR:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_OUTPUT_SUBPIXEL_ENUM */

#ifndef WL_OUTPUT_TRANSFORM_ENUM
#define WL_OUTPUT_TRANSFORM_ENUM
/**
 * @ingroup iface_wl_output
 * transform from framebuffer to output
 *
 * This describes the transform that a compositor will apply to a
 * surface to compensate for the rotation or mirroring of an
 * output device.
 *
 * The flipped values correspond to an initial flip around a
 * vertical axis followed by rotation.
 *
 * The purpose is mainly to allow clients to render accordingly and
 * tell the compositor, so that for fullscreen surfaces, the
 * compositor will still be able to scan out directly from client
 * surfaces.
 */
enum wl_output_transform {
	/**
	 * no transform
	 */
	WL_OUTPUT_TRANSFORM_NORMAL = 0,
	/**
	 * 90 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_90 = 1,
	/**
	 * 180 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_180 = 2,
	/**
	 * 270 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_270 = 3,
	/**
	 * 180 degree flip around a vertical axis
	 */
	WL_OUTPUT_TRANSFORM_FLIPPED = 4,
	/**
	 * flip and rotate 90 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_FLIPPED_90 = 5,
	/**
	 * flip and rotate 180 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_FLIPPED_180 = 6,
	/**
	 * flip and rotate 270 degrees counter-clockwise
	 */
	WL_OUTPUT_TRANSFORM_FLIPPED_270 = 7,
};
/**
 * @ingroup iface_wl_output
 * Validate a wl_output transform value.
 *
 * @return true on success, false on error.
 * @ref wl_output_transform
 */
static inline bool
wl_output_transform_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_OUTPUT_TRANSFORM_NORMAL:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_90:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_180:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_270:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_FLIPPED:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_FLIPPED_90:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_FLIPPED_180:
		return version >= 1;
	case WL_OUTPUT_TRANSFORM_FLIPPED_270:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_OUTPUT_TRANSFORM_ENUM */

#ifndef WL_OUTPUT_MODE_ENUM
#define WL_OUTPUT_MODE_ENUM
/**
 * @ingroup iface_wl_output
 * mode information
 *
 * These flags describe properties of an output mode.
 * They are used in the flags bitfield of the mode event.
 */
enum wl_output_mode {
	/**
	 * indicates this is the current mode
	 */
	WL_OUTPUT_MODE_CURRENT = 0x1,
	/**
	 * indicates this is the preferred mode
	 */
	WL_OUTPUT_MODE_PREFERRED = 0x2,
};
/**
 * @ingroup iface_wl_output
 * Validate a wl_output mode value.
 *
 * @return true on success, false on error.
 * @ref wl_output_mode
 */
static inline bool
wl_output_mode_is_valid(uint32_t value, uint32_t version) {
	uint32_t valid = 0;
	if (version >= 1)
		valid |= WL_OUTPUT_MODE_CURRENT;
	if (version >= 1)
		valid |= WL_OUTPUT_MODE_PREFERRED;
	return (value & ~valid) == 0;
}
#endif /* WL_OUTPUT_MODE_ENUM */

/**
 * @ingroup iface_wl_output
 * @struct wl_output_interface
 */
struct wl_output_interface {
	/**
	 * release the output object
	 *
	 * Using this request a client can tell the server that it is not
	 * going to use the output object anymore.
	 * @since 3
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_OUTPUT_MAX_VERSION 3

#define WL_OUTPUT_GEOMETRY 0
#define WL_OUTPUT_MODE 1
#define WL_OUTPUT_DONE 2
#define WL_OUTPUT_SCALE 3

/**
 * @ingroup iface_wl_output
 */
#define WL_OUTPUT_GEOMETRY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_output
 */
#define WL_OUTPUT_MODE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_output
 */
#define WL_OUTPUT_DONE_SINCE_VERSION 2
/**
 * @ingroup iface_wl_output
 */
#define WL_OUTPUT_SCALE_SINCE_VERSION 2

/**
 * @ingroup iface_wl_output
 */
#define WL_OUTPUT_RELEASE_SINCE_VERSION 3

/**
 * @ingroup iface_wl_output
 * Sends an geometry event to the client owning the resource.
 * @param resource_ The client's resource
 * @param x x position within the global compositor space
 * @param y y position within the global compositor space
 * @param physical_width width in millimeters of the output
 * @param physical_height height in millimeters of the output
 * @param subpixel subpixel orientation of the output
 * @param make textual description of the manufacturer
 * @param model textual description of the model
 * @param transform transform that maps framebuffer to output
 */
static inline void
wl_output_send_geometry(struct wl_resource *resource_, int32_t x, int32_t y, int32_t physical_width, int32_t physical_height, int32_t subpixel, const char *make, const char *model, int32_t transform)
{
	wl_resource_post_event(resource_, WL_OUTPUT_GEOMETRY, x, y, physical_width, physical_height, subpixel, make, model, transform);
}

/**
 * @ingroup iface_wl_output
 * Sends an mode event to the client owning the resource.
 * @param resource_ The client's resource
 * @param flags bitfield of mode flags
 * @param width width of the mode in hardware units
 * @param height height of the mode in hardware units
 * @param refresh vertical refresh rate in mHz
 */
static inline void
wl_output_send_mode(struct wl_resource *resource_, uint32_t flags, int32_t width, int32_t height, int32_t refresh)
{
	wl_resource_post_event(resource_, WL_OUTPUT_MODE, flags, width, height, refresh);
}

/**
 * @ingroup iface_wl_output
 * Sends an done event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
wl_output_send_done(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_OUTPUT_DONE);
}

/**
 * @ingroup iface_wl_output
 * Sends an scale event to the client owning the resource.
 * @param resource_ The client's resource
 * @param factor scaling factor of output
 */
static inline void
wl_output_send_scale(struct wl_resource *resource_, int32_t factor)
{
	wl_resource_post_event(resource_, WL_OUTPUT_SCALE, factor);
}

/**
 * @ingroup iface_wl_region
 * @struct wl_region_interface
 */
struct wl_region_interface {
	/**
	 * destroy region
	 *
	 * Destroy the region. This will invalidate the object ID.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * add rectangle to region
	 *
	 * Add the specified rectangle to the region.
	 * @param x region-local x coordinate
	 * @param y region-local y coordinate
	 * @param width rectangle width
	 * @param height rectangle height
	 */
	void (*add)(struct wl_client *client,
		    struct wl_resource *resource,
		    int32_t x,
		    int32_t y,
		    int32_t width,
		    int32_t height);
	/**
	 * subtract rectangle from region
	 *
	 * Subtract the specified rectangle from the region.
	 * @param x region-local x coordinate
	 * @param y region-local y coordinate
	 * @param width rectangle width
	 * @param height rectangle height
	 */
	void (*subtract)(struct wl_client *client,
			 struct wl_resource *resource,
			 int32_t x,
			 int32_t y,
			 int32_t width,
			 int32_t height);
};

#define WL_REGION_MAX_VERSION 1


/**
 * @ingroup iface_wl_region
 */
#define WL_REGION_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_region
 */
#define WL_REGION_ADD_SINCE_VERSION 1
/**
 * @ingroup iface_wl_region
 */
#define WL_REGION_SUBTRACT_SINCE_VERSION 1

#ifndef WL_SUBCOMPOSITOR_ERROR_ENUM
#define WL_SUBCOMPOSITOR_ERROR_ENUM
enum wl_subcompositor_error {
	/**
	 * the to-be sub-surface is invalid
	 */
	WL_SUBCOMPOSITOR_ERROR_BAD_SURFACE = 0,
};
/**
 * @ingroup iface_wl_subcompositor
 * Validate a wl_subcompositor error value.
 *
 * @return true on success, false on error.
 * @ref wl_subcompositor_error
 */
static inline bool
wl_subcompositor_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SUBCOMPOSITOR_ERROR_BAD_SURFACE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SUBCOMPOSITOR_ERROR_ENUM */

/**
 * @ingroup iface_wl_subcompositor
 * @struct wl_subcompositor_interface
 */
struct wl_subcompositor_interface {
	/**
	 * unbind from the subcompositor interface
	 *
	 * Informs the server that the client will not be using this
	 * protocol object anymore. This does not affect any other objects,
	 * wl_subsurface objects included.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * give a surface the role sub-surface
	 *
	 * Create a sub-surface interface for the given surface, and
	 * associate it with the given parent surface. This turns a plain
	 * wl_surface into a sub-surface.
	 *
	 * The to-be sub-surface must not already have another role, and it
	 * must not have an existing wl_subsurface object. Otherwise a
	 * protocol error is raised.
	 * @param id the new sub-surface object ID
	 * @param surface the surface to be turned into a sub-surface
	 * @param parent the parent surface
	 */
	void (*get_subsurface)(struct wl_client *client,
			       struct wl_resource *resource,
			       uint32_t id,
			       struct wl_resource *surface,
			       struct wl_resource *parent);
};

#define WL_SUBCOMPOSITOR_MAX_VERSION 1


/**
 * @ingroup iface_wl_subcompositor
 */
#define WL_SUBCOMPOSITOR_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subcompositor
 */
#define WL_SUBCOMPOSITOR_GET_SUBSURFACE_SINCE_VERSION 1

#ifndef WL_SUBSURFACE_ERROR_ENUM
#define WL_SUBSURFACE_ERROR_ENUM
enum wl_subsurface_error {
	/**
	 * wl_surface is not a sibling or the parent
	 */
	WL_SUBSURFACE_ERROR_BAD_SURFACE = 0,
};
/**
 * @ingroup iface_wl_subsurface
 * Validate a wl_subsurface error value.
 *
 * @return true on success, false on error.
 * @ref wl_subsurface_error
 */
static inline bool
wl_subsurface_error_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case WL_SUBSURFACE_ERROR_BAD_SURFACE:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* WL_SUBSURFACE_ERROR_ENUM */

/**
 * @ingroup iface_wl_subsurface
 * @struct wl_subsurface_interface
 */
struct wl_subsurface_interface {
	/**
	 * remove sub-surface interface
	 *
	 * The sub-surface interface is removed from the wl_surface
	 * object that was turned into a sub-surface with a
	 * wl_subcompositor.get_subsurface request. The wl_surface's
	 * association to the parent is deleted, and the wl_surface loses
	 * its role as a sub-surface. The wl_surface is unmapped.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * reposition the sub-surface
	 *
	 * This schedules a sub-surface position change. The sub-surface
	 * will be moved so that its origin (top left corner pixel) will be
	 * at the location x, y of the parent surface coordinate system.
	 * The coordinates are not restricted to the parent surface area.
	 * Negative values are allowed.
	 *
	 * The scheduled coordinates will take effect whenever the state of
	 * the parent surface is applied. When this happens depends on
	 * whether the parent surface is in synchronized mode or not. See
	 * wl_subsurface.set_sync and wl_subsurface.set_desync for details.
	 *
	 * If more than one set_position request is invoked by the client
	 * before the commit of the parent surface, the position of a new
	 * request always replaces the scheduled position from any previous
	 * request.
	 *
	 * The initial position is 0, 0.
	 * @param x x coordinate in the parent surface
	 * @param y y coordinate in the parent surface
	 */
	void (*set_position)(struct wl_client *client,
			     struct wl_resource *resource,
			     int32_t x,
			     int32_t y);
	/**
	 * restack the sub-surface
	 *
	 * This sub-surface is taken from the stack, and put back just
	 * above the reference surface, changing the z-order of the
	 * sub-surfaces. The reference surface must be one of the sibling
	 * surfaces, or the parent surface. Using any other surface,
	 * including this sub-surface, will cause a protocol error.
	 *
	 * The z-order is double-buffered. Requests are handled in order
	 * and applied immediately to a pending state. The final pending
	 * state is copied to the active state the next time the state of
	 * the parent surface is applied. When this happens depends on
	 * whether the parent surface is in synchronized mode or not. See
	 * wl_subsurface.set_sync and wl_subsurface.set_desync for details.
	 *
	 * A new sub-surface is initially added as the top-most in the
	 * stack of its siblings and parent.
	 * @param sibling the reference surface
	 */
	void (*place_above)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_resource *sibling);
	/**
	 * restack the sub-surface
	 *
	 * The sub-surface is placed just below the reference surface.
	 * See wl_subsurface.place_above.
	 * @param sibling the reference surface
	 */
	void (*place_below)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_resource *sibling);
	/**
	 * set sub-surface to synchronized mode
	 *
	 * Change the commit behaviour of the sub-surface to synchronized
	 * mode, also described as the parent dependent mode.
	 *
	 * In synchronized mode, wl_surface.commit on a sub-surface will
	 * accumulate the committed state in a cache, but the state will
	 * not be applied and hence will not change the compositor output.
	 * The cached state is applied to the sub-surface immediately after
	 * the parent surface's state is applied. This ensures atomic
	 * updates of the parent and all its synchronized sub-surfaces.
	 * Applying the cached state will invalidate the cache, so further
	 * parent surface commits do not (re-)apply old state.
	 *
	 * See wl_subsurface for the recursive effect of this mode.
	 */
	void (*set_sync)(struct wl_client *client,
			 struct wl_resource *resource);
	/**
	 * set sub-surface to desynchronized mode
	 *
	 * Change the commit behaviour of the sub-surface to
	 * desynchronized mode, also described as independent or freely
	 * running mode.
	 *
	 * In desynchronized mode, wl_surface.commit on a sub-surface will
	 * apply the pending state directly, without caching, as happens
	 * normally with a wl_surface. Calling wl_surface.commit on the
	 * parent surface has no effect on the sub-surface's wl_surface
	 * state. This mode allows a sub-surface to be updated on its own.
	 *
	 * If cached state exists when wl_surface.commit is called in
	 * desynchronized mode, the pending state is added to the cached
	 * state, and applied as a whole. This invalidates the cache.
	 *
	 * Note: even if a sub-surface is set to desynchronized, a parent
	 * sub-surface may override it to behave as synchronized. For
	 * details, see wl_subsurface.
	 *
	 * If a surface's parent surface behaves as desynchronized, then
	 * the cached state is applied on set_desync.
	 */
	void (*set_desync)(struct wl_client *client,
			   struct wl_resource *resource);
};

#define WL_SUBSURFACE_MAX_VERSION 1


/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_SET_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_PLACE_ABOVE_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_PLACE_BELOW_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_SET_SYNC_SINCE_VERSION 1
/**
 * @ingroup iface_wl_subsurface
 */
#define WL_SUBSURFACE_SET_DESYNC_SINCE_VERSION 1

#ifdef  __cplusplus
}
#endif

#endif
