#!/bin/bash

# https://zmk.dev/docs/development/build-flash

WORKSPACE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cd zmk
west build -s app -d build/left -b "nice_nano_v2" -- -DSHIELD="splitkb_aurora_sweep_left" -DZMK_CONFIG="$WORKSPACE_DIR/config"
west build -s app -d build/right -b "nice_nano_v2" -- -DSHIELD="splitkb_aurora_sweep_right" -DZMK_CONFIG="$WORKSPACE_DIR/config"
