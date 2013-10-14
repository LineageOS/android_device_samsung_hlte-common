#!/bin/sh

set -e

export DEVICE=hltexx
export VENDOR=samsung
./../hltexx/extract-files.sh $@
