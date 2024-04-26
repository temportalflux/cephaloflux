#!/bin/bash

# https://zmk.dev/docs/development/setup

rm-rf zmk

git clone https://github.com/zmkfirmware/zmk.git

cd zmk
west init -l app/
west update
west zephyr-export
pip install -r zephyr/scripts/requirements.txt
