#include "nappgui.h"
#include "osmain.h"
//#include <iostream>

typedef struct _app_t App;

char foo();

struct _app_t {
    Window *window;
    TextView *text;
    uint32_t clicks;
};

/*---------------------------------------------------------------------------*/

static void i_OnButton(App *app, Event *e) {
    String *msg = str_printf("Button click (%d)\n", app->clicks);
    textview_writef(app->text, tc(msg));
    str_destroy(&msg);
    app->clicks += 1;
    unref(e);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app) {
    Panel *panel = panel_create();
    Layout *layout = layout_create(1, 3);
    Label *label = label_create();
    Button *button = button_push();
    TextView *text = textview_create();
    app->text = text;
    label_text(label, "Hello!, I'm a label");
    button_text(button, "Click Me!");
    button_OnClick(button, listener(app, i_OnButton, App));
    layout_label(layout, label, 0, 0);
    layout_button(layout, button, 0, 1);
    layout_textview(layout, text, 0, 2);
    layout_hsize(layout, 0, 250);
    layout_vsize(layout, 2, 100);
    layout_margin(layout, 5);
    layout_vmargin(layout, 0, 5);
    layout_vmargin(layout, 1, 5);
    panel_layout(panel, layout);
    return panel;
}

/*---------------------------------------------------------------------------*/

static void i_OnClose(App *app, Event *e) {
    osapp_finish();
    unref(app);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static App *i_create(void) {
    App *app = heap_new0(App);
    Panel *panel = i_panel(app);
    app->window = window_create(ekWINDOW_STD);
    window_panel(app->window, panel);
    window_title(app->window, /*"Hello, World!"*/new char(foo()));
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app) {
    window_destroy(&(*app)->window);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/
osmain(i_create, i_destroy, "", App)
// static void init() {
//     //osmain(i_create, i_destroy, "", App);
//     #if defined(__LINUX__) // TODO: Add options for other OSes as well. See osmain.h.
//     FUNC_CHECK_APP_CREATE(/*func_create*/i_create, /*type*/App),
//     FUNC_CHECK_DESTROY(/*func_destroy*/i_destroy, /*type*/App),
//     osmain_imp(
//                (uint32_t)/*argc*/0, (char_t**)/*argv*/NULL, NULL, 0.,
//                (FPtr_app_create)/*func_create*/i_create,
//                (FPtr_app_update)NULL,
//                (FPtr_destroy)/*func_destroy*/i_destroy,
//                (char_t*)/*options*/"");
//     #endif
//     //std::cout << "Foobar!";
//     //return 0;
// }