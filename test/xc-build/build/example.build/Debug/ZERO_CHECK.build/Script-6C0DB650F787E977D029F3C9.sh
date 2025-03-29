#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build
  make -f /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build
  make -f /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build
  make -f /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build
  make -f /Users/mucbuc/work/wgui/test/lib/oxygen/test/xc-build/CMakeScripts/ReRunCMake.make
fi

