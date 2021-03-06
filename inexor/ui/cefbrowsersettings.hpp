#ifndef _CEF_BROWSER_SETTINGS_H
#define _CEF_BROWSER_SETTINGS_H
#pragma once

#include "include/cef_app.h"

class InexorCefBrowserSettings : public CefBrowserSettings {
    public:
        InexorCefBrowserSettings() {
            windowless_frame_rate = 60;
            file_access_from_file_urls = STATE_ENABLED;
            plugins = STATE_DISABLED;
            webgl = STATE_DISABLED;
            java = STATE_DISABLED;
            caret_browsing = STATE_DISABLED;
            javascript = STATE_ENABLED;
            javascript_access_clipboard = STATE_ENABLED;
            javascript_dom_paste = STATE_ENABLED;
        };
};

#endif
