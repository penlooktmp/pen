#!/bin/sh
autoreconf -fiv || exit 1;
automake --add-missing --copy --force-missing