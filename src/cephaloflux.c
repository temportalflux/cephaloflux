
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/events/keycode_state_changed.h>
#include <zmk/events/layer_state_changed.h>

int handle_keycode_event(const zmk_event_t *eh) {
	const struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);

	// cause a key press
	// sampled from https://github.com/zmkfirmware/zmk/blob/main/app/src/behaviors/behavior_key_repeat.c#L80
	// ```
	// zmk_keycode_state_changed event;
	// raise_zmk_keycode_state_changed(event);
	// ```

	LOG_DBG("cephaloflux handle_keycode_event");

	return ZMK_EV_EVENT_BUBBLE; // to allow the event to continue
	//return ZMK_BEHAVIOR_OPAQUE; // to consume
}

// may want `zmk_position_state_changed`, its unclear if position or keycode represents a switch vs a key a switch is mapped to
ZMK_LISTENER(cephaloflux_keycode_handler, handle_keycode_event);
ZMK_SUBSCRIPTION(cephaloflux_keycode_handler, zmk_keycode_state_changed);

int handle_layer_event(const zmk_event_t *eh) {
	const struct zmk_layer_state_changed *ev = as_zmk_layer_state_changed(eh);

	// `WRITE_BIT(?, ?, bool)` sends data over HID?
	
	LOG_DBG("cephaloflux handle_layer_event");

	return ZMK_EV_EVENT_BUBBLE; // to allow the event to continue
	//return ZMK_BEHAVIOR_OPAQUE; // to consume
}

ZMK_LISTENER(cephaloflux_layer_handler, handle_layer_event);
ZMK_SUBSCRIPTION(cephaloflux_layer_handler, zmk_layer_state_changed);
