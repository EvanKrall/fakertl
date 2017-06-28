#!/bin/bash

DYLD_LIBRARY_PATH="$(dirname "${BASH_SOURCE[0]}")" "$@"
