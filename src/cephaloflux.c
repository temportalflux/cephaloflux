
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(cephaloflux, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/events/keycode_state_changed.h>
#include <zmk/events/layer_state_changed.h>

int handle_keycode_event(const zmk_event_t *eh) {
	const struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);

	return ZMK_EV_EVENT_BUBBLE; // to allow the event to continue
	//return ZMK_BEHAVIOR_OPAQUE; // to consume
}

ZMK_LISTENER(cephaloflux_keycode_handler, handle_keycode_event);
ZMK_SUBSCRIPTION(cephaloflux_keycode_handler, zmk_keycode_state_changed);

int handle_layer_event(const zmk_event_t *eh) {
	const struct zmk_layer_state_changed *ev = as_zmk_layer_state_changed(eh);
	
	return ZMK_EV_EVENT_BUBBLE; // to allow the event to continue
	//return ZMK_BEHAVIOR_OPAQUE; // to consume
}

ZMK_LISTENER(cephaloflux_layer_handler, handle_layer_event);
ZMK_SUBSCRIPTION(cephaloflux_layer_handler, zmk_layer_state_changed);
